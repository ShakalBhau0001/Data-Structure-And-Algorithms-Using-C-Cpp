# include <stdio.h>

int main(){
	int n,i,k,arr[100],found=0;
	printf("Enter Number Of Elements:\n");
	scanf("%d",&n);
	printf("Enter %d Elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("Enter Element For Search:\n");
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(arr[i]==k){
			printf("Element Found at Index: %d\n", i);
			found=1;
			break;
		}
	}
	
	if(!found){
		printf("Element Not Found\n");
	}
	return 0;
}
