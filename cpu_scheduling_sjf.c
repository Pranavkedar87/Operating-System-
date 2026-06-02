#include <stdio.h>
void get(int at[],int bt[],int n){
    for(int i=0;i<n;i++){
        printf("Enter the burst time: ");
        scanf("%d",&bt[i]);
        at[i]=0;
    }
}
void cal(int at[],int bt[],int wt[],int tat[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=1;j<(n-1)-i;j++){
            if(bt[j-1]>bt[j]){
            int temp = bt[j-1];
            bt[j-1]= bt[j];
            bt[j] = temp;
        }
    }
    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1]+bt[i-1];
        
    }
    for(int i=0;i<n;i++){
       
        tat[i] = wt[i]+bt[i];
    }

}
void result(int at[],int bt[],int tat[],int wt[],int n){
    printf("\nP\tat\tbt\ttat\twt\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],tat[i],wt[i]);
    }
}
int main(){
    printf("Enter the no of process: ");
    int n;
    scanf("%d",&n);
    int at[n];
    int bt[n];
    int wt[n];
    int tat[n];
    get(at,bt,n);
    cal(at,bt,wt,tat,n);
    result(at,bt,tat,wt,n);  
    
}