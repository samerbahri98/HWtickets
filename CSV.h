#ifndef CSV_H
#define CSV_H

using namespace std;

inline int generateId(string fileName);
class CSV
{
public:
    string fileName;
    CSV(string fileName);                                 //Constructor
    void create(string content) const;                    //add a string content)to the end of the file
    void fetch(vector<vector<string>> &matrix) const;     //matrix of strings (matrix) corresponds to all the cells in the CSV file
    void getLine(int lineNum, vector<string> &row) const; //vector of strings (row) corresponds to the cells in the row (lineNum) in the CSV file
    void update(int lineNum, string content) const;       //replace the row (lineNum) by the string content
    int generateId() const;                               //return the number of lines in a file, could be used for unique id
};

#endif // CSV_H