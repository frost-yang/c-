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

void Push( SeqStack &S,ElemType x) // 入栈
{
	if(S.top==MAXSIZE-1) {cout<<" 栈已满"<<endl; exit(1);}
	S.top++;
	S.data[S.top]=x;
} 

ElemType Pop( SeqStack &S) // 出栈
{
	if(S.top==-1) {cout<<" 栈已空"<<endl; exit(1);}
	ElemType x=S.data[S.top];
	S.top--;
	return x;
} 

ElemType Top(SeqStack &S) //取栈顶元素
{
	if(S.top==-1) {cout<<" 栈已空"<<endl; exit(1);}
	return S.data[S.top];
} 

bool StackEmpty(SeqStack &S)  //栈空
{
	return S.top==-1;
}

bool StackFull(SeqStack &S)   //栈满
{
	return S.top==MAXSIZE-1;
}

void conversion (int n)    //转换成八进制
{
	SeqStack S;
	InitStack(S);      
	while (n) 
	{
        Push(S, n % 8);       
        n = n/8;              
	}
	while (!StackEmpty(S)) 
		cout<<Pop(S);
	cout<<endl;
} 

void Conversion (int n,int r) //转换成r进制
{
	SeqStack S;
	ElemType x;
	char c;
	InitStack(S);      
	while (n) 
	{
        Push(S, n % r);       
        n = n/r;              
	}
	while (!StackEmpty(S)) 
	{    
        x=Pop(S);
		if(x>=10)
			c='A'+x-10;
		else
			c='0'+x;
        cout<<c;
	}
} 

/*int main()
{
	int n;
	cout<<"请输入需要转换的十进制数：";
	cin>>n;
	cout<<"相应的八进制数为：";
	conversion(n);
	return 0;
}*/

int main()
{
	int n,r;
	cout<<"请输入需要转换的十进制数：";
	cin>>n;
	cout<<"请输入需要转换成的进制：";
	cin>>r;
	
	cout<<"相应的"<<r<<"进制数为：";
	Conversion(n,r);
	
	cout<<endl;
	return 0;
}