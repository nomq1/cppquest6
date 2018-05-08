#pragma once
#include <iostream>
#include<string>
#include <utility>     
#include "Array.h"
using namespace std;


class Board {




public:
	Array* mat;
	int length;



	Board::Board() {
		mat = new Array(5);
		this->length = 5;
	}
	Board::Board(int num) {
		this->length = num;
		mat = new Array(num);
	}

	Array& operator [](const int& i)
	{
		return mat[i];
	}

	friend ostream &operator<<(ostream &output, const Board &temp) {
		string p = "";
		for (int i = 0; i < temp.length; i++) {
			for (int k = 0; k < temp.length; k++) {
				p += temp.mat[i][k];
			}
			p += "\n";
		}
		output << p;
		return output;
	}

};