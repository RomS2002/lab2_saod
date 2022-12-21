#pragma once
#define QUEUE_MAX_LEN 5

#include <iostream>

template <class T>
class Queue {
public:
	Queue();
	~Queue();
	bool isEmpty();
	void push(T elem);
	T pop();
	int size();
	void printState();
private:
	T* elements;
	int top;
	int bottom;
};

template <class T>
Queue<T>::Queue(): top(0), bottom(0) {
	elements = new T[QUEUE_MAX_LEN];
}

template <class T>
Queue<T>::~Queue() {
	delete[] elements;
}

template <class T>
bool Queue<T>::isEmpty() {
	return top == bottom;
}

template <class T>
void Queue<T>::push(T elem) {
	if (size() < QUEUE_MAX_LEN) {
		elements[bottom] = elem;
		bottom = (bottom + 1) % (QUEUE_MAX_LEN + 1);
	}
	else {
		std::cout << "Очередь полная!\n";
	}
}

template <class T>
T Queue<T>::pop() {
	if (isEmpty()) {
		std::cout << "Очередь пустая!\n";
		return NULL;
	}
	T elem = elements[top];
	top = (top + 1) % (QUEUE_MAX_LEN + 1);
	return elem;
}

template <class T>
int Queue<T>::size() {
	if (top > bottom) {
		return QUEUE_MAX_LEN - top + bottom;
	}
	else {
		return bottom - top;
	}
}

template <class T>
void Queue<T>::printState()
{
	if (isEmpty()) {
		std::cout << "Очередь пуста";
		return;
	}

	if (top < bottom) {
		for (int i = top; i < bottom; i++) {
			std::cout << elements[i] << ", ";
		}
	}
	if (top > bottom) {
		for (int i = top; i < QUEUE_MAX_LEN; i++) {
			std::cout << elements[i] << ", ";
		}
		for (int i = 0; i < bottom; i++) {
			std::cout << elements[i] << ", ";
		}
	}
}