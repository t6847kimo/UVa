#include<stdio.h>
#include<stdlib.h>

// Modified Maximum Sub Array Problem
//http://www.csie.ntnu.edu.tw/~u91029/MaximumSubarray.html

int main(){
    int n;
    int in;
    scanf("%d",&n);
    while(n!=0){
                int sum=0,maxSum=0;
                for(int i=0;i<n;i++){
                        scanf("%d",&in);
                        sum+=in;
                        if(sum<0)sum=0;
                        if(sum>maxSum)maxSum=sum;
                }
                if(maxSum==0)
                          printf("Losing streak.\n");
                else
                    printf("The maximum winning streak is %d.\n",maxSum);
                scanf("%d",&n);
    }

    system("pause");
    return 0;
    
}
