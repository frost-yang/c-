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


void InvertLinkedList( LinkList &L ) // 逆置头指针L所指链表
{
      
      LinkList s,p = L->next;  
	  L->next = NULL;         // 设逆置后的链表的初态为空表
      while ( p ) {             //  p 为待逆置链表的头指针
        s = p;  p = p->next;    // 从 p 所指链表中删除第一个结点(s 结点)
        s->next = L->next;  L->next = s;    // 将 s 结点插入到逆置表的表头
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
	ElemType a[]={1,2,3,4,5,6,7,8,9};
	LinkList LA;
	CreateList_L(LA,a,9);
	Show_L(LA);

	InvertLinkedList(LA);
	Show_L(LA);

	DestroyList_L(LA);

	return 0;
}