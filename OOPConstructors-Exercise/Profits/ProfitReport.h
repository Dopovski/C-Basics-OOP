#pragma once

#include "Company.h"
#include "ProfitCalculator.h"

#include <map>
#include <string>
#include <sstream>

std::string getProfitReport(Company* fromInclusive, Company* toInclusive, const std::map<int, ProfitCalculator>& calculators) {
    std::ostringstream out;
    for (Company* c = fromInclusive; c <= toInclusive; ++c) {
        int profit = calculators.at(c->getId()).calculateProfit(*c);
        out << c->getName() << " = " << profit << "\n";
    }
    std::string result = out.str();
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }
    return result;
}
