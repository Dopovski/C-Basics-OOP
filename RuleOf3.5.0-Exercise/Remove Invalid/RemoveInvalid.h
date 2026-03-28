#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include <list>
#include "Company.h"

void removeInvalid(std::list<Company*>& companies) {
    for (std::list<Company*>::iterator it = companies.begin(); it != companies.end();) {
        Company* curr = *it;
        if (curr->getId() < 0) {
            delete curr;
            it = companies.erase(it);
        } else {
            ++it;
        }
    }
}

#endif // !REMOVE_INVALID_H
