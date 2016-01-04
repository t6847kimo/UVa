#include<stdio.h>
#include<stdlib.h>

//Difficult!
//idea : the last number equal to next number between two equations

int main(){
	int base,factor,beginDigits;
	while(scanf("%d %d %d",&base,&beginDigits,&factor)!=EOF)
	{
		int s=beginDigits*factor;
		int ans=1;
		while(s!=beginDigits)
		{
			s=(s%base)*factor+s/base;
			ans++;
		}
		printf("%d\n",ans);							
	}
	system("pause");
	return 0;
}

