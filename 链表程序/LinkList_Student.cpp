#include <iostream.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	int no;            //学号
	char name[10];     //姓名
	char sex;          //性别
	int age;           //年龄
	char major[12];    //专业
};
typedef struct Student ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

void copy(struct Student &s1,struct Student s2)
{
	s1.no=s2.no;
	strcpy(s1.name,s2.name);
	s1.sex=s2.sex;
	s1.age=s2.age;
	strcpy(s1.major,s2.major);
}



void CreateList_L(LinkList &L, ElemType A[], int n ) 
{
      // 已知一维数组A[n]中存有线性表的数据元素，创建单链线性表L
	  LinkList s;
	  L=new Node;
      L->next = NULL;                   // 先建立一个空的单链表
      for (int i = n-1; i >=0; i-- ) {
        s = new Node;            // 生成新结点
        copy(s->data,A[i]);      //s->data = A[i];           // 赋元素值
        s->next = L->next;    L->next = s;    // 插入在第一个结点之前
      }
}

void Show_L(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		cout<<p->data.no<<" "<<p->data.name<<" "<<p->data.sex<<" "<<p->data.age<<" "<<p->data.major<<endl;
		p=p->next;
	}
	cout<<endl;
}

int ListLength_L( LinkList L ) 
{
      // L 为链表的头指针，本函数返回 L 所指链表的长度
      LinkList p=L->next; int k=0;
      while ( p ) {
        k++;  p=p->next;   // k 计非空结点数
      }
      return k;
} 


int LocateElem_L( LinkList L,ElemType e ) 
{
      LinkList p=L->next;
	  int index=1;
      while ( p && p->data.no != e.no )  //
	  {
		  p=p->next;
		  index++;
	  }
	  if(p) return index;
	  else return 0;
} 

LinkList GetElem_L( LinkList L,int i) 
{
      LinkList p=L->next;
	  int index=1;
      while ( p && index<i )  //
	  {
		  p=p->next;
		  index++;
	  }
	   return p;
} 

void ListInsert_L(LinkList L,int i,ElemType e)
{
	LinkList p=L,s; 
	int j=0;
	while (p && j<i-1)  //找到第i-1个结点的位置
	{
		p=p->next;
		j++;
	}
	if (!p)  {cout<<"插入位置非法"; exit(1);}
	else { 
        s=new Node;          //生成元素值为item的新结点s
		copy(s->data,e);      //s->data=e;  
        s->next=p->next;     //用后插法将s插入到结点p的后面
        p->next=s;
	}
}

void ListDelete_L(LinkList L,int i)
{
	LinkList p=L,q ; 
	int j=0;  
	while (p && j<i-1)  //查找第i-1个结点
    {
		p=p->next;
		j++;
    }
    if (!p || !p->next)  {cout<<"删除位置非法"; exit(1);}
    else 
	{
		q=p->next; 
		p->next=q->next;  
		delete q; 
	}
}


void DestroyList_L(LinkList &L)
{
    LinkList p=L,q;
	while(p)
	{
		q=p;
		p=p->next;
		delete q;
	}
	L=NULL;
}




int main()
{
	LinkList List;
	struct Student st[100],s;
	int n;
	int choice=0;
	do
	{
		cout<<"****************学生信息管理***************\n";
		cout<<"******************1----建立****************\n";
		cout<<"******************2----查询****************\n";
		cout<<"******************3----删除****************\n";
		cout<<"******************4----增加****************\n";
		cout<<"******************0----退出****************\n";
		cout<<"*******************************************\n";
		cout<<"请选择（0-4）：";
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				cout<<"请输入学生人数：";
				cin>>n;
				cout<<"请输入每位学生的信息：";
				for(int i=0;i<n;i++)
					cin>>st[i].no>>st[i].name>>st[i].sex>>st[i].age>>st[i].major;
				CreateList_L(List,st,n);
				cout<<"学生信息如下：\n";
				Show_L(List);
				break;
			}
		case 2:
			{
				cout<<"请输入需查询学生的学号：";
				cin>>s.no;
				int index=LocateElem_L(List, s);
				if(index==0)
					cout<<"没有此学号的学生\n";
				else
				{
					LinkList p=GetElem_L(List, index) ;
					cout<<p->data.no<<" "<<p->data.name<<" "<<p->data.sex<<" "<<p->data.age<<" "<<p->data.major<<endl;
				}
				break;
			}
		case 3:
			{
				cout<<"请输入需删除学生的学号：";
				cin>>s.no;
				int index=LocateElem_L(List, s);
				if(index==0)
					cout<<"没有此学号的学生\n";
				else
				{
					ListDelete_L(List, index);
					Show_L(List);
				}
				break;
			}
		case 4:
			{ 
				struct Student s;
				cout<<"请输入需插入学生的学号：";
				cin>>s.no;
				cout<<"请输入需插入学生的姓名：";
				cin>>s.name;
				cout<<"请输入需插入学生的性别：";
				cin>>s.sex;
				cout<<"请输入需插入学生的年龄：";
				cin>>s.age;
				cout<<"请输入需插入学生的专业：";
				cin>>s.major;
				int len=ListLength_L(List);
				ListInsert_L(List, len+1, s );
				cout<<"学生信息如下：\n";
				Show_L(List);
			}
		}
	}while(choice);

	DestroyList_L(List);

	return 0;
}
	
	

