#ifndef CSV_H
#define CSV_H

using namespace std;

inline int generateId(string fileName);
class CSV
{
public:
    string fileName;
    CSV(string fileName);
    void create(string content) const;
    void fetch(vector<vector<string>> &matrix) const;
    void getLine(int lineNum,vector<string> &row) const;
    void update(int lineNum, string content) const;
    int generateId() const;
};

#endif // CSV_H