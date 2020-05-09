#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

inline int generateId(string fileName);
class CSV
{
public:
    string fileName;
    CSV(string fileName);
    void create(string content);
    void fetch(vector<vector<string>> &matrix);
    void update(int lineNum, string content);
    int generateId();
//    void pop(int lineNum);
};