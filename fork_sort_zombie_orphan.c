#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>   
void sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-i;j++){
            if(a[j-1]>a[j]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }

    }
}
void result(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
   pid_t pid = fork();
   int a[] = {7,4,6,2};
   int n =4;
   if(pid> 0){
    printf("Parent ID: %d\n",getpid());
    
    printf("Array Before sort:\n");
    result(a,n);
    sort(a,n);
    printf("\n");
     printf("Array After sort:\n");
    result(a,n);
     printf("\n");
    //printf("Parent exisiting...."); //Orphan
    //exit(0); //otphan


    
    //sleep(5); //zombie
    wait(NULL); //Noramal
   }
   else if(pid ==0) {
    //sleep(5);
    printf("Child ID: %d\n",getpid());
    printf("Array Before sort:\n");
    result(a,n);
     printf("\n");
    sort(a,n);
     printf("Array After sort:\n");
    result(a,n);
     printf("\n");
    //printf("Child exiting....\n"); // zombie
    //printf("New Parent ID: %d\n",getppid()); // orphan
    

   }
   return 0;
}