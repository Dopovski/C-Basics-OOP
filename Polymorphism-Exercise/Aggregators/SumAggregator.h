#pragma once

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {
protected:
    void aggregate(int next) override {
        StreamAggregator::aggregate(next);
        this->aggregationResult += next;
    }
public:
    SumAggregator(std::istream& stream) : StreamAggregator(stream) {
        this->aggregationResult = 0;
    }
};
