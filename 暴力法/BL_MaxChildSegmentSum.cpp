// Algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// OJ 编号451 第3题 最大子段和

#include <iostream>
using namespace std;

int _getSetMaxSum(int set[], int n)
{
    int sum = 0, maxSum = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                sum += set[k];
            }
            if (sum > maxSum)
            {
                maxSum = sum;
            }
            sum = 0;
        }
    }

    return maxSum;
}

int main()
{
    int n;
    int set[100];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }

    cout << _getSetMaxSum(set, n);

    return 0;
}