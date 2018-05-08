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
	}
	Board::Board(int num) {
		this->length = num;
		mat = new char(num);
	}

	char& operator [](initializer_list<int> p)
	{
		
		int a = returnsyntax(*p.begin(), *p.end());
		return mat[a];
	}
	int returnsyntax(const int x, const int y) {
		return length*x + y;
	}
	friend ostream &operator<<(ostream &output, const Board &temp) {
		string p = "";
		int counter = 0;
		for (int i = 0; i < temp.length*temp.length; i++) {
			p += temp.mat[i];
			counter++;
			if(counter == temp.length-1) {
				p += "\n";
				counter = 0;
			}
		}
		output << p;
		return output;
	}
};