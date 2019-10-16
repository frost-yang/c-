#include <iostream.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	int no;            //ѧ��
	char name[10];     //����
	char sex;          //�Ա�
	int age;           //����
	char major[12];    //רҵ
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
      // ��֪һά����A[n]�д������Ա������Ԫ�أ������������Ա�L
	  LinkList s;
	  L=new Node;
      L->next = NULL;                   // �Ƚ���һ���յĵ�����
      for (int i = n-1; i >=0; i-- ) {
        s = new Node;            // �����½��
        copy(s->data,A[i]);      //s->data = A[i];           // ��Ԫ��ֵ
        s->next = L->next;    L->next = s;    // �����ڵ�һ�����֮ǰ
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
	while (p && j<i-1)  //�ҵ���i-1������λ��
	{
		p=p->next;
		j++;
	}
	if (!p)  {cout<<"����λ�÷Ƿ�"; exit(1);}
	else { 
        s=new Node;          //����Ԫ��ֵΪitem���½��s
		copy(s->data,e);      //s->data=e;  
        s->next=p->next;     //�ú�巨��s���뵽���p�ĺ���
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




int main()
{
	LinkList List;
	struct Student st[100],s;
	int n;
	int choice=0;
	do
	{
		cout<<"****************ѧ����Ϣ����***************\n";
		cout<<"******************1----����****************\n";
		cout<<"******************2----��ѯ****************\n";
		cout<<"******************3----ɾ��****************\n";
		cout<<"******************4----����****************\n";
		cout<<"******************0----�˳�****************\n";
		cout<<"*******************************************\n";
		cout<<"��ѡ��0-4����";
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				cout<<"������ѧ��������";
				cin>>n;
				cout<<"������ÿλѧ������Ϣ��";
				for(int i=0;i<n;i++)
					cin>>st[i].no>>st[i].name>>st[i].sex>>st[i].age>>st[i].major;
				CreateList_L(List,st,n);
				cout<<"ѧ����Ϣ���£�\n";
				Show_L(List);
				break;
			}
		case 2:
			{
				cout<<"���������ѯѧ����ѧ�ţ�";
				cin>>s.no;
				int index=LocateElem_L(List, s);
				if(index==0)
					cout<<"û�д�ѧ�ŵ�ѧ��\n";
				else
				{
					LinkList p=GetElem_L(List, index) ;
					cout<<p->data.no<<" "<<p->data.name<<" "<<p->data.sex<<" "<<p->data.age<<" "<<p->data.major<<endl;
				}
				break;
			}
		case 3:
			{
				cout<<"��������ɾ��ѧ����ѧ�ţ�";
				cin>>s.no;
				int index=LocateElem_L(List, s);
				if(index==0)
					cout<<"û�д�ѧ�ŵ�ѧ��\n";
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
				cout<<"�����������ѧ����ѧ�ţ�";
				cin>>s.no;
				cout<<"�����������ѧ����������";
				cin>>s.name;
				cout<<"�����������ѧ�����Ա�";
				cin>>s.sex;
				cout<<"�����������ѧ�������䣺";
				cin>>s.age;
				cout<<"�����������ѧ����רҵ��";
				cin>>s.major;
				int len=ListLength_L(List);
				ListInsert_L(List, len+1, s );
				cout<<"ѧ����Ϣ���£�\n";
				Show_L(List);
			}
		}
	}while(choice);

	DestroyList_L(List);

	return 0;
}
	
	

