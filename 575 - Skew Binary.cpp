#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 50
int main(){
	char in[MAX_LEN];
	while(scanf("%s",&in))
	{
		if(in[0]=='0')
		{
			break;
		}		
		int len=strlen(in);
		int base=1;
		int sum=0;
		for(int i=0;i<len;i++)
		{
			base*=2;
			sum += (base-1) * (in[len-1-i] - '0');				
		}
		printf("%d\n",sum);                         
	}
	system("pause");
	return 0;
}
