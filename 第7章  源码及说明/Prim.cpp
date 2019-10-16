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

typedef struct 
{
	VertexType vex;	        //放置已经位于最小生成树的顶点名称
	float      lowcost;  	//存放交叉边的权值，为0时表示该点加入最小生成树
}Edge;

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

/****************Prim****************/
int MiniNum(MGraph G,Edge *miniedges)
{
	int i,j,mini;
	for(i=0;i<G.vexnum;i++)
	{
		if(miniedges[i].lowcost!=0)
		{
			mini=i;
			break;
		}
	}
	for(j=mini;j<G.vexnum;j++)
	{
		if(miniedges[mini].lowcost>miniedges[j].lowcost&&miniedges[j].lowcost!=0)
			mini=j;
	}
	return mini;
}

void Prim(MGraph G,int v)					//v为任取的prim起点		
{
	int i,j,k;
	Edge *miniedges=new Edge[G.vexnum];	    //存放候选交叉边
	for(i=0;i<G.vexnum;i++)				    //初始化候选交叉边
	{
		miniedges[i].vex=G.vexs[v];
		miniedges[i].lowcost=G.arcs[v][i];
	}	
	miniedges[v].lowcost=0;		 //表示起点v已经在最小生成树中
	for(i=1;i<G.vexnum;i++)
	{
		//选取出权值最小的候选交叉边，并加入生成树中
		k=MiniNum(G,miniedges);
		cout<<miniedges[k].vex<<"-->"<<G.vexs[k]<<endl;
		miniedges[k].lowcost=0;

		//调整候选交叉边，新增的点与和原来最小生成树相连的顶点的权值比较
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[k][j]<miniedges[j].lowcost)
			{
				miniedges[j].vex=G.vexs[k];
				miniedges[j].lowcost=G.arcs[k][j];
			}
		}
	}
	delete[] miniedges;
}


/****************main****************/
int main()
{
	MGraph Graph;

	CreateMGraph(Graph);
	ShowMGraph(Graph);
	Prim(Graph,0);

	cout<<endl;

	return 0;
}


