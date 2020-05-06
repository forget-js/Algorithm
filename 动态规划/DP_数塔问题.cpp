// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 动态规划法求数塔问题
// 输入：二维数组d[n][n]
// 输出：数塔的最大数值和及其路径

#include <stdio.h>

const int n = 5;	// 数塔的层数

int DataTower(int d[n][n])
{
	int i, j;
	int maxAdd[n][n] = { 0 };	// 存储每一次决策的值，初始化为0
	int path[n][n] = { 0 };		// 储存每一次决策的路径，及每次选择的数字在数组d[n][n]中的下标，初始化为0

	for (j = 0; j < n; j++)		// 初始化底层决策结果
	{
		maxAdd[n - 1][j] = d[n - 1][j];
	}
	for (i = n - 2; i >= 0; i--)	// 进行第i层的决策
	{
		for (j = 0; j <= i; j++)	// 只填写maxAdd[i][j]的下三角
		{
			if (maxAdd[i + 1][j] > maxAdd[i + 1][j + 1])
			{
				maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j];
				path[i][j] = j;		// 本次决策选择左边的数字
			}
			else
			{
				maxAdd[i][j] = d[i][j] + maxAdd[i + 1][j + 1];
				path[i][j] = j + 1;		// 本次决策选择右边的数字
			}
		}
	}
	// 输出决策路径
	printf("路径为：%d", d[0][0]);
	j = path[0][0];
	for (i = 1; i < n; i++)
	{
		printf("-->%d", d[i][j]);
		j = path[i][j];
	}

	return maxAdd[0][0];
}

int main()
{
	int d[n][n] = { {8,0,0,0,0},\
					{12,15,0,0,0},\
					{3,9,6,0,0},\
					{8,10,5,12,0},\
					{16,4,18,10,9} };

	printf("数塔如下：\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	int maxSum = DataTower(d);
	printf("\n最大值的和是%d\n", maxSum);

	return 0;
}