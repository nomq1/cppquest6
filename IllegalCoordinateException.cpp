

#include <iostream>
#include <string>
using namespace std;


class IllegalCoordinateException : public exception {

public:
	int a, b;
	string p;

	IllegalCoordinateException(int x, int y) {
		a = x;
		b = y;

	} 

	const char* theCoordinate() const throw()
	{
		cout << a + "," + b << p;
		return p.c_str();
	}

};

