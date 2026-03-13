#ifndef CODEORGANIZATIONANDTEMPLATES_LAB_SPLIT_H
#define CODEORGANIZATIONANDTEMPLATES_LAB_SPLIT_H
#include <vector>
#include <sstream>

template<typename T>
std::vector<T> split(const std::string & line, char separator) {
    std::vector<T> res;
    std::istringstream iss(line);
    std::string buffer;
    while (getline(iss, buffer, separator)) {
        std::istringstream elementStream(buffer);
        T temp;
        elementStream >> temp;
        res.push_back(temp);
    }

    return res;
}

#endif
