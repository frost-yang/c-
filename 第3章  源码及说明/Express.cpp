#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
const MAXSIZE=100;

/******�ַ���ջ******/
typedef char ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}SeqStack_char;

void InitStack( SeqStack_char &S ) 
{
      S.top = -1;                
} 

void Push( SeqStack_char &S,ElemType x) // ��ջ
{
      if(S.top==MAXSIZE-1) {cout<<" ջ����"<<endl; exit(1);}
	  S.top++;
	  S.data[S.top]=x;
} 

ElemType Pop( SeqStack_char &S) // ��ջ
{
      if(S.top==-1) {cout<<" ջ�ѿ�"<<endl; exit(1);}
	  ElemType x=S.data[S.top];
	  S.top--;
	  return x;
} 

ElemType Top(SeqStack_char &S) //ȡջ��Ԫ��
{
      if(S.top==-1) {cout<<" ջ�ѿ�"<<endl; exit(1);}
	  return S.data[S.top];
} 

bool StackEmpty(SeqStack_char &S)  //ջ��
{
	return S.top==-1;
}

bool StackFull(SeqStack_char &S)   //ջ��
{
	return S.top==MAXSIZE-1;
}

/******������ջ******/
typedef double elemType;
typedef struct
{
	elemType data[MAXSIZE];
	int top;
}SeqStack_double;

void InitStack( SeqStack_double &S ) 
{
      S.top = -1;                
} 

void Push( SeqStack_double &S,elemType x) // ��ջ
{
      if(S.top==MAXSIZE-1) {cout<<" ջ����"<<endl; exit(1);}
	  S.top++;
	  S.data[S.top]=x;
} 

elemType Pop( SeqStack_double &S) // ��ջ
{
      if(S.top==-1) {cout<<" ջ�ѿ�"<<endl; exit(1);}
	  elemType x=S.data[S.top];
	  S.top--;
	  return x;
} 

elemType Top(SeqStack_double &S) //ȡջ��Ԫ��
{
      if(S.top==-1) {cout<<" ջ�ѿ�"<<endl; exit(1);}
	  return S.data[S.top];
} 

bool StackEmpty(SeqStack_double &S)  //ջ��
{
	return S.top==-1;
}

bool StackFull(SeqStack_double &S)   //ջ��
{
	return S.top==MAXSIZE-1;
}


//��������ȼ��Ƚϱ���ʵ�֣���һ����ά����
const char precede[7][7]={{'>','>','<','<','<','>','>'},
                         {'>','>','<','<','<','>','>'},
                         {'>','>','>','>','<','>','>'},
                         {'>','>','>','>','<','>','>'},
                         {'<','<','<','<','<','=',' '},
                         {'>','>','>','>',' ','>','>'},
                         {'<','<','<','<','<',' ','='}};

//����������Ӧ�����ȼ��ȽϵĶ�ά������
int optrToInt(char ch)
{
	if(ch=='+')  return 0;
	if(ch=='-')  return 1;
	if(ch=='*')  return 2;
	if(ch=='/')  return 3;
	if(ch=='(')  return 4;
	if(ch==')')  return 5;
	if(ch=='@')  return 6;
}

//ʵ�ּӼ��˳�����ĺ���
double Operate(int left,char oper,int right)
{
	switch(oper)
	{
		case '+':  return left + right;
		case '-':  return left - right;
		case '*':  return left * right;
		case '/':                //����ʱ��Ҫ�жϷ�ĸ
			if(right==0.0)  {  cerr<<"��ĸ����Ϊ0��"; exit(1);  }
			else return left / right;
	}
}

//������ȷ����������ʽ��ֵ
double Expression_Eval()
{
	SeqStack_char   OPTR;  //������ջ
	SeqStack_double OPND;  //������ջ
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR,'@');             //���ڷ�ջջ�ף��ñȽϴ�С
	char ch=getchar();          //�Ӽ��̶���һ���ַ���ȱ�ݣ�ֻ����10���ڵ�����
	while(ch!='@'||Top(OPTR)!='@')
	{
		if(ch>='0'&&ch<='9')    //�������ǲ���������ջ
		{
			Push(OPND,ch-'0');  //�ַ������ֵ�ת��
			ch=getchar();
		}
		else   //�������ǲ�����
		{
			char pre_op=Top(OPTR);//pre_op��������ջ��Ԫ��
			switch(precede[optrToInt(pre_op)][optrToInt(ch)])  //�ж϶����Ĳ�����
			{
			   case'<'://��pre_op<ch����ch��ջ����������һ���ַ�
				   Push(OPTR,ch);
				   ch=getchar();
				   break;
			   case'='://��pre_op=ch����pre_op��ջ����������һ���ַ�
				   Pop(OPTR);
				   ch=getchar();
				   break;
			   case'>'://��pre_op>ch����pre_op��ջ�����ڲ�����ջ����ջ2�Σ����εõ�������left��right��Ȼ��������㣬��������Ľ��ѹ�������ջ��
				   double right=Pop(OPND);
				   double left=Pop(OPND);
				   pre_op=Pop(OPTR);
				   Push(OPND,Operate(left,pre_op,right));
				   break;
			}
		}
	}
	return Top(OPND);
}

int main()
{
	cout<<"��������Ҫ��ֵ���������ʽ����@�������룩��"<<endl;
	cout<<"���������ʽ�Ľ��Ϊ��"<<Expression_Eval()<<endl;
	return 0;
}