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

int QueuqLength(SeqQueue &Q)
{
	return (Q.rear+MAXSIZE-Q.front)%MAXSIZE;
}

int main()
{
	SeqQueue Q;
	int num=0;
	int choice=0;
	InitQueue(Q);
	do
	{
		cout<<"****************�����Ŷ�ģ��***************\n";
		cout<<"******************1----ȡ��****************\n";
		cout<<"******************2----�к�****************\n";
		cout<<"******************0----�˳�****************\n";
		cout<<"*******************************************\n";
		cout<<"��ѡ��0-2����";
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				if(QueueFull(Q))
					cout<<"Ŀǰ�Ŷ��������������Ժ���ȡ�ţ�\n";
				else
				{
					num++;
					EnQueue(Q,num);
					cout<<"�����Ŷ�����ǣ�"<<num<<endl;
					cout<<"��ǰ�滹�У�"<<QueuqLength(Q)-1<<"���ͻ�"<<endl;
				}
				break;
			}
		case 2:
			{
				if(QueueEmpty(Q))
					cout<<"Ŀǰ������Ҫ����Ŀͻ���\n";
				else
					cout<<"�����Ϊ"<<DeQueue(Q)<<"�Ŀͻ�����ҵ��"<<endl;
				break;
			}
        case 0:
			break;
		default:
			cout<<"�������\n";
		}
	} while(choice);
	return 0;
}