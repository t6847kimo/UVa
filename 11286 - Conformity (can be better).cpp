#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 30
int courseNumber[10000][6];

bool _judge(int *a,int *b){
    //int count=0;
    for(int i=0;i<5;i++){
        bool found=false;
        for(int j=0;j<5;j++){
            if(a[i]==b[j]){
                found=true;
                //++count;
                break;              
            }
        }
        if(!found)return false;
    }
    //printf("%d\n",count);
    return true;
}

void judge(int index){
    //int count=0;
    for(int i=0;i<index;i++){
        if(_judge(courseNumber[i],courseNumber[index])){
            courseNumber[i][5]++;
            break;
        }
    }
    //printf("%d\n",count);
}
int main(){
    int n;
    
    while(true)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(int i=0;i<n;i++)
            courseNumber[i][5]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
                scanf("%d",&courseNumber[i][j]);
            judge(i);
        }
        int max=1;
        for(int i=0;i<n;i++)
            if(max<courseNumber[i][5])max=courseNumber[i][5];
        if(max!=1){
            int g=0;
            for(int i=0;i<n;i++)
                if(max==courseNumber[i][5])g+=max;
            //max-=max;
            max=g;
        }
        printf("%d\n",max==1 ? n : max);
        
    } 
    system("pause");
    return 0;
    
}
