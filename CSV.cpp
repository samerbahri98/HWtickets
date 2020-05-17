#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSV.h"

using namespace std;
//Constructor
CSV::CSV(string fileName) : fileName(fileName) {}
//add a string (content)to the end of the file
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
//matrix of strings (matrix) corresponds to all the cells in the CSV file
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
        stringstream ss(line); //decompose the line into words
        string word;
        stringstream tempString; // for string with space
        while (ss >> word)
        {
            if (word != ",") //for columns separation
            {
                if ((!longString) && (word != "[")) //no string with space
                    lineArray.push_back(word);
                if ((longString) && (word != "]")) //string with space not ended
                    tempString << " " << word; //add the spaces
                if (word == "[") //string with space begin
                    longString = true;
                if (word == "]") //string with space end
                {
                    longString = false;
                    lineArray.push_back(tempString.str());
                    tempString.str(""); //empty the string with space
                }
            }
        }
        matrix.push_back(lineArray);
        lineArray = {}; //empty the row
    }
    file.close();
};
//vector of strings (row) corresponds to the cells in the row (lineNum) in the CSV file
void CSV::getLine(int lineNum, vector<string> &row) const
{
    row = {};
    vector<vector<string>> matrix;
    fetch(matrix);
    for (int i = 0; i < matrix[lineNum].size(); i++)
        row.push_back(matrix[lineNum][i]);
}
//replace the row (lineNum) by the string content
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
    int i = -1; //the first line is 0
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
//return the number of lines in a file, could be used for unique id
int CSV::generateId() const
{

    vector<vector<string>> matrix;
    this->fetch(matrix);
    int i = matrix.size();
    matrix.clear();
    return i;
}