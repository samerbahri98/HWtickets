#include <iostream>
#include <string>
#include <vector>
#include "Queue.h"
#include "CSV.h"

using namespace std;

Queue::Queue(string fileName) : fileName(fileName) { matrix = {}; };
void Queue::fetch()
{
    CSV ticketFile("tickets.csv");
    ticketFile.fetch(matrix);
}

Queue::~Queue(){matrix.clear();};

void Queue::display()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << "|\t";
        cout << endl;
    };
};
