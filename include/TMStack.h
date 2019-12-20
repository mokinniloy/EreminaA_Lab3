#pragma once
#include <TStack.h>

template<class T>
class TMStack {
protected:
	TStack* st;
	T* data;
	T** Starts;
	int N;
	int size;
	void Resize(int s);
public:
	TMStack(int _n, int _s);
	TMStack(TMStack<T> &t);
	bool isFull(int s);
	bool isEmpty(int s);
	void Add(T d, int s);
	T Get(int s);
};