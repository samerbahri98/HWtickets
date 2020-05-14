#include <iostream>
#include <string>
#include <vector>
#include "Queue.h"
#include "CSV.h"
#include "Controller.h"

using namespace std;

Queue::Queue(string fileName) : fileName(fileName) { matrix = {}; };
void Queue::fetch()
{
    CSV ticketFile(fileName);
    ticketFile.fetch(matrix);
    sizeOfQueue = matrix.size();
}

Queue::~Queue() { matrix.clear(); };

void Queue::display()
{
    if (sizeOfQueue == 0)
        cout << "There are no tickets" << endl;
    else
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
                cout << matrix[i][j] << "|\t";
            cout << endl;
        };
};

void Queue::filter(int column, string value)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (value.compare(matrix[i][column]) == 0)
        {
            for (int j = 0; j < matrix[i].size(); j++)

                cout << matrix[i][j] << "|\t";
            cout << endl;
        }
    };
}
