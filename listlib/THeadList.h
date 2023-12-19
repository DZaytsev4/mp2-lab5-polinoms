#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead; // заголовок, pFirst - звено за pHead
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item); // вставка звеньев после заголовка
	void DeleteFirst(); // удалить первое звено
};

template<class T>
THeadList<T>::THeadList() : TList<T>()
{
	pHead = new TNode<T>;
	pHead->pNext = this->pFirst;
	this->pStop->pNext = pHead;
}

template<class T>
THeadList<T>::~THeadList()
{
	if (pHead != nullptr)
		delete pHead;
	pHead = nullptr;
}

template <class T>
void THeadList<T>::InsertFirst(T item)
{
	TList<T>::InsertFirst(item);

	pHead->pNext = this->pFirst;

}

template <class T>
void THeadList<T>::DeleteFirst()
{
	TList<T>::DeleteFirst();

	pHead->pNext = this->pFirst;
}