#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class Queue
{
    string fileName;
    vector<vector<string>> matrix;

public:
    Queue(string fileName);                                              //Constructor
    ~Queue();                                                            //Destructor
    void fetch();                                                        //Pull data from file to matrix
    void display() const;                                                //Display data
    void filter(int column, string value);                               //Filter the data in the matrix
    void map(string fileNameTemp, vector<int> columns, int columnValue); //Change data from matrix with extrenal data (extrernal keys)
};

#endif //QUEUE_H