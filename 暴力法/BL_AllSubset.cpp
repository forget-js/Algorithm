// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 暴力法求n的所有子集

#include <iostream>
using namespace std;

void printSubset(int set[], int count)
/*count: The count of set's elemnts.*/
{
    int i, j, k;
    int subSetCount = 1 << count;          // 子集合的个数
    for (i = 0; i < subSetCount; i++)
    {
        j = i;
        k = 0;
        printf("{");
        while (j)
        {
            if (j & 1)
            {
                printf("%d", set[k]);
            }
            j >>= 1;
            k++;
        }
        printf("}\n");
    }
}

int main()
{
    int a[5] = { 1, 2, 3 };
    printSubset(a, 3);
    return 0;
}