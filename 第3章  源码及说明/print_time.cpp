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

void EnQueue( SeqQueue &Q,ElemType x) // ���
{
      if((Q.rear+1)%MAXSIZE==Q.front) 
	  {cout<<" ��������"<<endl; exit(1);}
	  Q.rear=(Q.rear+1)%MAXSIZE;
	  Q.data[Q.rear]=x;
	  
} 

ElemType DeQueue( SeqQueue &Q) // ����
{
      if(Q.front==Q.rear) 
	  {cout<<" �����ѿ�"<<endl; exit(1);}
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

int QueueLength(SeqQueue &Q)
{
	return (Q.rear+MAXSIZE-Q.front)%MAXSIZE;
}

ElemType QueueMax(SeqQueue &Q)
{
	int i;
	int f=(Q.front+1)%MAXSIZE;
	ElemType max=Q.data[f];
	for(i=1;i<=QueueLength(Q);i++)
		if(max<Q.data[f+i])
			max=Q.data[f+i];
	return max;
}


int main()
{
	SeqQueue Q;
	int time=0;
	ElemType e;
	int x,flag,index;

	InitQueue(Q);
	cout<<"�������ӡ���У���-1������";
	cin>>e;
	while(e!=-1)
	{
		EnQueue(Q,e);
		cin>>e;
	}

	cout<<"���������ӡ�����ڴ�ӡ�����е�λ�ã�";
	cin>>x;
	if(x>QueueLength(Q))
	{
		cout<<"�����λ������\n";
		return 0;
	}
	flag=x;

	while(!QueueEmpty(Q))
	{
		e=DeQueue(Q);
		flag--;
		if(e<QueueMax(Q))
		{
			EnQueue(Q,e);
			if(flag==0)
				flag=QueueLength(Q);
		}
		else
		{
			time++;	
			if(flag==0)
				break;
		}
	}

	cout<<"��ɴ�ӡ��������ʱ��Ϊ��"<<time<<"min.\n";
	return 0;
}