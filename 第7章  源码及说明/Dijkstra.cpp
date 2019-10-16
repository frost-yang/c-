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


void CreateMGraph(MGraph &G)
{
	int i,j,va,vb,w;
	G.kind=DN;      //有向网
	cout<<"请输入图的顶点数：";
	cin>>G.vexnum;
	cout<<"请输入图的弧数：";
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
	cout<<"请输入弧的信息（顶点1 顶点2 权值）：";
	for(i=0;i<G.arcnum;i++)
	{
		cin>>va>>vb>>w;
		G.arcs[va][vb]=w;
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

/****************Dijkstra****************/
void Dijkstra(MGraph G,int v,int *path,int *dist)
//求出从编号为v的顶点到其余各点的最短路径，path[]中存放路径，dist[]中存放路径长度
{
	int i,j,k,min;
	bool *s=new bool[G.vexnum];
	for(i=0;i<G.vexnum;i++)
	{
		s[i]=false;
		dist[i]=G.arcs[v][i];                 //距离初始化
		if(dist[i]<INFINITY || i==v)          //路径初始化
			path[i]=v;
		else
			path[i]=-1;                        //表示顶点i前驱顶点不是v
	}
	dist[v]=0;
	s[v]=true;
	for(i=1;i<G.vexnum;i++)
	{
		min=INFINITY;                       
		for( j=0;j<G.vexnum;j++)               //选择距离值最小的顶点k，并加入最短路径顶点集中
			if(!s[j] && dist[j]<min)
			{
				k=j;
				min=dist[j];
			}
		s[k]=true; 
		
		for(int w=0;w<G.vexnum;w++)            //调整剩余顶点的距离
			if(!s[w] && dist[w]>dist[k]+G.arcs[k][w])
			{
				dist[w]=dist[k]+G.arcs[k][w];
			    path[w]=k;
			}
	}
	delete[]s;
}


void SearchPre(MGraph G,int *path,int k,int v)				
{
	int m=path[k];
	if(m!=v)								     //如果前驱不是起点，继续遍历
		SearchPre(G,path,path[k],v);
	cout<<G.vexs[m]<<"-->";		             	//前驱是起点输出前驱
}
void PrintPath(MGraph G,int *path,int *dist,int v)   //输出最短路径
{
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<"从"<<G.vexs[v]<<"到"<<G.vexs[i]<<"的路径为:"<<endl;
		SearchPre(G,path,i,v);			//输出前驱
		cout<<G.vexs[i]<<endl;
		cout<<"长度为:"<<dist[i]<<endl;
		cout<<endl;
	}
}

/****************main****************/
int main()
{
	MGraph Graph;
	int *path,*dist;

	CreateMGraph(Graph);
	ShowMGraph(Graph);

	path=new int[Graph.vexnum];
	dist=new int[Graph.vexnum];
	Dijkstra(Graph,0,path,dist);
	PrintPath(Graph,path,dist,0);

	/*for(int i=0;i<Graph.vexnum;i++)
		cout<<path[i]<<" ";
	cout<<endl;

	for(int j=0;j<Graph.vexnum;j++)
		cout<<dist[j]<<" ";
	cout<<endl;*/

	delete[] path;
	delete[] dist;
	return 0;
}


