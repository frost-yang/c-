#include <iostream.h>
#include <stdlib.h>
const MAXSIZE=100;
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

void InitQueue( SeqQueue &Q ) 
{
      Q.front=Q.rear = 0;                
} 

void EnQueue( SeqQueue &Q,ElemType x) // 入队
{
      if((Q.rear+1)%MAXSIZE==Q.front) 
	  {cout<<" 队列已满"<<endl; exit(1);}
	  Q.rear=(Q.rear+1)%MAXSIZE;
	  Q.data[Q.rear]=x;
	  
} 

ElemType DeQueue( SeqQueue &Q) // 出队
{
      if(Q.front==Q.rear) 
	  {cout<<" 队列已空"<<endl; exit(1);}
	  Q.front=(Q.front+1)%MAXSIZE;
	  ElemType x=Q.data[Q.front];
	  return x;
	  
} 


bool QueueEmpty(SeqQueue &Q)
{
	return Q.front==Q.rear;
}

bool QueueFull(SeqQueue &Q)
{
	return (Q.rear+1)%MAXSIZE==Q.front;
}

