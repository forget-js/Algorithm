// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 减治法求无序序列的第K小元素
// 

#include <iostream>
using namespace std;

int Partition(int r[], int low, int high)
{
	int i = low, j = high;
	while (i < j)
	{
		while (i < j && r[i] <= r[j]) j--;
		if (i < j)
		{
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
		}
		while (i < j && r[i] <= r[j]) i++;
		if (i < j)
		{
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			j--;
		}
	}
	return i;
}

int SelectMinK(int r[], int low, int high, int k)
{
	int s;
	s = Partition(r, low, high);
	if (s == k)
	{
		return r[s];
	}
	if (s > k)
	{
		return SelectMinK(r, low, s - 1, k);
	}
	else
	{
		return SelectMinK(r, s + 1, high, k);
	}
}

int main()
{
	int r[] = { 4,2,6,7,8,3,4 };
	cout << SelectMinK(r, 0, 6, 3);

	return 0;
}