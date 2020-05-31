// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 找零问题，动态规划解法
// 类似01背包问题，找零数是背包容量，硬币面值是物品价值

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    // 初始化dp数组，Max防止出现无法找零情况
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;

    /* 状态转移过程
     * F[i] = min{ F[i-Cj] + 1 }
     * j = 0...n-1
     * Cj = coins[j]
     */
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < (int)coins.size(); j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = { 1,2,3 };
    int amount = 6;
    int res;

    res = coinChange(coins, amount);
    cout << res << endl;

	return 0;
}