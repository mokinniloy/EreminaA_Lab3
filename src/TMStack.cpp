#include <TMStack.h>

template<class T>
TMStack<T>::TMStack(int _n, int _s) {
	if (_s <= 0 || _n <= 0) {
		throw "Error";
	}
	int* arrSize = new int[_n];
	data = new T[_s];
	size = -s;
	N = _n;
	arrSize[0] = _s / _n + _s % _n;
	for (int i = 1; i < _n; i++) {
		arrSize[i] = _s / _n;
	}
	st = new TStack[_n];
	Starts = new T*[_n];
	Starts[0] = data;
	st[0].Set
}

template<class T>
TMStack<T>::TMStack(TMStack<T>& t)
{
}
