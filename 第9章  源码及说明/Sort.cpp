#include <iostream.h>
#include <stdlib.h>
#include <time.h>

const COUNT=10;

//����10�������
void Random(int *r,int count)
{	
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<count;i++)
		r[i]=rand()%100;	
}

//��ӡ����
void Printdata(int *r,int count,int sort)
{	
	int i,s;
	if(sort==7||sort==8)
		s=1;
	else
		s=0;
	for(i=s;i<count;i++)
		cout<<r[i]<<"  ";
	cout<<endl;
}

//ð������
void  BubbleSort (int r[ ], int n)  //����r�е����ݱ�����0~n-1��
{ 
	int i,j,temp;  
	for (i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(r[j]>r[j+1]) 
			{ 
				temp=r[j]; 
				r[j]=r[j+1]; 
				r[j+1]=temp;
			}
}


// ��������
int  Partition(int r[ ], int i, int j)  //һ�λ���,i��j�ֱ��ʾ����������������յ�λ��
{   
	int temp= r[i];
	while (i<j)
	{ 
		while (i<j && r[j]>= temp)   j--;
		if (i<j)    r[i++]= r[j];
		while (i<j && r[i]<= temp)   i++;
		if (i<j)  r[j--]= r[i];
	}
	r[i] = temp;
	return i;
}
void  QuickSort (int r[ ], int i, int j ) //i��j�ֱ��ʾ����������������յ�λ��
{  
	if (i<j)
	{  
		int pivot=Partition(r, i, j);
		QuickSort(r, i, pivot-1);
		QuickSort(r, pivot+1, j);
	}
}

//ֱ�Ӳ�������
void  InsertSort(int r[ ], int n)
{  
	int i,j,temp;
	for (i=1; i<n; i++)
	{  
		temp=r[i];
		for (j=i-1;j>=0&&temp<r[j];j--)
			r[j+1]=r[j];
		r[j+1]=temp;
	}
}

//�۰��������
void  BinInsertSort(int r[ ], int n)
{   
	int i,j,mid,low,high,temp;
	for(i=1; i<n; i++) 
	{  
		temp=r[i],
		low=0; high=i-1;
		while(low<=high)
		{ 
			mid=(low+high)/2;
			if (temp<r[mid]) 
				high=mid-1;
			else 
				low=mid+1;
		}
		for(j=i-1; j>=low; j--)  
			r[j+1]=r[j];
		r[low]=temp;
	}
}

//ϣ������
void  ShellSort(int r[ ], int n)
{
	int i,j,d,temp;
	for(d=n/2;d>=1;d=d/2)     //������Ϊd����ֱ�Ӳ�������
	{
		for(i=d; i<n; i++)
		{
			temp=r[i];            //�ݴ汻�����¼
			for(j=i-d;j>=0&&temp<r[j];j=j-d)
				r[j+d]=r[j];        //��¼���� d��λ��
			r[j+d]=temp;
		}
    }
}

//��ѡ������
void  SelectSort(int r[ ], int n)  
{  
	int i,j,k,temp;
	for(i=0; i<n-1; i++)
	{  
		k=i;
		for (j=i+1; j<n; j++)
			if(r[j]<r[k]) 
				k=j;
			if (k!=i) 
			{
				temp=r[i]; 
				r[i]=r[k]; 
				r[k]=temp; 
			}
	}
}

//������
void  Sift(int r[ ], int k , int m)
{
	int i,j,temp;
	i=k;                 //iΪҪɸ�Ľ��
	j=2*i ;              //jΪi������
	while (j<=m)         //ɸѡ��û�н��е�Ҷ��
	{
		if(j<m&&r[j]<r[j+1])    j++;          //�Ƚ�i�����Һ��ӣ�jΪ�ϴ���
		if(r[i]>r[j])   break;                //������Ѿ��������Һ����еĽϴ���
		else 
		{
			temp=r[i];           //�����������j����
			r[i]=r[j];
			r[j]=temp;			
			i=j;j=2*i;         //��ɸ���λ��ԭ�����j��λ��
        }
	}
}
void  HeapSort(int r[ ], int n)
{
	int i,temp;
	for (i=n/2;i>=1;i--)       //��ʼ���ѣ������һ�����ն˽������������ɸѡ
		Sift(r,i,n);
	for (i=1;i<n;i++)          //���߶Ѷ����ؽ��ѵĲ���
	{
		temp=r[1];
		r[1]=r[n-i+1];
		r[n-i+1]=temp;
		Sift(r,1,n-i);
	}
}

//�鲢����
void  Merge(int r[ ],int r1[ ], int s, int m, int t)  //һ�ι鲢
{
	int i,j,k;
	i=s; j=m+1; k=s;
	while (i<=m && j<=t)
		if (r[i]<=r[j])     r1[k++]=r[i++];  //ȡr[i]��r[ j]�н�С�߷���rl[k]
		else                r1[k++]=r[j++];
		if (i<=m) 
			while (i<=m)     r1[k++]=r[i++];   //����һ��������û�����꣬�������β����
			else
				while (j<=t)     r1[k++]=r[j++];  //���ڶ���������û�����꣬�������β����
}

void  MergePass(int r[ ], int r1[ ], int n, int h)  //һ�˹鲢
{
	int i,k;
	i=1;
	while(i<=n-2*h+1)      //���鲢��¼��������������Ϊh��������
	{
		Merge(r,r1,i,i+h-1,i+2*h-1);
		i=i+2*h;
	}
	if (i<n-h+1)    
		Merge(r,r1,i,i+h-1,n);            //���鲢��������һ������С��h
	else 
		for (k=i;k<=n;k++)   r1[k]=r[k];   //���鲢������ֻʣһ��������
}

void  MergeSort1(int r[ ],int r1[],int n)  //�鲢�ǵݹ�
{
	int h=1;
	while(h<n)
	{
		MergePass (r,r1,n,h);
		h=2*h;
		MergePass (r1,r,n,h);
		h=2*h;
	}
}

void  MergeSort2 (int r[ ], int r1[ ], int s, int t) //�鲢�ݹ�
{
	int m;
	int r2[COUNT];
	if(s==t) 
		r1[s]=r[s];
	else 
	{
		m=(s+t)/2;
		MergeSort2(r,r2,s,m);       //�鲢����ǰ�벿��
		MergeSort2(r,r2,m+1,t);     //�鲢�����벿��
		Merge(r2,r1,s,m,t );       //������������������й鲢
	}
}


/**********************************************/
int main()
{
	int a[COUNT]={10,9,8,7,6,5,4,3,2,1},b[COUNT],SortMethod;
	char user;
	do{
		Random(a,COUNT);
		cout<<"*******************************"<<endl;
		cout<<"1.ð������"<<endl;
		cout<<"2.��������"<<endl;
		cout<<"3.ֱ�Ӳ�������"<<endl;
		cout<<"4.�۰��������"<<endl;
		cout<<"5.ϣ������"<<endl;
		cout<<"6.��ѡ������"<<endl;
		cout<<"7.������"<<endl;
		cout<<"8.�鲢���򣨷ǵݹ飩"<<endl;
		cout<<"9.�鲢���򣨵ݹ飩"<<endl;
		cout<<"*******************************"<<endl;
		
		do	{
			cout<<"ѡ�����򷽷�(1-9):";
			cin>>SortMethod;
		}while(SortMethod<0 || SortMethod>9);
		cout<<"\n\nδ�������Ϊ��";
		Printdata(a,COUNT,SortMethod);
		switch(SortMethod)
		{
		case 1:				
			BubbleSort(a,COUNT);	  break;
		case 2:
			QuickSort(a,0,COUNT-1);	  break;
		case 3:
			InsertSort(a,COUNT);	  break;
		case 4:
			BinInsertSort(a,COUNT);	  break;
		case 5:
			ShellSort(a,COUNT);	      break;
		case 6:
			SelectSort(a,COUNT);	  break;
		case 7:
			HeapSort(a,COUNT);        break;
		case 8:
			MergeSort1(a,b,COUNT);    break;
		case 9:
		    MergeSort2(a,a,0,COUNT-1); break;
		default:
			user='n';
		}
		cout<<endl;
		cout<<"�Ź������Ϊ��";
		Printdata(a,COUNT,SortMethod);
		cout<<endl;
		cout<<"��Ҫ��һ����?Y/N:";
		cin>>user;
	}while(user=='Y'||user=='y');
	return 0;
}


