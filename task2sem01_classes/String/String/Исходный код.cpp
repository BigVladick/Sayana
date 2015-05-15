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
- Rонкатенация (+)
- Конструтор копирования и оператор присваивания
- оператор присваивания от char*
- индексация
*/

int main()
{
	String m = String("m");
	String n = String("n");
	String slot = String();
	slot = m + n;
	//String mn = m + n;
	return 0;
}