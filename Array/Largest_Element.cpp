# include <stdio.h>

int main(){
	int n,i,arr[100],max;
	
	printf("Enter Number Of Elements:\n");
	scanf("%d",&n);
	
	printf("Enter %d Elements:\n",n);
	for(i=0;i<n;i++){	
		scanf("%d",&arr[i]);
	}
	
	max = arr[0];
	for(i=1;i<n;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	printf("Largest Element Is: %d\n",max);
	return 0;
}
