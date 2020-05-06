// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 分治法求分糖果问题

#include <stdio.h>
#include <iostream>
using namespace std;

int getCount(int candy, int plate)
{
	int count = 0;

	if (candy < 0)
	{
		count = 0;
	}
	else if (candy == 1 || plate == 1)
	{
		count = 1;
	}
	else
	{
		count = getCount(candy, plate - 1) + getCount(candy - plate, plate);
	}

	return count;
}

int main()
{
	int candy, plate;
	int count;

	cin >> candy >> plate;
	count = getCount(candy, plate);
	cout << count << endl;

	return 0;
}