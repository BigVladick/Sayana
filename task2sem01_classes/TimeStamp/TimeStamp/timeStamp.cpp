#include "timeStamp.h"

// СМ комментарий в задаче про Date
int indexOf(string s, char a, int num)
{
	int l = s.size();
	int k = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == a)
		{
			if (k++ == num)
				return i;
		}
	}
	return -1;
}

// String -> int
int toInt(string s)
{
	int l = s.size();
	int result = 0;
	for (int i = 0; i < l; i++)
	{
		result += pow(10, l - i - 1) * (s[i] - '0'); // взятие степени
	}
	return result;
}

int TimeStamp::getDiff(TimeStamp a, TimeStamp b)
{
	int time1 = a.hour * 60 * 60 + a.minute * 60 + a.second;
	int time2 = b.hour * 60 * 60 + b.minute * 60 + b.second;
	return abs(time1 - time2); // abs - модуль от числа
}

// Аналогично предыдущей задачи
TimeStamp::TimeStamp(string input)
{
	string hourS = "";
	string minuteS = "";
	string secondS = "";
	int stage = 0;
	int start = 0;
	int l = input.size();
	int finish = indexOf(input, ':', stage++);
	for (int i = start; i < finish; i++)
		hourS += input[i];
	start = finish + 1;
	finish = indexOf(input, ':', stage);
	for (int i = start; i < finish; i++)
		minuteS += input[i];
	start = finish + 1;
	for (int i = start; i < l; i++)
		secondS += input[i];
	hour = toInt(hourS);
	minute = toInt(minuteS);
	second = toInt(secondS);

}


TimeStamp::TimeStamp()
{
}


TimeStamp::~TimeStamp()
{
}

ostream& operator<<(ostream& cout, TimeStamp& time)
{
	if (time.hour < 9)
		cout << "0";
	cout << time.hour << ":";
	if (time.minute < 9)
		cout << "0";
	cout << time.minute << ":";
	if (time.second < 9)
		cout << "0";
	cout << time.second;
	return cout;
}
