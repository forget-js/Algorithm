// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 堆排序

#include <stdio.h>

// 堆调整
void SiftHeap(int r[], int k, int n)
{
	int i, j, temp;
	i = k;					// 要筛选的节点
	j = 2 * i + 1;			// 左孩子
	while (j < n)
	{
		if (j < n - 1 && r[j] < r[j + 1])		// 选出较大的孩子节点
		{
			j++;
		}
		if (r[i] > r[j])		// 筛选节点已大于其较大的孩子节点
		{
			break;
		}
		else
		{
			// 将筛选节点与其较大的孩子节点交换
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			// 设置下一个要筛选的节点和其左孩子
			i = j;
			j = 2 * i + 1;
		}
	}
}

// 堆排序
void HeapSort(int r[], int n)
{
	int i, temp;
	for (i = (n - 1) / 2; i >= 0; i--)		// 初始建堆，从最后一个非叶子节点开始
	{
		SiftHeap(r, i, n);
	}
	for (i = n - 1; i >= 1; i--)		// 堆排序过程，从小到大排序
	{
		temp = r[0];
		r[0] = r[i];
		r[i] = temp;
		SiftHeap(r, 0, i);
	}
}

int main()
{
	int r[] = { 2,5,1,8,6 };
	HeapSort(r, 5);

	printf("排序后：\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", r[i]);
	}

	return 0;
}