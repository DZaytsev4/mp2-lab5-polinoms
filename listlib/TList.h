#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst; // первое звено
	TNode<T>* pCurrent; // текущее звено
	TNode<T>* pPrevious; // звено перед текущим
	TNode<T>* pLast; // последнее звено
	TNode<T>* pStop; // значение указателя, означающего конец списка
	int length; // количество звеньев в списке

public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty(); // список пуст ?
	// вставка звеньев
	void InsertFirst(T item); // перед первым
	void InsertCurrent(T item); // перед текущим 
	void InsertLast(T item);  // вставить последним 
	void InsertNextCurrent(T item);

	// удаление звеньев
	void DeleteFirst(); // удалить первое звено 
	void DeleteCurrent(); // удалить текущее звено

	void GoNext(); // сдвиг вправо текущего звена
	// (=1 после применения GoNext для последнего звена списка)

	void Reset(); // установить на начало списка
	bool IsEnd();  // список завершен ?

	T GetCurrentItem();
	void SetCurrentItem(T item) { pCurrent->value = item; }


};
template <class T>
TList<T>::TList()
{
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pLast = nullptr;
	pStop = new TNode<T>;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
	while (length > 0) {
		DeleteFirst();
	}

	if (pStop != nullptr) {
		delete pStop;
		pStop = nullptr;
	}

	pFirst = nullptr;
	pPrevious = nullptr;
	pCurrent = nullptr;
	pLast = nullptr;

}

template <class T>
bool TList<T>::IsEmpty()
{
	return length == 0;
}

template <class T>
void TList<T>::InsertFirst(T item)
{
	TNode<T>* newNode = new TNode<T>;
	newNode->value = item;
	newNode->pNext = pFirst;
	pFirst = newNode;
	if (length == 0) {
		pLast = pFirst;
		pStop->pNext = pFirst;
	}
	length++;
}

template <class T>
void TList<T>::InsertLast(T item)
{
	if (length == 0) {
		InsertFirst(item);
	}
	else {
		TNode<T>* newNode = new TNode<T>;
		newNode->value = item;
		pLast->pNext = newNode;
		pLast = newNode;
		pStop->pNext = pLast;
		length++;
	}
}

template <class T>
void TList<T>::InsertCurrent(T item)
{
	if (pCurrent == pFirst) {
		InsertFirst(item);
	}
	else {
		TNode<T>* newNode = new TNode<T>;
		newNode->value = item;
		newNode->pNext = pCurrent;
		pPrevious->pNext = newNode;
		length++;
	}
}
template <class T>
void TList<T>::InsertNextCurrent(T item)
{
	TNode<T>* newNode = new TNode<T>;
	newNode->value = item;
	if (pCurrent == pLast) {
		newNode->pNext = nullptr;
		pLast->pNext = newNode;
		pLast = newNode;
	}
	else {
		newNode->pNext = pCurrent->pNext;
		pCurrent->pNext = newNode;
	}
	length++;
}
template <class T>
void TList<T>::DeleteFirst()
{
	if (!IsEmpty()) {
		TNode<T>* temp = pFirst;
		pFirst = pFirst->pNext;
		delete temp;
		length--;
		if (IsEmpty()) {
			pLast = nullptr;
			pStop->pNext = nullptr;
		}
	}
}

template <class T>
void TList<T>::DeleteCurrent()
{
	if (pCurrent != nullptr && pPrevious != nullptr) {
		pPrevious->pNext = pCurrent->pNext;
		delete pCurrent;
		pCurrent = pPrevious->pNext;
		length--;
		if (pCurrent == nullptr) {
			pLast = pPrevious;
			pStop->pNext = pLast;
		}
	}
}

template <class T>
T TList<T>::GetCurrentItem()
{
	if (pCurrent == pStop)
		throw " ";
	return pCurrent->value;
}

template <class T>
void TList<T>::Reset()
{
	pCurrent = pFirst;
	pPrevious = nullptr;
}

template <class T>
void TList<T>::GoNext()
{
	if (pCurrent != nullptr) {
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurrent == nullptr || pCurrent == pStop;
}





