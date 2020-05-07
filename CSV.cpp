#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "CSV.h"

using namespace std;

CSV::CSV(string fileName) : fileName(fileName) {}

void CSV::create(string content)
{
    fstream file;
    file.open(this->fileName, ios::out | ios::app);
    file << content << endl;
    file.close();
}

void CSV::fetch(vector<vector<string>> &matrix)
{
    matrix = {};
    bool longString = false;
    int id, client, agent;
    string line, content, priority, status;
    fstream file;
    vector<string> lineArray;
    file.open(fileName, ios::in);
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        stringstream tempString, tempString2;
        tempString << "";
        tempString2 << "";
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
                    tempString << endl;
                }
            }
        }

        matrix.push_back(lineArray);
        lineArray = {};
    }
    file.close();
};

// void CSV::pop(int lineNum)
// {
//     fstream file, tempFile;
//     file.open(fileName, ios::in);
//     tempFile.open("temp.csv", ios::out);
//     string line;
//     int i = -1;
//     while (getline(file, line))
//     {
//         i++;
//         if (i != lineNum)
//             tempFile << line << endl;
//     }
//     file.close();
//     tempFile.close();
//     remove(fileName.c_str());
// }

void CSV::update(int lineNum, string content)
{
    fstream file, tempFile;
    file.open(fileName, ios::in);
    tempFile.open("temp.csv", ios::out);
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
}