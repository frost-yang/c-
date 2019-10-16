#include <iostream.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct
{
	Node *front;
	Node *rear;
}LinkQueue;


void InitQueue( LinkQueue &Q ) 
{
      Q.front=Q.rear=new Node;
	  Q.front->next=NULL;
} 

void EnQueue( LinkQueue &Q,ElemType x) // 入队
{
      Node *p=new Node;
	  p->data=x;
	  p->next=NULL;
	  Q.rear->next=p;
	  Q.rear=p;	  
} 

ElemType DeQueue( LinkQueue &Q) // 出队
{
      if(Q.front==Q.rear) 
		  {cout<<" 队列已空"<<endl; exit(1);}
	  Node *p=Q.front->next;
	  ElemType x=p->data;
	  Q.front->next=p->next;
	  if(Q.rear==p)
		  Q.rear=Q.front;
	  delete p;
	  return x;	  
} 


bool QueueEmpty(LinkQueue &Q)
{
	return Q.front==Q.rear;
}

void DestroyListQueue(LinkQueue &Q)
{
    while(Q.front)
	{
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
}


int main()
{
	LinkQueue q;
	InitQueue(q);
	ElemType a[]={1,2,3,4,5,6};
	for(int i=0;i<6;i++)
		EnQueue(q,a[i]);
	while(!QueueEmpty(q))
	{
		cout<<DeQueue(q)<<endl;
	}
	DestroyListQueue(q);
	
	return 0;
}