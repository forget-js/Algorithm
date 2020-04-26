﻿// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 减治法求两个序列的中位数
// 

#include <iostream>
using namespace std;

int SearchMid(int A[], int B[], int n)
{
	int s1 = 0, e1 = n - 1, s2 = 0, e2 = n - 1;
	int mid1, mid2;
	while (s1 < e1 && s2 < e2)
	{
		mid1 = (s1 + e1) / 2;
		mid2 = (s2 + e2) / 2;
		if (A[mid1] < B[mid2])
		{
			if ((s1 + e1) % 2 == 0) s1 = mid1;
			else s1 = mid1 + 1;
			e2 = mid2;
		}
		else
		{
			if ((s2 + e2) % 2 == 0) s2 = mid2;
			else s2 = mid2 + 1;
			e1 = mid1;
		}
	}
	if (A[s1] < B[s2]) return A[s1];
	else return B[s2];
}

int main()
{
	int A[5] = { 1,3,2,4,5 }, B[5] = { 3,2,2,5,8 };
	cout << SearchMid(A, B, 5);

	return 0;
}