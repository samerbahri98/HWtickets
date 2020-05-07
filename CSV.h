#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
class CSV
{
public:
    string fileName;
    CSV(string fileName);
    void create(string content);
    void fetch(vector<vector<string>> &matrix);
    void update(int lineNum, string content);
//    void pop(int lineNum);
};