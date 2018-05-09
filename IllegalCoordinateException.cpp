

#include <iostream>
#include <string>
using namespace std;


class IllegalCoordinateException : public exception {

public:
	int a, b;

	IllegalCoordinateException(int x, int y) {
		a = x;
		b = y;
	} 

	virtual const string theCoordinate() const throw()
	{
		string p = a + "," + b;
		return p;
	}

};

