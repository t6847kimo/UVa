#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 100

typedef struct straw{
    int x1,x2,y1,y2;
};

bool connect[MAX_LEN][MAX_LEN]={0};

straw straws[MAX_LEN];
int index=0;
void check(int x1,int x2){
    for(int i=0;i<index;i++);
}
void insert(int x1,int x2,int y1,int y2){
    straws[index].x1=x1;
    straws[index].x2=x2;
    straws[index].y1=y1;
    straws[index++].y2=y2;
}
int main(){
    int cases;
    
    scanf("%d",&cases);
    scanf("\n");
    
    for(int c=0;c<cases;c++)
    {
        int inputs;
        scanf("%d",&inputs);
        for(int j=0;j<inputs;j++){
            int x1,x2,y1,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            insert(x1,x2,y1,y2);
            printf("%d %d %d %d",x1,y1,x2,y2);
        }
        int straw1,straw2;
        do 
        {
            scanf("%d %d",&straw1,&straw2);  
        } while(straw1!=0&&straw2!=0);                        
    }
    system("pause");
    return 0;
}
