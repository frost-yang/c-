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

typedef struct 
{
	VertexType vex;	        //�����Ѿ�λ����С�������Ķ�������
	float      lowcost;  	//��Ž���ߵ�Ȩֵ��Ϊ0ʱ��ʾ�õ������С������
}Edge;

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

void Prim(MGraph G,int v)					//vΪ��ȡ��prim���		
{
	int i,j,k;
	Edge *miniedges=new Edge[G.vexnum];	    //��ź�ѡ�����
	for(i=0;i<G.vexnum;i++)				    //��ʼ����ѡ�����
	{
		miniedges[i].vex=G.vexs[v];
		miniedges[i].lowcost=G.arcs[v][i];
	}	
	miniedges[v].lowcost=0;		 //��ʾ���v�Ѿ�����С��������
	for(i=1;i<G.vexnum;i++)
	{
		//ѡȡ��Ȩֵ��С�ĺ�ѡ����ߣ���������������
		k=MiniNum(G,miniedges);
		cout<<miniedges[k].vex<<"-->"<<G.vexs[k]<<endl;
		miniedges[k].lowcost=0;

		//������ѡ����ߣ������ĵ����ԭ����С�����������Ķ����Ȩֵ�Ƚ�
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


