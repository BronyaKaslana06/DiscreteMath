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
		p[i] = v;		//p��¼���������㼯�����������뼯�����ĸ��������(��Ȩֵ��С)
		key[i] = tb[v][i];	//key������������㼯���ڶ��㵽�������������ĸ����ϵĵ�ǰ��СȨֵ
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
		cout << "��С�ķ���:" << p[v] << "��" << v << "\t��ȨΪ��" << key[v] << endl;
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
		cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������������0����):\n"; //��������Ķ�����Ŀ�ͱ���
		while (1)
		{
			cin >> n >> m;
			if (n < 0 || m < 0 || cin.fail())
			{
				cout << "������Ǹ�����!" << endl;
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
			cout << "�����������ߵĽڵ�����Լ����ǵ�Ȩֵ(�Կո�ָ�������):\n";
			while (m--)	      //�������б����Լ����ǵ�Ȩֵ
			{
				while (1)
				{
					cin >> u >> v >> w;	//��������Լ����ǵ�Ȩֵ
					if (cin.fail())
					{
						cout << "��������ȷ������!" << endl;
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
