// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 分治法求满二叉树任意两个节点的最近共同祖先(nearest common ancestor)

#include <stdio.h>
#include <iostream>
using namespace std;

int findNCA(int x, int y)
{
	int result;

	if (x == y)
	{
		result = x;
	}
	else if (x > y)
	{
		result = findNCA(x / 2, y);
	}
	else
	{
		result = findNCA(x, y / 2);
	}

	return result;
}

int main()
{
	int x, y;
	int nca;

	cin >> x >> y;
	nca = findNCA(x, y);
	cout << nca << endl;

	return 0;
}