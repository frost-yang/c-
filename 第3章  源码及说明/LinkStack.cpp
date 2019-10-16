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
	p->data = x;     //����һ��������Ϊx�Ľ��p
	p->next = S; 
	S=p;      //�����p����ջ��
}


ElemType Pop(LinkStack &S)
{   
	if (S==NULL)  
	{cout<<"ջ�ѿ�"; exit(1);}
	ElemType x=S->data;   //�ݴ�ջ��Ԫ��
	LinkStack p=S; 
	S=S->next;           //ɾ��ջ�����
	delete p;
	return x;
}


ElemType Top(LinkStack &S)
{   
	if (S==NULL)  
	{cout<<"ջ�ѿ�"; exit(1);}
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