#include <iostream>
#include <fstream>
#include "number.h"

using namespace std;

int main()
{
	cout << "put x and y :=\n";
	string x = "";
	string y = "";
	cin >> x >> y;
	Number x1 = Number(x);
	Number y1 = Number(y);
	Number* sum = x1 * y1;
	cout << *sum << endl;
	

	ofstream outFile;
	outFile.open("data.txt", ios::out);
	outFile << x << "*" << y << "=" << *sum;
	outFile.close();
	delete sum;
	return 0;
}