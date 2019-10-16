#include <iostream.h>
#include <stdlib.h>

const MAX=100;
const INFINITY=9999;
enum GraphType{DG,UG,DN,UN};//图的类型定义：有向图，无向图，有向网，无向网
typedef char VertexType;
typedef struct 
{
	VertexType vexs[MAX];   //顶点表
	int arcs[MAX][MAX];     //邻接矩阵
	int vexnum,arcnum;      //顶点数和边数
	GraphType kind;         //图的类型
} MGraph;

typedef struct 					//边的定义
{
	int head,tail;
	int cost;
}EdgeType;

void CreateMGraph(MGraph &G)
{
	int i,j,va,vb,w;
	G.kind=UN;      //无向网
	cout<<"请输入图的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入图的边数：";
	cin>>G.arcnum;
	cout<<"请输入顶点的信息：";
	for(i=0;i<G.vexnum;i++)    
		cin>>G.vexs[i];
   for(i=0;i<G.vexnum;i++)     
	   for(j=0;j<G.vexnum;j++)
	   {
		   if(i==j)
			   G.arcs[i][j]=0;
		   else
			   G.arcs[i][j]=INFINITY;
	   }
	cout<<"请输入边的信息（顶点1 顶点2 权值）：";
	for(i=0;i<G.arcnum;i++)
	{
		cin>>va>>vb>>w;
		G.arcs[va][vb]=w;
		G.arcs[vb][va]=w;
	}
}

void ShowMGraph(MGraph G)
{
	int i,j;
	cout<<"顶点：\n";
	for(i=0;i<G.vexnum;i++)
		cout<<G.vexs[i]<<" ";
	cout<<endl;
	cout<<"邻接矩阵：\n";
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			cout<<G.arcs[i][j]<<" ";
		cout<<endl;
	}
}

/****************Kruskal****************/
void GetGraph(MGraph G,EdgeType *graph)//生成边集数组
{
	int k=0;	             
	int i,j;
	EdgeType tmp;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=i+1;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]!=INFINITY)
			{
				graph[k].head=i;
				graph[k].tail=j;
				graph[k].cost=G.arcs[i][j];
				k++;
			}
		}
	}
	//排序
	for(i=1;i<G.arcnum;i++)	
	{
		for(j=0;j<G.arcnum-i;j++)	
		{
			if(graph[j].cost>graph[j+1].cost)
			{
				tmp.head=graph[j].head,tmp.tail=graph[j].tail,tmp.cost=graph[j].cost;
				graph[j].head=graph[j+1].head,graph[j].tail=graph[j+1].tail,graph[j].cost=graph[j+1].cost;
				graph[j+1].head=tmp.head,graph[j+1].tail=tmp.tail,graph[j+1].cost=tmp.cost;
			}
		}
	}
}

void Kruskal(MGraph G, EdgeType *tree)	//Kruskal算法
{
	int i,j,k;
	EdgeType  *graph;             //边集数组
	int *components;

	graph=new EdgeType[G.arcnum];
	GetGraph(G,graph);             //生成边集数组

	components=new int[G.arcnum];	//初始化并查集
	for(i=0;i<G.vexnum;i++)
	{
		components[i]=i;				
	}

	k=0;		//并查集下标
	j=0;		//边集下标
	while(k<G.vexnum-1)
	{
		//获得权值最小边的始点和终点，并判断是否产生回路
		int h1=graph[j].head;
		int t1=graph[j].tail;

		int h2=components[h1];	
		int t2=components[t1];
		if(h2!=t2)	
		{
			tree[k].head=h1;
			tree[k].tail=t1;
			tree[k].cost=graph[j].cost;
			k++;
			//合并
			for(i=0;i<G.vexnum;i++)
			{
				if(components[i]==t2)	
					components[i]=h2;
			}
		}
		j++;
	}
	delete[] components;
	delete[] graph; 
}

void PrintSubTree(MGraph G,EdgeType *tree)	//显示最小生成树
{
	int i=0;
	while(i<G.vexnum-1)
	{
		int h1=tree[i].head;
		int h2=tree[i].tail;
		cout<<G.vexs[h1]<<"-->"<<G.vexs[h2]<<endl;
		i++;
	}
}


/****************main****************/
int main()
{
	MGraph Graph;
	EdgeType *Tree;

	CreateMGraph(Graph);
	ShowMGraph(Graph);

	Tree=new EdgeType[Graph.arcnum-1];
	Kruskal(Graph, Tree);
	PrintSubTree(Graph, Tree);	
	cout<<endl;

	delete[] Tree;
	return 0;
}


