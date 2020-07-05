// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 计算车费

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double minFare(int kilometres)
{
	double fare = 0;

	// 1、剩余路程不大于13公里就不换车
	// 2、剩余路程大于13公里，就每8公里换一次车
	if (kilometres <= 13)
	{
		fare += 10;
		kilometres -= 4;
		if (kilometres > 0 && kilometres <= 4)
		{
			fare += 2 * kilometres;
		}
		if (kilometres > 4)
		{
			fare += 8;
			kilometres -= 4;
			fare += 2.4 * kilometres;
		}
	}
	else
	{
		fare += 18;
		kilometres -= 8;
		fare += minFare(kilometres);
	}
	
	return fare;
}

int main()
{
	int n;
	cin >> n;

	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(1) << minFare(n) << endl;

	return 0;
}