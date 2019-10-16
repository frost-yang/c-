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
		cout<<"�����ļ��򿪴���!\n";
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
		cout<<"�����������·��ͨ!"<<endl;
	else
	{		
		cout<<"��"<<G.vexs[i]<<"��"<<G.vexs[j]<<"�����ٽ�ͨ����Ϊ:"<<D[i][j]<<endl;
		cout<<"·��Ϊ:"<<G.vexs[i];  
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
		cout<<"============��ӭʹ��������·��ѯϵͳ============\n";
		cout<<endl;
		cout<<"******����******\n";
	    ShowMGraph(Graph);
		cout<<"************************\n";
		cout<<endl;
		cout<<"��������ʼ��������:";
		cin>>name1;
		cout<<"�������յ㾰������:";
		cin>>name2;
		for(i=0;i<Graph.vexnum;i++)
			if(strcmp(Graph.vexs[i],name1)==0)
				break;
		for(j=0;j<Graph.vexnum;j++)
			if(strcmp(Graph.vexs[j],name2)==0)
				break;
		if(i==Graph.vexnum||j==Graph.vexnum)
			cout<<"����ľ��������д�����������!\n";
		else if(i==j)
			   cout<<"�����յ���ͬ!"<<endl;
		     else
			   OutputPath(Graph,path,D,i,j);
				
		cout<<"��Ҫ�ٴβ�ѯ�룿(Y/N):";
		cin>>choice;
	}	
	return 0;
}


