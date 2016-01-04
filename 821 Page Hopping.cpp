#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

//all pairs shortest path
double floydWarshall(int graph[SIZE][SIZE],int len){
	int pi[SIZE][SIZE];
	int dst[SIZE][SIZE];
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(i==j)
			{
				pi[i][j]=-1;
			}
			else if(graph[i][j]!=0)
			{
				pi[i][j]=i;
				dst[i][j]=graph[i][j];
			}
			else 
			{
				dst[i][j]=1e3;
				pi[i][j]=-1;
			}	
		}
	}

	for(int k=0;k<len;k++)
	{
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<len;j++)
			{
				if (dst[i][j]>dst[i][k]+dst[k][j])
				{
					dst[i][j]=dst[i][k]+dst[k][j];
					pi[i][j]=pi[k][j];	
				}											
			}
		}
	}
	//print2DimArray(dst);
	int sum=0;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			sum+=dst[i][j];
		}
	}
	return (double)sum / (len*(len-1));
	
}

int convert(int* mark,int num,int* len){
	for(int i=0;i<*len;i++)
	{
		if(mark[i]==num)
		{
			return i;
		}
	}
	mark[*len]=num;
	return (*len)++;
}

int main()
{
	int graph[SIZE][SIZE];
	int mark[SIZE];
	int len=0;
	int caseNum=0;
	int x,y;
	
  while(true)
	{
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++){
				graph[i][j]=0;
			}
		}
    for(int i=0;i<SIZE;i++)
		{
			mark[i]=0;
		}		
		len=0;
		while(scanf("%d %d", &x, &y) == 2)
		{
			if(x==0&&y==0)
			{
				break;
			}
			graph[convert(mark,x,&len)][convert(mark,y,&len)]=1;
    }
    if(len==0)
		{
			break;
		}			
    printf("Case %d: average length between pages = %.3lf clicks\n",++caseNum,floydWarshall(graph,len));

  }
  return 0;
}


