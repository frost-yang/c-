#include<iostream>
using namespace std;
void BubbleSort0(int r[],int n);
void BubbleSort1(int r[],int n);
void BubbleSort2(int r[],int n);
void BubbleSort3(int r[],int n); 

int main()
{
   int a[10]={1,2,3,4,5,6,7,8,9,10};
   cout<<"测试数据为：";
   for(int i=0;i<10;i++)
		cout<<a[i]<<"  ";
   cout<<endl;
   cout<<endl;

//普通冒泡算法测试
   BubbleSort0(a,10);
   cout<<"结果为：";
   for(i=0;i<10;i++)
		cout<<a[i]<<"  ";
   cout<<endl;
   cout<<endl;

//改进1冒泡算法测试
   int a1[10]={1,2,3,4,5,6,7,8,9,10};
   BubbleSort1(a1,10);
   cout<<"结果为：";
   for(i=0;i<10;i++)
		cout<<a1[i]<<"  ";
   cout<<endl;
   cout<<endl;

//改进2冒泡算法测试
   int a2[10]={1,2,3,4,5,6,7,8,9,10};
   BubbleSort2(a2,10);
   cout<<"结果为：";
   for(i=0;i<10;i++) 
		cout<<a2[i]<<"  ";
   cout<<endl;
   cout<<endl;

//改进3冒泡算法测试
   int a3[10]={1,2,3,4,5,6,7,8,9,10};
   BubbleSort3(a3,10);
   cout<<"结果为：";
   for(i=0;i<10;i++)
		cout<<a3[i]<<"  ";
   cout<<endl;
 
   return 0;
}

//普通冒泡算法
/*
  在不论正序、逆序，都需要进行n-1趟扫描
*/
void BubbleSort0(int r[],int n)
{
	int i,j,temp;
	int compare_num0=0;//记录比较次数
    for (i=1;i<n;i++)
	{
      for(j=0;j<n-i;j++)
      {
		 compare_num0++;
         if (r[j]>r[j+1])
         {
           temp=r[j];
           r[j]=r[j+1];
           r[j+1]=temp;
         }  
      }
	}
   cout<<"普通冒泡比较次数为："<<compare_num0<<endl;
}

//改进1：增加1个标志位，记录是否发生交换
/*
增加：若某一趟循环不发生记录交换，则结束排序过程。
说明排序已经完成，此后处理都是多余的。
*/
void BubbleSort1(int r[],int n)
{
	int compare_num1=0;//记录比较次数
    bool exchange=true;
	int i=1,j,temp;
	while(exchange)
	{
		exchange=false;
		for(j=0;j<n-i;j++)
		{
		  compare_num1++;
          if (r[j]>r[j+1])
          {
			   temp=r[j];
			   r[j]=r[j+1];
			   r[j+1]=temp;
			   exchange=true;
          }  
		}
		i++;
	}
   cout<<"改进1冒泡比较次数为："<<compare_num1<<endl;
}


//改进2：记录发生交换的最后位置
/*
在每趟扫描中，记住最后一次交换发生的位置exchange，（该位置之前的相邻记录均已有序）。
这样，一趟排序可能使当前有序区扩充多个记录，从而减少排序的趟数。
*/
void BubbleSort2(int r[],int n)
{
	int compare_num2=0;//记录比较次数
	int exchange=n-1;
	int j,bound,temp;
	while(exchange)
	{
		bound=exchange;
		exchange=0;
		for(j=0;j<bound;j++)
		{
		  compare_num2++;
          if (r[j]>r[j+1])
          {
			  temp=r[j];
			  r[j]=r[j+1];
			  r[j+1]=temp;
			  exchange=j;
          }  
		}
	}
   cout<<"改进2冒泡比较次数为："<<compare_num2<<endl;
}

//改进3：增加2个记录位，双向记录发生交换的最后位置
/*
设置正反向双向扫描，则需要增加2个记录位，
分别记录上一次冒泡排序中正向和反向发生交换的最后位置，
类似从两侧开始向中间排序，最小的，次小的……从左边开始排，
最大的，次大的……从右边开始排，大大提高了效率。
*/
void BubbleSort3(int r[],int n) 
{  
	int compare_num3=0;//记录比较次数
	int low=0;  
	int high=n-1;      
	bool exchange=true;  
	int high1,low1; 
	int i,j,temp;
	while(exchange && (high-low)>1)
	//当high和low相差1时，则表明在前一次排序中，所有的数值均已排好，故不用继续扫描。  
	{   
		exchange=false;   //先正向扫描   
		for (i=low;i<high;i++)   
		{    
			compare_num3++;    
			if(r[i]>r[i+1]) 
			{     
				temp=r[i];
				r[i]=r[i+1];
				r[i+1]=temp;     
				exchange=true;
				high1=i;    
			}     
		}   
		//再反向扫描   
		if (exchange)    
		{    
			high=high1;    
			if(low<high)    
			{     
				exchange=false;     
				for (i=high;low<i;i--)     
				{      
					compare_num3++;      
					if (r[i]<r[i-1])      
					{       
						int temp=r[i];  
						r[i]=r[i-1];  
						r[i-1]=temp;       
						exchange=true;
						low1=i;      
					}     
				}     
				if(exchange)
				{
					low=low1;
				}    
			}   
		}  
	}  
   cout<<"改进3冒泡比较次数为："<<compare_num3<<endl;
}
