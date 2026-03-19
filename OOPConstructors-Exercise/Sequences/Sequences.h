#pragma once
#include <vector>
#include <climits>

template <typename T, typename Generator>
class Sequence {
private:
    typedef std::vector<T> Data;
    std::vector<T> data;
    Generator gen;

public:

    class Iterator {
    private:
        int i;
        Data & data;
    public:
        Iterator(Data & data, int i) : data(data), i(i) {}

        T & operator*() { return data[i]; }

        Iterator & operator++() {
            i++;
            return *this;
        }

        bool operator==(const Iterator & other) const {
            if (&(this->data) != &(other.data)) {
                return false;
            }
            if (isAtEnd() && other.isAtEnd()) {
                return true;
            }
            return this->i == other.i;
        }

        bool operator!=(const Iterator & other) const {
            if (&(this->data) != &(other.data)) {
                return true;
            }
            if (isAtEnd() && other.isAtEnd()) {
                return false;
            }
            return this->i != other.i;
        }
    protected:
        bool isAtEnd() const {
            return i >= (int)this->data.size();
        }
    };

    Iterator begin() { return Iterator(this->data, 0); }
    Iterator end()   { return Iterator(this->data, INT_MAX); }

    void generateNext(size_t numToGen) {
        while (numToGen--) {
            data.push_back(gen());
        }
    }
};
