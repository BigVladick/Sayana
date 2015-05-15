#include <iostream>
#include "string.h"

using namespace std;

/*
CL06.	Реализовать класс «строка» с возможностями конкатенации, сравнения, индексации элементов.
*/

/*
*План разработки:
+ Коструктор от char*
+ Оператор сравнения == и !=
+ Rонкатенация (+)
+ индексация
+ комментарии
*/

int main()
{
	// создание
	String m = String("m");
	String n = String("n");

	// сравнение
	cout << (m == n) << endl;
	cout << (m != n) << endl;
	
	// 2 оператора конкатенации
	m += n;
	cout << m << endl;
	String* nm = (n + m);
	cout << *nm << endl;
	delete nm;
	
	// идексация
	cout << m[1] << endl;
	return 0;
}