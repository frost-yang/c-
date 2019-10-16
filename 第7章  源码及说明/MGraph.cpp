#include <iostream.h>
#include <stdlib.h>

const MAX=100;
enum GraphType{DG,UG,DN,UN};//图的类型定义：有向图，无向图，有向网，无向网
typedef char VertexType;
typedef struct 
{
	VertexType vexs[MAX];   //顶点表
	int arcs[MAX][MAX];     //邻接矩阵
	int vexnum,arcnum;      //顶点数和边数
	GraphType kind;         //图的类型
} MGraph;


void CreateMGraph(MGraph &G)
{
	int i,j,va,vb;
	G.kind=UG;      //无向图
	cout<<"请输入图的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入图的边数：";
	cin>>G.arcnum;
	cout<<"请输入顶点的信息：";
	for(i=0;i<G.vexnum;i++)    
		cin>>G.vexs[i];
   for(i=0;i<G.vexnum;i++)     
	   for(j=0;j<G.vexnum;j++)
		   G.arcs[i][j]=0;
	cout<<"请输入边的信息：";
	for(i=0;i<G.arcnum;i++)
	{
		cin>>va>>vb;
		G.arcs[va][vb]=1;
		G.arcs[vb][va]=1;
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

bool visited[MAX]={false};          
void  DFS(MGraph G,int v)
{
	cout<<G.vexs[v];
	visited[v]=true;
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.arcs[v][i]!=0 && !visited[i])
			DFS(G,i);
	}
}
void  DFSTraverse(MGraph G)
{ 
    int i;
	for(i=0;i<G.vexnum;i++)
		if(!visited[i])
			DFS(G,i);   //对尚未访问的顶点调用DFS
}




int main()
{
	MGraph Graph;
	CreateMGraph(Graph);

	ShowMGraph(Graph);

	cout<<"图的深度优先遍历序列是：";
	DFSTraverse(Graph);
	cout<<endl;

	return 0;
}


