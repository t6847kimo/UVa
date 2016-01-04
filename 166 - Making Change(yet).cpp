#include<stdio.h>
#include<stdlib.h>
#define abs(x) ((x)> 0 ? (x) : (x)*(-1) )
int coinPrice[6]={5,10,20,50,100,200};
int coinCount[6];
bool checkBreak(int* in){
    for(int i=0;i<6;i++)
    {
        if(in[i]!=0)
            return false;    
    }
    return true;
}
int findClosest(int total){
    int minimum=1000;
    int index=0;
    if(total%2==1&&coinCount[0]>0)
        return 0;
    if(total>=50&&coinCount[4]>0)
        return 4;
    for(int i=0;i<6;i++){
        int dist=abs(coinPrice[i]-total);
        if(coinCount[i]>0&&minimum>dist){
            minimum=dist;
            index=i;
            //total-=coinPrice[i];
            //--coinCount[i];
        }
    }
    //printf("index=%d\n",index);
    return index;
}
int findClosest2(int total){
    int minimum=1000;
    int index=0;
    for(int i=0;i<6;i++){
        int dist=abs(coinPrice[i]-total);
        if(minimum>dist){
            minimum=dist;
            index=i;
        }
    }
    //printf("index=%d\n",index);
    return index;
}
int main(){
    int n1,n2;
    int total;
    
    while(true)
    {
        for(int i=0;i<6;i++)
            scanf("%d",&coinCount[i]);
        if(checkBreak(coinCount))
            break;
        scanf("%d.%d",&n1,&n2);
        //printf("%f\n",n);
        total=n1*100+n2;
        bool changing=false;
        int count=0;
        while(total>0){
            int i=findClosest(total);
            total-=coinPrice[i];
            --coinCount[i];
            count++;
        }
        total*=-1;
        while(total!=0){
            int i=findClosest2(total);
            total-=coinPrice[i];
            //--coinCount[i];
            count++;
        }
        //for(int i=0;i<6;i++){printf("%d ",coinCount[i]);}
        //if(total%10!=0)++total;
        printf("%d\n",count);

        
    } 
    system("pause");
    return 0;
    
}
