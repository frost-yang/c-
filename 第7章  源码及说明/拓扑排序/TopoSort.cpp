#include <iostream.h>
#include <stdlib.h>
#include "SeqQueue.h"

const MAX=100;
enum GraphType{DG,UG,DN,UN};//ͼ�����Ͷ��壺����ͼ������ͼ����������������
typedef char VertexType;
typedef struct EdgeNode        //�߱�Ľ������
{          
	int adjvex;                // �ڽӵ�洢λ��
	EdgeNode* next;            // ָ����һ���ڽӵ�
}*EdgeList;
typedef struct                //������Ԫ������
{          
	VertexType data;         // ������Ϣ
	EdgeList firstedge;     // �߱��ͷָ��
}VexNode;
typedef struct 
{
	VexNode adjlist[MAX];   //�����
	int vexnum,arcnum;      //�������ͱ���
	GraphType kind;        //ͼ������
} ALGraph;



void CreateALGraph(ALGraph &G)
{
	int i,va,vb;
	EdgeList p;
	G.kind=UG;      //����ͼ
	cout<<"������ͼ�Ķ�������";
	cin>>G.vexnum;
	cout<<"������ͼ�ı�����";
	cin>>G.arcnum;
	cout<<"�����붥�����Ϣ��";
	for(i=0;i<G.vexnum;i++) 
	{
		cin>>G.adjlist[i].data;
		G.adjlist[i].firstedge=NULL;
	}

	cout<<"������ߵ���Ϣ(����1 ����2)��";
	for(i=0;i<G.arcnum; i++ )    //�����������еıߵ���Ϣ
	{
		cin>>va>>vb;             // ����һ�����ڽӵ�������������
		p=new EdgeNode;          //������һ���߱����
		p->adjvex=vb;
		p->next=G.adjlist[va].firstedge;  // ���ڱ�ͷ
		G.adjlist[va].firstedge=p;
		
	}
}

void ShowALGraph(ALGraph G)
{
	int i;
	EdgeList p;

	for(i=0;i<G.vexnum;i++)
	{
		cout<<G.adjlist[i].data<<":";
		p=G.adjlist[i].firstedge;
		while(p)
		{
			cout<<p->adjvex<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}


void TopoSort(ALGraph G)
{
	int *indegree=new int[G.vexnum];
	EdgeList p;
	SeqQueue s;
	int i,c;

	InitQueue(s);
	for(i=0;i<G.vexnum;i++)    //��ʼ�����������
		indegree[i]=0;
	for(i=0;i<G.vexnum;i++)     //�������������         
	{
		p=G.adjlist[i].firstedge;
		while(p)
		{
			indegree[p->adjvex]++;
			p=p->next;
		}
	}
	for(i=0;i<G.vexnum;i++)             //�����Ϊ0�Ķ������
	{
		if(!indegree[i])
			EnQueue(s,i); 
	}

	c=0;                       //������������
	while(!QueueEmpty(s))
	{
		i=DeQueue(s);               //����
		cout<<G.adjlist[i].data;    //�������
		c++;
        p=G.adjlist[i].firstedge;
		while(p)                   //��Ӧ��ͷ������ȼ�1
		{
			indegree[p->adjvex]--;
	    	if(!indegree[p->adjvex])
			    EnQueue(s,p->adjvex);
			p=p->next;
		}
	}
	if(c<G.vexnum)
		cout<<"�� AOV �����ڻ�·!"<<endl;
	delete[] indegree;
}


int main()
{
	ALGraph Graph;
	CreateALGraph(Graph);
	cout<<"ͼ���ڽӱ�Ϊ:\n";
	ShowALGraph(Graph);

	cout<<"��������Ϊ:\n";
	TopoSort(Graph);

	cout<<endl;

	return 0;
}


