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

//��ʼ������ѡ����
void select()
{
	while (1)//���������
	{
		cout << "��������������������:";
		cin >> n;
		if (cin.fail() || !(n >= 1 && n <= 4))
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "����������" << endl;
		}
		else
			break;
	}
	cout << "�������ϵ����:\n";
	for (i = 0; i < n; i++)
	{
		cout << endl;
		cout << "���������ĵ�" << i << "��Ԫ��(Ԫ���Կո�ָ�) :";
		for (j = 0; j < n; j++)
			cin >> s[i][j];
	}
	while (1)//���������
	{
		cout << "�����Ӧ���ѡ���㷨\nl:�Է��հ�\n2:���ݱհ�\n3:�ԳƱհ�\n4:�˳�\n";
		cin >> z;
		if (cin.fail() || !(z >= 1 && z <= 4))
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "����������1-4" << endl;
		}
		else
			break;
	}
	//������Ӧ���㷨
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

//��������ϵ����
void output(int s[][100])
{
	cout << "�����ϵ����Ϊ:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << s[i][j];
		cout << endl;
	}
}

//���Է��հ�
void zifan(int s2[][100])
{
	for (i = 0; i < n; i++)
		s2[i][i] = 1;
	output(s2);
	select();
}

//��ԳƱհ�
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

//�󴫵ݱհ�
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
