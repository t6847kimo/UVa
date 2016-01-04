#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 30

// difficult, if use the next_permutation, will reach time limit

int main(){
	int cases;
	unsigned long long location;
	char input[MAX_LEN];
	int permutation[MAX_LEN];
	char output[MAX_LEN];
	scanf("%d",&cases);
	for(int c=0;c<cases;c++)
	{
		scanf("%s %llu",&input,&location);  //Biggest input = 20! so need be long long 
		location--;
		int length=strlen(input);
		unsigned long long pCount=1;
		bool marked[MAX_LEN]={0};
		for(int i=2;i<=length;i++)
		{
			pCount*=i;
		}
		for(int i=length;i>=1;i--)
		{
			unsigned long long div=(pCount/i);  //The divisor for each alphabet
			unsigned long long index=0;
			unsigned long long target = location/div;
			for(int x=0;x<length;x++)
			{
				if(index==target&&!marked[x]){
					index=x;
					break;
				}
				if(!marked[x])
				{
					index++;
				}                
			} 
			marked[index]=true;
			permutation[length-i]=index;
			location = location%div;
			pCount=pCount/i;
		}

		printf("Case %d: ",c+1);

		for(int i=0;i<length;i++)
		{
			output[permutation[i]]=input[i];
		}
		output[length]='\0';
		printf("%s\n",output);
	}
	system("pause");
  return 0;
    
}
