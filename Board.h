#pragma once
#include <iostream>
#include<string>
#include <utility>     

using namespace std;


class Board {




public:
	char* mat;
	int length;



	Board::Board() {
		mat = new char(5);
		this->length = 5;
		for (int i = 0; i < length*length; i++) { mat[i] = '.'; }
	}
	Board::Board(int num) {
		this->length = num;
		mat = new char(num*num);
		for (int i = 0; i < length*length; i++) { mat[i] = '.'; }
	}

	char& operator [](initializer_list<int> p)
	{
		int a = returnsyntax(*p.begin(), *p.begin() + 1);
		return mat[a];
	}
	int returnsyntax(const int x, const int y) {	
		return this->length*x + y;
		
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