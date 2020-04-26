// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 俄式乘法
// n*m=n/2*(2*m)		【n是偶数】
// n*m=(n-1)/2*(2*m)+m	【n是奇数】

#include <stdio.h>
#include <math.h>

int e(int n, int m)
{
	int sum = 0;
	while (n > 1)	// 结束条件：1*m=m
	{
		if (n % 2 == 1)
		{
			sum += m;
		}
		m *= 2;
		n = ceil(n / 2);
	}
	sum += m;
	return sum;
}

int main()
{
	int n, m;
	n = 13;
	m = 32;
	int result = e(n, m);
	printf("%d乘以%d的结果为：%d", n, m, result);

	return 0;
}