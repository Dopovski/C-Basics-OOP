#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> &operator <<(vector<string> & res, const string &str) {
    res.push_back(str);

    return res;
}
string operator+(const string & left, int num) {
    ostringstream oss;
    oss << left << num;
    return oss.str();
}
ostream & operator <<(ostream & os,const vector<string> & data) {
    for (auto s: data) {
        os << s << endl;
    }
    return os;
}

#endif // !OPERATORS_H
