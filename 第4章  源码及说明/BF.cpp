#include <iostream.h>
#include <stdlib.h>
#include <string.h>

const int MaxSize=100;
int BF(char *s, char *t)
{
	int i,j,m,n;
	i=0;j=0;
	n=strlen(s);m=strlen(t);
	while(i<n && j<m)
	{
		if(s[i]==t[j])
		{  i++;  j++;  }
		else 
		{  i=i-j+1;  j=0; 	}
	}
	if (j>=m)   return  i-j;  //ƥ��ɹ��������Ӵ����������״γ��ֵ��±�λ��
	else       return  -1;  //ƥ�䲻�ɹ�������-1
}


int main()
{
	char s[MaxSize],t[]="ת��";
	int flag;
	
	cout<<"������������Ϣ��\n";
	cin>>s;
	flag=BF(s,t);
	if(flag!=-1)
		cout<<"***��ȫ��ʾ������������ἰ�Ʋ�����һ���Ⱥ�ʵ������ݣ�***\n";
	
	return 0;
}


