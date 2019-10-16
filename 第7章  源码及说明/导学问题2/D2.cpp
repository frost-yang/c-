#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <fstream.h>

const MAX=100;
const INFINITY=9999;
enum GraphType{DG,UG,DN,UN};
typedef char VertexType[20];
typedef struct 
{
	VertexType vexs[MAX];   
	int arcs[MAX][MAX];     
	int vexnum,arcnum;      
	GraphType kind;        
} MGraph;


void CreateMGraph(MGraph &G)
{
	int i,j,va,vb,w;
	ifstream infile("data.txt");
	if (!infile.is_open())
	{ 
		cout<<"数据文件打开错误!\n";
		exit (1); 
	}
	G.kind=DN;      
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
	}
	infile.close();
}

void ShowMGraph(MGraph G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		cout<<G.vexs[i]<<endl;
}


/****************Floyd****************/
void Floyd(MGraph G,int path[][MAX],int D[][MAX])
{
	int i,j,k;
	for(i=0;i<G.vexnum;i++)        
	{
		for(j=0;j<G.vexnum;j++)
		{
			D[i][j]=G.arcs[i][j];			
			if(D[i][j]<INFINITY)   
				path[i][j]=j;
			else
				path[i][j]=-1;
		}
	}
	for(k=0;k<G.vexnum;k++)       
	{
		for(i=0;i<G.vexnum;i++)
		{
			for(j=0;j<G.vexnum;j++)	 


			{
				if(D[i][k]+D[k][j]<D[i][j])
				{
					D[i][j]=D[i][k]+D[k][j];		
					path[i][j]=path[i][k];			
				}
			}
		}
	}
}

void OutputPath(MGraph G,int path[][MAX],int D[][MAX],int i,int j)
{
	int next;		
	if(path[i][j]==-1)
		cout<<"两个景点间无路相通!"<<endl;
	else
	{		
		cout<<"从"<<G.vexs[i]<<"到"<<G.vexs[j]<<"的最少交通费用为:"<<D[i][j]<<endl;
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


/****************main****************/
int main()
{
	MGraph Graph;
	int path[MAX][MAX];
	int D[MAX][MAX];
        char name1[20],name2[20],choice='y';
	int i,j;
	
	CreateMGraph(Graph);
	Floyd(Graph,path,D);
		
	while(choice=='y'||choice=='Y')
	{
		cout<<"============欢迎使用旅游线路查询系统============\n";
		cout<<endl;
		cout<<"******景点******\n";
	    ShowMGraph(Graph);
		cout<<"************************\n";
		cout<<endl;
		cout<<"请输入起始景点名称:";
		cin>>name1;
		cout<<"请输入终点景点名称:";
		cin>>name2;
		for(i=0;i<Graph.vexnum;i++)
			if(strcmp(Graph.vexs[i],name1)==0)
				break;
		for(j=0;j<Graph.vexnum;j++)
			if(strcmp(Graph.vexs[j],name2)==0)
				break;
		if(i==Graph.vexnum||j==Graph.vexnum)
			cout<<"输入的景点名称有错，请重新输入!\n";
		else if(i==j)
			   cout<<"起点和终点相同!"<<endl;
		     else
			   OutputPath(Graph,path,D,i,j);
				
		cout<<"需要再次查询码？(Y/N):";
		cin>>choice;
	}	
	return 0;
}


