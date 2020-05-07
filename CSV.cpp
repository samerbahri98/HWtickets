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
    file.open(this->fileName, ios::in);
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
                    cout << tempString.str() << endl;
                    tempString << endl;
                }
            }
        }

        matrix.push_back(lineArray);
        lineArray = {};
    }
    file.close();
};