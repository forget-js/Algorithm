// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 二叉平衡树（AVLTree）的创建与查找

#include <stdio.h>
#include <cmath>

// 节点结构
struct AVLTreeNode
{
	int bf;			// balance factor平衡因子（左-右）
	int data;		// 数据
	AVLTreeNode* parent, * lchild, * rchild;		//父节点、左子树、右子树

	AVLTreeNode()
	{
		bf = 0;
		parent = lchild = rchild = NULL;
	}
};

// 旋转操作
void RotateRR(AVLTreeNode* parent)
{
	AVLTreeNode* subR = parent->rchild;
	AVLTreeNode* subRL = subR->lchild;
	AVLTreeNode* ppNode = parent->parent;		//标记祖先节点

	// 1.构建parent子树 链接parent和subRL
	parent->rchild = subRL;
	if (subRL) subRL->parent = parent;
	// 2.构建subR子树 链接parent和subR
	subR->lchild = parent;
	parent->parent = subR;
	// 3.连接祖先节点和subR节点
	subR->parent = ppNode;
	if (ppNode == NULL)		// 如果祖先节点为NULL，说明目前的根节点为subR
	{
		//_root = subR;
	}
	else
	{	// 将祖先节点和subR节点链接起来
		if (parent == ppNode->lchild)
			ppNode->lchild = subR;
		else
			ppNode->rchild = subR;
	}
	// 4.重置平衡因子
	parent->bf = 0;
	subR->bf = 0;
	// 5.更新subR为当前父节点
	parent = subR;
}
void RotateLL(AVLTreeNode* parent)
{
	AVLTreeNode* subL = parent->lchild;		// 构造的左子树
	AVLTreeNode* subLR = subL->rchild;		// subL的右子树
	AVLTreeNode* ppNode = parent->parent;	// 标记祖先节点

	// 1.构建parent子树 将parent和subLR链接起来
	parent->lchild = subLR;
	if (subLR) subLR->parent = parent;
	// 2.构建subL子树 将subL与parent链接起来
	subL->rchild = parent;
	parent->parent = subL;
	// 3.将祖先节点与subL链接起来
	if (ppNode == NULL)		// 如果祖先为NULL，说明当前subL节点为根节点
	{	
		subL->parent = NULL;
		//_root = subL;
	}
	else
	{
		subL->parent = ppNode;
		if (ppNode->lchild == parent)
			ppNode->lchild = subL;
		else if (ppNode->rchild == parent)
			ppNode->rchild = subL;
	}
	//4.重置平衡因子
	parent->bf = 0;
	subL->bf = 0;
	//5.更新subL为当前父节点
	parent = subL;
}
void RotateRL(AVLTreeNode* parent)
{
	AVLTreeNode* pNode = parent;
	// 构造的左子树
	AVLTreeNode* subL = parent->lchild;
	// subL的右子树
	AVLTreeNode* subRL = subL->rchild;
	int bf = subRL->bf;

	RotateRR(parent->lchild);
	RotateLL(parent);

	if (bf == -1)
	{
		pNode->bf = 0;
		subL->bf = 1;
	}
	else if (bf == 1)
	{
		pNode->bf = -1;
		subL->bf = 0;
	}
	else
	{
		pNode->bf = 0;
		subL->bf = 0;
	}
}
void RotateLR(AVLTreeNode* parent)
{
	AVLTreeNode* pNode = parent;
	AVLTreeNode* subR = parent->rchild;
	AVLTreeNode* subLR = subR->lchild;
	int bf = subLR->bf;

	RotateLL(parent->rchild);
	RotateRR(parent);
	// LR(b)型
	if (bf == -1)
	{
		pNode->bf = 0;
		subR->bf = 1;
	}
	// LR(a)型
	else if (bf == 1)
	{
		pNode->bf = -1;
		subR->bf = 0;
	}
	// LR(c)型
	else
	{
		pNode->bf = 0;
		subR->bf = 0;
	}
}

// 求树的高度
int Height(AVLTreeNode* root)
{
	if (root == NULL)	return 0;

	int high = 0;
	int left = Height(root->lchild);
	int right = Height(root->rchild);

	if (left > right)	high = left;
	else	high = right;

	if (root->parent != NULL)	return 1 + high;
	else	return high;
}

// 判断是否平衡，是则返回ture
bool IsBalance(AVLTreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	int bf = Height(root->lchild) - Height(root->rchild);
	if (root->bf != bf)
	{
		return false;
	}
	// bf的绝对值小于2，并且左树和右树都平衡则以root为根的子树才处于平衡状态
	return abs(bf) < 2 && IsBalance(root->lchild) && IsBalance(root->rchild);
}

// 插入算法
AVLTreeNode* Insert(AVLTreeNode* root, int data)
{
	if (root == NULL)	// 若为空树
	{
		root = new AVLTreeNode();
		root->data = data;
	}
	else
	{
		AVLTreeNode* parent = NULL;
		AVLTreeNode* current = root;

		// 找到合适的插入位置
		while (current)
		{
			if (current->data >= data)
			{
				parent = current;
				current = current->lchild;
			}
			else
			{
				parent = current;
				current = current->rchild;
			}
		}
		// 插入数据
		current=new AVLTreeNode();
		current->data = data;
		current->parent = parent;
		if (parent->data >= data)
		{
			parent->lchild = current;
		}
		else
		{
			parent->rchild = current;
		}

		while (parent)
		{
			// 更新平衡因子
			if (current == parent->lchild)
			{
				parent->bf++;
			}
			else
			{
				parent->bf--;
			}
			// 检测是否平衡
			if (parent->bf == 0)
			{
				break;
			}
			else if (parent->bf == -1 || parent->bf == 1)	// 向上回溯更新并检测
			{
				current = parent;
				parent = current->parent;
			}
			else
			{
				if (parent->bf == -2)
				{
					if (current->bf == -1)
					{
						RotateRR(parent);
					}
					else
					{
						RotateLR(parent);
					}
				}
				else if (parent->bf == 2)
				{
					if (current->bf == 1)
					{
						RotateLL(parent);
					}
					else
					{
						RotateRL(parent);
					}
				}
				break;
			}
		}
	}

	return root;
}

// 构建 将无序序列a[n]建立二叉平衡树
AVLTreeNode* Create(int a[], int n)		
{
	AVLTreeNode* T = NULL;
	for (int i = 0; i < n; i++)
	{
		T = Insert(T, a[i]);
	}
	return T;
}

// 查找算法 查找是否存在数据为k的节点，有则返回该节点，否则返回空
AVLTreeNode* Search(AVLTreeNode* root, int k)	
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
		return Search(root->lchild, k);
	}
	else
	{
		return Search(root->rchild, k);
	}
}

// 中序遍历
void InOrder(AVLTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		InOrder(root->lchild);
		printf("%d ", root->data);
		InOrder(root->rchild);
	}
}

int main()
{
	int a[] = { 2,5,1,8,6 };

	AVLTreeNode* AVLTree = Create(a, 5);
	InOrder(AVLTree);
	printf("\n");

	AVLTreeNode* KeyNode = Search(AVLTree, 8);
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