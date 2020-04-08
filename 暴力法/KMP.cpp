// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// KMP算法

#include <iostream>
using namespace std;

void _getNext(char T[],int next[])
{
	int i = 0, j = -1;
	next[0] = -1;

	while (T[i] != '\0')
	{
		if (j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP(char S[], char T[])
{
    int i = 0, j = 0;
    int next[80];
    _getNext(T, next);
	while (S[i] != '\0' && T[j] != '\0')
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
			if (j == -1)
			{
				i++;
				j++;
			}
		}
	}
	if (T[j] == '\0')
	{
		return(i - strlen(T) + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char S[] = "abcdeabc12";
	char T1[] = "bcd1", T2[] = "bcd";
	int place1 = KMP(S, T1);
	int place2 = KMP(S, T2);

	cout << "主串S：" << S << endl;
	cout << "子串T1:" << T1 << " 在主串的出现位置：" << place1 << endl;
	cout << "子串T2:" << T2 << " 在主串的出现位置：" << place2 << endl;

	return 0;
}
