#pragma once

#include <sstream>
#include <vector>
#include <set>
#include "Company.h"

Company* parseUniqueCompanies(const std::string& input, int& numCompanies, std::string (*uniqueIdGenerator)(const Company& c)) {
    numCompanies = 0;
    std::vector<Company> companies;
    std::set<std::string> companiesSet;

    std::istringstream iss(input);
    std::string cur;
    while (std::getline(iss, cur)) {
        int id;
        std::string name;
        std::istringstream curLine(cur);
        curLine >> id >> name;
        Company curCompany(id, name);
        std::string uniqueID = uniqueIdGenerator(curCompany);
        if (companiesSet.insert(uniqueID).second) {
            companies.push_back(curCompany);
            numCompanies++;
        }
    }

    Company* retArray = new Company[companies.size()];
    for (size_t i = 0; i < companies.size(); i++) {
        retArray[i] = companies[i];
    }
    return retArray;
}
