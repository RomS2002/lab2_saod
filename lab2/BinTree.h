#pragma once

#include <iostream>

template <class T>
struct BinTreeElem {
	T value;
	BinTreeElem<T>* left;
	BinTreeElem<T>* right;
};

template <class T>
class BinTree {
public:
	BinTree();
	~BinTree();
	void printState();
	void add(T elem);
	void delSubtree(BinTreeElem<T>* p);
private:
	BinTreeElem<T>* root;
	void printElem(BinTreeElem<T>* p, int depth);
	void addNode(T elem, BinTreeElem<T>* p);
};

template <class T>
BinTree<T>::BinTree() {
	root = nullptr;
}

template <class T>
BinTree<T>::~BinTree() {
	if()
}

template <class T>
void BinTree<T>::printElem(BinTreeElem<T>* p, int depth) {
	if (p == nullptr) {
		if (depth == 0) {
			std::cout << "Дерево пустое!\n";
		}
		return;
	}
	printElem(p->left,depth+1);
	std::cout << p->value << ", ";
	printElem(p->right, depth + 1);
}

template <class T>
void BinTree<T>::printState() {
	printElem(root, 0);
}

template <class T>
void BinTree<T>::add(T elem) {
	addNode(elem, T);
}

template <class T>
void BinTree<T>::addNode(T elem, BinTreeElem<T>* p) {
	if (p == nullptr) {
		p = new BinTreeElem<T>;
		p->value = elem;
		p->left = p->right = nullptr;
	}
	else if (elem < p->value) {
		addNode(elem, p->left);
	}
	else {
		addNode(elem, p->right);
	}
}

template <class T>
void BinTree<T>::delSubtree(BinTreeElem<T>* p) {
	if (p == nullptr) {
		return;
	}
	delSubtree(p->left);
	delSubtree(p->right);
	delete p;
}