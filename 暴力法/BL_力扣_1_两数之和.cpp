// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 力扣 1.两数之和

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> ans;
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}
	return ans;
}

int main()
{
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	int ans = twoSum(nums, target);

	return 0;
}