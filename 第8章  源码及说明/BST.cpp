#include <iostream.h>
#include <stdlib.h>

typedef struct BiNode
{
	int key;
	struct BiNode *lchild,*rchild;
} *BiSortTree;

 
void Insert(BiSortTree &T,int k) //����
{
	if(T==NULL)
	{
		T=new BiNode;
		T->key=k;
		T->lchild=T->rchild=NULL;
	}
	else if(k<T->key)
		Insert(T->lchild,k);
	else
		Insert(T->rchild,k);
}

void CreateBiSortTree(BiSortTree &T,int a[],int n) //����
{
	int i;
	for(i=0;i<n;i++)
		Insert(T,a[i]);
}

void Inorder(BiSortTree T)
{
      if (T) 
	  {             
        Inorder(T->lchild);   
		cout<<T->key<<" ";          
        Inorder(T->rchild);   
      }
}


BiSortTree BST_Search(BiSortTree T,int k)//�ݹ����
{
	if(T==NULL)
		return NULL;
	else if(k==T->key)
		return T;
	else if(k<T->key)
		return BST_Search(T->lchild,k);
	else
		return BST_Search(T->rchild,k);
}

BiSortTree BST_Search2(BiSortTree T,int k)//�ǵݹ����
{
	BiSortTree p=T;
	while(p) 
    { 	
		if(k==p->key)  return p; 
		else if(k<p->key)  p=p->lchild;
		else p=p->rchild;
	}
	return NULL;
}

void Delete(BiSortTree &T, int k) //ɾ��
{
	BiSortTree temp;
	if(T!=NULL)
	{
		if(k<T->key)  Delete(T->lchild,k);          //������������ɾ��
		else if(k>T->key)  Delete(T->rchild,k);     //������������ɾ��
		else                                        //Tָ��Ľ�����Ҫɾ���Ľ��
		{
			if(T->lchild!=NULL&&T->rchild!=NULL)    //˫֧���
			{
				temp=T->lchild;
				while(temp->rchild!=NULL)           //Ѱ���������о������ֵ�Ľ��
					temp=temp->rchild;
				T->key=temp->key;
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
	int n,key;
	BiSortTree p,tree=NULL;
	int a[]={61,86,70,53,67,52,88};
	n=7;
	CreateBiSortTree(tree,a,n);

	cout<<"���������������������Ϊ:";
	Inorder(tree);
	cout<<endl;

	cout<<"��������Ҫ���ҵ���:";
	cin>>key;
	cout<<"********�ݹ�������������ҽ��********\n";
    p=BST_Search(tree,key);
	if(p) cout<<p->key<<endl;
	else cout<<"��Ҫ���ҵ����ݲ�����!"<<endl;
	cout<<"********�ǵݹ�������������ҽ��********\n";
    p=BST_Search2(tree,key);
	if(p) cout<<p->key<<endl;
	else cout<<"��Ҫ���ҵ����ݲ�����!"<<endl;

	cout<<"\n��������Ҫɾ������:";
	cin>>key;
	Delete(tree,key);
	cout<<"ɾ���󣬶��������������������Ϊ:";
	Inorder(tree);
	cout<<endl;

	DestroyBiSortTree(tree);

	return 0;
}


