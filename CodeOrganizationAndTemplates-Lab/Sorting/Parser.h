#ifndef CODEORGANIZATIONANDTEMPLATES_LAB_PARSER_H
#define CODEORGANIZATIONANDTEMPLATES_LAB_PARSER_H
#include <sstream>
#include <string>
#include <iostream>

template<typename T>
class Parser {
private:
    std::istream& stream;
    std::string stopLine;
public:
    Parser(std::istream& stream, const std::string& stopLine)
        : stream(stream), stopLine(stopLine) {}

    bool readNext(T& data) const {
        std::string line;
        if (!std::getline(stream, line)) return false;
        if (line == stopLine) return false;
        std::istringstream istr(line);
        istr >> data;
        return true;
    }
};

template<>
class Parser<std::string> {
private:
    std::istream& stream;
    std::string stopLine;
public:
    Parser(std::istream& stream, const std::string& stopLine)
        : stream(stream), stopLine(stopLine) {}

    bool readNext(std::string& data) const {
        std::string line;
        if (!std::getline(stream, line)) return false;
        if (line == stopLine) return false;
        data = line;
        return true;
    }
};

#endif
