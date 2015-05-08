#include <iostream>
#include "timeStamp.h"

using namespace std;

int main()
{
	// заданный формат чч:мм:сс либо ч:м:c и тд

	TimeStamp a = TimeStamp(16, 57, 43);
	cout << a << endl;
	TimeStamp b = TimeStamp("16:57:43");
	cout << b << endl;
	TimeStamp c = TimeStamp("10:0:0");
	cout << c << endl;
	cout << TimeStamp::getDiff(b, c) << endl;
	return 0;
}