#ifndef CODEORGANIZATIONANDTEMPLATES_LAB_JOIN_H
#define CODEORGANIZATIONANDTEMPLATES_LAB_JOIN_H
#include <vector>
#include <sstream>

template<typename T>

std::string join(const std::vector<T> & v, const std::string &joinStr) {
    std::ostringstream oss;
    bool First =true;
    for (const T & element : v) {
        if (First) {
            First =false;
        }
        else{
            oss << joinStr;

        }
        oss << element;

    }


    return oss.str();
}
#endif //CODEORGANIZATIONANDTEMPLATES_LAB_JOIN_H
