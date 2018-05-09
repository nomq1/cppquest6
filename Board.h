#pragma once
#include <iostream>
#include<string>
#include <utility>     
#include "IllegalCoordinateException.cpp"
#include "Cell.h"
using namespace std;


class Board {




public:
	char* mat;
	int length;

	Board() {
		mat = new char[5];
		length = 5;
		for (int i = 0; i < length*length; i++) { mat[i] = '.'; }
	}
	Board(int num) {
		length = num;
		mat = new char[num*num];
		for (int i = 0; i < length*length; i++) { mat[i] = '.'; }
	}

	char& operator [](initializer_list<int> p)
	{
		int x = *p.begin();
		int y = *(p.begin() + 1);
		int a = returnsyntax(x, y);
		if (a > (length-1)*(length-1)) { throw IllegalCoordinateException(x, y); }
		else {
			return mat[a];
		}
	}
	int returnsyntax(const int x, const int y) {	
		return this->length*x + y;
		
	}

	Board& operator = (char c) {
		if (c == 'O' || c == 'X') {

			return *this;
		}
		else if (c == '.') { 
			for (int i = 0; i < length*length; i++) {
				mat[i] = '.'; 
			} 
		}
		else { throw IllegalCharException(c); }
	}
	
	friend ostream &operator<<(ostream &output, const Board &temp) {
		string p = "";
		int counter = 0;
		for (int i = 0; i < temp.length*temp.length; i++) {
			p += temp.mat[i];
			counter++;
			if(counter == temp.length) {
				p += "\n";
				counter = 0;
			}
		}
		output << p;
		return output;
	}
};