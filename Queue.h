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
};

#endif //QUEUE_H