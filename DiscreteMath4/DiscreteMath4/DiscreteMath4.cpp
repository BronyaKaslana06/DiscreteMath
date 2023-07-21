#include <iostream>
using namespace std;
#define N 100
#define INT_MAX 2147483647
int p[N], key[N], tb[N][N];

void prim(int v, int n)
{
	int i, j;
	int min;
	for (i = 1; i <= n; i++)
	{
		p[i] = v;		//p记录生成树顶点集合外各顶点距离集合内哪个顶点最近(即权值最小)
		key[i] = tb[v][i];	//key存放生成树顶点集合内顶点到生成树外各顶点的各边上的当前最小权值
	}
	key[v] = 0;
	for (i = 2; i <= n; i++)
	{
		min = INT_MAX;
		for (j = 1; j <= n; j++)
			if (key[j] > 0 && key[j] < min)
			{
				v = j;
				min = key[j];
			}
		cout << "最小耗费是:" << p[v] << "和" << v << "\t边权为：" << key[v] << endl;
		key[v] = 0;
		for (j = 1; j <= n; j++)
			if (tb[v][j] < key[j])
			{
				p[j] = v;
				key[j] = tb[v][j];
			}
	}
}

int main()
{
	int n, m;//n: number of point, m :number of edge
	int i, j;
	int u, v, w;
	while (1)
	{
		cout << "请输入所求图的顶点数目和边的数目(以空格分隔各个数，输入两个0结束):\n"; //输入所求的顶点数目和边数
		while (1)
		{
			cin >> n >> m;
			if (n < 0 || m < 0 || cin.fail())
			{
				cout << "请输入非负整数!" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			else
				break;
		}
		if (m != 0 && n != 0)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
					tb[i][j] = INT_MAX;
			}
			cout << "请输入两条边的节点序号以及它们的权值(以空格分隔各个数):\n";
			while (m--)	      //输入所有边数以及它们的权值
			{
				while (1)
				{
					cin >> u >> v >> w;	//输入边数以及它们的权值
					if (cin.fail())
					{
						cout << "请输入正确的数字!" << endl;
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
					else
						break;
				}
				tb[u][v] = w;
				tb[v][u] = w;
			}
			prim(1, n);
			cout << endl;
		}
		else if (n == 0 && m == 0)
			break;
	}
	return 0;
}
