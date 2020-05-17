#include <iostream>
#include <string>
#include <vector>
#include "Queue.h"
#include "CSV.h"
#include "Controller.h"

using namespace std;

//Constructor
Queue::Queue(string fileName) : fileName(fileName) { matrix = {}; };
//Destructor
Queue::~Queue() { matrix.clear(); };
//Pull data from file to matrix
void Queue::fetch()
{
    CSV ticketFile(fileName);
    ticketFile.fetch(matrix);
    sizeOfQueue = matrix.size();
}
//Display data
void Queue::display() const
{
    if (sizeOfQueue == 0)
        cout << "There are no tickets" << endl;
    else
        for (int i = 0; i < matrix.size(); i++)
        {

            margin.push_back(stoi(matrix[i][0]));
            for (int j = 0; j < matrix[i].size(); j++)
                cout << matrix[i][j] << "|\t";
            cout << endl;
        };
};
//Filter the data in the matrix
void Queue::filter(int column, string value)
{
    if (matrix.size() != 0)
    {
        vector<vector<string>> matrixTemp = {};
        for (int i = 0; i < matrix.size(); i++)
            if (value.compare(matrix[i][column]) == 0)
                matrixTemp.push_back(matrix[i]);
        matrix = matrixTemp;
        sizeOfQueue = matrix.size();
    }
}
//Change data from matrix with extrenal data (extrernal keys)
void Queue::map(string fileNameTemp, vector<int> columns, int columnValue)
{
    vector<vector<string>> matrixTemp;
    CSV mapFile(fileNameTemp);
    mapFile.fetch(matrixTemp);
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < columns.size(); j++)
            stoi(matrix[i][columns[j]]) < 0
                ? matrix[i][columns[j]] = "N/A"
                : matrix[i][columns[j]] = matrixTemp[stoi(matrix[i][columns[j]])][columnValue];
}