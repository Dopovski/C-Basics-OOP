#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <sstream>
using namespace std;

vector<string>  operator+(const vector<string> & v1, const vector<string> & v2) {
    vector<string> res;


    size_t len = v1.size() > v2.size() ? v1.size() : v2.size();
    res.reserve(len);
    for (size_t i = 0; i < len; i++) {
        res.push_back(v1[i] + " " + v2[i]);
    }
    return res;
};

#endif // !SUMOFVECTORS_H
