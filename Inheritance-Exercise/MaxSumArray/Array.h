#pragma once
#include <cstdlib>

template <typename T>
class ArrayBase {
protected:
    size_t size;
    T* data;

    ArrayBase(size_t size) : size(size), data(size > 0 ? new T[size]() : nullptr) {}

    void copyFrom(const ArrayBase& other) {
        size = other.size;
        data = size > 0 ? new T[size] : nullptr;
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~ArrayBase() {
        delete[] data;
    }
};

template <typename T>
class Array : public ArrayBase<T> {
public:
    explicit Array(size_t size) : ArrayBase<T>(size) {}

    Array(const Array& other) : ArrayBase<T>(0) {
        this->copyFrom(other);
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] this->data;
            this->copyFrom(other);
        }
        return *this;
    }

    ~Array() {}

    T& operator[](size_t index) { return this->data[index]; }
    const T& operator[](size_t index) const { return this->data[index]; }

    size_t getSize() const { return this->size; }

    T* begin() { return this->data; }
    T* end()   { return this->data + this->size; }
    const T* begin() const { return this->data; }
    const T* end()   const { return this->data + this->size; }
};
