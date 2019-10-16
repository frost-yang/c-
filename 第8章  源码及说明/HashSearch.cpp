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
		{cout<<"hash������"<<endl;exit(1);}
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
	int n,m,p,i,k,pos;          //nΪ�ؼ��ָ�����mΪ����pΪģ����ĳ���key%p                     
	int key[]={36,7,40,11,16,81,22,8,14};   //�ؼ���
	int *hash; 
	n=9;
	m=p=11;
	CreateHash(hash,m,p,key,n);             //����hash��
	cout<<"�ؼ���Ϊ��";
	for(i=0;i<n;i++)
      cout<<key[i]<<" ";
	cout<<endl;
	cout<<"����Ϊ11��ģ11��Hash��Ϊ��";
	for(i=0;i<m;i++)
		if(hash[i]==EMPTY) 
			cout<<"Empty"<<" ";
		else cout<<hash[i]<<" ";
	cout<<endl;
 
    cout<<"��������Ҫ���ҵ�ֵ��";
    cin>>k;
    pos=HashSearch_1(hash,m,k);           //����
    if(pos!=-1) 
		cout<<"���ҵ���"<<k<<"�ɹ���"<<"λ���±�"<<pos<<"��"<<endl;
    else 
		cout<<"����ʧ�ܣ�"<<k<<"������"<<endl; 

	delete[] hash;
	return 0;
}



