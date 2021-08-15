// hexNdouble.cpp : Defines the entry point for the application.
//

#include "hexNdouble.h"

#include <iostream>
#include <string>

using namespace std;

double hexstr2double(const std::string& hexstr)
{
    double d = 0.0;

    try {
        *reinterpret_cast<unsigned long long*>(&d) = std::stoull(hexstr, nullptr, 16);
    }
    catch (...) {}

    return d;
}


std::string double2hexstr(double x) {

    union
    {
        long long i;
        double    d;
    } value;

    value.d = x;

    char buf[17];

    snprintf(buf, sizeof(buf), "%016llx", value.i);
    buf[16] = 0; //make sure it is null terminated.

    return std::string(buf);

}

int main()
{
	cout << "Hello CMake." << endl;

    std::string hex_s = "402F800000000000";

    auto res = hexstr2double(hex_s);

    cout << res << endl;
    cout << double2hexstr(res) << endl;

	return 0;
}
