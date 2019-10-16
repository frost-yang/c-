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

/****************Floyd****************/
void Floyd(MGraph G,int path[][MAX],int D[][MAX])
{
	int i,j,k;
	for(i=0;i<G.vexnum;i++)        //初始化D
	{
		for(j=0;j<G.vexnum;j++)
		{
			D[i][j]=G.arcs[i][j];			
			if(D[i][j]<INFINITY)    //初始化path
				path[i][j]=j;
			else
				path[i][j]=-1;
		}
	}
	for(k=0;k<G.vexnum;k++)       //迭代
	{
		for(i=0;i<G.vexnum;i++)
		{
			for(j=0;j<G.vexnum;j++)	 //依次在vi->vj中插入vk并测试是否为更短的路径


			{
				if(D[i][k]+D[k][j]<D[i][j])
				{
					D[i][j]=D[i][k]+D[k][j];		//调整最短路径长度
					path[i][j]=path[i][k];			//调整最短路径，vi的后继改为vk(本来是vj)
				}
			}
		}
	}
}


void OutputPath(MGraph G,int path[][MAX],int D[][MAX])
{
	int i,j,next;
	cout<<"所有路径:"<<endl;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)	
		{
			cout<<"从"<<G.vexs[i]<<"到"<<G.vexs[j]<<"的最短路径长度为:"<<D[i][j]<<endl;
			if(path[i][j]==-1)
				cout<<"两点间无路径!"<<endl;
			else
			{
				if(i==j)
				{
					cout<<"路径为:"<<G.vexs[i]<<endl;
				}
				else
				{
					cout<<"路径为:"<<G.vexs[i];  
					next = path[i][j];  
					while(next != j) 
					{  
						cout<<"-->"<<G.vexs[next];  
						next=path[next][j];  
					}  
					cout<<"->"<<G.vexs[j]<<endl; 
				}
			}
		}
		cout<<endl;
	}
}


/****************main****************/
int main()
{
	MGraph Graph;
	int path[MAX][MAX];
	int D[MAX][MAX];
    
	CreateMGraph(Graph);
	ShowMGraph(Graph);
	cout<<endl;


	Floyd(Graph,path,D);

	OutputPath(Graph,path,D);

	return 0;
}


