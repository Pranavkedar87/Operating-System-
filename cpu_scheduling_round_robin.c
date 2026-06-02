#include <stdio.h>
int main(){
    printf("Enter the no of process: ");
    int n;
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    printf("Enter the arrival time:\n");
    for(int i=0;i<n;i++){
        printf("Enter the arrival of %d:",i);
        scanf("%d",&at[i]);
    }
    printf("Enter the burest time:\n");
    for(int i=0;i<n;i++){
        printf("Enter the burest of %d:",i);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    int tq,time=0;
    printf("Enter the time quntaum:");
    scanf("%d",&tq);
    int r=n;
    while(r != 0){
        int done=1;
        for(int i=0;i<n;i++){
            if(rt[i]>0&&at[i]<=time){
                done=0;
                if(rt[i]>tq){
                    rt[i]-=tq;
                    time += tq;
                }else{
                    time+=rt[i];
                    ct[i]=time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    rt[i]=0;
                    r--;
                }
            }
        }
        if(done ==1){
            time++;
        }

    }
    printf("p\tat\tbt\twt\ttat\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],wt[i],tat[i]);
    }
}