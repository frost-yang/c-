#include <iostream.h>
#include <stdlib.h>
#include <time.h>

const COUNT=10;

//产生10个随机数
void Random(int *r,int count)
{	
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<count;i++)
		r[i]=rand()%100;	
}

//打印数据
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

//冒泡排序
void  BubbleSort (int r[ ], int n)  //数组r中的数据保存在0~n-1中
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


// 快速排序
int  Partition(int r[ ], int i, int j)  //一次划分,i和j分别表示待划分区域的起点和终点位置
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
void  QuickSort (int r[ ], int i, int j ) //i和j分别表示待排序区域的起点和终点位置
{  
	if (i<j)
	{  
		int pivot=Partition(r, i, j);
		QuickSort(r, i, pivot-1);
		QuickSort(r, pivot+1, j);
	}
}

//直接插入排序
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

//折半插入排序
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

//希尔排序
void  ShellSort(int r[ ], int n)
{
	int i,j,d,temp;
	for(d=n/2;d>=1;d=d/2)     //以增量为d进行直接插入排序
	{
		for(i=d; i<n; i++)
		{
			temp=r[i];            //暂存被插入记录
			for(j=i-d;j>=0&&temp<r[j];j=j-d)
				r[j+d]=r[j];        //记录后移 d个位置
			r[j+d]=temp;
		}
    }
}

//简单选择排序
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

//堆排序
void  Sift(int r[ ], int k , int m)
{
	int i,j,temp;
	i=k;                 //i为要筛的结点
	j=2*i ;              //j为i的左孩子
	while (j<=m)         //筛选还没有进行到叶子
	{
		if(j<m&&r[j]<r[j+1])    j++;          //比较i的左右孩子，j为较大者
		if(r[i]>r[j])   break;                //根结点已经大于左右孩子中的较大者
		else 
		{
			temp=r[i];           //将根结点与结点j交换
			r[i]=r[j];
			r[j]=temp;			
			i=j;j=2*i;         //被筛结点位于原来结点j的位置
        }
	}
}
void  HeapSort(int r[ ], int n)
{
	int i,temp;
	for (i=n/2;i>=1;i--)       //初始建堆，从最后一个非终端结点至根结点进行筛选
		Sift(r,i,n);
	for (i=1;i<n;i++)          //移走堆顶及重建堆的操作
	{
		temp=r[1];
		r[1]=r[n-i+1];
		r[n-i+1]=temp;
		Sift(r,1,n-i);
	}
}

//归并排序
void  Merge(int r[ ],int r1[ ], int s, int m, int t)  //一次归并
{
	int i,j,k;
	i=s; j=m+1; k=s;
	while (i<=m && j<=t)
		if (r[i]<=r[j])     r1[k++]=r[i++];  //取r[i]和r[ j]中较小者放入rl[k]
		else                r1[k++]=r[j++];
		if (i<=m) 
			while (i<=m)     r1[k++]=r[i++];   //若第一个子序列没处理完，则进行收尾处理
			else
				while (j<=t)     r1[k++]=r[j++];  //若第二个子序列没处理完，则进行收尾处理
}

void  MergePass(int r[ ], int r1[ ], int n, int h)  //一趟归并
{
	int i,k;
	i=1;
	while(i<=n-2*h+1)      //待归并记录至少有两个长度为h的子序列
	{
		Merge(r,r1,i,i+h-1,i+2*h-1);
		i=i+2*h;
	}
	if (i<n-h+1)    
		Merge(r,r1,i,i+h-1,n);            //待归并序列中有一个长度小于h
	else 
		for (k=i;k<=n;k++)   r1[k]=r[k];   //待归并序列中只剩一个子序列
}

void  MergeSort1(int r[ ],int r1[],int n)  //归并非递归
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

void  MergeSort2 (int r[ ], int r1[ ], int s, int t) //归并递归
{
	int m;
	int r2[COUNT];
	if(s==t) 
		r1[s]=r[s];
	else 
	{
		m=(s+t)/2;
		MergeSort2(r,r2,s,m);       //归并排序前半部分
		MergeSort2(r,r2,m+1,t);     //归并排序后半部分
		Merge(r2,r1,s,m,t );       //将两个已排序的子序列归并
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
		cout<<"1.冒泡排序"<<endl;
		cout<<"2.快速排序"<<endl;
		cout<<"3.直接插入排序"<<endl;
		cout<<"4.折半插入排序"<<endl;
		cout<<"5.希尔排序"<<endl;
		cout<<"6.简单选择排序"<<endl;
		cout<<"7.堆排序"<<endl;
		cout<<"8.归并排序（非递归）"<<endl;
		cout<<"9.归并排序（递归）"<<endl;
		cout<<"*******************************"<<endl;
		
		do	{
			cout<<"选择排序方法(1-9):";
			cin>>SortMethod;
		}while(SortMethod<0 || SortMethod>9);
		cout<<"\n\n未排序的数为：";
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
		cout<<"排过序的数为：";
		Printdata(a,COUNT,SortMethod);
		cout<<endl;
		cout<<"你要排一次吗?Y/N:";
		cin>>user;
	}while(user=='Y'||user=='y');
	return 0;
}


