#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
// ref: http://www.csie.ntnu.edu.tw/~u91029/Language.html

char* highOp="*";
char* lowOp="+";
long long unsigned cal(long long unsigned lv, char op,long long unsigned rv)
{
	if (op == '+')
	{
		return lv + rv;
	} 
	//if (op == '-') return lv - rv;
	if (op == '*')
	{
		return lv * rv;
	} 
	//if (op == '/') return lv / rv;
	return 0;   // crash
}
// �M��B��l����m�C�����X�A�G�q�k�ݧ�C
int findop(char* s,int L, int R, char* ops)
{
	int c = 0;
	for (int i=R; i>=L; --i)
	{
		if (s[i] == '(')
		{
			c++;
		} 
		if (s[i] == ')')
		{
			c--;
		} 		
		if (c == 0)
		{
			int size=strlen(ops);
			for(int j=0;j<size;j++)
			{
				if(s[i]==ops[j])
				{
					return i;
				}
			}

		}
	}
	return -1;
}

long long unsigned parse(char* s,int L, int R,int max)
{
	// �����u���v�̧C���B��Ÿ��C�̥����ѡB�̫�p��C

	char *a,*b;
	a=(max==0) ? lowOp : highOp;
	b=(max==0) ? highOp : lowOp;
	int	M = findop(s,L, R,a);

	// �䤣��C���A�A���u���v���C���B��Ÿ��C
	if (M == -1)
	{
		M=findop(s,L, R,b);
	} 
	// �B��Ÿ������k�⦡���j�U�h�D�o�T���ƭȡA�M��A�p��C
	// Unspecified Behavior�G�����B�k���A�������I�s�֡I
	if (M != -1)
	{
		return cal(parse(s,L, M-1,max), s[M], parse(s,M+1, R,max));
	}
	// �A��
	if (s[L] == '(' && s[R] == ')')
	{
		return parse(s,L+1, M-1,max);
	}
	// �ƭ�
	long long unsigned n = 0;
	for (int i=L; i<=R; ++i)
	{
		n = n * 10 + s[i] - '0';
	}
	return n;
	//return number(s,L, R);
}
 
long long unsigned evaluate(char* data,int len,int max)
{
  return parse(data,0, len-1,max);
}


int main()
{
	int size;
	char data[10000];
	scanf("%d", &size);
	for(int i=0;i<size;i++)
	{
		scanf("%s", &data);
		int len=strlen(data);
		printf("The maximum and minimum are %llu and %llu.\n",evaluate(data,len,1),evaluate(data,len,0));

	}

    return 0;
}


