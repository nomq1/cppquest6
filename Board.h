#pragma once
#include <iostream>
#include <string>
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
	Board(Board& temp) {
		length = temp.length;
		mat = new char[length*length];
		for (int i = 0; i < length*length; i++) { mat[i] = temp.mat[i]; }
	}
	~Board() {
		delete[] mat;
	}
	Cell operator [](initializer_list<int> p)
	{
		int x = *p.begin();
		int y = *(p.begin() + 1);
		int a = returnsyntax(x, y);
		if (x > length-1 || y > length-1) { 
			throw IllegalCoordinateException(x, y); 
		}
		
		return Cell(&mat[a]);
		
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
				this->mat[i] = '.'; 
			} 
			return *this;
		}
		else { throw IllegalCharException(c); }
	}

	Board& operator = (const Board& c) {
		if (length != c.length) {
			delete[] mat;
			mat = new char[c.length*c.length];
		}
		length = c.length;
		for (int i = 0; i < c.length*c.length; i++) {
			this->mat[i] = c.mat[i];
		}
		return *this;
		
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