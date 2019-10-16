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

typedef struct 					//�ߵĶ���
{
	int head,tail;
	int cost;
}EdgeType;

void CreateMGraph(MGraph &G)
{
	int i,j,va,vb,w;
	G.kind=UN;      //������
	cout<<"������ͼ�Ķ�������";
	cin>>G.vexnum;
	cout<<"������ͼ�ı�����";
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
	cout<<"������ߵ���Ϣ������1 ����2 Ȩֵ����";
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

/****************Kruskal****************/
void GetGraph(MGraph G,EdgeType *graph)//���ɱ߼�����
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
	//����
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

void Kruskal(MGraph G, EdgeType *tree)	//Kruskal�㷨
{
	int i,j,k;
	EdgeType  *graph;             //�߼�����
	int *components;

	graph=new EdgeType[G.arcnum];
	GetGraph(G,graph);             //���ɱ߼�����

	components=new int[G.arcnum];	//��ʼ�����鼯
	for(i=0;i<G.vexnum;i++)
	{
		components[i]=i;				
	}

	k=0;		//���鼯�±�
	j=0;		//�߼��±�
	while(k<G.vexnum-1)
	{
		//���Ȩֵ��С�ߵ�ʼ����յ㣬���ж��Ƿ������·
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
			//�ϲ�
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

void PrintSubTree(MGraph G,EdgeType *tree)	//��ʾ��С������
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


