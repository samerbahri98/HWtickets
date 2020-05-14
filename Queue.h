#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Queue
{
public:
    string fileName;

    vector<vector<string>>matrix;
    Queue(string fileName);
    ~Queue();
    void fetch();
    void display();
    void filter(int column,string value);
    void map(string fileNameTemp, vector<int>columns,int columnValue);
};

#endif //QUEUE_H