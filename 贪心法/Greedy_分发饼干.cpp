// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 分发饼干

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
	int res = 0;

	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int gn = g.size();
	int sn = s.size();
	int i = 0, j = 0;

	while (i < gn && j < sn)
	{
		if (s[j] >= g[i])
		{
			res++;
			i++;
		}
		j++;
	}

	return res;
}

int main()
{
	int m, n;
	vector<int> g;
	vector<int> s;

	cout << "请输入孩子的个数m：";
	cin >> m;
	cout << "请输入这m个孩子的胃口值：" << endl;
	for (int i = 0; i < m; i++)
	{
		int gi;
		cin >> gi;
		g.push_back(gi);
	}
	cout << "请输入饼干的数量n：";
	cin >> n;
	cout << "请输入这n个饼干的尺寸：" << endl;
	for (int i = 0; i < n; i++)
	{
		int si;
		cin >> si;
		s.push_back(si);
	}

	cout << "可以满足的孩子数量为：" << findContentChildren(g, s) << endl;

	return 0;
}