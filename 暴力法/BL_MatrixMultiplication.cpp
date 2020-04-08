// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 暴力法解矩阵乘法
// n×n的矩阵A、B，求A*B

#include <iostream>
using namespace std;

void MatrixMultiplication(int n, int** A, int** B, int** AB)
{
	// AB[i][j]=∑（A[i][0-k]*B[0-k][j]）

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			for (int k = 0; k < n; k++)
			{
				int mul = 1;
				mul = A[i][k] * B[k][j];
				sum += mul;
			}
			AB[i][j] = sum;
		}
	}
}

int main()
{
	// 输入矩阵大小
	int n = 0;
	cout << "请输入矩阵的大小n：";
	cin >> n;

	// 创建矩阵数组
	int** A = new int* [n];
	int** B = new int* [n];
	int** AB = new int* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[n];
		B[i] = new int[n];
		AB[i] = new int[n];
	}

	// 输入矩阵
	cout << "请输入矩阵A:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	cout << "请输入矩阵B:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> B[i][j];
		}
	}
	cout << "您输入的矩阵A：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "   ";
		}
		cout << endl;
	}
	cout << "您输入的矩阵B：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << B[i][j] << "   ";
		}
		cout << endl;
	}

	// 调用暴力矩阵乘法
	MatrixMultiplication(n, A, B, AB);

	// 输出AB
	cout << "A*B：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << AB[i][j] << "   ";
		}
		cout << endl;
	}

	// 释放内存
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] AB[i];
	}
	delete[] A;
	delete[] B;
	delete[] AB;

	return 0;
}