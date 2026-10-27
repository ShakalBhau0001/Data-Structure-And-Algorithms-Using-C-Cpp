#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev,*next;
};

struct node *head = NULL;

void createList(int);
void display();
void insertAtBeginning(int);
void insertAtMiddle(int,int);
void insertAtEnd(int);
void deleteAtBeginning();
void deleteAtMiddle(int);
void deleteAtEnd();

int main(){
	int num,ch,data,pos;
	printf("Enter Number Of Nodes To Create DLL: ");
	scanf("%d",&num);
	createList(num);
	display();
	while(1){
		printf("\n========== DOUBLE LINKED LIST ===========\n");
		printf("1. Insert At Beginning\n");
		printf("2. Insert At Middle\n");
		printf("3. Insert At End\n");
		printf("4. Delete At Beginning\n");
		printf("5. Delete At Middle\n");
		printf("6. Delete At End\n");
		printf("7. Display\n");
		printf("8. Exit\n");
		printf("Enter Choice: \n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter Data: \n");
				scanf("%d",&data);
				insertAtBeginning(data);
				display();
				break;
				
			case 2:
				printf("Enter Data: \n");
				scanf("%d",&data);
				printf("Enter Position After Which To Insert: \n");
				scanf("%d",&pos);
				insertAtMiddle(data,pos);
				display();
				break;
				
			case 3:
				printf("Enter Data: \n");
				scanf("%d",&data);
				insertAtEnd(data);
				display();
				break;
			
			case 4:
				deleteAtBeginning();
				display();
				break;
				
			case 5:
				printf("Enter Position To Delete: \n");
				scanf("%d",&pos);
				deleteAtMiddle(pos);
				display();
				break;
			
			case 6:
				deleteAtEnd();
				display();
				break;
			
			case 7:
				display();
				break;
			
			case 8:
				exit(0);
			
			default:
				printf("Enter Valid Choice...!!!\n");	
		}
	}
	return 0;
}

void createList(int n){
	struct node *newnode,*temp;
	int i;
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode == NULL){
			printf("Memory Allocation Failed!\n");
			return;
		}
		printf("Enter Data For Node: %d: ",i+1);
		scanf("%d",&newnode -> data);
		newnode -> prev = NULL;
		newnode -> next = NULL;
		if (head == NULL){
			head = temp = newnode;
		} else {
			temp -> next = newnode;
			newnode -> prev = temp;
			temp = newnode;
		}
	}
}

void insertAtBeginning(int data){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode == NULL) return;
	newnode -> data = data;
	newnode -> prev = NULL;
	newnode -> next = head;
	if(head != NULL){
		head -> prev = newnode;
	}
	head = newnode;
	printf("Node Inserted At Beginning...\n");
}

void insertAtMiddle(int data,int pos){
	struct node *newnode,*temp;
	int i;
	if(pos < 1 || head == NULL){
		printf("Invalid Position Or Empty List!!!\n");
		return;
	}
	temp = head;
	for(i = 1; i < pos && temp != NULL; i++){
		temp = temp -> next;
	}
	if(temp == NULL){
		printf("Position Not Found!!!\n");
		return;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode == NULL) return;
	newnode -> data = data;
	newnode -> next = temp -> next;
	newnode -> prev = temp;
	if(temp -> next != NULL){
		temp -> next -> prev = newnode;
	}
	temp -> next = newnode;
	printf("Node Inserted After Position %d\n", pos);
}

void insertAtEnd(int data){
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode == NULL) return;
	newnode -> data = data;
	newnode -> prev = NULL;
	newnode -> next = NULL;
	if (head == NULL){
		head = newnode;
	} else {
		temp = head;
		while (temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = newnode;
		newnode -> prev = temp;
	}
	printf("Node Inserted At End\n");
}

void deleteAtBeginning(){
	struct node *temp;
	if(head == NULL){
		printf("Double Linked List Is Empty...\n");
	} else {
		temp = head;
		head = head -> next;
		if(head != NULL){
			head -> prev = NULL;
		}
		free(temp);
		printf("Node Deleted From Beginning...\n");
	}
}

void deleteAtMiddle(int pos){
	struct node *temp,*del;
	int i;
	
	if(head == NULL || pos < 1){
		printf("Double Linked List Is Empty Or Position Is Invalid...\n");
		return;
	} else if (pos == 1){
		deleteAtBeginning();
		return;
	} else {
		temp = head;
		for(i=1;i<pos-1 && temp!=NULL;i++){
			temp = temp -> next;
		}
		if(temp == NULL || temp -> next == NULL){
			printf("Position Not Found!!!\n");
			return;
		}
		del = temp -> next;
		temp -> next = del -> next;
		if(del -> next != NULL){
			del -> next -> prev = temp;
		}
		free(del);
		printf("Node Deleted From Position %d\n",pos);
	}
}

void deleteAtEnd(){
	struct node *temp,*del;
	
	if(head == NULL){
		printf("Double Linked List Is Empty...\n");
	} else if(head -> next == NULL) {
		free(head);
		head = NULL;
		printf("Node Deleted From End...\n");
	} else {
		temp = head;
		while(temp -> next -> next != NULL){
			temp = temp -> next;
		}
		del = temp -> next;
		temp -> next = NULL;
		free(del);
		printf("Node Deleted From End...\n");
	}
}

void display(){
	struct node *temp = head;
	
	if(head == NULL){
		printf("Double Linked List Is Empty...\n");
	} else {
		printf("Double Linked List: ");
		printf("NULL <-> ");
		while(temp != NULL){
			printf("%d <-> ",temp -> data);
			temp = temp -> next;
		}
		printf("NULL\n");
	}
}

