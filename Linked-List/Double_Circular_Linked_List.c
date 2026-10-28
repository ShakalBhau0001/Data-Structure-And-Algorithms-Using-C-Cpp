#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next,*prev;
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
	printf("Enter Number Of Nodes To Create DCLL: ");
	scanf("%d",&num);
	createList(num);
	display();
	while(1){
		printf("\n========== DOUBLE CIRCULAR LINKED LIST ===========\n");
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
    struct node *newnode, *temp;
    int i;

    for(i = 0; i < n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));

        if(newnode == NULL){
            printf("Memory Allocation Failed!\n");
            return;
        }

        printf("Enter Data For Node: %d: ", i+1);
        scanf("%d", &newnode -> data);

        if(head == NULL){
            head = temp = newnode;
            newnode -> next = head;
            newnode -> prev = head;
        } else {
            newnode -> prev = temp;
            newnode -> next = head;
            temp -> next = newnode;
            head -> prev = newnode;
            temp = newnode;
        }
    }
}

void insertAtBeginning(int data){
	struct node *newnode,*last;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	if(head == NULL){
		head = newnode;
		newnode -> prev = head;
		newnode -> next = head;
	} else {
		last = head -> prev;
		newnode -> next = head;
		newnode -> prev = last;
		last -> next = newnode;
		head -> prev = newnode;
		head = newnode;
	}
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
	for(i = 1; i < pos && temp -> next != head; i++){
		temp = temp -> next;
	}
	if(i != pos){
		printf("Position Not Found!!!\n");
		return;
	}
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	newnode -> prev = temp;
	newnode -> next = temp -> next;
	temp -> next -> prev = newnode;
	temp -> next = newnode;
	printf("Node Inserted After Position %d\n", pos);
}

void insertAtEnd(int data){
	struct node *newnode,*last;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	if(head == NULL){
		head = newnode;
		newnode -> prev = head;
		newnode -> next = head;
	} else {
		last = head -> prev;
		newnode -> next = head;
		newnode -> prev = last;
		last -> next = newnode;
		head -> prev = newnode;
	}
	printf("Node Inserted At End\n");
}

void deleteAtBeginning(){
	struct node *temp,*del;
	if(head == NULL){
		printf("Double Circular Linked List Is Empty...\n");
		return;
	}
	if(head -> next == head){
		free(head);
		head = NULL;
	} else {
		temp = head;
		temp = head -> prev;
		del = head;
		head = head -> next;
		head -> prev = temp;
		temp -> next = head;
		free(del);
	}
	printf("Node Deleted From Beginning...\n");
}

void deleteAtMiddle(int pos){
	struct node *temp,*del;
	int i;

	if(head == NULL || pos < 1){
		printf("Double Circular Linked List Is Empty Or Position Is Invalid...\n");
		return;
	} else if(pos == 1){
		deleteAtBeginning();
		return;
	} else {
		temp = head;
		for(i = 1; i < pos - 1 && temp -> next != head; i++){
			temp = temp -> next;
		}
		if(i != pos - 1 || temp -> next == head){
			printf("Position Not Found!!!\n");
			return;
		}
		del = temp -> next;
		temp -> next = del -> next;
		del -> next -> prev = temp;
		free(del);
		printf("Node Deleted From Position %d\n",pos);
	}
}

void deleteAtEnd(){
	struct node *temp,*del;

	if(head == NULL){
		printf("Double Circular Linked List Is Empty...\n");
	} else if(head -> next == head){
		free(head);
		head = NULL;
		printf("Node Deleted From End...\n");
	} else {
		temp = head -> prev;
		del = temp;
 		temp -> prev -> next = head;
    	head -> prev = temp -> prev;
		free(del);
		printf("Node Deleted From End...\n");
	}
}

void display(){
	struct node *temp = head;

	if(head == NULL){
		printf("Double Circular Linked List Is Empty...\n");
	} else {
		printf("Double Circular Linked List: ");
		printf("(HEAD) <-> ");
		do{
			printf("%d <-> ",temp -> data);
			temp = temp -> next;
		}while(temp != head);
		printf("(HEAD)\n");
	}
}
