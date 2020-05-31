// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 最长有效括号子串 - 动态规划

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Algorithm.h"
using namespace std;

int longestValidParentheses(string s)
{
	int maxLength = 0;

	int size = s.length();
	vector<int> dp(size, 0);

	for (int i = 1; i < size; i++)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				dp[i] = 2;
				if (i - 2 >= 0)
				{
					dp[i] = dp[i] + dp[i - 2];
				}
			}
			else if (dp[i - 1] > 0)
			{
				if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(')
				{
					dp[i] = dp[i - 1] + 2;
					if ((i - dp[i - 1] - 2) >= 0)
					{
						dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
					}
				}
			}
		}
		maxLength = max(maxLength, dp[i]);
	}
	return maxLength;
}

int main()
{
	string s;
	cin >> s;
	cout << longestValidParentheses(s) << endl;

	return 0;
}