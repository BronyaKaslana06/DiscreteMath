#include<iostream>
using namespace std;
void output(int s[][100]);
void zifan(int s2[][100]);
void duichen();
void chuandi();
void select();
void exit();
int s[100][100], z;
int d, n, i, j;

int main()
{
	select();
	return 0;
}

//初始化矩阵，选择功能
void select()
{
	while (1)//输入错误处理
	{
		cout << "请输入矩阵的行数和列数:";
		cin >> n;
		if (cin.fail() || !(n >= 1 && n <= 4))
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "请输入数字" << endl;
		}
		else
			break;
	}
	cout << "请输入关系矩阵:\n";
	for (i = 0; i < n; i++)
	{
		cout << endl;
		cout << "请输入矩阵的第" << i << "行元素(元素以空格分隔) :";
		for (j = 0; j < n; j++)
			cin >> s[i][j];
	}
	while (1)//输入错误处理
	{
		cout << "输入对应序号选择算法\nl:自反闭包\n2:传递闭包\n3:对称闭包\n4:退出\n";
		cin >> z;
		if (cin.fail() || !(z >= 1 && z <= 4))
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "请输入数字1-4" << endl;
		}
		else
			break;
	}
	//调用相应的算法
	switch (z)
	{
		case 1:
			zifan(s); 
			break;
		case 2:
			chuandi(); 
			break;
		case 3:
			duichen(); 
			break;
		case 4:
			exit(); 
			break;
		/*default:
			exit();
			break;*/
	}
}

//输出所求关系矩阵
void output(int s[][100])
{
	cout << "所求关系矩阵为:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << s[i][j];
		cout << endl;
	}
}

//求自反闭包
void zifan(int s2[][100])
{
	for (i = 0; i < n; i++)
		s2[i][i] = 1;
	output(s2);
	select();
}

//求对称闭包
void duichen()
{
	int s1[100][100];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			s1[j][i] = s[i][j];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			s[i][j] = s[i][j] + s1[i][j];
			if (s[i][j] > 1)
				s[i][j] = 1;
		}
	output(s);
	select();
}

//求传递闭包
void chuandi()
{
	int m[100][100], a[100][100], k, h;
	int t[100][100];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			a[i][j] = 0;
			t[i][j] = s[i][j];
			m[i][j] = s[i][j];
		}
	for (h = 0; h < n; h++)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (m[i][j] == 1)
				{
					for (k = 0; k < n; k++)
						if (s[j][k] == 1)
							a[i][k] = 1;
				}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				m[i][j] = a[i][j];
				t[i][j] += a[i][j];
				a[i][j] = 0;
				if (t[i][j] > 1)
					t[i][j] = 1;
			}
	}

	output(t);
	select();
}

void exit()
{
	exit(1);
}
