#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//min max search//
void minmax(int arr[],int n){
    int i;
    int  min =INT_MAX, max=INT_MIN,;
    for(i=0;i<n;i++){
        if(arr[i]<min)
        min=arr[i];
        if(arr[i]>max)
        max=arr[i];
    }
    printf("The minimum number of the elements %d",min);
    printf("\n");
    printf("The maximum number of the elements %d",max);
    printf("\n");
}
int main(){
    int i,n;
    printf("Enter the number of the elemnts : \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements : \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    minmax(arr,n);
    return 0;
}
