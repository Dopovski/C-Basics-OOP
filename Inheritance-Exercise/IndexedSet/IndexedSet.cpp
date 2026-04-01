#include "IndexedSet.h"

IndexedSet::IndexedSet() : valuesArray(nullptr) {}

IndexedSet::IndexedSet(const IndexedSet& other) : valuesSet(other.valuesSet), valuesArray(nullptr) {}

IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
    if (this != &other) {
        clearIndex();
        valuesSet = other.valuesSet;
    }
    return *this;
}

IndexedSet::~IndexedSet() {
    clearIndex();
}

void IndexedSet::add(const Value& v) {
    clearIndex();
    valuesSet.insert(v);
}

size_t IndexedSet::size() const {
    return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
    if (!valuesArray) {
        buildIndex();
    }
    return valuesArray[index];
}

void IndexedSet::buildIndex() {
    valuesArray = new Value[valuesSet.size()];
    size_t i = 0;
    for (const Value& v : valuesSet) {
        valuesArray[i++] = v;
    }
}

void IndexedSet::clearIndex() {
    delete[] valuesArray;
    valuesArray = nullptr;
}
