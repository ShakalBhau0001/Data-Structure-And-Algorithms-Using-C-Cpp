// Bubble Sort 
// Ascending Order

#include <stdio.h>

int main(){
	int arr[5] = {64,25,12,22,11};
	int i,j,temp,n=5;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("Bubble Sorted Array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
