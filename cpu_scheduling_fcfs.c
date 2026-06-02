#include <stdio.h>
void get(int n,int at[],int bt[]){
    for(int i=0;i<n;i++){
        printf("Enter the Arrival time of %d process",i);
        scanf("%d",&at[i]);
         printf("Enter the Busrt time of %d process",i);
        scanf("%d",&bt[i]);
    }
} 
void cal(int at[],int bt[],int ct[],int tat[], int wt[],int n){
    ct[0] = at[0]+bt[0];
    for(int i=1;i<n;i++){
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
        }else{
            ct[i]=ct[i-1]+bt[i];
        }

    }
    for(int i=0;i<n;i++){
        tat[i] = ct[i]-at[i];
        wt[i] = tat[i]-bt[i];
    }
}
void result(int at[],int bt[],int ct[],int tat[],int wt[],int n){
    printf("\nP\tat\tbt\ttat\tbt\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],tat[i],wt[i]);
    }
}
int main(){
    int n;
    
    printf("Enter the no of process:");
    scanf("%d",&n); 
    int at[n];
    int bt[n];
    int ct[n];
    int tat[n];
    int wt[n];
    get(n,at,bt);
    cal(at,bt,ct,tat,wt,n);
    result(at,bt,ct,tat,wt,n);
    
}