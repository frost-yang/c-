#include <iostream.h>
#include <stdlib.h>
#include "SeqQueue.h"

const MAX=100;
enum GraphType{DG,UG,DN,UN};//ͼ�����Ͷ��壺����ͼ������ͼ����������������
typedef char VertexType;
typedef struct 
{
	VertexType vexs[MAX];   //�����
	int arcs[MAX][MAX];     //�ڽӾ���
	int vexnum,arcnum;      //�������ͱ���
	GraphType kind;         //ͼ������
} MGraph;


void CreateMGraph(MGraph &G)
{
	int i,j,va,vb;
	G.kind=UG;      //����ͼ
	cout<<"������ͼ�Ķ�������";
	cin>>G.vexnum;
	cout<<"������ͼ�ı�����";
	cin>>G.arcnum;
	cout<<"�����붥�����Ϣ��";
	for(i=0;i<G.vexnum;i++)    
		cin>>G.vexs[i];
   for(i=0;i<G.vexnum;i++)     
	   for(j=0;j<G.vexnum;j++)
		   G.arcs[i][j]=0;
	cout<<"������ߵ���Ϣ��";
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
	cout<<"���㣺\n";
	for(i=0;i<G.vexnum;i++)
		cout<<G.vexs[i]<<" ";
	cout<<endl;
	cout<<"�ڽӾ���\n";
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			cout<<G.arcs[i][j]<<" ";
		cout<<endl;
	}
}


void BFSTraverse(MGraph G,int v)
{
	bool* visited=new bool[G.vexnum];
	SeqQueue  q;
	int i,j,u;
	InitQueue(q);
	for(i=0; i<G.vexnum; i++)
		visited[i]=false;
	
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			cout<<G.vexs[i]<<" ";
			visited[i]=true;
			EnQueue(q,i);
			while(!QueueEmpty(q))
			{
				
				u=DeQueue(q);
				for(j=0;j<G.vexnum;j++)
				{
					if(G.arcs[u][j]==1&& !visited[j])
					{
						cout<<G.vexs[j]<<" ";
						visited[j]=true;
						EnQueue(q,j);
					}
				}
			}
		}
	}	
	delete [] visited;
}



int main()
{
	MGraph Graph;
	CreateMGraph(Graph);

	ShowMGraph(Graph);

	cout<<"ͼ�Ĺ�����ȱ��������ǣ�";
	BFSTraverse(Graph,0);
	cout<<endl;

	return 0;
}


