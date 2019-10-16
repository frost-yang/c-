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

int ListLength_L( LinkList L ) 
{
      // L Ϊ�����ͷָ�룬���������� L ��ָ����ĳ���
      LinkList p=L->next; int k=0;
      while ( p ) {
        k++;  p=p->next;   // k �Ʒǿս����
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
	while (p && j<i-1)  //�ҵ���i-1������λ��
	{
		p=p->next;
		j++;
	}
	if (!p)  {cout<<"����λ�÷Ƿ�"; exit(1);}
	else { 
        s=new Node; //����Ԫ��ֵΪitem���½��s
		s->data=e;  
        s->next=p->next; //�ú�巨��s���뵽���p�ĺ���
        p->next=s;
	}
}

void ListDelete_L(LinkList L,int i)
{
	LinkList p=L,q ; 
	int j=0;  
	while (p && j<i-1)  //���ҵ�i-1�����
    {
		p=p->next;
		j++;
    }
    if (!p || !p->next)  {cout<<"ɾ��λ�÷Ƿ�"; exit(1);}
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
{//�ϲ�A��B��������B���ӵ�����A ��
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
 //����һ�仰,�ú�巨,��B���뵽���LC�ĺ���
   
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