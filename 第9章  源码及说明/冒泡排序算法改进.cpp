#include<iostream>
using namespace std;
void BubbleSort0(int r[],int n);
void BubbleSort1(int r[],int n);
void BubbleSort2(int r[],int n);
void BubbleSort3(int r[],int n); 

int main()
{
   int a[10]={1,2,3,4,5,6,7,8,9,10};
   cout<<"��������Ϊ��";
   for(int i=0;i<10;i++)
		cout<<a[i]<<"  ";
   cout<<endl;
   cout<<endl;

//��ͨð���㷨����
   BubbleSort0(a,10);
   cout<<"���Ϊ��";
   for(i=0;i<10;i++)
		cout<<a[i]<<"  ";
   cout<<endl;
   cout<<endl;

//�Ľ�1ð���㷨����
   int a1[10]={1,2,3,4,5,6,7,8,9,10};
   BubbleSort1(a1,10);
   cout<<"���Ϊ��";
   for(i=0;i<10;i++)
		cout<<a1[i]<<"  ";
   cout<<endl;
   cout<<endl;

//�Ľ�2ð���㷨����
   int a2[10]={1,2,3,4,5,6,7,8,9,10};
   BubbleSort2(a2,10);
   cout<<"���Ϊ��";
   for(i=0;i<10;i++) 
		cout<<a2[i]<<"  ";
   cout<<endl;
   cout<<endl;

//�Ľ�3ð���㷨����
   int a3[10]={1,2,3,4,5,6,7,8,9,10};
   BubbleSort3(a3,10);
   cout<<"���Ϊ��";
   for(i=0;i<10;i++)
		cout<<a3[i]<<"  ";
   cout<<endl;
 
   return 0;
}

//��ͨð���㷨
/*
  �ڲ����������򣬶���Ҫ����n-1��ɨ��
*/
void BubbleSort0(int r[],int n)
{
	int i,j,temp;
	int compare_num0=0;//��¼�Ƚϴ���
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
   cout<<"��ͨð�ݱȽϴ���Ϊ��"<<compare_num0<<endl;
}

//�Ľ�1������1����־λ����¼�Ƿ�������
/*
���ӣ���ĳһ��ѭ����������¼�����������������̡�
˵�������Ѿ���ɣ��˺����Ƕ���ġ�
*/
void BubbleSort1(int r[],int n)
{
	int compare_num1=0;//��¼�Ƚϴ���
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
   cout<<"�Ľ�1ð�ݱȽϴ���Ϊ��"<<compare_num1<<endl;
}


//�Ľ�2����¼�������������λ��
/*
��ÿ��ɨ���У���ס���һ�ν���������λ��exchange������λ��֮ǰ�����ڼ�¼�������򣩡�
������һ���������ʹ��ǰ��������������¼���Ӷ����������������
*/
void BubbleSort2(int r[],int n)
{
	int compare_num2=0;//��¼�Ƚϴ���
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
   cout<<"�Ľ�2ð�ݱȽϴ���Ϊ��"<<compare_num2<<endl;
}

//�Ľ�3������2����¼λ��˫���¼�������������λ��
/*
����������˫��ɨ�裬����Ҫ����2����¼λ��
�ֱ��¼��һ��ð������������ͷ��������������λ�ã�
���ƴ����࿪ʼ���м�������С�ģ���С�ġ�������߿�ʼ�ţ�
���ģ��δ�ġ������ұ߿�ʼ�ţ���������Ч�ʡ�
*/
void BubbleSort3(int r[],int n) 
{  
	int compare_num3=0;//��¼�Ƚϴ���
	int low=0;  
	int high=n-1;      
	bool exchange=true;  
	int high1,low1; 
	int i,j,temp;
	while(exchange && (high-low)>1)
	//��high��low���1ʱ���������ǰһ�������У����е���ֵ�����źã��ʲ��ü���ɨ�衣  
	{   
		exchange=false;   //������ɨ��   
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
		//�ٷ���ɨ��   
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
   cout<<"�Ľ�3ð�ݱȽϴ���Ϊ��"<<compare_num3<<endl;
}
