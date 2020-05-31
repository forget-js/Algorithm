// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 最大矩形面积

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxm = 4, maxn = 5;

int maximalRectangle(vector<vector<char>>& matrix)
{
	int maxarea = 0;

	int m = matrix.size();		// 矩阵的行数
	if (m != 0)					// 确保矩阵非空
	{
		int n = matrix[0].size();	// 矩阵的列数

		int* left = new int[n];
		int* right = new int[n];
		int* height = new int[n];

		// 初始化辅助数组
		for (int i = 0; i < n; i++)
		{
			left[i] = 0;
			right[i] = n;
			height[i] = 0;
		}

		for (int i = 0; i < m; i++)
		{
			int cur_left = 0, cur_right = n;

			// 更新height
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1') height[j]++;
				else height[j] = 0;
			}
			// 更新left
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
				else { left[j] = 0; cur_left = j + 1; }
			}
			// 更新right
			for (int j = n - 1; j >= 0; j--)
			{
				if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
				else { right[j] = n; cur_right = j; }
			}
			// 更新maxarea
			for (int j = 0; j < n; j++)
			{
				maxarea = max(maxarea, (right[j] - left[j]) * height[j]);
			}
		}
		
		delete[] left, right, height;
	}

	return maxarea;
}

int main()
{
	vector<vector<char>> matrix(maxm);

	for (int i = 0; i < maxm; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			char c;
			cin >> c;
			matrix[i].push_back(c);
		}
	}
	cout << maximalRectangle(matrix);

	return 0;
}