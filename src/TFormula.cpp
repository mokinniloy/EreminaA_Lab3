#include <TFormula.h>
#include <TStack.h>

const int MaxLength = 255;

TFormula::TFormula(const char* form) {
	Formula = new char[MaxLength];
	PostfixForm = new char[MaxLength];
	for (int i = 0; i < MaxLength; i++) {
		Formula[i] = '\0';
		PostfixForm[i] = '\0';
	}
	int i = 0;
	while (form[i] != '\0') {
		if (i == MaxLength) {
			throw - 1;
		}
		Formula[i] = form[i];
		i++;
	}
}

TFormula::~TFormula() {
	delete[] PostfixForm;
	delete[] Formula;
}

int TFormula::FormulaChecker(int Brackets[], int size) {
	int err = 0, n = 1, p = 0;
	TStack<int> st(MaxLength);
	for (int i = 0; Formula[i] != '\0'; i++) {
		if (Formula[i] == '(' || Formula[i] == ')') {
			if (Formula[i] == '(') {
				st.Put(n);
				n++;
			}
			else {
				if (st.isEmpty()) {
					err++;
					Brackets[p++] = 0;
					Brackets[p++] = n;
					n++;
					continue;
				}
				Brackets[p++] = st.Get();
				Brackets[p++] = n;
				n++;
			}
		}
	}
	while (!st.isEmpty()) {
		err++;
		Brackets[p++] = st.Get();
		Brackets[p++] = 0;
	}
	return err;
}

void TFormula::FormulaConverter()
{
	int Br[MaxLength];
	if (this->FormulaChecker(Br, MaxLength)) throw - 1;
	TStack<int> st(MaxLength);
	int i = 0, j = 0;
	while (Formula[i] != '\0') {
		switch (Formula[i]) {
		case '1': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '2': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '3': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '4': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '5': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '6': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '7': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '8': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '9': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '0': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '.': {
			PostfixForm[j++] = Formula[i];
			break;
		}
		case '(': {
			st.Put('(');
			break;
		}
		case ')': {
			while (st.getTop() != '(') {
				PostfixForm[j++] = ' ';
				PostfixForm[j++] = st.Get();
			}
			st.Get();
			break;
		}
		case '+': {
			PostfixForm[j++] = ' ';
			if (st.isEmpty() || st.getTop() == '(') {
				st.Put('+');
			}
			else {
				while (!st.isEmpty() && st.getTop() != '(') {
					PostfixForm[j++] = st.Get();
				}
				st.Put('+');
			}
			break;
		}
		case '-': {
			PostfixForm[j++] = ' ';
			if (st.isEmpty() || st.getTop() == '(') {
				st.Put('-');
			}
			else {
				while (!st.isEmpty() && st.getTop() != '(') {
					PostfixForm[j++] = st.Get();
				}
				st.Put('-');
			}
			break;
		}
		case '*': {
			PostfixForm[j++] = ' ';
			if (st.isEmpty() || st.getTop() == '(' || st.getTop() == '+' || st.getTop() == '-') {
				st.Put('*');
			}
			else {
				while (!st.isEmpty() && st.getTop() != '(' && st.getTop() != '+' && st.getTop() != '-') {
					PostfixForm[j++] = st.Get();
				}
				st.Put('*');
			}
			break;
		}
		case '/': {
			PostfixForm[j++] = ' ';
			if (st.isEmpty() || st.getTop() == '(' || st.getTop() == '+' || st.getTop() == '-') {
				st.Put('/');
			}
			else {
				while (!st.isEmpty() && st.getTop() != '(' && st.getTop() != '+' && st.getTop() != '-') {
					PostfixForm[j++] = st.Get();
				}
				st.Put('/');
			}
			break;
		}
		case ' ': {
			break;
		}
		default: {
			throw - 1;
		}
		}
		i++;
	}
	while (!st.isEmpty()) {
		if (st.getTop() != '(') {
			PostfixForm[j++] = ' ';
			PostfixForm[j++] = st.Get();
		}
		else st.Get();
	}
}

double TFormula::FormulaCalculator() {
	if (this->PostfixForm[0] == '\0') {
		this->FormulaConverter();
	}
	TStack<double> st(MaxLength);
	int i = 0;
	double result = 0;
	while (PostfixForm[i] != '\0') {
		if (PostfixForm[i] == '-' || PostfixForm[i] == '+' || PostfixForm[i] == '*' || PostfixForm[i] == '/') {
			if (st.numOfElem() < 1) {
				throw "Wrong record";
			}
			double op2 = st.Get(), op1 = st.Get(), res;
			switch (PostfixForm[i]) {
			case '-': {
				res = op1 - op2;
				break;
			}
			case '+': {
				res = op1 + op2;
				break;
			}
			case '*': {
				res = op1 * op2;
				break;
			}
			case '/': {
				res = op1 / op2;
				break;
			}
			default: {
				break;
			}
			}
			st.Put(res);
		}
		else if (PostfixForm[i] == ' ') {
			i++;
			continue;
		}
		else {
			bool decimal = false;
			double number = 0;

			while (PostfixForm[i] != ' ') {
				if (PostfixForm[i] == '.') {
					if (decimal) {
						throw "Wrong form";
					}
					decimal = true;
					int p = 1;
					while (PostfixForm[i] != ' ') {
						number += (PostfixForm[i] - '0') * pow(10, (-1) * p);
						i++; p++;
					}
					break;
				}
				number = number * 10 + (PostfixForm[i] - '0');
				i++;
			}
			st.Put(number);
		}
		i++;
	}
	if (st.numOfElem() > 1) {
		throw - 1;
	}
	result = st.Get();
	return result;
}