#pragma once

#include <string>
#include <vector>

std::string minBy(const std::vector<std::string>& values, bool (*compare)(const std::string& a, const std::string& b)) {
    std::string result = values[0];
    for (auto it = (values.begin() + 1); it != values.end(); it++) {
        if (compare(*it, result)) {
            result = *it;
        }
    }
    return result;
}
