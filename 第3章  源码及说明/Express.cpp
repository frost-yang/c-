#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
const MAXSIZE=100;

/******字符型栈******/
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

void Push( SeqStack_char &S,ElemType x) // 入栈
{
      if(S.top==MAXSIZE-1) {cout<<" 栈已满"<<endl; exit(1);}
	  S.top++;
	  S.data[S.top]=x;
} 

ElemType Pop( SeqStack_char &S) // 出栈
{
      if(S.top==-1) {cout<<" 栈已空"<<endl; exit(1);}
	  ElemType x=S.data[S.top];
	  S.top--;
	  return x;
} 

ElemType Top(SeqStack_char &S) //取栈顶元素
{
      if(S.top==-1) {cout<<" 栈已空"<<endl; exit(1);}
	  return S.data[S.top];
} 

bool StackEmpty(SeqStack_char &S)  //栈空
{
	return S.top==-1;
}

bool StackFull(SeqStack_char &S)   //栈满
{
	return S.top==MAXSIZE-1;
}

/******浮点型栈******/
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

void Push( SeqStack_double &S,elemType x) // 入栈
{
      if(S.top==MAXSIZE-1) {cout<<" 栈已满"<<endl; exit(1);}
	  S.top++;
	  S.data[S.top]=x;
} 

elemType Pop( SeqStack_double &S) // 出栈
{
      if(S.top==-1) {cout<<" 栈已空"<<endl; exit(1);}
	  elemType x=S.data[S.top];
	  S.top--;
	  return x;
} 

elemType Top(SeqStack_double &S) //取栈顶元素
{
      if(S.top==-1) {cout<<" 栈已空"<<endl; exit(1);}
	  return S.data[S.top];
} 

bool StackEmpty(SeqStack_double &S)  //栈空
{
	return S.top==-1;
}

bool StackFull(SeqStack_double &S)   //栈满
{
	return S.top==MAXSIZE-1;
}


//运算符优先级比较表格的实现，用一个二维数组
const char precede[7][7]={{'>','>','<','<','<','>','>'},
                         {'>','>','<','<','<','>','>'},
                         {'>','>','>','>','<','>','>'},
                         {'>','>','>','>','<','>','>'},
                         {'<','<','<','<','<','=',' '},
                         {'>','>','>','>',' ','>','>'},
                         {'<','<','<','<','<',' ','='}};

//将操作符对应到优先级比较的二维数组中
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

//实现加减乘除计算的函数
double Operate(int left,char oper,int right)
{
	switch(oper)
	{
		case '+':  return left + right;
		case '-':  return left - right;
		case '*':  return left * right;
		case '/':                //除法时需要判断分母
			if(right==0.0)  {  cerr<<"分母不能为0！"; exit(1);  }
			else return left / right;
	}
}

//算符优先法求算术表达式的值
double Expression_Eval()
{
	SeqStack_char   OPTR;  //操作符栈
	SeqStack_double OPND;  //操作数栈
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR,'@');             //放在符栈栈底，好比较大小
	char ch=getchar();          //从键盘读入一个字符，缺陷：只能做10以内的运算
	while(ch!='@'||Top(OPTR)!='@')
	{
		if(ch>='0'&&ch<='9')    //读到的是操作数则入栈
		{
			Push(OPND,ch-'0');  //字符到数字的转换
			ch=getchar();
		}
		else   //读到的是操作符
		{
			char pre_op=Top(OPTR);//pre_op操作符的栈顶元素
			switch(precede[optrToInt(pre_op)][optrToInt(ch)])  //判断读到的操作符
			{
			   case'<'://若pre_op<ch，则将ch入栈，并读入下一个字符
				   Push(OPTR,ch);
				   ch=getchar();
				   break;
			   case'='://若pre_op=ch，则将pre_op出栈，并读入下一个字符
				   Pop(OPTR);
				   ch=getchar();
				   break;
			   case'>'://若pre_op>ch，则将pre_op出栈，并在操作数栈中退栈2次，依次得到操作数left和right，然后进行运算，并将运算的结果压入操作数栈中
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
	cout<<"请输入需要求值的算术表达式（以@结束输入）："<<endl;
	cout<<"该算术表达式的结果为："<<Expression_Eval()<<endl;
	return 0;
}