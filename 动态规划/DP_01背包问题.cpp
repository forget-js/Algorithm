// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 动态规划法解0/1背包问题（使用vector容器）

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int n, vector<int>& w, vector<int>& v, int c, vector<int>& x)
{
	int maxVal = 0;
	vector<vector<int>> V(n + 1, vector<int>(c + 1, 0));	// 迭代结果，初始化为0
	int i, j;

	// 迭代
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (j < w[i])	V[i][j] = V[i - 1][j];
			else			V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
		}
	}
	maxVal = V[n][c];

	// 回溯，标记装入背包的物品
	for (j = c, i = n; i > 0; i--)
	{
		if (V[i][j] > V[i - 1][j])
		{
			x[i] = 1;
			j = j - w[i];
		}
		else
		{
			x[i] = 0;
		}
	}

	return maxVal;
}

int main()
{
	int n, c;						// 物品个数，背包容量
	vector<int> w(1,0), v(1,0);		// 物品重量，物品价值
	vector<int> x;					// 标记装入背包的物品

	// 输入数据
	cout << "请输入物品个数n：";
	cin >> n;
	cout << "请输入这n个物品的重量：" << endl;
	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;
		w.push_back(weight);
	}
	cout << "请输入这n个物品的价值：" << endl;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		v.push_back(value);
	}
	cout << "请输入背包的容量c：";
	cin >> c;

	// 调用算法求解
	x.resize(n + 1);
	int maxVal = knapsack(n, w, v, c, x);

	// 输出结果
	cout << "最大价值为：" << maxVal << endl;
	cout << "被放入背包的物品编号为：\n";
	for (int i = 1; i <= n; i++)
	{
		if (x[i] == 1) cout << i << " ";
	}

	return 0;
}