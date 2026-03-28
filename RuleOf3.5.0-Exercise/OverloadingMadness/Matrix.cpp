#include "Matrix.h"

Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data) {
    _data = data;
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    size_t rows = std::min(_data.size(), other._data.size());
    for (size_t r = 0; r < rows; r++) {
        size_t cols = std::min(_data[r].size(), other._data[r].size());
        for (size_t c = 0; c < cols; c++) {
            _data[r][c] += other._data[r][c];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    size_t rows = std::min(_data.size(), other._data.size());
    for (size_t r = 0; r < rows; r++) {
        size_t cols = std::min(_data[r].size(), other._data[r].size());
        for (size_t c = 0; c < cols; c++) {
            _data[r][c] -= other._data[r][c];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    size_t rows = std::min(_data.size(), other._data.size());
    for (size_t r = 0; r < rows; r++) {
        size_t cols = std::min(_data[r].size(), other._data[r].size());
        for (size_t c = 0; c < cols; c++) {
            _data[r][c] *= other._data[r][c];
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(const Matrix& other) {
    size_t rows = std::min(_data.size(), other._data.size());
    for (size_t r = 0; r < rows; r++) {
        size_t cols = std::min(_data[r].size(), other._data[r].size());
        for (size_t c = 0; c < cols; c++) {
            if (other._data[r][c] == 0) {
                _data[r][c] = 0;
            } else {
                _data[r][c] /= other._data[r][c];
            }
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (const auto& row : matrix._data) {
        for (const auto& val : row) {
            os << val << " ";
        }
        os << "\n";
    }
    return os;
}
