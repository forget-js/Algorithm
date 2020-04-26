// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 二叉查找树（binary search tree BST）的创建与查找

#include <stdio.h>

// 节点结构
struct BiNode
{
	int data;
	BiNode* lchild, * rchild;
};

// 插入算法
BiNode* InsertBST(BiNode* root, int data)
{
	if (root == NULL)
	{
		root = new BiNode;
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	else
	{
		if (data <= root->data)
		{
			root->lchild = InsertBST(root->lchild, data);
		}
		else
		{
			root->rchild = InsertBST(root->rchild, data);
		}
	}

	return root;
}
// 二叉查找树的构建
BiNode* createBST(int a[], int n)		// 将无序序列a[n]建立二叉查找树
{
	BiNode* T = NULL;
	for (int i = 0; i < n; i++)
	{
		T = InsertBST(T, a[i]);
	}
	return T;
}

// 查找算法
BiNode* SearchBST(BiNode* root, int k)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->data == k)
	{
		return root;
	}
	else if (k < root->data)
	{
		return SearchBST(root->lchild, k);
	}
	else
	{
		return SearchBST(root->rchild, k);
	}
}

int main()
{
	int a[] = { 2,5,1,8,6 };
	BiNode* bn = createBST(a, 5);
	BiNode* KeyNode = SearchBST(bn, 8);
	if (KeyNode)
	{
		printf("查找%d成功。\n", KeyNode->data);
	}
	else
	{
		printf("查找失败。\n");
	}

	return 0;
}