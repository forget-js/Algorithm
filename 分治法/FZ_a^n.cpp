// Algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 分治法解a的n次方

#include <iostream>
#include <math.h>
using namespace std;

int f(int a, int n)
{
	if (n == 1)
	{
		return a;
	}
	else
	{
		int m, b;
		m = floor(n / 2.0);
		b = ceil(n / 2.0);

		return f(a, m) * f(a, b);
	}
}

int main()
{
	int a, n;

	cin >> a >> n;
	cout << f(a, n);

	return 0;
}
