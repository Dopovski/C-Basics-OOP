#pragma once

#include "Company.h"
#include <vector>

class ArrayOfPointers {
private:
    std::vector<Company*> data;
public:
    ArrayOfPointers() {}

    ~ArrayOfPointers() {
        for (Company* c : data) {
            delete c;
        }
    }

    void add(Company* c) {
        data.push_back(c);
    }

    size_t getSize() const {
        return data.size();
    }

    Company* get(size_t i) const {
        return data[i];
    }

    ArrayOfPointers(const ArrayOfPointers&) = delete;
    ArrayOfPointers& operator=(const ArrayOfPointers&) = delete;
};
