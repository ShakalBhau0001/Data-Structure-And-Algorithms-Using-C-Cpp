#include <stdio.h>
#include <stdlib.h>
#define max 100

int arr[max];
int c = 0;


void display(){
	int i;
	
	if (c == 0){
		printf("\nArray Is Empty\n");
		return;
	}
	
	printf("\nArray Elements Are:\n");
	for(i=0;i<c;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\n");
}

void insertBeginning(int val){
	int i;
	
	if(c == max){
		printf("\nArray Is Full\n");
		return;
	}
	
	for(i=c;i>0;i--){ // Shifting logic
		arr[i] = arr[i-1];
	}
	
	arr[0] = val;
	c++;
}

void insertPosition(int val,int pos){
	int i;
	
	if(c == max){
		printf("\nArray Is Full\n");
		return;
	}
	
	if(pos < 1 || pos > c+1){
		printf("\nInvalid Position\n");
		return;
	}
	
	for(i=c;i>=pos;i--){
		arr[i] = arr[i-1];
	}
	
	arr[pos-1] = val;
	c++;
}

void insertEnd(int val){
	
	if(c == max){
		printf("\nArray Is Full\n");
		return;
	}
	
	arr[c++] = val;
}

void deleteBeginning(){
	int i;
	
	if(c == 0){
		printf("\nArray Is Empty\n");
		return;		
	}
	
	for(i=0;i<c-1;i++){
		arr[i] = arr[i+1];
	}
	
	c--;
}

void deletePosition(int pos){
	int i;
	
	if(c == 0){
		printf("\nArray Is Empty\n");
		return;			
	}
	
	if(pos < 1 || pos > c){
		printf("\nInvalid Position\n");
		return;
	}
	
	for(i=pos-1;i<c-1;i++){
		arr[i] = arr[i+1];
	}
	
	c--;
}

void deleteEnd(){
	
	if(c == 0){
		printf("\nArray Is Empty\n");
		return;			
	}
	c--;
}

int main(){
	int i,ch,val,pos;
	
	printf("\nEnter Number Of Elements:\n");
	scanf("%d",&c);
	
	if(c < 0 || c > max){
		printf("\nInvalid Size\n");
		return 1;
	}
	
	printf("\nEnter %d Elements: \n",c);
	for(i=0;i<c;i++){
		scanf("%d",&arr[i]);
	}
	
	do{

		printf("\n-----MENU-----\n");
		printf("\n1: Insert At Begin\n");
		printf("\n2: Insert At Position\n");
		printf("\n3: Insert At End\n");
		printf("\n4: Delete From Begin\n");
		printf("\n5: Delete From Position\n");
		printf("\n6: Delete From End\n");
		printf("\n7: Display\n");
		printf("\n8: Exit\n");
		printf("\nEnter Choice:\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter Value:");
				scanf("%d",&val);
				insertBeginning(val);
				display();
				break;
			
			case 2:
				printf("\nEnter Value:");
				scanf("%d",&val);
				printf("\nEnter Position(1-%d): ",c+1);
				scanf("%d",&pos);				
				insertPosition(val,pos);
				display();
				break;
				
			case 3:
				printf("\nEnter Value:");
				scanf("%d",&val);
				insertEnd(val);
				display();
				break;
				
			case 4:
				deleteBeginning();
				display();
				break;
			
			case 5:
				printf("\nEnter Position(1-%d): ",c);
				scanf("%d",&pos);
				deletePosition(pos);
				display();
				break;
				
			case 6:
				deleteEnd();
				display();
				break;
			
			case 7:
				display();
				break;
				
			case 8:
				exit(1);
				break;
			
			default:
				printf("\nInvalid Choice...\n");	
		}
	}while(ch!=8);
	return 0;
}
