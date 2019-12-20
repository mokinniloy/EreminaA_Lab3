#pragma once
#include <iostream>
using namespace std;

class TFormula {
private:
	char* Formula;
	char* PostfixForm;
public:
	TFormula(const char* form);
	~TFormula();
	int FormulaChecker(int Brackets[], int size);
	void FormulaConverter();
	double FormulaCalculator();

	friend ostream& operator<<(ostream& ostr, const TFormula& tf) {
		ostr << tf.PostfixForm;
		return ostr;
	}
};
