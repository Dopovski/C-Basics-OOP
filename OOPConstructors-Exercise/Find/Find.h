#pragma once

#include "Company.h"
#include <vector>

Company* find(const std::vector<Company*>& companies, int searchId) {
    for (Company* c : companies) {
        if (c->getId() == searchId) {
            return c;
        }
    }
    return nullptr;
}
