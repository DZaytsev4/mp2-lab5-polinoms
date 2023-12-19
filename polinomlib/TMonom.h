#pragma once
#include <string>
struct TMonom
{
	double coef; // коэффициент монома
	int index; // индекс (свертка степеней)


	TMonom() {
		coef = 0;
		index = 0;
	}

	TMonom(double _coef, int degX, int degY, int degZ) {
		coef = _coef;
		index = degX * 100 + degY * 10 + degZ;
	}
	
	void SetCoef(int cval) { coef = cval; }
	int GetCoef(void) { return coef; }

	void SetIndex(int ival) { index = ival; }
	int GetIndex(void) { return index; }


	bool operator==(const TMonom& other) { 
		return index == other.index && coef == other.coef;
	}
	
	bool operator>(const TMonom& other) {
		return index >= other.index || coef > other.coef;
	}

	bool operator<(const TMonom& other) {
		return index <= other.index || coef < other.coef;
	}
	string ToString() {
		string result;
		int x = index / 100;
		int y = index / 10 % 10;
		int z = index % 10;
		if (coef != 1) result += to_string(coef)+"*";
		if (x != 0) {
			result += "X";
			if (x != 1) result += "^" + to_string(x) + "*";
			else result += "*";
		}
		if (y != 0) {
			result += "Y";
			if (y != 1) result += "^" + to_string(y)+"*";
			else result += "*";
		}
		if (z != 0) {
			result += "Z";
			if (z != 1) result += "^" + to_string(z);
			else result += "*";
		}
		return result;
	}
};