#pragma once

#include <climits>
#include "Aggregator.h"

class MinAggregator : public StreamAggregator {
protected:
    void aggregate(int next) override {
        StreamAggregator::aggregate(next);
        if (next < this->aggregationResult) {
            this->aggregationResult = next;
        }
    }
public:
    MinAggregator(std::istream& stream) : StreamAggregator(stream) {
        this->aggregationResult = INT_MAX;
    }
};
