// Algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//OJ 编号451 第4题 凸包问题

#include <iostream>
using namespace std;

// 点的结构体
struct Point
{
	int x;
	int y;
};

// 检测点集里的点是否都在同一直线上
int _oneline(Point P[], int n)
{
	bool result = true;
	int A, B, C;

	A = P[1].y - P[2].y;
	B = P[2].x - P[1].x;
	C = P[1].x * P[2].y - P[2].x * P[1].y;

	for (int i = 3; i <= n; i++)
	{
		if (A * P[i].x + B * P[i].y + C != 0)
		{
			result = false;
		}
	}

	return result;
}

// 蛮力法计算点集的凸包
void _getConvexHull(Point P[], int n, int R[])
{
	int i, j, k;

	for (i = 1; i <= n-1; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			int sign1 = 0, sign2 = 0;
			int A, B, C;
			A = P[i].y - P[j].y;
			B = P[j].x - P[i].x;
			C = P[i].x * P[j].y - P[j].x * P[i].y;
			for (k = 1; k <= n; k++)
			{
				if (k != i && k != j)
				{
					if (A * P[k].x + B * P[k].y + C > 0) sign1 = 1;
					else sign2 = 1;
					if (sign1 == sign2) break;
				}
			}
			if (k == n + 1)
			{
				R[i] = 1;
				R[j] = 1;
			}
		}
	}
}

int main()
{
	int n;
	Point P[100];
	int R[100] = { 0 };
	int first;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> P[i].x;
		cin >> P[i].y;
	}

	// 所有点都在一条直线上就输出-1，否则调用函数计算凸包
	if (_oneline(P, n))
	{
		cout << -1;
	}
	else
	{
		_getConvexHull(P, n, R);

		for (first = 1; first <= n; first++)
		{
			if (R[first] == 1)
			{
				cout << first;
				break;
			}
		}
		for (int i = first + 1; i <= n; i++)
		{
			if (R[i] == 1)
			{
				cout << ' ' << i;
			}
		}
	}
	
	return 0;
}
