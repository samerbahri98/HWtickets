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
    void read();
    void fetch(vector<vector<string>> &matrix);
    void update(string content);
    void update(int line, string content);
    void remove(string content);
    void remove(int line);
};