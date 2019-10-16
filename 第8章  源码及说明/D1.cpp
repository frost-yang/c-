#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream.h>

const MAX=500;
typedef struct 
{
	char name[10];       //����
    char mobilephone[12]; //�ֻ�
    char home[9];        //լ��
    char office[9];        //�칫�绰
    char email[20];       //�����ʼ�
} Phone;


typedef struct BiNode
{
	Phone key;
	struct BiNode *lchild,*rchild;
} *BiSortTree;


void Insert(BiSortTree &T,Phone k) //����
{
	if(T==NULL)
	{
		T=new BiNode;
		strcpy(T->key.name,k.name);
		strcpy(T->key.mobilephone,k.mobilephone);
		strcpy(T->key.home,k.home);
		strcpy(T->key.office,k.office);
		strcpy(T->key.email,k.email);
		T->lchild=T->rchild=NULL;
	}
	else if(strcmp(k.name,T->key.name)<0)
		Insert(T->lchild,k);
	else
		Insert(T->rchild,k);
}

void CreateBiSortTree(BiSortTree &T,Phone a[],int n) //����
{
	int i;
	for(i=0;i<n;i++)
		Insert(T,a[i]);
}

void Inorder(BiSortTree T)  //�������
{
      if (T) 
	  {             
        Inorder(T->lchild);   
		cout<<T->key.name<<" "<<T->key.mobilephone<<" "<<T->key.home<<" "<<T->key.office<<" "<<T->key.email<<" "<<endl;          
        Inorder(T->rchild);   
      }
}


BiSortTree BST_Search(BiSortTree T,Phone k)//�ݹ����
{
	if(T==NULL)
		return NULL;
	else if(strcmp(k.name,T->key.name)==0)
		return T;
	else if(strcmp(k.name,T->key.name)<0)
		return BST_Search(T->lchild,k);
	else
		return BST_Search(T->rchild,k);
}


void Delete(BiSortTree &T, Phone k) //ɾ��
{
	BiSortTree temp;
	if(T!=NULL)
	{
		if(strcmp(k.name,T->key.name)<0)  Delete(T->lchild,k);          //������������ɾ��
		else if(strcmp(k.name,T->key.name)>0)  Delete(T->rchild,k);     //������������ɾ��
		else                                        //Tָ��Ľ�����Ҫɾ���Ľ��
		{
			if(T->lchild!=NULL&&T->rchild!=NULL)    //˫֧���
			{
				temp=T->lchild;
				while(temp->rchild!=NULL)           //Ѱ���������о������ֵ�Ľ��
					temp=temp->rchild;
				strcpy(T->key.name,temp->key.name);
				strcpy(T->key.mobilephone,temp->key.mobilephone);
				strcpy(T->key.home,temp->key.home);
				strcpy(T->key.office,temp->key.office);
				strcpy(T->key.email,temp->key.email);
				Delete(T->lchild,temp->key);			
			}
			else
			{
				temp=T;
				if(T->lchild==NULL)               //��֧��㣬������Ϊ��
					T=T->rchild;
				else if(T->rchild==NULL)          //��֧��㣬������Ϊ��
					T=T->lchild;
				delete temp;                      //ɾ��
			}
		}
	}
}

void Save(BiSortTree T,ofstream outfile) //�洢
{	
	if (T) 
	  {             
        Save(T->lchild,outfile);   
		outfile<<T->key.name<<" "<<T->key.mobilephone<<" "<<T->key.home<<" "<<T->key.office<<" "<<T->key.email<<endl;          
        Save(T->rchild,outfile);   
      }
}


void DestroyBiSortTree(BiSortTree &T)  //����������������
{
	if (T) 
	{             
        DestroyBiSortTree(T->lchild);   
        DestroyBiSortTree(T->rchild);
		delete T;   
        T=NULL;
    }
} 


int main()
{
	int n;
	Phone key,a[MAX];
	char buffer[100],name[10],mp[12],home[9],office[9],email[20];
	BiSortTree p,tree=NULL;
	
	ifstream infile("data.txt");
	if (!infile.is_open())
	{ 
		cout<<"�����ļ��򿪴���!\n";
		exit (1); 
	}
	n=0;  
	while(infile)		  //��ȡ�ļ�
	{
		infile.getline(buffer,100,'\n'); 		
		sscanf(buffer,"%s %s %s %s %s", name,mp,home,office,email);
		strcpy(a[n].name,name);
		strcpy(a[n].mobilephone,mp);
		strcpy(a[n].home,home);
		strcpy(a[n].office,office);
		strcpy(a[n].email,email);
		n++;
	}
	n--;
	infile.close();
	CreateBiSortTree(tree,a,n);  
	
	int choice=0;
	do
	{
		cout<<"***********��ӭʹ�õ绰�����ѯϵͳ*********\n";
		cout<<"******************1----���****************\n";
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
				cout<<"ͨѶ¼��Ϣ���£�\n";
				Inorder(tree);
				cout<<endl;
				break;
			}
		case 2:
			{
				cout<<"��������ҵ�������";
				cin>>key.name;
				p=BST_Search(tree,key);
				if(p) 
					cout<<p->key.name<<" "<<p->key.mobilephone<<" "<<p->key.home<<" "<<p->key.office<<" "<<p->key.email<<endl;
				else 
					cout<<"ͨѶ¼���޴�����Ϣ!"<<endl;
				cout<<endl;
				break;
			}
		case 3:
			{
				cout<<"��������ɾ����������";
				cin>>key.name;
				Delete(tree,key);
				cout<<"ɾ����ͨѶ¼Ϊ:\n";
				Inorder(tree);
				cout<<endl;
				break;
			}
		case 4:
			{ 
				cout<<"��������������Ա����Ϣ��"<<endl;
				cout<<"������";
				cin>>key.name;
				cout<<"�ֻ��ţ�";
				cin>>key.mobilephone;
				cout<<"լ�磺";
				cin>>key.home;
				cout<<"�칫�绰��";
				cin>>key.office;
				cout<<"Email��";
				cin>>key.email;
				Insert(tree,key);
				cout<<"ͨѶ¼��Ϣ���£�\n";
				Inorder(tree);
				cout<<endl;
				break;
			}
		case 0:
			{
				ofstream outfile("data.txt");
				if (!outfile.is_open())
				{ 
					cout<<"�����ļ��򿪴���!\n";
					exit (1);
				}
				Save(tree,outfile);
				outfile.close();
				DestroyBiSortTree(tree); 
				break;
			}
		default:
			cout<<"�������\n";
		}
	}while(choice);

	return 0;
}


