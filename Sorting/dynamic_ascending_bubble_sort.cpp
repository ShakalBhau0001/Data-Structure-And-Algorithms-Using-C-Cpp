// Dynamic Bubble Sort
// Ascending Order

# include <stdio.h>

int main(){
	int n,i,j,temp,arr[100];
	printf("Enter Number Of Elements:\n");
	scanf("%d",&n);
	printf("Enter %d Elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("\nBubble Sorted Array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
