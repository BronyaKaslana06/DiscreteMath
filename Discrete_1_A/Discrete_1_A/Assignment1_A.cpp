#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int a[4];
	int p = -1, q = -1;
	char s;
tt:cout<<"***************************************\n";  //����
	cout<<"**                                   **\n";
	cout<<"**        ��ӭ�����߼��������       **\n";
	cout<<"**                                   **\n";
	cout<<"***************************************\n\n";
	while (1)
	{
		cout << "������P��ֵ��0��1��,�Իس�����:";
		cin >> p;
		if (cin.fail())
		{
			cout << "������Ϸ�������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (p != 0 && p != 1)
		{
			cout << "������Ϸ�������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}
	cout << endl;
	while (1)
	{
		cout << "������Q��ֵ��0��1��,�Իس�����:";
		cin >> q;
		if (cin.fail())
		{
			cout << "������Ϸ�������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (q != 0 && q != 1)
		{
			cout << "������Ϸ�������" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}
	a[0] = p && q;  //������
	a[1] = p || q;  //������
	a[2] = (!p) || q;  //�̺����㣬����ת��Ϊ������ʽ
	a[3] = ((!p) || q) && ((!q) || p);  //��ֵ���㣬����ת��Ϊ������ʽ
	cout << "\n\n��ȡ:\n       P/\\Q = " << a[0] << endl;  //������
	cout << "��ȡ:\n       P\\/Q = " << a[1] << endl;
	cout << "����:\n       P->Q = " << a[2] << endl;
	cout << "˫����:\n       P<->Q = " << a[3] << endl;
bb:cout << "\n�Ƿ��������?��y/n��"; //ѯ���Ƿ��������
	cin >> s;
	if (s == 'y' || s == 'n')
	{
		if (s == 'y')
		{
			system("cls");  //����
			goto tt;  //���ض���
		}
		else
		{
			cout << "��ӭ�´��ٴ�ʹ��!\n";  //�˳�
			exit(0);
		}
	}
	else
	{
		cout << "�������,����������!\n"; //����У��
		goto bb;
	}
	return 0;
}
