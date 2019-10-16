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

/****************Floyd****************/
void Floyd(MGraph G,int path[][MAX],int D[][MAX])
{
	int i,j,k;
	for(i=0;i<G.vexnum;i++)        //��ʼ��D
	{
		for(j=0;j<G.vexnum;j++)
		{
			D[i][j]=G.arcs[i][j];			
			if(D[i][j]<INFINITY)    //��ʼ��path
				path[i][j]=j;
			else
				path[i][j]=-1;
		}
	}
	for(k=0;k<G.vexnum;k++)       //����
	{
		for(i=0;i<G.vexnum;i++)
		{
			for(j=0;j<G.vexnum;j++)	 //������vi->vj�в���vk�������Ƿ�Ϊ���̵�·��


			{
				if(D[i][k]+D[k][j]<D[i][j])
				{
					D[i][j]=D[i][k]+D[k][j];		//�������·������
					path[i][j]=path[i][k];			//�������·����vi�ĺ�̸�Ϊvk(������vj)
				}
			}
		}
	}
}


void OutputPath(MGraph G,int path[][MAX],int D[][MAX])
{
	int i,j,next;
	cout<<"����·��:"<<endl;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)	
		{
			cout<<"��"<<G.vexs[i]<<"��"<<G.vexs[j]<<"�����·������Ϊ:"<<D[i][j]<<endl;
			if(path[i][j]==-1)
				cout<<"�������·��!"<<endl;
			else
			{
				if(i==j)
				{
					cout<<"·��Ϊ:"<<G.vexs[i]<<endl;
				}
				else
				{
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


