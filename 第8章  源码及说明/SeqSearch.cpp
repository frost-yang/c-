#include <iostream.h>
#include <stdlib.h>

int SeqSearch(int r[], int n, int k) //无监视哨
{ 
	int i=0;
	while(i<n&&r[i]!=k) i++;
	if(i<n) return i;
	else return -1;
}

int SeqSearch2(int r[], int n, int k)//有监视哨
{
	int i=0;
	r[n]=k;
	while(r[i]!=k) 
		i++;
	if(i<n) return i;
	else return -1;
}

   
int main()
{
	int record[11]={710,342,45,686,6,841,429,134,68,264};
    int n=10, key=686, i;
	cout<<"请输入需要查找的数:";
	cin>>key;
	cout<<"********无监视哨查找结果********\n";
	i=SeqSearch(record, n, key);
    if(i==-1)
		cout<<"需要查找的数据不存在!"<<endl;
	else
        cout<<"需要查找的数据位置在:"<<i<<endl;

	cout<<"********有监视哨查找结果********\n";
	i=SeqSearch2(record, n, key);
    if(i==-1 )
		cout<<"需要查找的数据不存在!"<<endl;
	else
        cout<<"需要查找的数据位置在:"<<i<<endl;

	return 0;
}

