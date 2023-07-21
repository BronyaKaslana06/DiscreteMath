#include <iostream>
using namespace std;
//�ýṹ������ʾ��Ԫ��ϵ
typedef struct
{
	char a;
	char b;
}BR;
int n, m; //n ��ʾ���� A �е�Ԫ�ظ�����m ��ʾ��Ԫ��ϵ R �е�Ԫ�ظ���
//�������� A ����ʼ��
void init_aggregation(char*& A)
{
	cout << "�����뼯�� A �е�Ԫ�ظ���(������)�����س���������һ�" << endl;
	while (1)
	{
		cin >> n;
		if (cin.fail() || n <= 0)
		{
			cout << "������һ��������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}
	A = new(nothrow) char[n + 1];
	if (A == NULL)
	{
		cout << "Failed to call memory" << endl;
		exit(1);
	}
	cout << "���������뼯�� A �е�";
	cout << n; //n �Ǽ��� A �е�Ԫ�ظ���
	cout << "��Ԫ��(���磺a b c d ......�����ĸ�ʽ)�����س���������һ�" << endl;
	for (int i = 0; i < n; i++)
		cin >> A[i];
}
//�������� A �Ķ�Ԫ��ϵ R �ļ��ϲ���ʼ��
void init_BinaryRelation(BR*& R)
{
	cout << "�������Ԫ��ϵ R �е�Ԫ�ظ���(������)�����س���������һ�" << endl;
	while (1)
	{
		cin >> m;
		if (cin.fail() || m <= 0)
		{
			cout << "������һ��������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}

	R = new BR[n + 4];
	cout << "���������� R �е�";
	cout << m; //m �� R �е�Ԫ�ظ���
	cout << "��Ԫ�أ�һ����һ��Ԫ��" << endl;
	cout << "(���磺" << endl << "a b" << endl;
	cout << "b c" << endl;
	cout << "c d" << endl;
	cout << "......" << endl;
	cout << "�����ĸ�ʽ)�����س���������һ�" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> R[i].a;
		cin >> R[i].b;
	}
}
int fun(char ch, char*& A)
{
	for (int i = 0; i < n; i++)
		if (ch == A[i])
			return i;
	return -1;
}
//Warshall �㷨�ĺ��Ĳ���
void Warshall(char*& A, BR*& R, bool**& tR)
{
	int i, j, k;
	int x, y;
	//�ù�ϵ�����ʾ��Ԫ��ϵ R
	for (i = 0; i < m; i++)
	{
		x = fun(R[i].a, A);
		y = fun(R[i].b, A);
		tR[x][y] = 1;
	}
	//���㴫�ݱհ��Ĺ���
	for (i = 0; i < n; i++)
	{ //������
		for (j = 0; j < n; j++)
		{ //������
			if (tR[j][i] == 1)
			{
				for (k = 0; k < n; k++)
				{
					tR[j][k] = tR[j][k] + tR[i][k];
				}
			}
		}
	}
}
//�����ݱհ� t(R)�Ĺ�ϵ�����ʾת��Ϊ���ϱ�ʾ
void translation_output(char*& A, bool**& tR)
{
	cout << endl;
	cout << "R �Ĵ��ݱհ�(������ʽ)Ϊ��" << endl;
	cout << "t(R) = {";
	int i, j;
	int num = 0;//the number of 1 in matrix tR
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (tR[i][j] == 1)
				num++;
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (tR[i][j] == 1)
			{
				if (num > 1)
					cout << "<" << A[i] << "," << A[j] << ">" << ",";
				else
					cout << "<" << A[i] << "," << A[j] << ">";
				num--;
			}
	cout << "}" << endl;
}

int main()
{
	char* A;
	init_aggregation(A); //��ʼ������ A
	BR* R;
	init_BinaryRelation(R); //��ʼ����Ԫ��ϵ
	bool** tR; //���ݱհ�����
	//��̬���� bool ���͵Ķ�ά����
	tR = new(nothrow) bool* [n + 1];
	if (tR == NULL)
	{
		cout << "Failed to call memrory" << endl;
		exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		//tR[i] = new(nothrow) bool[n * n];
		tR[i] = new(nothrow) bool[n + 1];
		if (tR[i] == NULL)
		{
			cout << "Failed to call memory" << endl;
			exit(1);
		}
	}

	//��ʼ����ά����(ȫ����ֵΪ 0)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tR[i][j] = 0;
	Warshall(A, R, tR);//���� Warshall �㷨����
	translation_output(A, tR); //�����ݱհ� t(R)�Ĺ�ϵ�����ʾת��Ϊ���ϱ�ʾ
	delete[] A;
	delete[] R;
	delete[] tR;
	return 0;
}
