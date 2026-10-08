# include <stdio.h>

int main(){
	int n,i,arr1[100],arr2[100];
	
	printf("Enter Number Of Elements:\n");
	scanf("%d",&n);
	
	printf("Enter %d Elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}
	
	printf("Original Array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr1[i]);
	}
	
	for(i=0;i<n;i++){
		arr2[i] = arr1[i];
	}
	
	printf("\nCopied Array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr2[i]);
	}
	
	return 0;
}
