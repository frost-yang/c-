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
      // ��֪һά����A[n]�д������Ա������Ԫ�أ������������Ա�L
	  LinkList s;
	  L=new Node;
      L->next = NULL;                   // �Ƚ���һ���յĵ�����
      for (int i = n-1; i >=0; i-- ) {
        s = new Node;            // �����½��
        s->data = A[i];           // ��Ԫ��ֵ
        s->next = L->next;    L->next = s;    // �����ڵ�һ�����֮ǰ
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
      LinkList pa = La->next;     // pa ָ�� La �е�ǰ����Ľ��
      LinkList pb = Lb->next;     // pb ָ�� Lb�е�ǰ����Ľ��
      LinkList pc = La;           // pc ָ�� Lc ��ǰ�ı�β���ı�β
      while ( pa!=NULL && pb!=NULL ) 
	  {
        if ( pa->data < pb->data ) 
		{ // ���� La�Ľ�㣬pa ָ��La ����һ���
          pc->next = pa;  pc = pa;  pa = pa->next;
        }
        else 
		{// ����Lb�Ľ�㣬pbָ��Lb����һ���
          pc->next = pb;  pc = pb;  pb = pb->next;
        }     
      }
      if(pa)  
		  pc->next = pa;    // ����La��ʣ���
      else 
		  pc->next=pb;     // ����Lb��ʣ���
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