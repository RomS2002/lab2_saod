#pragma once

#include <iostream>

template<class T>
struct CycleListElem {
	T value;
	CycleListElem* next;
};

template<class T>
class CycleList {
public:
	CycleList();
	~CycleList();
	int getSize();
	void insert(T elem, int ind);
	void insert(T elem);
	T getValue(int ind);
	void deleteElement(int ind);
	void printState();
private:
	CycleListElem<T>* first;
	CycleListElem<T>* getElemByNum(int ind);
	int size;
};

template<class T>
CycleList<T>::CycleList(): size(0) {
	first = nullptr;
}

template<class T>
CycleList<T>::~CycleList() {
	if (size == 0) {
		return;
	}
	CycleListElem<T>* p = first;
	for (int i = 0; i < size; i++) {
		CycleListElem<T>* nxt = p->next;
		delete p;
		p = nxt;
	}
}

template<class T>
void CycleList<T>::insert(T elem) {
	CycleListElem<T>* p = new CycleListElem<T>;
	p->value = elem;
	if (size != 0) {
		p->next = first;
		CycleListElem<T>* last = getElemByNum(size-1);
		last->next = p;
	}
	else {
		first = p;
		first->next = first;
	}
	size++;
}

template<class T>
void CycleList<T>::insert(T elem, int ind) {
	if (ind > size || ind < 0) {
		std::cout << "Недопустимый индекс!\n";
		return;
	}
	if (ind == size) {
		insert(elem);
		return;
	}

	CycleListElem<T>* p = new CycleListElem<T>;
	p->value = elem;

	if (size == 0) {
		first = p;
		first->next = first;
		size++;
		return;
	}
	else if (ind == 0) {
		CycleListElem<T>* prev = getElemByNum(size - 1);
		p->next = first;
		prev->next = p;
		p = first;
	}
	else {
		CycleListElem<T>* prev = getElemByNum(ind - 1);
		p->next = prev->next;
		prev->next = p;
		size++;
	}
}

template<class T>
void CycleList<T>::deleteElement(int ind) {
	if (ind > size - 1 || ind < 0) {
		std::cout << "Недопустимый индекс!\n";
		return;
	}
	if (size != 1) {
		if (ind == 0) {
			CycleListElem<T>* prev = getElemByNum(size - 1);
			prev->next = first->next;
			delete first;
			first = prev->next;
		}
		else {
			CycleListElem<T>* prev = getElemByNum(ind - 1);
			CycleListElem<T>* toDel = prev->next;
			prev->next = toDel->next;
			delete toDel;
		}
		
		size--;
	}
	else {
		delete first;
		size = 0;
	}

}

template<class T>
CycleListElem<T>* CycleList<T>::getElemByNum(int ind) {
	CycleListElem<T>* p = first;
	for (int i = 0; i < ind; i++) {
		p = p->next;
	}
	return p;
}

template<class T>
int CycleList<T>::getSize() {
	return size;
}

template<class T>
T CycleList<T>::getValue(int ind) {
	if (ind > size || ind < 0) {
		std::cout << "Недопустимый индекс!\n";
		return 0;
	}

	CycleListElem<T>* elem = getElemByNum(ind);
	return elem->value;
}

template<class T>
void CycleList<T>::printState() {
	if (size == 0) {
		std::cout << "Список пуст!\n";
		return;
	}

	CycleListElem<T>* p = first;
	for (int i = 0; i < size; i++) {
		std::cout << p->value << "[" << i << "], ";
		p = p->next;
	}
}