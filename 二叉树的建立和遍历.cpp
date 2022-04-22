#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#define max 1000
#define OK 1
typedef char TElemType;
typedef struct BiTNode 
{ // ���ṹ
	TElemType data;
	struct BiTNode* lchild, * rchild;
	// ���Һ���ָ��
} BiTNode, * BiTree;
int CreateBiTree(BiTree& T) 
{ //������������������н���ֵ 
	char ch; 
	cin>>ch; 
	if(ch=='*') 
		T=NULL; 
	else
	{
		if(!(T=new BiTNode)) 
			exit(-2);
		T->data=ch;//���ɸ���� 
	CreateBiTree(T->lchild); //����������
	CreateBiTree(T->rchild); //���������� 
	}
	return OK;
} //A B * C * * D * *


void PreOrder(BiTree T) 
{ // ������������� 
	if (T != NULL) 
	{
		cout << T->data << " "; // ���ʽ��
		PreOrder(T->lchild); // ����������
		PreOrder(T->rchild);// ����������
	}
}

void InOrder(BiTree T)
{ // �������������
	if (T != NULL) 
	{
		InOrder(T->lchild);// ����������
		cout << T->data << " "; // ���ʽ��
		InOrder(T->rchild);// ����������
	}
}
void PostOrder(BiTree T) 
{ // �������������
	if (T != NULL) 
	{
		PostOrder(T->lchild); // ����������
		PostOrder(T->rchild);// ����������
		cout << T->data << " "; // ���ʽ��
	}
}

typedef struct Quene
{      //����˳��� 
	int front;        //��ͷָ�� 
	BiTNode* data[max];     //��Ŷ���Ԫ�� 
	int rear;        //��βָ�� 
}SqQueue;          //struct Queue �ı��� 

/*
* ���к���
*/
void initQueue(SqQueue*& q);    //��ʼ������
bool emptyQueue(SqQueue*& q);    //�ж϶��п�
bool enQueue(SqQueue*& q, BiTNode*& BT);  //���
bool deQueue(SqQueue*& q, BiTNode*& BT);  //����

//��α���
void levelOrder(BiTNode*& BT) 
{
	SqQueue* q;         //������� 
	initQueue(q);        //��ʼ������ 
	if (BT != NULL) 
	{
		enQueue(q, BT);       //���ڵ�ָ������� 
	}
	while (emptyQueue(q) != true) 
	{    //�Ӳ�Ϊ��ѭ�� 
		deQueue(q, BT);       //����ʱ�Ľڵ� 
		cout<<BT->data<<" ";     //����ڵ�洢��ֵ 
		if (BT->lchild != NULL)
		{    //������ʱ���ýڵ������ 
			enQueue(q, BT->lchild);
		}
		if (BT->rchild != NULL)
		{    //���Һ���ʱ���ýڵ������ 
			enQueue(q, BT->rchild);
		}          //һ��һ��İѽڵ������� 
	}            //��û�к��ӽڵ�ʱ�Ͳ���ѭ�� 
}

//��ʼ������
void initQueue(SqQueue*& q) 
{
	q = (SqQueue*)malloc(sizeof(SqQueue)); //����һ���ռ� 
	q->front = q->rear = -1;    //�� -1 
}

//�ж϶����Ƿ�Ϊ��
bool emptyQueue(SqQueue*& q)
{
	if (q->front == q->rear)
	{    //��ָ���βָ����ȣ�˵��Ϊ�� 
		return true;      //������ 
	}
	else
	{
		return false;      //���ؼ� 
	}
}

//������
bool enQueue(SqQueue*& q, BiTNode*& BT)
{
	if (q->rear == max - 1) 
	{   //�ж϶����Ƿ����� 
		return false;      //���ؼ� 
	}
	q->rear++;        //ͷָ��� 1 
	q->data[q->rear] = BT;     //��ֵ 
	return true;       //������ 
}

//������ 
bool deQueue(SqQueue*& q, BiTNode*& BT)
{
	if (q->front == q->rear)
	{    //�ж��Ƿ���� 
		return false;      //���ؼ� 
	}
	q->front++;        //βָ��� 1 
	BT = q->data[q->front];     //ȡֵ 
	return true;       //������ 
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

