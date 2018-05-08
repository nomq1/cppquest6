

#include <iostream>
#include <string>
using namespace std;


class IllegalCoordinateException : public exception {
	int a, b;
	IllegalCoordinateException(int x, int y) {
		a = x;
		b = y;
	}
public : 
	virtual const char* theCoordinate() const throw()
	{
		return (a + "," + b);
	}

};

