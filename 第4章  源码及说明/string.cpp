#include <iostream.h>
#include <stdlib.h>
#include <string.h>
const int MaxSize=100;

void StrCpy(char *s1, char *s2)  //复制
{
	int len=strlen(s2);
	if (len>MaxSize-1)  {cout<<"超长"; exit(1);}
	while (*s1++ = *s2++);
}

void StrCat (char *s1, char *s2)  //连接
{ 
	int len1=strlen(s1); 
	int len2=strlen(s2);
	if (len1+len2>MaxSize-1)  {cout<<"超长"; exit(1);}
	int i=0;
	while(s2[i]!='\0')  
	{
		s1[i+len1]=s2[i];
		i++; 
	}
	s1[i+len1]='\0';   
}

int StrCmp(char *s1, char *s2)  //比较
{ 
	int i=0;
	while (s1[i]==s2[i] && s1[i]!='\0')
		i++;
	return (s1[i]-s2[i]);
}


int main()
{
	char s[MaxSize]="ababcabcacbab",t[]="abcac";
	cout<<StrCmp(s,t)<<endl;
	StrCat(s,t);
	cout<<s<<endl;
	cout<<t<<endl;
	StrCpy(s,t);
	cout<<s<<endl;
	cout<<t<<endl;
	
	return 0;
}


