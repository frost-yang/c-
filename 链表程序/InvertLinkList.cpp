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


void InvertLinkedList( LinkList &L ) // ����ͷָ��L��ָ����
{
      
      LinkList s,p = L->next;  
	  L->next = NULL;         // �����ú������ĳ�̬Ϊ�ձ�
      while ( p ) {             //  p Ϊ�����������ͷָ��
        s = p;  p = p->next;    // �� p ��ָ������ɾ����һ�����(s ���)
        s->next = L->next;  L->next = s;    // �� s �����뵽���ñ�ı�ͷ
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