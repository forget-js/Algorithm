// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 矩阵连乘

#include <iostream>
using namespace std;

const int MAX_N = 10;

void MatrixChain(int m[][MAX_N + 1], int n, int p[])
{
	for (int d = 2; d <= n; d++)				// d个矩阵一组
	{
		for (int i = 1; i <= n - d + 1; i++)	// d个矩阵一组时有 n-d+1 种次序
		{
			int j = i + d - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];

			for (int k = i + 1; k < j; k++)		// 寻找最优值
			{
				int min = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (min < m[i][j])
				{
					m[i][j] = min;
				}
			}
		}
	}
}

int main()
{
	int n;
	int p[MAX_N + 1];
	int m[MAX_N + 1][MAX_N + 1] = { 0 };

	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> p[i];
	}

	// 构建 m[i][j]
	MatrixChain(m, n, p);

	// 输出结果
	cout << m[1][n];
	
	return 0;
}