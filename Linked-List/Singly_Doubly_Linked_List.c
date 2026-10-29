#include <stdio.h>
#include <stdlib.h>

// SINGLE LINKED LIST

struct node{
	int data;
	struct node *next;
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

// DOUBLE LINKED LIST

struct dnode{
	int data;
	struct dnode *prev,*next;
};

struct dnode *dhead = NULL;

void createDList(int);
void displayD();
void insertDAtBeginning(int);
void insertDAtMiddle(int,int);
void insertDAtEnd(int);
void deleteDAtBeginning();
void deleteDAtMiddle(int);
void deleteDAtEnd();

// MAIN MENU

int main(){
	int ch;

	while(1){
		printf("\n========== MAIN MENU ===========\n");
		printf("1. Single Linked List\n");
		printf("2. Double Linked List\n");
		printf("3. Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:{
				int num,choice,data,pos,back=0;

				printf("Enter Number Of Nodes To Create SLL: ");
				scanf("%d",&num);
				head = NULL;
				createList(num);
				display();

				while(!back){
					printf("\n========== SINGLE LINKED LIST ===========\n");
					printf("1. Insert At Beginning\n");
					printf("2. Insert At Middle\n");
					printf("3. Insert At End\n");
					printf("4. Delete At Beginning\n");
					printf("5. Delete At Middle\n");
					printf("6. Delete At End\n");
					printf("7. Display\n");
					printf("8. Exit To Main Menu\n");
					printf("Enter Choice: ");
					scanf("%d",&choice);

					switch(choice){
						case 1:
							printf("Enter Data: ");
							scanf("%d",&data);
							insertAtBeginning(data);
							display();
							break;

						case 2:
							printf("Enter Data: ");
							scanf("%d",&data);
							printf("Enter Position After Which To Insert: ");
							scanf("%d",&pos);
							insertAtMiddle(data,pos);
							display();
							break;

						case 3:
							printf("Enter Data: ");
							scanf("%d",&data);
							insertAtEnd(data);
							display();
							break;

						case 4:
							deleteAtBeginning();
							display();
							break;

						case 5:
							printf("Enter Position To Delete: ");
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
							back = 1;
							break;

						default:
							printf("Enter Valid Choice...!!!\n");
					}
				}
				break;
			}

			case 2:{
				int num,choice,data,pos,back=0;

				printf("Enter Number Of Nodes To Create DLL: ");
				scanf("%d",&num);
				dhead = NULL;
				createDList(num);
				displayD();

				while(!back){
					printf("\n========== DOUBLE LINKED LIST ===========\n");
					printf("1. Insert At Beginning\n");
					printf("2. Insert At Middle\n");
					printf("3. Insert At End\n");
					printf("4. Delete At Beginning\n");
					printf("5. Delete At Middle\n");
					printf("6. Delete At End\n");
					printf("7. Display\n");
					printf("8. Exit To Main Menu\n");
					printf("Enter Choice: ");
					scanf("%d",&choice);

					switch(choice){
						case 1:
							printf("Enter Data: ");
							scanf("%d",&data);
							insertDAtBeginning(data);
							displayD();
							break;

						case 2:
							printf("Enter Data: ");
							scanf("%d",&data);
							printf("Enter Position After Which To Insert: ");
							scanf("%d",&pos);
							insertDAtMiddle(data,pos);
							displayD();
							break;

						case 3:
							printf("Enter Data: ");
							scanf("%d",&data);
							insertDAtEnd(data);
							displayD();
							break;

						case 4:
							deleteDAtBeginning();
							displayD();
							break;

						case 5:
							printf("Enter Position To Delete: ");
							scanf("%d",&pos);
							deleteDAtMiddle(pos);
							displayD();
							break;

						case 6:
							deleteDAtEnd();
							displayD();
							break;

						case 7:
							displayD();
							break;

						case 8:
							back = 1;
							break;

						default:
							printf("Enter Valid Choice...!!!\n");
					}
				}
				break;
			}

			case 3:
				printf("Program Exited Successfully.\n");
				exit(0);

			default:
				printf("Enter Valid Choice...!!!\n");
		}
	}
	return 0;
}

// SINGLE LINKED LIST FUNCTIONS

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
		scanf("%d",&newnode->data);
		newnode->next=NULL;

		if(head==NULL){
			head=temp=newnode;
		} else {
			temp->next=newnode;
			temp=newnode;
		}
	}
}

void insertAtBeginning(int data){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL) return;

	newnode->data=data;
	newnode->next=head;
	head=newnode;

	printf("Node Inserted At Beginning...\n");
}

void insertAtMiddle(int data,int pos){
	struct node *newnode,*temp;
	int i;

	if(pos<1 || head==NULL){
		printf("Invalid Position Or Empty List!!!\n");
		return;
	}

	temp=head;
	for(i=1;i<pos && temp!=NULL;i++){
		temp=temp->next;
	}

	if(temp==NULL){
		printf("Position Not Found!!!\n");
		return;
	}

	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL) return;

	newnode->data=data;
	newnode->next=temp->next;
	temp->next=newnode;

	printf("Node Inserted After Position %d\n",pos);
}

void insertAtEnd(int data){
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL) return;

	newnode->data=data;
	newnode->next=NULL;

	if(head==NULL){
		head=newnode;
	} else {
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}

	printf("Node Inserted At End\n");
}

void deleteAtBeginning(){
	struct node *temp;

	if(head==NULL){
		printf("Single Linked List Is Empty...\n");
	} else {
		temp=head;
		head=head->next;
		free(temp);
		printf("Node Deleted From Beginning...\n");
	}
}

void deleteAtMiddle(int pos){
	struct node *temp,*del;
	int i;

	if(head==NULL || pos<1){
		printf("List Is Empty Or Position Is Invalid...\n");
		return;
	}

	if(pos==1){
		deleteAtBeginning();
		return;
	}

	temp=head;
	for(i=1;i<pos-1 && temp!=NULL;i++){
		temp=temp->next;
	}

	if(temp==NULL || temp->next==NULL){
		printf("Position Not Found!!!\n");
		return;
	}

	del=temp->next;
	temp->next=del->next;
	free(del);

	printf("Node Deleted From Position %d\n",pos);
}

void deleteAtEnd(){
	struct node *temp,*del;

	if(head==NULL){
		printf("Single Linked List Is Empty...\n");
	} else if(head->next==NULL){
		free(head);
		head=NULL;
		printf("Node Deleted From End...\n");
	} else {
		temp=head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}

		del=temp->next;
		temp->next=NULL;
		free(del);

		printf("Node Deleted From End...\n");
	}
}

void display(){
	struct node *temp=head;

	if(head==NULL){
		printf("Single Linked List Is Empty...\n");
	} else {
		printf("Single Linked List: ");
		while(temp!=NULL){
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

// DOUBLE LINKED LIST FUNCTIONS

void createDList(int n){
	struct dnode *newnode,*temp;
	int i;

	for(i=0;i<n;i++){
		newnode=(struct dnode*)malloc(sizeof(struct dnode));
		if(newnode==NULL){
			printf("Memory Allocation Failed!\n");
			return;
		}

		printf("Enter Data For Node: %d: ",i+1);
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next=NULL;

		if(dhead==NULL){
			dhead=temp=newnode;
		} else {
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
	}
}

void insertDAtBeginning(int data){
	struct dnode *newnode;
	newnode=(struct dnode*)malloc(sizeof(struct dnode));
	if(newnode==NULL) return;

	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=dhead;

	if(dhead!=NULL){
		dhead->prev=newnode;
	}
	dhead=newnode;

	printf("Node Inserted At Beginning...\n");
}

void insertDAtMiddle(int data,int pos){
	struct dnode *newnode,*temp;
	int i;

	if(pos<1 || dhead==NULL){
		printf("Invalid Position Or Empty List!!!\n");
		return;
	}

	temp=dhead;
	for(i=1;i<pos && temp!=NULL;i++){
		temp=temp->next;
	}

	if(temp==NULL){
		printf("Position Not Found!!!\n");
		return;
	}

	newnode=(struct dnode*)malloc(sizeof(struct dnode));
	if(newnode==NULL) return;

	newnode->data=data;
	newnode->next=temp->next;
	newnode->prev=temp;

	if(temp->next!=NULL){
		temp->next->prev=newnode;
	}
	temp->next=newnode;

	printf("Node Inserted After Position %d\n",pos);
}

void insertDAtEnd(int data){
	struct dnode *newnode,*temp;
	newnode=(struct dnode*)malloc(sizeof(struct dnode));
	if(newnode==NULL) return;

	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;

	if(dhead==NULL){
		dhead=newnode;
	} else {
		temp=dhead;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}

	printf("Node Inserted At End\n");
}

void deleteDAtBeginning(){
	struct dnode *temp;

	if(dhead==NULL){
		printf("Double Linked List Is Empty...\n");
	} else {
		temp=dhead;
		dhead=dhead->next;

		if(dhead!=NULL){
			dhead->prev=NULL;
		}

		free(temp);
		printf("Node Deleted From Beginning...\n");
	}
}

void deleteDAtMiddle(int pos){
	struct dnode *temp,*del;
	int i;

	if(dhead==NULL || pos<1){
		printf("List Is Empty Or Position Is Invalid...\n");
		return;
	}

	if(pos==1){
		deleteDAtBeginning();
		return;
	}

	temp=dhead;
	for(i=1;i<pos-1 && temp!=NULL;i++){
		temp=temp->next;
	}

	if(temp==NULL || temp->next==NULL){
		printf("Position Not Found!!!\n");
		return;
	}

	del=temp->next;
	temp->next=del->next;

	if(del->next!=NULL){
		del->next->prev=temp;
	}

	free(del);
	printf("Node Deleted From Position %d\n",pos);
}

void deleteDAtEnd(){
	struct dnode *temp,*del;

	if(dhead==NULL){
		printf("Double Linked List Is Empty...\n");
	} else if(dhead->next==NULL){
		free(dhead);
		dhead=NULL;
		printf("Node Deleted From End...\n");
	} else {
		temp=dhead;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}

		del=temp->next;
		temp->next=NULL;
		free(del);

		printf("Node Deleted From End...\n");
	}
}

void displayD(){
	struct dnode *temp=dhead;

	if(dhead==NULL){
		printf("Double Linked List Is Empty...\n");
	} else {
		printf("Double Linked List: NULL <-> ");
		while(temp!=NULL){
			printf("%d <-> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
