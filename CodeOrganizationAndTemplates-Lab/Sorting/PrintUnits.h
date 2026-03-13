#pragma once

#include <vector>
#include <iostream>

template<typename T>
void printVector(const std::vector<T> & v) {
    for(const T & element : v)
        std::cout << element << ' ';
    std::cout << std::endl;
}

template<typename T>
void printContainer(typename T::iterator begin, typename T::iterator end) {
    for(;begin != end; begin++)
        std::cout << *begin << ' ';
    std::cout << std::endl;
}
