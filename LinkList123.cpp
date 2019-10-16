#include <iostream.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*LinkList;

void InitList_L(LinkList &L)
{
	L=new Node;
	L->next=NULL;
}

void CreateList_L(LinkList &L, ElemType A[], int n ) 
{
      // 已知一维数组A[n]中存有线性表的数据元素，创建单链线性表L
	  LinkList s;
	  L=new Node;
      L->next = NULL;                   // 先建立一个空的单链表
      for (int i = n-1; i >=0; i-- ) {
        s = new Node;            // 生成新结点
        s->data = A[i];           // 赋元素值
        s->next = L->next;    L->next = s;    // 插入在第一个结点之前
      }
}

void Show_L(LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		cout<<p->data<<" ";
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
      while ( p && p->data != e ) 
	  {
		  p=p->next;
		  index++;
	  }
	  if(p) return index;
	  else return 0;
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
        s=new Node; //生成元素值为item的新结点s
		s->data=e;  
        s->next=p->next; //用后插法将s插入到结点p的后面
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

void link(LinkList  &A,LinkList &B)
{//合并A，B链表，链表B链接到链表A 后方
   LinkList LC;
   int i;

i=ListLength_L(A) ;
cout<<i<<"***";
	LinkList p=A->next;

	while(i--)
	{   LC=p;
		cout<<p->data<<" ";
		p=p->next;
	
	}
 cout<<"\n********************************\n";     
 //补充一句话,用后插法,将B插入到结点LC的后面
   
cout<<"\n********************************\n";
}


int main()
{
	ElemType a[]={1,2,3,4,5,6,7,8,9};
	LinkList LA;
	CreateList_L(LA,a,9);
	Show_L(LA);
	cout<<ListLength_L(LA)<<endl;
LinkList LB;
	InitList_L(LB);
	for(int i=0;i<5;i++)
		ListInsert_L(LB,1,i);
	Show_L(LB);
	link(LA,LB);
	Show_L(LA);
/*	cout<<LocateElem_L(LA,5);cout<<endl;

	ListInsert_L(LA,1,66);
	Show_L(LA);

	ListDelete_L(LA,1);
	Show_L(LA);



	DestroyList_L(LA);

	
*/


	return 0;
}