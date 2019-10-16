#include <iostream.h>
#include <stdlib.h>

int BiSearch(int r[ ], int n, int k) //非递归
{	int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(r[mid]==k) return mid;
		else if(r[mid]<k) low=mid+1;
		else high=mid-1;
	}
	return -1;
}

int BiSearch2(int r[],int low,int high,int k)//递归
{	
	int mid;
	if(low>high)
		return -1;
	else
	{
		mid=(low+high)/2;
		if(r[mid]==k)  
			return mid;
		else
			if(r[mid]<k)
				return BiSearch2(r,mid+1,high,k);
			else
				return BiSearch2(r,low,mid-1,k);
	}
}

  
int main()
{
	int record[]={5,13,19,21,23,29,32,35,37,42,46,49,56};
    int n=13, key=686, i;
	cout<<"请输入需要查找的数:";
	cin>>key;
	cout<<"********非递归折半查找结果********\n";
	i=BiSearch(record, n, key);                 
	if(i==-1)
		cout<<"需要查找的数据不存在!"<<endl; 
    else
        cout<<"需要查找的数据位置在:"<<i<<endl;

	cout<<"********递归折半查找结果********\n";
	i=BiSearch2(record,0,n-1,key);
    if(i==-1 )
		cout<<"需要查找的数据不存在!"<<endl;
	else
        cout<<"需要查找的数据位置在:"<<i<<endl;

	return 0;
}

