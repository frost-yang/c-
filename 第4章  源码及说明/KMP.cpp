#include <iostream.h>
#include <stdlib.h>
#include <string.h>

const int MaxSize=100;
int next[MaxSize];
int nextval[MaxSize];
void getnext(char *t)
{
	int j,k,m;
	j=0; k= -1;
	m=strlen(t);
	next[0]= -1;
	while(j<m-1)   //ֻ��ѭ��m-1�Σ���Ϊÿ�ε�nextֵ��ǰ��ľ���
	{
		if(k== -1||t[j]==t[k])
		{ j++; k++; next[j]=k; }
		else  k=next[k];
	}
}

void getnextval(char *t)
{
	int j,k,m;
	j=0; k=-1;
	m=strlen(t);
	nextval[0]=-1;
	cout<<"nextval[0]="<<nextval[0]<<endl;
	while(j<m-1)
	{
		if(k==-1||t[j]==t[k])
		{
			j++;
			k++;
			if(t[j]!=t[k])  
				nextval[j]=k;
			else
				nextval[j]=nextval[k];
			cout<<"nextval["<<j<<"]="<<nextval[j]<<endl;
		}
		else k=nextval[k];
	}
}



int KMP (char *s, char *t)
{
	int i,j,m,n;
	i=0;j=0;
	n=strlen(s);m=strlen(t);
	while(i<n&&j<m)
	{
		if(j==-1||s[i]==t[j])
		{ i++;j++;}
		else  j=next[j];
	}
	if (j>=m)  return  i-m;
	else      return -1;
}


int main()
{
	char s[MaxSize],t[]="ת��";
	int flag;
	
	cout<<"������������Ϣ��\n";
	cin>>s;
	getnext(t);
	flag=KMP(s,t);
	if(flag!=-1)
		cout<<"***��ȫ��ʾ������������ἰ�Ʋ�����һ���Ⱥ�ʵ������ݣ�***\n";
	
	return 0;
}


