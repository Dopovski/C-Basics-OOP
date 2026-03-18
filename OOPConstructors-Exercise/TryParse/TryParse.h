#pragma once
#include <string>
#include <sstream>

bool tryParse(const std::string& s, int& result) {
    std::istringstream iss(s);
    iss >> result;
    return !iss.fail() && iss.eof();
}
