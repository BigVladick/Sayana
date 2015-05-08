#include <iostream>
#include <string>
#include "number.h"


// АТД Длинное число
// операции: +, -, *, /, ^

using namespace std;

int main()
{
	Number a = Number("576");
	Number b = Number("24");
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "a+b=" << *(a + b) << endl;
	cout << "a-b=" << *(a - b) << endl;
	cout << "a*b=" << *(a * b) << endl;
	cout << "a/b=" << *(a / b) << endl;
	cout << "b^2=" << *(b ^ 2) << endl;
	return 0;
}