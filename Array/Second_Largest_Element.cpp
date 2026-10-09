# include <stdio.h>

int main(){
	int n,i,max1,max2,arr[100];
	
	printf("Enter Number Of Elements:\n");
	scanf("%d",&n);
	
	printf("Enter %d Elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	max1 = max2 = -99999;
	for(i=0; i<n; i++) {
		if(arr[i] > max1) {
			max2 = max1;
			max1 = arr[i];
		} else if(arr[i] > max2 && arr[i] < max1) {
			max2 = arr[i];
		}
	}
	
	if(max2 == -99999)
		printf("No second largest element\n");
	else
		printf("Second largest = %d\n", max2);
	
	return 0;
}
