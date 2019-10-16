#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

const MAX=100;
const INFINITY=9999;
enum GraphType{DG,UG,DN,UN};//图的类型定义：有向图，无向图，有向网，无向网
typedef char VertexType[20];
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

void CreateMGraph(MGraph &G,char *filename)
{
	int i,j,va,vb,w;
	ifstream infile(filename);;
	if (!infile.is_open())
	{ 
		cout<<"数据文件打开错误!\n";
		exit (1); 
	}

	G.kind=UN;      //无向网
	infile>>G.vexnum;
	infile>>G.arcnum;
	for(i=0;i<G.vexnum;i++)    
		infile>>G.vexs[i];
   for(i=0;i<G.vexnum;i++)     
	   for(j=0;j<G.vexnum;j++)
	   {
		   if(i==j)
			   G.arcs[i][j]=0;
		   else
			   G.arcs[i][j]=INFINITY;
	   }
	for(i=0;i<G.arcnum;i++)
	{
		infile>>va>>vb>>w;
		G.arcs[va][vb]=w;
		G.arcs[vb][va]=w;
	}
	infile.close();
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
	char *filename="result.txt";
	ofstream outfile(filename);
	if (! outfile.is_open())
	{ 
		cout<<"结果文件打开错误!\n";
		exit (1); 
	}
    outfile<<"通信线路构造方案为："<<endl;

	for(i=0;i<G.vexnum;i++)				    //初始化候选交叉边
	{
		strcpy(miniedges[i].vex,G.vexs[v]);
		miniedges[i].lowcost=G.arcs[v][i];
	}	
	miniedges[v].lowcost=0;		 //表示起点v已经在最小生成树中
	for(i=1;i<G.vexnum;i++)
	{
		//选取出权值最小的候选交叉边，并加入生成树中
		k=MiniNum(G,miniedges);
		outfile<<miniedges[k].vex<<"-->"<<G.vexs[k]<<endl;
		miniedges[k].lowcost=0;

		//调整候选交叉边，新增的点与和原来最小生成树相连的顶点的权值比较
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[k][j]<miniedges[j].lowcost)
			{
				strcpy(miniedges[j].vex,G.vexs[k]);
				miniedges[j].lowcost=G.arcs[k][j];
			}
		}
	}
	delete[] miniedges;
	outfile.close();
}


/****************main****************/
int main()
{
	MGraph Graph;
	char filename[20];

	cout<<"请输入存放城市间通信线路代价的文件名:";
	cin>>filename;
	CreateMGraph(Graph,filename);
	Prim(Graph,0);
	cout<<endl;

	return 0;
}


