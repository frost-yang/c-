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

void Push( SeqStack &S,ElemType x) // ��ջ
{
	if(S.top==MAXSIZE-1) {cout<<" ջ����"<<endl; exit(1);}
	S.top++;
	S.data[S.top]=x;
} 

ElemType Pop( SeqStack &S) // ��ջ
{
	if(S.top==-1) {cout<<" ջ�ѿ�"<<endl; exit(1);}
	ElemType x=S.data[S.top];
	S.top--;
	return x;
} 

ElemType Top(SeqStack &S) //ȡջ��Ԫ��
{
	if(S.top==-1) {cout<<" ջ�ѿ�"<<endl; exit(1);}
	return S.data[S.top];
} 

bool StackEmpty(SeqStack &S)  //ջ��
{
	return S.top==-1;
}

bool StackFull(SeqStack &S)   //ջ��
{
	return S.top==MAXSIZE-1;
}

void conversion (int n)    //ת���ɰ˽���
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

void Conversion (int n,int r) //ת����r����
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
	cout<<"��������Ҫת����ʮ��������";
	cin>>n;
	cout<<"��Ӧ�İ˽�����Ϊ��";
	conversion(n);
	return 0;
}*/

int main()
{
	int n,r;
	cout<<"��������Ҫת����ʮ��������";
	cin>>n;
	cout<<"��������Ҫת���ɵĽ��ƣ�";
	cin>>r;
	
	cout<<"��Ӧ��"<<r<<"������Ϊ��";
	Conversion(n,r);
	
	cout<<endl;
	return 0;
}