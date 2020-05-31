// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 贪心法解埃及分数问题

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int CommFactor(int m, int n)
{
	int r = m % n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}
	return n;
}

void EgyptFraction(int A, int B)
{
	int E, R;
	cout << A << "/" << B << "=";
	do
	{
		E = B / A + 1;
		cout << "1/" << E << "+";
		A = A * E - B;
		B = B * E;
		R = CommFactor(B, A);
		if (R > 1)
		{
			A = A / R;
			B = B / R;
		}
	} while (A > 1);
	cout << "1/" << B << endl;
	return;
}

int main()
{
	EgyptFraction(7, 8);

	return 0;
}