#include <iostream.h>
#include <stdlib.h>

int SeqSearch(int r[], int n, int k) //�޼�����
{ 
	int i=0;
	while(i<n&&r[i]!=k) i++;
	if(i<n) return i;
	else return -1;
}

int SeqSearch2(int r[], int n, int k)//�м�����
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
	cout<<"��������Ҫ���ҵ���:";
	cin>>key;
	cout<<"********�޼����ڲ��ҽ��********\n";
	i=SeqSearch(record, n, key);
    if(i==-1)
		cout<<"��Ҫ���ҵ����ݲ�����!"<<endl;
	else
        cout<<"��Ҫ���ҵ�����λ����:"<<i<<endl;

	cout<<"********�м����ڲ��ҽ��********\n";
	i=SeqSearch2(record, n, key);
    if(i==-1 )
		cout<<"��Ҫ���ҵ����ݲ�����!"<<endl;
	else
        cout<<"��Ҫ���ҵ�����λ����:"<<i<<endl;

	return 0;
}

