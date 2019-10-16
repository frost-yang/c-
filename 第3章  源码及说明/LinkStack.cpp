#include <iostream.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}*LinkStack;


void InitStack(LinkStack &S)
{
	S=NULL;
}


void Push(LinkStack &S, ElemType x ) 
{
    LinkStack p=new Node;    
	p->data = x;     //申请一个数据域为x的结点p
	p->next = S; 
	S=p;      //将结点p插在栈顶
}


ElemType Pop(LinkStack &S)
{   
	if (S==NULL)  
	{cout<<"栈已空"; exit(1);}
	ElemType x=S->data;   //暂存栈顶元素
	LinkStack p=S; 
	S=S->next;           //删除栈顶结点
	delete p;
	return x;
}


ElemType Top(LinkStack &S)
{   
	if (S==NULL)  
	{cout<<"栈已空"; exit(1);}
	return  S->data;
}


bool StackEmpty(LinkStack &S)
{
	return  S==NULL;
}

void DestroyListStack(LinkStack &S)
{
    LinkStack p;
	while(S)
	{
		p=S;
		S=S->next;
		delete p;
	}
}


int main()
{
	LinkStack s;
	InitStack(s);
	ElemType a[]={1,2,3,4,5,6};
	for(int i=0;i<6;i++)
		Push(s,a[i]);
	while(!StackEmpty(s))
	{
		cout<<Pop(s)<<endl;
	}

	DestroyListStack(s);
	
	return 0;
}