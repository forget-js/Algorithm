// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 地下城游戏

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
	int minHP = 0;

	int m = dungeon.size();				// 地下城的行数
	if (m > 0)
	{
		int n = dungeon[0].size();		// 地下城的列数
		vector<vector<int>> dp(m, vector<int>(n));		// 定义dp数组

		// 初始化dp数组的最后一个值
		dp[m - 1][n - 1] = max(0, 0 - dungeon[m - 1][n - 1]);

		// 初始化最后一行
		for (int i = n - 2; i >= 0; i--)
		{
			int minNum = dp[m - 1][i + 1] - dungeon[m - 1][i];
			dp[m - 1][i] = max(0, minNum);
		}

		// 初始化最后一列
		for (int i = m - 2; i >= 0; i--)
		{
			int minNum = dp[i + 1][n - 1] - dungeon[i][n - 1];
			dp[i][n - 1] = max(0, minNum);
		}

		// 状态转移过程
		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				int minNum = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
				dp[i][j] = max(0, minNum);
			}
		}

		minHP = dp[0][0] + 1;
	}

	return minHP;
}

int main()
{
	vector<vector<int>> dungeon = {	{-2,-3,3},
									{-5,-10,1},
									{10,30,-5}
								 };
	
	cout << "骑士所需最低初始健康值为：" << calculateMinimumHP(dungeon) << endl;

	return 0;
}