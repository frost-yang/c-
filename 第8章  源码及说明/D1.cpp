#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream.h>

const MAX=500;
typedef struct 
{
	char name[10];       //姓名
    char mobilephone[12]; //手机
    char home[9];        //宅电
    char office[9];        //办公电话
    char email[20];       //电子邮件
} Phone;


typedef struct BiNode
{
	Phone key;
	struct BiNode *lchild,*rchild;
} *BiSortTree;


void Insert(BiSortTree &T,Phone k) //插入
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

void CreateBiSortTree(BiSortTree &T,Phone a[],int n) //创建
{
	int i;
	for(i=0;i<n;i++)
		Insert(T,a[i]);
}

void Inorder(BiSortTree T)  //中序遍历
{
      if (T) 
	  {             
        Inorder(T->lchild);   
		cout<<T->key.name<<" "<<T->key.mobilephone<<" "<<T->key.home<<" "<<T->key.office<<" "<<T->key.email<<" "<<endl;          
        Inorder(T->rchild);   
      }
}


BiSortTree BST_Search(BiSortTree T,Phone k)//递归查找
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


void Delete(BiSortTree &T, Phone k) //删除
{
	BiSortTree temp;
	if(T!=NULL)
	{
		if(strcmp(k.name,T->key.name)<0)  Delete(T->lchild,k);          //在左子树进行删除
		else if(strcmp(k.name,T->key.name)>0)  Delete(T->rchild,k);     //在右子树进行删除
		else                                        //T指向的结点就是要删除的结点
		{
			if(T->lchild!=NULL&&T->rchild!=NULL)    //双支结点
			{
				temp=T->lchild;
				while(temp->rchild!=NULL)           //寻找左子树中具有最大值的结点
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
				if(T->lchild==NULL)               //单支结点，左子树为空
					T=T->rchild;
				else if(T->rchild==NULL)          //单支结点，右子树为空
					T=T->lchild;
				delete temp;                      //删除
			}
		}
	}
}

void Save(BiSortTree T,ofstream outfile) //存储
{	
	if (T) 
	  {             
        Save(T->lchild,outfile);   
		outfile<<T->key.name<<" "<<T->key.mobilephone<<" "<<T->key.home<<" "<<T->key.office<<" "<<T->key.email<<endl;          
        Save(T->rchild,outfile);   
      }
}


void DestroyBiSortTree(BiSortTree &T)  //二叉排序树的销毁
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
		cout<<"数据文件打开错误!\n";
		exit (1); 
	}
	n=0;  
	while(infile)		  //读取文件
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
		cout<<"***********欢迎使用电话号码查询系统*********\n";
		cout<<"******************1----浏览****************\n";
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
				cout<<"通讯录信息如下：\n";
				Inorder(tree);
				cout<<endl;
				break;
			}
		case 2:
			{
				cout<<"请输入查找的姓名：";
				cin>>key.name;
				p=BST_Search(tree,key);
				if(p) 
					cout<<p->key.name<<" "<<p->key.mobilephone<<" "<<p->key.home<<" "<<p->key.office<<" "<<p->key.email<<endl;
				else 
					cout<<"通讯录中无此人信息!"<<endl;
				cout<<endl;
				break;
			}
		case 3:
			{
				cout<<"请输入需删除者姓名：";
				cin>>key.name;
				Delete(tree,key);
				cout<<"删除后，通讯录为:\n";
				Inorder(tree);
				cout<<endl;
				break;
			}
		case 4:
			{ 
				cout<<"请输入需增加人员的信息："<<endl;
				cout<<"姓名：";
				cin>>key.name;
				cout<<"手机号：";
				cin>>key.mobilephone;
				cout<<"宅电：";
				cin>>key.home;
				cout<<"办公电话：";
				cin>>key.office;
				cout<<"Email：";
				cin>>key.email;
				Insert(tree,key);
				cout<<"通讯录信息如下：\n";
				Inorder(tree);
				cout<<endl;
				break;
			}
		case 0:
			{
				ofstream outfile("data.txt");
				if (!outfile.is_open())
				{ 
					cout<<"数据文件打开错误!\n";
					exit (1);
				}
				Save(tree,outfile);
				outfile.close();
				DestroyBiSortTree(tree); 
				break;
			}
		default:
			cout<<"输入错误！\n";
		}
	}while(choice);

	return 0;
}


