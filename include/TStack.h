#pragma once

template <class T>
class TStack{
protected:
	T* v;
	int size;
	int top;
public:
	TStack(int _size = 0);
	TStack(const TStack<T> &_s);
	~TStack();
	void Put(const T& val);
	T Get();
	int getSize();
	bool isFull();
	bool isEmpty();
	T getTop();
	int numOfElem();
};