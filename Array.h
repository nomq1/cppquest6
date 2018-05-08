#pragma once
#include<iostream>

using namespace std;
class Array
{
private: char *p;
public:
	int length;
	Array::Array(int size = 0) : length(size)
	{
		p = new char(length);
		for (int i = 0; i < length*length; i++) { p[i] = '.'; }
	}
	char& operator [](const int k)
	{
		return p[k];
	}
};