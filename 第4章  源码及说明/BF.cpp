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
	if (j>=m)   return  i-j;  //匹配成功，返回子串在主串中首次出现的下标位置
	else       return  -1;  //匹配不成功，返回-1
}


int main()
{
	char s[MaxSize],t[]="转账";
	int flag;
	
	cout<<"请输入聊天信息：\n";
	cin>>s;
	flag=BF(s,t);
	if(flag!=-1)
		cout<<"***安全提示：如果聊天中提及财产，请一定先核实好友身份！***\n";
	
	return 0;
}


