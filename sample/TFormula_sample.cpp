#include <string>
#include <iostream>
#include <TFormula.h>

using namespace std;

int main() {
	cout << "Enter expression: ";
	string s;
	cin >> s;
	TFormula f(s.c_str());
	double p = f.FormulaCalculator();
	cout << "Postfix expression: \n" << f << '\n';
	cout << "Result: " << p;
	return 0;
}