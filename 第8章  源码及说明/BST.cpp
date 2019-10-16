#include <iostream.h>
#include <stdlib.h>

typedef struct BiNode
{
	int key;
	struct BiNode *lchild,*rchild;
} *BiSortTree;

 
void Insert(BiSortTree &T,int k) //插入
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

void CreateBiSortTree(BiSortTree &T,int a[],int n) //创建
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


BiSortTree BST_Search(BiSortTree T,int k)//递归查找
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

BiSortTree BST_Search2(BiSortTree T,int k)//非递归查找
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

void Delete(BiSortTree &T, int k) //删除
{
	BiSortTree temp;
	if(T!=NULL)
	{
		if(k<T->key)  Delete(T->lchild,k);          //在左子树进行删除
		else if(k>T->key)  Delete(T->rchild,k);     //在右子树进行删除
		else                                        //T指向的结点就是要删除的结点
		{
			if(T->lchild!=NULL&&T->rchild!=NULL)    //双支结点
			{
				temp=T->lchild;
				while(temp->rchild!=NULL)           //寻找左子树中具有最大值的结点
					temp=temp->rchild;
				T->key=temp->key;
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
	int n,key;
	BiSortTree p,tree=NULL;
	int a[]={61,86,70,53,67,52,88};
	n=7;
	CreateBiSortTree(tree,a,n);

	cout<<"二叉排序树中序遍历序列为:";
	Inorder(tree);
	cout<<endl;

	cout<<"请输入需要查找的数:";
	cin>>key;
	cout<<"********递归二叉排序树查找结果********\n";
    p=BST_Search(tree,key);
	if(p) cout<<p->key<<endl;
	else cout<<"需要查找的数据不存在!"<<endl;
	cout<<"********非递归二叉排序树查找结果********\n";
    p=BST_Search2(tree,key);
	if(p) cout<<p->key<<endl;
	else cout<<"需要查找的数据不存在!"<<endl;

	cout<<"\n请输入需要删除的数:";
	cin>>key;
	Delete(tree,key);
	cout<<"删除后，二叉排序树中序遍历序列为:";
	Inorder(tree);
	cout<<endl;

	DestroyBiSortTree(tree);

	return 0;
}


