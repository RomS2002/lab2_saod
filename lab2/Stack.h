#pragma once
#define STACK_MAX_LEN 256

#include <iostream>

template <class T>
class Stack
{

public:
	Stack();
	~Stack();
	void push(T);
	T pop();
	void print();
private:
	T* top;
	int size;
};

template <class T>
Stack<T>::Stack(): size(0)
{
	top = new T[STACK_MAX_LEN];
}

template <class T>
Stack<T>::~Stack()
{
	top = top - size;
	delete[] top;
}

template <class T>
T Stack<T>::pop()
{
	if (size == 0) {
		std::cout << "Стек пуст!\n";
		return NULL;
	}

	size--;
	return *(--top);
}

template <class T>
void Stack<T>::push(T a)
{
	if (size == STACK_MAX_LEN - 1) {
		std::cout << "Стек полон!\n";
		return;
	}

	size++;
	*top = a;
	top++;
}

template <class T>
void Stack<T>::print()
{
	if (size == 0) {
		std::cout << "Стек пуст";
	}
	for (int i = 0; i < size; i++) {
		std::cout << *(top - size + i) << ", ";
	}
	std::cout << std::endl;
}