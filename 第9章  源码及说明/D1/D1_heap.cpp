#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <fstream.h>

const int MAXSIZE=100;
typedef struct Record
{
	int no;            //货号
	char name[20];     //名称
	int price;         //价格
	int sales;         //销量
	char date[20];     //日期
	int  interval;     //与当前时间的时间差
}ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}Table;

//计算日期对应的秒数
time_t StringToDatetime(char *str1,char *str2)
{
    tm tm_;
    int year, month, day, hour, minute,second;
    sscanf(str1,"%d-%d-%d", &year, &month, &day);
	sscanf(str2,"%d:%d:%d", &hour, &minute, &second);
    tm_.tm_year=year-1900;
    tm_.tm_mon=month-1;
    tm_.tm_mday=day;
    tm_.tm_hour=hour;
    tm_.tm_min=minute;
    tm_.tm_sec=second;
    tm_.tm_isdst=0;
    time_t t=mktime(&tm_); //已经减了8个时区

    return t; //秒时间
}

//结构体赋值
void Copy(ElemType &r1,ElemType r2)
{
	r1.no=r2.no;
	strcpy(r1.name,r2.name);
	r1.price=r2.price;
	r1.sales=r2.sales;
	strcpy(r1.date,r2.date);
	r1.interval=r2.interval;
}

//读取数据文件，创建信息表
void CreatTable(Table &L) 
{
    char name[20],buffer[100];
	int no,price,sales;
	char date[20],t[20];
    time_t today;

	time(&today);
	ifstream infile("data.txt");
	if (!infile.is_open())
	{ 
		cout<<"数据文件打开错误!\n";
		exit (1); 
	}

	L.length = 0;  
	while(!infile.eof())		  
	{
		infile.getline(buffer,100); 
		L.length++;
		sscanf(buffer,"%d %s %d %d %s %s", &no,name,&price,&sales,date,t);
		L.data[L.length].no=no;;
		strcpy(L.data[L.length].name,name);
		L.data[L.length].price=price;
		L.data[L.length].sales=sales;
		strcpy(L.data[L.length].date,date);
		L.data[L.length].interval=today-StringToDatetime(date,t);	
	}
	infile.close();
} 

//显示整个数据表
void PrintTable(Table L)
{
	int i;
	for(i=1;i<=L.length;i++)
		cout<<L.data[i].no<<" "<<L.data[i].name<<" "<<L.data[i].price<<" "<<L.data[i].sales<<" "<<L.data[i].date<<endl;
}

void Show(Table L,int i)
{
	cout<<"名称";
	cout<<setw(20)<<"价格";
	cout<<setw(20)<<"上市日期"<<endl;
	cout<<L.data[i].name;
	cout<<setw(20)<<L.data[i].price;
	cout<<setw(20)<<L.data[i].date<<endl;

}

void  BubbleSort(Table &L) //冒泡排序
 
{ 
	int i,j,n;
	ElemType temp;
	n=L.length;
	for (i=1;i<n;i++)
		for(j=1;j<=n-i;j++)
			if(L.data[j].sales<L.data[j+1].sales) 
			{ 
				Copy(temp,L.data[j]);
				Copy(L.data[j],L.data[j+1]);
				Copy(L.data[j+1],temp);
			}
}

int New(Table &L)
{
	int i,m=1;
	for(i=2;i<=5;i++)
		if(L.data[i].interval<L.data[m].interval)
			m=i;
    return m;
}


//堆排序
void  Sift(Table &L, int k , int m)
{
	int i,j;
	ElemType temp;
	i=k;                 //i为要筛的结点
	j=2*i ;              //j为i的左孩子
	while (j<=m)         //筛选还没有进行到叶子
	{
		if(j<m&&L.data[j].sales<L.data[j+1].sales)    j++;          //比较i的左右孩子，j为较大者
		if(L.data[i].sales>L.data[j].sales)   break;                //根结点已经大于左右孩子中的较大者
		else 
		{
			Copy(temp,L.data[i]);    //将根结点与结点j交换
			Copy(L.data[i],L.data[j]); 
			Copy(L.data[j],temp); 
			i=j;j=2*i;         //被筛结点位于原来结点j的位置
        }
	}
}
int  HeapSort(Table &L)
{
	int i,n,m,k;
	ElemType temp;
	n=L.length;
	for (i=n/2;i>=1;i--)       //初始建堆，从最后一个非终端结点至根结点进行筛选
		Sift(L,i,n);
	k=L.data[1].interval;
	for (i=1;i<=5;i++)          //移走堆顶及重建堆的操作
	{
		Copy(temp,L.data[1]);
		Copy(L.data[1],L.data[n-i+1]);
		Copy(L.data[n-i+1],temp);
		if(L.data[n-i+1].interval<=k)
		{
			k=L.data[n-i+1].interval;
			m=n-i+1;
		}
		Sift(L,1,n-i);
	}
	return m;
}


/**********************************************/
int main()
{
	Table Phone;
	CreatTable(Phone);
	PrintTable(Phone);
	cout<<endl;
	int n=HeapSort(Phone);
	cout<<"销量最高的五款手机中最新款是:\n";
	Show(Phone,n);
	
	return 0;
}


