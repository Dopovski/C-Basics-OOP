#ifndef CODEORGANIZATIONANDTEMPLATES_LAB_PARSER_H
#define CODEORGANIZATIONANDTEMPLATES_LAB_PARSER_H
#include <istream>
#include <sstream>


template<typename T>
class Parser {

private:
    std::string stopLine;
    std::istream & stream;


public:
    Parser(std::istream & stream, const string & stopLine) : stream(stream), stopLine(stopLine){}
    bool readNext(T & data) {
        std::string line;
        std::getline(stream, line);
        if (line ==stopLine) {
            return false;
        }
        std::istringstream istr(line);
        istr >> data;
        return true;
    }

};

#endif
