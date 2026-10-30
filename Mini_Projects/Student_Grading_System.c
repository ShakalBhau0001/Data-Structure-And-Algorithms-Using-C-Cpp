#include <stdio.h>

int main(){
	int choice;
	float marks;
	char grade;
	do{
		printf("=========== Student Grading System ===========\n");
		printf("1. Calculate Result\n");
		printf("2. Check Pass/Fail Status\n");
		printf("3. Exit\n");
		printf("Enter Your Choice:\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter Marks (0-100): \n");
				scanf("%f", &marks);
				
				if(marks < 0 || marks > 100){
					printf("Invalid Marks...\n");
				} else if (marks >= 90){
					grade = 'A';
				} else if (marks >= 75){
					grade = 'B';
				} else if (marks >= 60){
					grade = 'C';
				} else if (marks >= 40){
					grade = 'D';
				} else {
					grade = 'E';
				}
		}
	}while(choice != 3);
	return 0;
}
