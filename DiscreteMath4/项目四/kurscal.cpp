#include<iostream>
#define MAX_VEX  20
#define MAX_EDGE 380  
using namespace std;

struct Edge  //边结构体
{
	int start;
	int end;
	int weight;
};

int ini_graph(int& vex, int& edge, Edge* gragh);
void sort_edge(Edge* edges, int edge);//根据权值大小将边从小到大排序
int find_root(int parent[], int n);//寻找根节点以判断是否在一个集合中

int main()
{
	int vex; //顶点个数
	int edge; //边的个数
	Edge graph[MAX_EDGE];
	while (ini_graph(vex, edge, graph))		//边集数组初始化图
	{
		sort_edge(graph, edge);	//通过排序达到与最小堆相同的效果
		int roots[MAX_VEX];		//并查集的根数组
		Edge MST[MAX_EDGE] = { 0 };   //最小生成树
		int count = 0;
		for (int i = 0; i < vex; i++)
			roots[i] = -1;		//初始化root数组 -1代表根节点
		for (int i = 0; i < MAX_EDGE; i++)
		{
			int vex_m = find_root(roots, graph[i].start);
			int vex_n = find_root(roots, graph[i].end);
			if (vex_m != vex_n)//两者的根节点不同说明他们属于不同的集合，不会形成回路
			{
				MST[count] = graph[i];//将此边放入MST数组
				count++;
				roots[vex_m] = vex_n;//并查集的合并操作
			}
			if (count == vex - 1)//最小树已经生成，退出循环
				break;
		}
		int sum = 0;	//总耗费
		for (int i = 0; i < vex - 1; i++)
		{
			cout << "最小耗费是：" << MST[i].start << "和" << MST[i].end << "，边权为：" << MST[i].weight << endl;
			sum += MST[i].weight;
		}
		cout << "最小总耗费为：" << sum << endl;
	}
	return 0;
}

int ini_graph(int& vex, int& edge, Edge* graph)	//返回1代表继续，返回0代表结束
{
	cout << "请输入所求图的顶点数目和边的数目(以空格分隔各个数，输入两个0结束):\n";
	while (1)
	{
		cin >> vex >> edge;
		if (vex < 0 || edge < 0 || cin.fail())
		{
			cout << "请输入非负整数" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}
	if (vex == 0 && edge == 0)
		return 0;
	cout << "请输入两条边的节点序号以及它们的权值(以空格分隔各个数):\n";
	for (int i = 0; i < edge; i++)
	{
		while (1)
		{
			cin >> graph[i].start >> graph[i].end >> graph[i].weight;
			if (!(graph[i].start >= 1 && graph[i].start <= vex) || !(graph[i].end >= 1 && graph[i].end <= vex) || cin.fail())
			{
				cout << "请输入正确的数字" << endl;
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
//并查集的寻根操作
int find_root(int roots[], int n)
{
	while (roots[n] > -1)  
		n = roots[n];
	return n;
}