#include <iostream>
#include <math.h>

using namespace std;

/*
����������� ����� �������������� ��������, ��������� �� ���������� ����� (����� - ��� ���� �����,
��������� �� ����� ��������� x � y) 
� ����������� ������� �������� ������ ���������, �������� ������� ���������, ��������������
*/

struct Point
{
	double x;
	double y;
	Point() {} // default constructor
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
};

class Geometry
{
private:
	int amountPoints;
	Point* points;
public:
	Geometry()
	{
		amountPoints = 0;
		points = nullptr;
	}
	void addPoint(Point nova)
	{
		// ������ ������
		if (points == nullptr)
		{
			// ������������ ������ �������� 1
			points = new Point[amountPoints + 1](); // ������� ������ - ����� ������������ �� ���������
			points[amountPoints++] = nova;
		}
		//�������� ������
		else
		{
			// ������� ����� ������ �� 1 ������ �����������
			Point* slot = new Point[amountPoints + 1]();
			// ����������� �������� ������� ������� ������ �������
			for (int i = 0; i < amountPoints; i++)
			{
				slot[i] = points[i];
			}
			// ������� ����� ����� � ����� ������
			slot[amountPoints++] = nova;
			// ������� ������ ������
			delete[] points;
			// ������ ������ = ������
			points = slot;

		}
	}
	void print()
	{
		for (int i = 0; i < amountPoints; i++)
		{
			cout << "(" << points[i].x << ";" << points[i].y << ")\n";
		}
	}

	void shiftCenter(double a, double b)
	{
		for (int i = 0; i < amountPoints; i++)
		{
			points[i].x -= a;
			points[i].y -= b;
		}
	}

	void turn(double degree)
	{
		// ������� ������ http://vm.psati.ru/online-math-sem-1/page-2-7-02.html
		for (int i = 0; i < amountPoints; i++)
		{
			points[i].x = (points[i].x + points[i].y * sin(degree)) / cos(degree);
			points[i].y = (points[i].y - points[i].x * sin(degree)) / cos(degree);
		}
	}

	void newScale(double n)
	{
		// http://esate.ru/uroki/OpenGL/uroki-OpenGL-c-sharp/alg..
		for (int i = 0; i < amountPoints; i++)
		{
			points[i].x *= n;
			points[i].y *= n;
		}
	}

	~Geometry()
	{
		delete[] points;
	}
};

int main()
{
	Point z = Point(0, 0);
	Point z1 = Point(1, 1);

	Geometry* geom = new Geometry();
	geom->addPoint(z);
	geom->addPoint(z1);
	cout << "Default:\n";
	geom->print();
	cout << "after shifting center:\n";
	geom->shiftCenter(3, 3);
	geom->print();
	cout << "after turning:\n";
	geom->turn(0.5);
	geom->print();
	cout << "after new scale:\n";
	geom->newScale(2);
	geom->print();
	delete geom;
	system("pause");
	return 0;
}