#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30

bool inTarget(char in){
	const char *target="aeiou";
	for(int i=0;i<5;i++)
	{
		if(in==target[i]){
			return true;
		}
	}
	return false;
}

bool judge(char* a,char* b){
	int aLen=strlen(a);
	int bLen=strlen(b);
	if(aLen!=bLen)
	{
		return false;//
	}						 
	else
	{
		for(int i=0;i<aLen;i++)
		{
			if(a[i]!=b[i]&&(!inTarget(a[i])||!inTarget(b[i])))
			{
				return false;
			}
		}
		return true;
	}
}

int main(){
	int n;
	char a[SIZE],b[SIZE];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&a);
		scanf("%s",&b);
		if(judge(a,b)){
			printf("Yes\n"); 
		}
		else
		{
			printf("No\n");
		}
	}
	system("pause");
	return 0;
}
