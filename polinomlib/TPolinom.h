#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

const int nonDisplayedZeros = 4; 


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom(string str);
	TPolinom& operator=(TPolinom& other); // присваивание
	TPolinom& operator+(TPolinom& q); // сложение полиномов

	// дополнительно можно реализовать:
	void AddMonom(TMonom newMonom); // добавление монома
	TPolinom AddPolinom(TPolinom& other); // добавление полинома
	string ToString(); // перевод в строку
};

TPolinom::TPolinom() :THeadList<TMonom>::THeadList()
{
    length = 0;
}

TPolinom::TPolinom(TPolinom& other)
{
	other.Reset();
	for (int i = 0; i < other.length; i++) {
		AddMonom(other.pCurrent->value);
		other.GoNext();
	}
}

TPolinom::TPolinom(string str)
{	
    stringstream ss(str);
    char c;
    double coef;
    int degX, degY, degZ;

    while (ss >> coef) {
        ss >> c; 
        ss >> c; 
        ss >> c; 
        ss >> degX; 
        ss >> c; 
        ss >> c; 
        ss >> c; 
        ss >> degY; 
        ss >> c; 
        ss >> c; 
        ss >> c; 
        ss >> degZ; 

        TMonom monom(coef, degX, degY, degZ);
        AddMonom(monom);
    }
}

TPolinom& TPolinom::operator=(TPolinom& other)
{
    if (this == &other)
        return *this;

    if (pFirst != nullptr) {
        while (length > 0) {
            DeleteFirst();
        }
    }

    TNode<TMonom>* tmp = other.pFirst;
    for (int i = 0; i < other.length; i++) {
        AddMonom(tmp->value);
        tmp = tmp->pNext;
    }

    return *this;
}

void TPolinom::AddMonom(TMonom m)
{
    if (m.GetCoef() == 0)
        return;

    if (pFirst == nullptr)
        InsertFirst(m);
    else {
        int i = 0;
        Reset();
        while (i <= length && pCurrent->value.GetIndex() != m.GetIndex() && pCurrent->value > m)
        {
            i++;
            if (i == length) {
                InsertLast(m);
                return;
            }

            GoNext();
        }

        if (pCurrent->value.GetIndex() == m.GetIndex()) {
            double coef = pCurrent->value.GetCoef() + m.GetCoef();
            pCurrent->value.SetCoef(coef);
            if (coef == 0)
                DeleteCurrent();
        }
        else {
            if (pCurrent == pFirst) {
                InsertFirst(m);
            }
            else if (pPrevious != nullptr) {
                pCurrent = pPrevious;
                pPrevious = nullptr;
                InsertCurrent(m);
            }
        }
        Reset();
    }
}



TPolinom& TPolinom::operator+(TPolinom& other)
{
    TPolinom result(*this);
    return result;
}

TPolinom TPolinom::AddPolinom(TPolinom& other)
{
    TPolinom res(*this);
    return res;
}


string TPolinom::ToString()
{
    string result;
    int sz = GetLength();
    Reset();
    for (int i = 0; i < sz; i++) {
        TMonom a;
        a = GetCurrentItem();
        double A = a.GetCoef();
        std::ostringstream oss;
        oss << setprecision(5) << A;
        int ind = a.GetIndex();
        result += oss.str();
        result += "*";
        result += "x";
        result += "^";
        result += to_string((ind - ind % 100) / 100);
        result += "*";
        result += "y";
        result += "^";
        result += to_string(((ind % 100) - (ind % 10)) / 10);
        result += "*";
        result += "z";
        result += "^";
        result += to_string(ind % 10);
        if (i != sz - 1)
            result += " + ";
        if (i < sz - 1)
            GoNext();
    }
    Reset();
    return result;
}
