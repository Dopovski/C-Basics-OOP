#pragma once

#include "Company.h"
#include <vector>
#include <algorithm>

class OrderedInserter {
    std::vector<const Company*>& companies;
public:
    OrderedInserter(std::vector<const Company*>& companies) : companies(companies) {}

    void insert(const Company* company) {
        auto it = std::lower_bound(companies.begin(), companies.end(), company,
            [](const Company* a, const Company* b) {
                return a->getId() < b->getId();
            });
        companies.insert(it, company);
    }
};
