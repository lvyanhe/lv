#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#define max 1000
#define OK 1
typedef char TElemType;
typedef struct BiTNode 
{ // 结点结构
	TElemType data;
	struct BiTNode* lchild, * rchild;
	// 左右孩子指针
} BiTNode, * BiTree;
int CreateBiTree(BiTree& T) 
{ //按照先序输入二叉树中结点的值 
	char ch; 
	cin>>ch; 
	if(ch=='*') 
		T=NULL; 
	else
	{
		if(!(T=new BiTNode)) 
			exit(-2);
		T->data=ch;//生成根结点 
	CreateBiTree(T->lchild); //构造左子树
	CreateBiTree(T->rchild); //构造右子树 
	}
	return OK;
} //A B * C * * D * *


void PreOrder(BiTree T) 
{ // 先序遍历二叉树 
	if (T != NULL) 
	{
		cout << T->data << " "; // 访问结点
		PreOrder(T->lchild); // 遍历左子树
		PreOrder(T->rchild);// 遍历右子树
	}
}

void InOrder(BiTree T)
{ // 中序遍历二叉树
	if (T != NULL) 
	{
		InOrder(T->lchild);// 遍历左子树
		cout << T->data << " "; // 访问结点
		InOrder(T->rchild);// 遍历右子树
	}
}
void PostOrder(BiTree T) 
{ // 后序遍历二叉树
	if (T != NULL) 
	{
		PostOrder(T->lchild); // 遍历左子树
		PostOrder(T->rchild);// 遍历右子树
		cout << T->data << " "; // 访问结点
	}
}

typedef struct Quene
{      //定义顺序队 
	int front;        //队头指针 
	BiTNode* data[max];     //存放队中元素 
	int rear;        //队尾指针 
}SqQueue;          //struct Queue 的别名 

/*
* 队列函数
*/
void initQueue(SqQueue*& q);    //初始化对立
bool emptyQueue(SqQueue*& q);    //判断队列空
bool enQueue(SqQueue*& q, BiTNode*& BT);  //入队
bool deQueue(SqQueue*& q, BiTNode*& BT);  //出队

//层次遍历
void levelOrder(BiTNode*& BT) 
{
	SqQueue* q;         //定义队列 
	initQueue(q);        //初始化队列 
	if (BT != NULL) 
	{
		enQueue(q, BT);       //根节点指针进队列 
	}
	while (emptyQueue(q) != true) 
	{    //队不为空循环 
		deQueue(q, BT);       //出队时的节点 
		cout<<BT->data<<" ";     //输出节点存储的值 
		if (BT->lchild != NULL)
		{    //有左孩子时将该节点进队列 
			enQueue(q, BT->lchild);
		}
		if (BT->rchild != NULL)
		{    //有右孩子时将该节点进队列 
			enQueue(q, BT->rchild);
		}          //一层一层的把节点存入队列 
	}            //当没有孩子节点时就不再循环 
}

//初始化队列
void initQueue(SqQueue*& q) 
{
	q = (SqQueue*)malloc(sizeof(SqQueue)); //分配一个空间 
	q->front = q->rear = -1;    //置 -1 
}

//判断队列是否为空
bool emptyQueue(SqQueue*& q)
{
	if (q->front == q->rear)
	{    //首指针和尾指针相等，说明为空 
		return true;      //返回真 
	}
	else
	{
		return false;      //返回假 
	}
}

//进队列
bool enQueue(SqQueue*& q, BiTNode*& BT)
{
	if (q->rear == max - 1) 
	{   //判断队列是否满了 
		return false;      //返回假 
	}
	q->rear++;        //头指针加 1 
	q->data[q->rear] = BT;     //传值 
	return true;       //返回真 
}

//出队列 
bool deQueue(SqQueue*& q, BiTNode*& BT)
{
	if (q->front == q->rear)
	{    //判断是否空了 
		return false;      //返回假 
	}
	q->front++;        //尾指针加 1 
	BT = q->data[q->front];     //取值 
	return true;       //返回真 
}
int main()
{
	BiTree T;
	CreateBiTree(T);
	PreOrder(T);
	cout << endl;
	InOrder(T);
	cout << endl;
	PostOrder(T);
	cout << endl;
	levelOrder(T);
	system("pause");
	return 0;
}

