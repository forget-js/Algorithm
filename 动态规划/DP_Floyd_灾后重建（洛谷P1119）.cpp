// 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 洛谷P1119 - 灾后重建

#include <iostream>
using namespace std;

const int MAX_N = 200;
const int MAX_M = MAX_N * (MAX_N - 1) / 2;
const int MAX_DIST = 100001;
const int MAX_Q = 50000;

void BuildMinDist(int dist[MAX_N][MAX_N], int N, int k)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (dist[i][k] + dist[k][j] < dist[i][j])
			{
				dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int getAns(int dist[MAX_N][MAX_N], int RebuildDates[], int x, int y, int t)
{
	int ans = -1;

	if (RebuildDates[x] > t || RebuildDates[y] > t || dist[x][y] == MAX_DIST)
	{
		ans = -1;
	}
	else
	{
		ans = dist[x][y];
	}

	return ans;
}

// 输出dist矩阵，调试使用。
void printdist(int dist[][MAX_N],int N)
{
	cout << "---start-------------" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dist[i][j] << "\t\t";
		}
		cout << endl;
	}
	cout << "---end-------------" << endl;
}

int main()
{
	int N;			// 村庄数
	int M;			// 公路数
	int i, j, w;	// 连接村庄i和村庄j的道路长度为w
	int Q;			// 询问数
	int x, y, t;	// 在第t天，从村庄x到村庄y
	
	int dist[MAX_N][MAX_N];		// 村庄之间的距离矩阵
	int RebuildDates[MAX_N];	// 村庄的重建时间
	int ans[MAX_Q];

	// 输入村庄数、公路数
	cin >> N >> M;

	// 初始化dist矩阵
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			if (a == b)
			{
				dist[a][b] = 0;
			}
			else
			{
				dist[a][b] = MAX_DIST;
			}
		}
	}

	// 输入每个村庄的重建时间
	for (int a = 0; a < N; a++)
	{
		cin >> RebuildDates[a];
	}

	// 输入每条公路的长度
	for (int a = 0; a < M; a++)
	{
		cin >> i >> j >> w;
		dist[i][j] = w;
		dist[j][i] = w;
	}

	// 输入询问数
	cin >> Q;

	// 输入Q组询问并保存每组询问的答案。k代表待重建的村庄编号。
	int k = 0;	
	for (int a = 0; a < Q; a++)
	{
		cin >> x >> y >> t;
		while (RebuildDates[k] <= t && k < N)
		{
			// 在线构建最短距离矩阵
			BuildMinDist(dist, N, k);
			k++;
		}
		ans[a] = getAns(dist, RebuildDates, x, y, t);
	}

	// 输出答案
	for (int a = 0; a < Q; a++)
	{
		cout << ans[a] << endl;
	}

	return 0;
}