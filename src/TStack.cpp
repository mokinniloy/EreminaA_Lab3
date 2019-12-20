#include "TStack.h"

template<class T>
inline TStack<T>::TStack(int _size) {
	if (_size < 0) {
		throw "Wrong size";
	}
	size = _size;
	top = 0;
	if (size == 0) {
		v = nullptr;
	}
	else {
		v = new T[size];
	}
}

template<class T>
TStack<T>::TStack(const TStack<T>& s) : size(s.size), top(s.top) {
	size = s.size();
	if (size == 0) {
		v = nullptr;
	}
	else {
		v = new T[size];
		for (int i = 0; i < size; i++) {
			v[i] = s.v[i];
		}
	}
}

template<class T>
TStack<T>::~TStack() {
	if (v != nullptr) {
		delete[] v;
	}
}

template<class T>
void TStack<T>::Put(const T& val) {
	if (isFull()) {
		throw "Not enough space!";
	}
	v[top] = val;
	top++;
}

template<class T>
bool TStack<T>::isFull() {
	return top >= size;
}

template<class T>
bool TStack<T>::isEmpty() {
	return (top == 0);
}

template<class T>
int TStack<T>::getSize() {
	return size;
}

template<class T>
T TStack<T>::getTop() {
	return v[top - 1];
}

template<class T>
T TStack<T>::Get() {
	if (isEmpty()) {
		throw "Is empty";
	}
	return v[--top];
}

template<class T> 
int TStack<T>::numOfElem() {
	return top;
}