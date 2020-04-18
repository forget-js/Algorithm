// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 分治法求格雷码
// 程序产生n位元的格雷码，n<=10

#include <iostream>
using namespace std;

char graycode[1024][10];

void CreateGrayCode(int n ,int count)
{
	if (n == 1)
	{
		graycode[0][0] = '0';
		graycode[1][0] = '1';
		return;
	}
	for (int i = 0; i < count / 2; i++)
	{
		graycode[i][n - 1] = '0';
		graycode[count - i - 1][n - 1] = '1';
	}
	CreateGrayCode(n - 1, count / 2);
	for (int i = count / 2; i < count; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			graycode[i][j] = graycode[count - i - 1][j];
		}
	}
}

int main()
{
	int n, count;

	cout << "本程序构造n位元的格雷码（n<=10）,请输入n：";
	cin >> n;
	count = pow(2, n);
	CreateGrayCode(n, count);
	cout << "生成的格雷码：\n";
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << graycode[i][j];
		}
		cout << endl;
	}

	return 0;
}