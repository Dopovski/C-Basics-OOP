#ifndef CAR_H
#define CAR_H

#include <sstream>

using namespace std;

class Car {
private:
    string sBrand;
    string sModel;
    int nYear;

public:
    Car(const string & sBrand, const string &sModel, int nYear) : sBrand(sBrand), sModel(sModel), nYear(nYear) {}


        const string & GetBrand()const{return sBrand;}

        const string & GetModel()const{return sModel;}

         const int & GetYear()const{return nYear;}
};

#endif // !CAR_H
