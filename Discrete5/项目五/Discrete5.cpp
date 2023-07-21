#include<iostream>
#include<string>
using namespace std;

typedef struct {
    int weight;     //weight of eack node
    int parent, lchild, rchild;    //pointer to parent and child
}HTNode, * HuffmanTree;

//choose 2 min node, return as idx1 and idx2
void Select(HuffmanTree& HT, int k, int& idx1, int& idx2)
{
    int min1, min2;
    min1 = 65536;
    min2 = 65536;
    for (int i = 1; i < k; i++)
    {
        //nodes' parent should be 0, make sure they haven't been chosen
        if (HT[i].parent == 0 && min1 > HT[i].weight)
        {
            if (min1 < min2)
            {
                min2 = min1;
                idx2 = idx1;
            }
            min1 = HT[i].weight;
            idx1 = i;
        }
        else if (HT[i].parent == 0 && min2 > HT[i].weight)
        {
            min2 = HT[i].weight;
            idx2 = i;
        }
    }
}

void CreatHuffmanTree(HuffmanTree& HT, int n)
{
    int m = 2 * n - 1;  //node numer of Huffman tree
    int i;
    if (n < 0)    //if tree is empty, return
        return;
    //initialize Huffman tree
    HT = new(nothrow) HTNode[m + 5];   //root: HT[m]
    if (HT == NULL)
    {
        cerr << "Failed to call memory!" << endl;
        exit(1);
    }
    //initialize nodes' pointer   (0)
    for (i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    //input weight
    cout << "输入节点: ";
    for (i = 1; i <= n; i++)
        cin >> HT[i].weight;
    //create Huffman tree, index begins from n+1 to m
    int idx1, idx2;     //index of 2 min nodes
    for (i = n + 1; i <= m; i++)
    {
        Select(HT, i, idx1, idx2);
        HT[idx1].parent = i;
        HT[idx2].parent = i;
        HT[i].lchild = idx1;
        HT[i].rchild = idx2;
        HT[i].weight = HT[idx1].weight + HT[idx2].weight;
    }
}
void outputHuffmanTree(HuffmanTree& HT, int n)
{
    for (int i = 1; i <= n; i++)
    {
        string code = "";
        //left is 0, right is 1
        int current = i;
        while (1)   //generate huffuman code
        {
            if (current == 0)
                break;
            if (HT[HT[current].parent].lchild == current)
                code = "0" + code;
            else if (HT[HT[current].parent].rchild == current)
                code = "1" + code;
            current = HT[current].parent;
        }
        cout << HT[i].weight << "：" << code << endl;
    }
}
int main()
{
    int n;  //node number
    HuffmanTree HT;
    int sum = 0;    //total cost
    cout << "请输入节点个数(必须是正整数):";
    while (1)
    {
        cin >> n;
        if (cin.fail() || n < 0)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "输入错误，请重新输入" << endl;
        }
        else
            break;
    }
    CreatHuffmanTree(HT, n);
    outputHuffmanTree(HT, n);
    delete[] HT;
    return 0;
}