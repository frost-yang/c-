#include <iostream.h>
#include <stdlib.h>

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

	cout<<"请输入边的信息：";
	for(i=0;i<G.arcnum; i++ )    //依次输入所有的边的信息
	{
		cin>>va>>vb;             // 输入一条边邻接的两个顶点的序号
		p=new EdgeNode;          //产生第一个边表结结点
		p->adjvex=vb;
		p->next=G.adjlist[va].firstedge;  // 插在表头
		G.adjlist[va].firstedge=p;
		p=new EdgeNode;         // 产生第二个边表结点
		p->adjvex=va;
		p->next=G.adjlist[vb].firstedge; // 插在表头
		G.adjlist[vb].firstedge=p;
	}
}

void ShowALGraph(ALGraph G)
{
	int i,j;
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

int main()
{
	ALGraph Graph;

	CreateALGraph(Graph);
	ShowALGraph(Graph);
	cout<<endl;

	return 0;
}


