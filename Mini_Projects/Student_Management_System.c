#include <stdio.h>
#include <string.h>
#define STD_MAX 50
#define Name 50

char std[STD_MAX][Name];
int count = 0;

void insertStudent(char[],int);
void deleteStudent(int);
void traverse();

int main(){
	int ch,pos;
	char name[Name];
	do{
		printf("\n----- STUDENT MANAGEMENT SYSTEM -----\n");
		printf("\n1: Insert Student\n");
		printf("\n2: Delete Student\n");
		printf("\n3: Display Student\n");
		printf("\n4: Exit\n");
		printf("\nEnter Choice:\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter Student Name:\n");
				getchar();
				scanf("%[^\n]",&name);
				printf("\nEnter Position (1-%d):\n",count+1);
				scanf("%d",&pos);
				insertStudent(name,pos);
				break;
				
			case 2:
				printf("\nEnter Position To Delete (1-%d):\n",count);
				scanf("%d",&pos);
				deleteStudent(pos);
				break;
				
			case 3:
				traverse();
				break;
				
			case 4:
				exit(1);
				break;
			
			default:
				printf("\nInvalid Choice!!!\n");
		}
	}while(ch!=4);
	return 0;
}

void traverse(){
	int i;
	if(count==0){
		printf("\nNo Students In Class...\n");
	}
	for(i=0;i<count;i++){
		printf("%d.%s\n",i+1,std[i]);
	}
}

void insertStudent(char name[],int pos){
	int i;
	if(count==STD_MAX){
		printf("\nClass Is Full..!!!\n");
		return;
	}
	if(pos<1||pos>count+1){
		printf("\nInvalid Position\n");
		return;
	}
	for(i=count;i>=pos;i--){
		strcpy(std[i],std[i-1]);
	}
	strcpy(std[pos-1],name);
	count++;
	printf("\nStudent Inserted...\n");
}

void deleteStudent(int pos){
	int i;
	if(count==0){
		printf("\nClass Is Empty\n");
		return;
	}
	if(pos<1||pos>count){
		printf("\nInvalid Position\n");
		return;		
	}
	for(i=pos-1;i<count-1;i++){
		strcpy(std[i],std[i+1]);
	}
	count--;
	printf("\nStudent Deleted...\n");	
}
