// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 减治法求a^n
// 输入a、n，输出a^n

#include <iostream>
using namespace std;

int f(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return a;
	}
	else
	{
		if (n % 2 == 0)
		{
			int b = f(a, n / 2);
			return b * b;
		}
		else
		{
			int b = f(a, (n - 1) / 2);
			return a * b * b;
		}
	}
}

int main()
{
	int a, n;
	cin >> a >> n;
	cout << f(a, n);

	return 0;
}