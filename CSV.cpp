#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSV.h"

using namespace std;

CSV::CSV(string fileName) : fileName(fileName) {}

void CSV::create(string content) const
{
    fstream file;
    try
    {
        file.open(fileName, ios::out | ios::app);
    }
    catch (...)
    {
        cout << "Error: could not open file" << endl;
        throw exception();
    }

    file << content << endl;
    file.close();
}

void CSV::fetch(vector<vector<string>> &matrix) const
{
    matrix = {};
    bool longString = false; //string with space are between []
    string line;
    fstream file;
    vector<string> lineArray; //rows
    try
    {
        file.open(fileName, ios::in);
    }
    catch (...)
    {
        cout << "Error: could not open file" << endl;
        throw exception();
    }
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        stringstream tempString; // for string with space
        tempString << "";
        while (ss >> word)
        {
            if (word != ",")
            {
                if ((!longString) && (word != "["))
                    lineArray.push_back(word);
                if ((longString) && (word != "]"))
                {
                    tempString << " " << word;
                }
                if (word == "[")
                    longString = true;
                if (word == "]")
                {
                    longString = false;
                    lineArray.push_back(tempString.str());
                    tempString.str("");
                }
            }
        }
        matrix.push_back(lineArray);
        lineArray = {};
    }
    file.close();
};

void CSV::getLine(int lineNum, vector<string> &row) const
{
    row = {};
    vector<vector<string>> matrix;
    fetch(matrix);
    for (int i = 0; i < matrix[lineNum].size(); i++)
        row.push_back(matrix[lineNum][i]);
}

void CSV::update(int lineNum, string content) const
{
    fstream file, tempFile;
    try
    {
        file.open(fileName, ios::in);
    }
    catch (...)
    {
        cout << "Error: could not open file" << endl;
        throw exception();
    }
    try
    {
        tempFile.open("temp.csv", ios::out);
    }
    catch (...)
    {
        cout << "Error: could not open file" << endl;
        throw exception();
    }
    string line;
    int i = -1;
    while (getline(file, line))
    {
        i++;
        if (i != lineNum)
            tempFile << line << endl;
        else
            tempFile << content << endl;
    }
    file.close();
    tempFile.close();
    remove(fileName.c_str());
    rename("temp.csv", fileName.c_str());
}

int CSV::generateId() const
{

    vector<vector<string>> matrix;
    this->fetch(matrix);
    int i = matrix.size();
    matrix.clear();
    return i;
}