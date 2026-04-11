#pragma once

#include <sstream>
#include <string>
#include <vector>

template<typename T>
class TypedStream {
protected:
    std::istringstream stream;
public:
    TypedStream(const std::string& input) : stream(input) {}

    virtual TypedStream<T>& operator>>(T& item) = 0;

    operator bool() const {
        return !stream.fail();
    }

    std::vector<T> readToEnd() {
        std::vector<T> result;
        T item;
        while (*this >> item) {
            result.push_back(item);
        }
        return result;
    }

    virtual ~TypedStream() {}
};
