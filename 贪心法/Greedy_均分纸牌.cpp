// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 均分纸牌

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int averageCards(vector<int>& cards)
{
	int count = 0;

	// 求平均数
	int n = cards.size();
	int average;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += cards[i];
	}
	average = sum / n;
	
	// 移动过程
	for (int i = 0; i < n; i++)
	{
		// 求当前的这堆纸牌数与平均数的差值
		int difference;
		difference = cards[i] - average;

		// 不够则借，够则给
		if (difference)
		{
			cards[i] += difference;
			cards[i + 1] += difference;
			count++;
		}
	}

	return count;
}

int main()
{
	vector<int> cards = { 9,8,17,6 };
	int count = averageCards(cards);
	cout << count << endl;

	return 0;
}