# include <stdio.h>

int main(){
	int n,i,arr[100];
	
	printf("Enter Number Of Elements:\n");
	scanf("%d",&n);
	
	printf("Enter %d Elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Original Array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\nReversed Array:\n");
	for(i=n-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
