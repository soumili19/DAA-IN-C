#include<stdio.h>
#include<limits.h>
void Findminmax(int arr[],int n){
	int i;
	int min=INT_MAX;
	int max=INT_MIN;
	for(i=0;i<=n;i++){
		if(arr[i]>max)
		{
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	printf("The maximum element is %d",max);
	printf("The minimum element is %d",min);
}
int main()
{
	int n,i;
	printf("Enter the number of the elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the number : ");
	for(i=0;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	Findminmax(arr,n);
	return 0;
}
