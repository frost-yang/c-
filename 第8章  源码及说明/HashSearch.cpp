#include <iostream.h>
#include <stdlib.h>

const int EMPTY=-9999;
void CreateHash(int *&hash,int m,int p,int key[],int n)
{  
	int i,pos,t;
	hash=new int[m];
	for(i=0;i<m;i++)
		hash[i]=EMPTY;
   for(i=0;i<n;i++)
   {
     pos=key[i]%p;
     t=pos;
	 while(hash[pos]!=EMPTY)
	 {
		pos=(pos+1)%m;
		if(pos==t) 
		{cout<<"hash表已满"<<endl;exit(1);}
	 }
     hash[pos]=key[i];
   }
}

int HashSearch_1(int hash[],int m,int k)
{
  int pos=k%m;
  int t=pos;
  while(hash[pos]!=EMPTY)
  {
    if(hash[pos]==k) 
		return pos;
	else 
		pos=(pos+1)%m;
	if(pos==t) 
		return -1;
  }
  return -1;
}

int main()
{ 
	int n,m,p,i,k,pos;          //n为关键字个数，m为表长，p为模运算的除数key%p                     
	int key[]={36,7,40,11,16,81,22,8,14};   //关键字
	int *hash; 
	n=9;
	m=p=11;
	CreateHash(hash,m,p,key,n);             //构造hash表
	cout<<"关键字为：";
	for(i=0;i<n;i++)
      cout<<key[i]<<" ";
	cout<<endl;
	cout<<"长度为11，模11的Hash表为：";
	for(i=0;i<m;i++)
		if(hash[i]==EMPTY) 
			cout<<"Empty"<<" ";
		else cout<<hash[i]<<" ";
	cout<<endl;
 
    cout<<"请输入需要查找的值：";
    cin>>k;
    pos=HashSearch_1(hash,m,k);           //查找
    if(pos!=-1) 
		cout<<"查找的数"<<k<<"成功，"<<"位于下标"<<pos<<"处"<<endl;
    else 
		cout<<"查找失败，"<<k<<"不存在"<<endl; 

	delete[] hash;
	return 0;
}



