#include <iostream.h>
#include <stdlib.h>
const MAXSIZE=100;

typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}SeqStack;

void InitStack( SeqStack &S ) 
{
      S.top = -1;                
} 

void Push( SeqStack &S,ElemType x) // »Î’ª
{
      if(S.top==MAXSIZE-1) {cout<<" ’ª“—¬˙"<<endl; exit(1);}
	  S.top++;
	  S.data[S.top]=x;
} 

ElemType Pop( SeqStack &S) // ≥ˆ’ª
{
      if(S.top==-1) {cout<<" ’ª“—ø’"<<endl; exit(1);}
	  ElemType x=S.data[S.top];
	  S.top--;
	  return x;
} 

ElemType Top(SeqStack &S) //»°’ª∂•‘™Àÿ
{
      if(S.top==-1) {cout<<" ’ª“—ø’"<<endl; exit(1);}
	  return S.data[S.top];
} 

bool StackEmpty(SeqStack &S)  //’ªø’
{
	return S.top==-1;
}

bool StackFull(SeqStack &S)   //’ª¬˙
{
	return S.top==MAXSIZE-1;
}


int main()
{
	SeqStack s;
	InitStack(s);
	ElemType a[]={1,2,3,4,5,6};
	for(int i=0;i<6;i++)
		Push( s,a[i]);
	while(!StackEmpty(s))
	{
		cout<<Pop(s)<<endl;
	}

	Push( s,100);
	Push( s,500);
	Push( s,600);
	Pop(s);
	Push( s,400);
	Push( s,900);	
	Push( s,10);
	Pop(s);
		cout<<Pop(s)<<endl;
	return 0;
}