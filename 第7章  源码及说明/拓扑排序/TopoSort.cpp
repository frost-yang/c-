#include <iostream.h>
#include <stdlib.h>
#include "SeqQueue.h"

const MAX=100;
enum GraphType{DG,UG,DN,UN};//图的类型定义：有向图，无向图，有向网，无向网
typedef char VertexType;
typedef struct EdgeNode        //边表的结点类型
{          
	int adjvex;                // 邻接点存储位置
	EdgeNode* next;            // 指向下一个邻接点
}*EdgeList;
typedef struct                //顶点表的元素类型
{          
	VertexType data;         // 顶点信息
	EdgeList firstedge;     // 边表的头指针
}VexNode;
typedef struct 
{
	VexNode adjlist[MAX];   //顶点表
	int vexnum,arcnum;      //顶点数和边数
	GraphType kind;        //图的类型
} ALGraph;



void CreateALGraph(ALGraph &G)
{
	int i,va,vb;
	EdgeList p;
	G.kind=UG;      //无向图
	cout<<"请输入图的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入图的边数：";
	cin>>G.arcnum;
	cout<<"请输入顶点的信息：";
	for(i=0;i<G.vexnum;i++) 
	{
		cin>>G.adjlist[i].data;
		G.adjlist[i].firstedge=NULL;
	}

	cout<<"请输入边的信息(顶点1 顶点2)：";
	for(i=0;i<G.arcnum; i++ )    //依次输入所有的边的信息
	{
		cin>>va>>vb;             // 输入一条边邻接的两个顶点的序号
		p=new EdgeNode;          //产生第一个边表结结点
		p->adjvex=vb;
		p->next=G.adjlist[va].firstedge;  // 插在表头
		G.adjlist[va].firstedge=p;
		
	}
}

void ShowALGraph(ALGraph G)
{
	int i;
	EdgeList p;

	for(i=0;i<G.vexnum;i++)
	{
		cout<<G.adjlist[i].data<<":";
		p=G.adjlist[i].firstedge;
		while(p)
		{
			cout<<p->adjvex<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}


void TopoSort(ALGraph G)
{
	int *indegree=new int[G.vexnum];
	EdgeList p;
	SeqQueue s;
	int i,c;

	InitQueue(s);
	for(i=0;i<G.vexnum;i++)    //初始化各顶点入度
		indegree[i]=0;
	for(i=0;i<G.vexnum;i++)     //计算各顶点的入度         
	{
		p=G.adjlist[i].firstedge;
		while(p)
		{
			indegree[p->adjvex]++;
			p=p->next;
		}
	}
	for(i=0;i<G.vexnum;i++)             //将入度为0的顶点入队
	{
		if(!indegree[i])
			EnQueue(s,i); 
	}

	c=0;                       //对输出顶点计数
	while(!QueueEmpty(s))
	{
		i=DeQueue(s);               //出队
		cout<<G.adjlist[i].data;    //输出顶点
		c++;
        p=G.adjlist[i].firstedge;
		while(p)                   //相应弧头顶点入度减1
		{
			indegree[p->adjvex]--;
	    	if(!indegree[p->adjvex])
			    EnQueue(s,p->adjvex);
			p=p->next;
		}
	}
	if(c<G.vexnum)
		cout<<"该 AOV 网存在回路!"<<endl;
	delete[] indegree;
}


int main()
{
	ALGraph Graph;
	CreateALGraph(Graph);
	cout<<"图的邻接表为:\n";
	ShowALGraph(Graph);

	cout<<"拓扑序列为:\n";
	TopoSort(Graph);

	cout<<endl;

	return 0;
}


