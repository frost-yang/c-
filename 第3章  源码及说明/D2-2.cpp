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
		cout<<"****************银行排队模拟***************\n";
		cout<<"******************1----取号****************\n";
		cout<<"******************2----叫号****************\n";
		cout<<"******************0----退出****************\n";
		cout<<"*******************************************\n";
		cout<<"请选择（0-2）：";
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				if(QueueFull(Q))
					cout<<"目前排队人数已满，请稍后再取号！\n";
				else
				{
					num++;
					EnQueue(Q,num);
					cout<<"您的排队序号是："<<num<<endl;
					cout<<"您前面还有："<<QueuqLength(Q)-1<<"个客户"<<endl;
				}
				break;
			}
		case 2:
			{
				if(QueueEmpty(Q))
					cout<<"目前已无需要服务的客户！\n";
				else
					cout<<"请序号为"<<DeQueue(Q)<<"的客户办理业务"<<endl;
				break;
			}
        case 0:
			break;
		default:
			cout<<"输入错误！\n";
		}
	} while(choice);
	return 0;
}