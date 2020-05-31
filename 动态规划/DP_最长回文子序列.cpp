// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 最长回文子序列

#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 1000;

int longestPalindromeSubseq(string s) 
{
	int max = 0;

	int length[MAX][MAX] = { 0 };
    int n = s.size();
	
	// 初始化length数组，赋初态
	for (int i = 0; i < n; i++)
	{
		length[i][i] = 1;
	}
	// 自底向上进行状态转移
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			// 状态转移方程
			if (s[i] == s[j])
			{
				length[i][j] = length[i + 1][j - 1] + 2;
			}
			else
			{
				if (length[i + 1][j] > length[i][j - 1])
				{
					length[i][j] = length[i + 1][j];
				}
				else
				{
					length[i][j] = length[i][j - 1];
				}
			}
		}
	}
	max = length[0][n - 1];
	
    return max;
}

int main()
{
	string s;
	cin >> s;
    cout << longestPalindromeSubseq(s) << endl;
	
	return 0;
}