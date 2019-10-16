#include <iostream.h>
#include <stdlib.h>

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

	cout<<"������ߵ���Ϣ��";
	for(i=0;i<G.arcnum; i++ )    //�����������еıߵ���Ϣ
	{
		cin>>va>>vb;             // ����һ�����ڽӵ�������������
		p=new EdgeNode;          //������һ���߱����
		p->adjvex=vb;
		p->next=G.adjlist[va].firstedge;  // ���ڱ�ͷ
		G.adjlist[va].firstedge=p;
		p=new EdgeNode;         // �����ڶ����߱���
		p->adjvex=va;
		p->next=G.adjlist[vb].firstedge; // ���ڱ�ͷ
		G.adjlist[vb].firstedge=p;
	}
}

void ShowALGraph(ALGraph G)
{
	int i,j;
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

int main()
{
	ALGraph Graph;

	CreateALGraph(Graph);
	ShowALGraph(Graph);
	cout<<endl;

	return 0;
}


