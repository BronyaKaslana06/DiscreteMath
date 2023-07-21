#include<iostream>
#define MAX_VEX  20
#define MAX_EDGE 380  
using namespace std;

struct Edge  //�߽ṹ��
{
	int start;
	int end;
	int weight;
};

int ini_graph(int& vex, int& edge, Edge* gragh);
void sort_edge(Edge* edges, int edge);//����Ȩֵ��С���ߴ�С��������
int find_root(int parent[], int n);//Ѱ�Ҹ��ڵ����ж��Ƿ���һ��������

int main()
{
	int vex; //�������
	int edge; //�ߵĸ���
	Edge graph[MAX_EDGE];
	while (ini_graph(vex, edge, graph))		//�߼������ʼ��ͼ
	{
		sort_edge(graph, edge);	//ͨ������ﵽ����С����ͬ��Ч��
		int roots[MAX_VEX];		//���鼯�ĸ�����
		Edge MST[MAX_EDGE] = { 0 };   //��С������
		int count = 0;
		for (int i = 0; i < vex; i++)
			roots[i] = -1;		//��ʼ��root���� -1������ڵ�
		for (int i = 0; i < MAX_EDGE; i++)
		{
			int vex_m = find_root(roots, graph[i].start);
			int vex_n = find_root(roots, graph[i].end);
			if (vex_m != vex_n)//���ߵĸ��ڵ㲻ͬ˵���������ڲ�ͬ�ļ��ϣ������γɻ�·
			{
				MST[count] = graph[i];//���˱߷���MST����
				count++;
				roots[vex_m] = vex_n;//���鼯�ĺϲ�����
			}
			if (count == vex - 1)//��С���Ѿ����ɣ��˳�ѭ��
				break;
		}
		int sum = 0;	//�ܺķ�
		for (int i = 0; i < vex - 1; i++)
		{
			cout << "��С�ķ��ǣ�" << MST[i].start << "��" << MST[i].end << "����ȨΪ��" << MST[i].weight << endl;
			sum += MST[i].weight;
		}
		cout << "��С�ܺķ�Ϊ��" << sum << endl;
	}
	return 0;
}

int ini_graph(int& vex, int& edge, Edge* graph)	//����1�������������0�������
{
	cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������������0����):\n";
	while (1)
	{
		cin >> vex >> edge;
		if (vex < 0 || edge < 0 || cin.fail())
		{
			cout << "������Ǹ�����" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}
	if (vex == 0 && edge == 0)
		return 0;
	cout << "�����������ߵĽڵ�����Լ����ǵ�Ȩֵ(�Կո�ָ�������):\n";
	for (int i = 0; i < edge; i++)
	{
		while (1)
		{
			cin >> graph[i].start >> graph[i].end >> graph[i].weight;
			if (!(graph[i].start >= 1 && graph[i].start <= vex) || !(graph[i].end >= 1 && graph[i].end <= vex) || cin.fail())
			{
				cout << "��������ȷ������" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else
				break;
		}
	}
	return 1;
}

void sort_edge(Edge* edges_arr, int edge)
{
	Edge temp;
	for (int i = 0; i < edge; i++)
	{
		for (int k = 0; k < edge - i - 1; k++)
		{
			if (edges_arr[k].weight > edges_arr[k + 1].weight)
			{
				temp = edges_arr[k];
				edges_arr[k] = edges_arr[k + 1];
				edges_arr[k + 1] = temp;
			}
		}
	}
}
//���鼯��Ѱ������
int find_root(int roots[], int n)
{
	while (roots[n] > -1)  
		n = roots[n];
	return n;
}