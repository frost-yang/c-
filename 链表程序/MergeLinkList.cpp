#include <iostream.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

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

void MergeLinkList( LinkList &La,LinkList &Lb ) 
{
      LinkList pa = La->next;     // pa 指向 La 中当前考察的结点
      LinkList pb = Lb->next;     // pb 指向 Lb中当前考察的结点
      LinkList pc = La;           // pc 指向 Lc 当前的表尾结点的表尾
      while ( pa!=NULL && pb!=NULL ) 
	  {
        if ( pa->data < pb->data ) 
		{ // 链接 La的结点，pa 指向La 中下一结点
          pc->next = pa;  pc = pa;  pa = pa->next;
        }
        else 
		{// 链接Lb的结点，pb指向Lb中下一结点
          pc->next = pb;  pc = pb;  pb = pb->next;
        }     
      }
      if(pa)  
		  pc->next = pa;    // 链接La的剩余段
      else 
		  pc->next=pb;     // 链接Lb的剩余段
      delete Lb;                         
} 

int main()
{
	ElemType a[]={1,3,5},b[]={2,4,6,8,9};
	LinkList LA,LB;
	CreateList_L(LA,a,3);
	Show_L(LA);
	CreateList_L(LB,b,5);
	Show_L(LB);

	MergeLinkList(LA,LB);
	Show_L(LA);

	DestroyList_L(LA);

	return 0;
}