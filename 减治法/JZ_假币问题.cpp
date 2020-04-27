// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 假币问题
// 假设有n枚硬币，其中有一枚假币。
// 假币除了重量，其他与真币都一样。flag:假币轻重标识，0代表轻，1代表重
// 现用一个天平去找出假币，问需几次？
// 输入：n个整数，真币为1，假币若轻则小于1，假币若重则大于1
// 输出：假币的位置

#include <stdio.h>

// 已知假币轻重
int FindFalseCoinWithFlag(int coin[], int n, int flag, int start)
{
	int place = -1;		// 单一出口，假币位置

	if (n == 2)		// 只有两枚硬币时只需比较一次
	{
		int A = coin[start];
		int B = coin[start + 1];
		if (flag == 0)
		{
			if (A > B)	place = start + 1;
			else		place = start;
		}
		else
		{
			if (A > B)	place = start;
			else		place = start + 1;
		}
	}
	if (n == 3)		// 只有三枚硬币时也只需比较一次
	{
		int A, B, C;
		A = coin[start];
		B = coin[start+1];
		C = coin[start+2];
		if (flag == 0)
		{
			if (A > B)		place = start + 1;
			else if (A < B)	place = start;
			else			place = start + 2;
		}
		else
		{
			if (A > B)		place = start;
			else if (A < B)	place = start + 1;
			else			place = start + 2;
		}
	}
	if (n > 3)		// 超过三枚硬币
	{
		int a, b, c;
		a = b = n / 3;
		c = n - a - b;
		if (a == 1)		// 四枚硬币：1 1 2
		{
			int A = coin[start];
			int B = coin[start + 1];
			if (A == B)
			{
				place = FindFalseCoinWithFlag(coin, 2, flag, start + 2);
			}
			else
			{
				place = FindFalseCoinWithFlag(coin, 2, flag, start);
			}
		}
		else		// 不止四枚，分三堆：A B C
		{
			// 计算A B的重量
			int sumA = 0, sumB = 0;
			for (int i = start; i < start + a; i++)
			{
				sumA += coin[i];
			}
			for (int i = start + a; i < start + a + b; i++)
			{
				sumB += coin[i];
			}

			// A与B称
			if (sumA == sumB)		// 一样重，假币在C
			{
				place = FindFalseCoinWithFlag(coin, c, flag, start + a + b);
			}
			else if (sumA > sumB)	// A比B重
			{
				if (flag == 0)  // 假币轻
				{
					place = FindFalseCoinWithFlag(coin, b, flag, start + a);
				}
				else  // 假币重
				{
					place = FindFalseCoinWithFlag(coin, a, flag, start);
				}
			}
			else if (sumA < sumB)	// A比B轻
			{
				if (flag == 1)  // 假币重
				{
					place = FindFalseCoinWithFlag(coin, b, flag, start + a);
				}
				else  // 假币轻
				{
					place = FindFalseCoinWithFlag(coin, a, flag, start);
				}
			}
		}
	}

	return place;
}

// 不知假币轻重
int FindFalseCoinWithoutFlag(int coin[], int n)
{
	int place = -1;		// 单一出口，假币位置

	// 假币分四堆：A B C D
	int a, b, c, d;
	int suma = 0, sumb = 0, sumc = 0;
	// 计算A、B、C的数量
	a = b = c = n / 3;
	d = n % 3;
	// 计算A、B、C的重量
	for (int i = 0; i < a; i++)
	{
		suma += coin[i];
	}
	for (int i = a; i < a + b; i++)
	{
		sumb += coin[i];
	}
	for (int i = a + b; i < a + b + c; i++)
	{
		sumc += coin[i];
	}

	// A、B称
	if (suma == sumb)  // A B等重
	{
		// A与C称
		if (suma == sumc)  // A C等重，假币在D
		{
			int real = coin[0];
			for (int i = a + b + c; i < n; i++)
			{
				if (coin[i] != real)
				{
					place = i;
					break;
				}
			}
		}
		else  // A C不等重，假币在C
		{
			int flag;
			if (suma > sumc)	flag = 0;	// 假币轻
			else				flag = 1;	// 假币重
			place = FindFalseCoinWithFlag(coin, c, flag, a + b);
		}
	}
	else  // A B不等重
	{
		// A与C称
		if (suma == sumc)  // A C等重，假币在B
		{
			int flag;
			if (suma > sumb)	flag = 0;
			else				flag = 1;
			place = FindFalseCoinWithFlag(coin, b, flag, a);
		}
		else  // A C不等重，假币在A
		{
			int flag;
			if (suma > sumb)	flag = 1;
			else				flag = 0;
			place = FindFalseCoinWithFlag(coin, a, flag, 0);
		}
	}

	return place;
}

int main()
{
	const int N = 9;
	int coin[N] = { 1,1,1,1,1,1,9,1,1 };
	int place;

	printf("现有硬币%d个：", N);
	for (int i = 0; i < N; i++)
	{
		printf("%d ", coin[i]);
	}
	printf("\n");
	place = FindFalseCoinWithoutFlag(coin, 9);
	printf("假币是第%d个。\n", place + 1);

	return 0;
}