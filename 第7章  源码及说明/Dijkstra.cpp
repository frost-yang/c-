#include <iostream.h>
#include <stdlib.h>

const MAX=100;
const INFINITY=9999;
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
	int i,j,va,vb,w;
	G.kind=DN;      //������
	cout<<"������ͼ�Ķ�������";
	cin>>G.vexnum;
	cout<<"������ͼ�Ļ�����";
	cin>>G.arcnum;
	cout<<"�����붥�����Ϣ��";
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
	cout<<"�����뻡����Ϣ������1 ����2 Ȩֵ����";
	for(i=0;i<G.arcnum;i++)
	{
		cin>>va>>vb>>w;
		G.arcs[va][vb]=w;
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

/****************Dijkstra****************/
void Dijkstra(MGraph G,int v,int *path,int *dist)
//����ӱ��Ϊv�Ķ��㵽�����������·����path[]�д��·����dist[]�д��·������
{
	int i,j,k,min;
	bool *s=new bool[G.vexnum];
	for(i=0;i<G.vexnum;i++)
	{
		s[i]=false;
		dist[i]=G.arcs[v][i];                 //�����ʼ��
		if(dist[i]<INFINITY || i==v)          //·����ʼ��
			path[i]=v;
		else
			path[i]=-1;                        //��ʾ����iǰ�����㲻��v
	}
	dist[v]=0;
	s[v]=true;
	for(i=1;i<G.vexnum;i++)
	{
		min=INFINITY;                       
		for( j=0;j<G.vexnum;j++)               //ѡ�����ֵ��С�Ķ���k�����������·�����㼯��
			if(!s[j] && dist[j]<min)
			{
				k=j;
				min=dist[j];
			}
		s[k]=true; 
		
		for(int w=0;w<G.vexnum;w++)            //����ʣ�ඥ��ľ���
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
	if(m!=v)								     //���ǰ��������㣬��������
		SearchPre(G,path,path[k],v);
	cout<<G.vexs[m]<<"-->";		             	//ǰ����������ǰ��
}
void PrintPath(MGraph G,int *path,int *dist,int v)   //������·��
{
	for(int i=0;i<G.vexnum;i++)
	{
		cout<<"��"<<G.vexs[v]<<"��"<<G.vexs[i]<<"��·��Ϊ:"<<endl;
		SearchPre(G,path,i,v);			//���ǰ��
		cout<<G.vexs[i]<<endl;
		cout<<"����Ϊ:"<<dist[i]<<endl;
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


