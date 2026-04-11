#pragma once

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {
private:
    int sum;
protected:
    void aggregate(int next) override {
        StreamAggregator::aggregate(next);
        this->sum += next;
        this->aggregationResult = this->sum / this->getNumAggregated();
    }
public:
    AverageAggregator(std::istream& stream) : StreamAggregator(stream), sum(0) {
        this->aggregationResult = 0;
    }
};
