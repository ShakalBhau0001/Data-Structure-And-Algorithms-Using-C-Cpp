#include <stdio.h>
#include <stdlib.h>

// SINGLE LINEAR LINKED LIST

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;x

void createList(int);
void display();
void insertAtBeginning(int);
void insertAtMiddle(int,int);
void insertAtEnd(int);
void deleteAtBeginning();
void deleteAtMiddle(int);
void deleteAtEnd();

// DOUBLE LINEAR LINKED LIST

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

// SINGLE CIRCULAR LINKED LIST

struct cnode{
	int data;
	struct cnode *next;
};

struct cnode *chead = NULL;

void createCList(int);
void displayC();
void insertCAtBeginning(int);
void insertCAtMiddle(int,int);
void insertCAtEnd(int);
void deleteCAtBeginning();
void deleteCAtMiddle(int);
void deleteCAtEnd();

// DOUBLE CIRCULAR LINKED LIST

struct dcnode{
	int data;
	struct dcnode *next,*prev;
};

struct dcnode *dchead = NULL;

void createDCList(int);
void displayDC();
void insertDCAtBeginning(int);
void insertDCAtMiddle(int,int);
void insertDCAtEnd(int);
void deleteDCAtBeginning();
void deleteDCAtMiddle(int);
void deleteDCAtEnd();

// MENU FUNCTIONS

void linearMenu();
void circularMenu();
void singleLinearMenu();
void doubleLinearMenu();
void singleCircularMenu();
void doubleCircularMenu();

// MAIN MENU

int main(){
	int ch;

	while(1){
		printf("\n========== LINKED LIST ===========\n");
		printf("1. Linear Linked List\n");
		printf("2. Circular Linked List\n");
		printf("3. Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				linearMenu();
				break;

			case 2:
				circularMenu();
				break;

			case 3:
				printf("Program Exited Successfully.\n");
				exit(0);

			default:
				printf("Enter Valid Choice...!!!\n");
		}
	}
	return 0;
}

// LINEAR AND CIRCULAR SUB MENUS

void linearMenu(){
	int ch,back=0;

	while(!back){
		printf("\n========== LINEAR LINKED LIST ===========\n");
		printf("1. Single Linear Linked List\n");
		printf("2. Double Linear Linked List\n");
		printf("3. Exit To Main Menu\n");
		printf("Enter Choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				singleLinearMenu();
				break;

			case 2:
				doubleLinearMenu();
				break;

			case 3:
				back = 1;
				break;

			default:
				printf("Enter Valid Choice...!!!\n");
		}
	}
}

void circularMenu(){
	int ch,back=0;

	while(!back){
		printf("\n========== CIRCULAR LINKED LIST ===========\n");
		printf("1. Single Circular Linked List\n");
		printf("2. Double Circular Linked List\n");
		printf("3. Exit To Main Menu\n");
		printf("Enter Choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				singleCircularMenu();
				break;

			case 2:
				doubleCircularMenu();
				break;

			case 3:
				back = 1;
				break;

			default:
				printf("Enter Valid Choice...!!!\n");
		}
	}
}

// OPERATION MENUS

void singleLinearMenu(){
	int num,choice,data,pos,back=0;

	printf("Enter Number Of Nodes To Create SLL: ");
	scanf("%d",&num);
	head = NULL;
	createList(num);
	display();

	while(!back){
		printf("\n========== SINGLE LINEAR LINKED LIST ===========\n");
		printf("1. Insert At Beginning\n");
		printf("2. Insert At Middle\n");
		printf("3. Insert At End\n");
		printf("4. Delete At Beginning\n");
		printf("5. Delete At Middle\n");
		printf("6. Delete At End\n");
		printf("7. Display\n");
		printf("8. Exit To Previous Menu\n");
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
}

void doubleLinearMenu(){
	int num,choice,data,pos,back=0;

	printf("Enter Number Of Nodes To Create DLL: ");
	scanf("%d",&num);
	dhead = NULL;
	createDList(num);
	displayD();

	while(!back){
		printf("\n========== DOUBLE LINEAR LINKED LIST ===========\n");
		printf("1. Insert At Beginning\n");
		printf("2. Insert At Middle\n");
		printf("3. Insert At End\n");
		printf("4. Delete At Beginning\n");
		printf("5. Delete At Middle\n");
		printf("6. Delete At End\n");
		printf("7. Display\n");
		printf("8. Exit To Previous Menu\n");
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
}

void singleCircularMenu(){
	int num,choice,data,pos,back=0;

	printf("Enter Number Of Nodes To Create SCLL: ");
	scanf("%d",&num);
	chead = NULL;
	createCList(num);
	displayC();

	while(!back){
		printf("\n========== SINGLE CIRCULAR LINKED LIST ===========\n");
		printf("1. Insert At Beginning\n");
		printf("2. Insert At Middle\n");
		printf("3. Insert At End\n");
		printf("4. Delete At Beginning\n");
		printf("5. Delete At Middle\n");
		printf("6. Delete At End\n");
		printf("7. Display\n");
		printf("8. Exit To Previous Menu\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Enter Data: ");
				scanf("%d",&data);
				insertCAtBeginning(data);
				displayC();
				break;

			case 2:
				printf("Enter Data: ");
				scanf("%d",&data);
				printf("Enter Position After Which To Insert: ");
				scanf("%d",&pos);
				insertCAtMiddle(data,pos);
				displayC();
				break;

			case 3:
				printf("Enter Data: ");
				scanf("%d",&data);
				insertCAtEnd(data);
				displayC();
				break;

			case 4:
				deleteCAtBeginning();
				displayC();
				break;

			case 5:
				printf("Enter Position To Delete: ");
				scanf("%d",&pos);
				deleteCAtMiddle(pos);
				displayC();
				break;

			case 6:
				deleteCAtEnd();
				displayC();
				break;

			case 7:
				displayC();
				break;

			case 8:
				back = 1;
				break;

			default:
				printf("Enter Valid Choice...!!!\n");
		}
	}
}

void doubleCircularMenu(){
	int num,choice,data,pos,back=0;

	printf("Enter Number Of Nodes To Create DCLL: ");
	scanf("%d",&num);
	dchead = NULL;
	createDCList(num);
	displayDC();

	while(!back){
		printf("\n========== DOUBLE CIRCULAR LINKED LIST ===========\n");
		printf("1. Insert At Beginning\n");
		printf("2. Insert At Middle\n");
		printf("3. Insert At End\n");
		printf("4. Delete At Beginning\n");
		printf("5. Delete At Middle\n");
		printf("6. Delete At End\n");
		printf("7. Display\n");
		printf("8. Exit To Previous Menu\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Enter Data: ");
				scanf("%d",&data);
				insertDCAtBeginning(data);
				displayDC();
				break;

			case 2:
				printf("Enter Data: ");
				scanf("%d",&data);
				printf("Enter Position After Which To Insert: ");
				scanf("%d",&pos);
				insertDCAtMiddle(data,pos);
				displayDC();
				break;

			case 3:
				printf("Enter Data: ");
				scanf("%d",&data);
				insertDCAtEnd(data);
				displayDC();
				break;

			case 4:
				deleteDCAtBeginning();
				displayDC();
				break;

			case 5:
				printf("Enter Position To Delete: ");
				scanf("%d",&pos);
				deleteDCAtMiddle(pos);
				displayDC();
				break;

			case 6:
				deleteDCAtEnd();
				displayDC();
				break;

			case 7:
				displayDC();
				break;

			case 8:
				back = 1;
				break;

			default:
				printf("Enter Valid Choice...!!!\n");
		}
	}
}

// SINGLE LINEAR LINKED LIST FUNCTIONS

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

// DOUBLE LINEAR LINKED LIST FUNCTIONS

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

// SINGLE CIRCULAR LINKED LIST FUNCTIONS

void createCList(int n){
	struct cnode *newnode,*temp;
	int i;
	for(i=0;i<n;i++){
		newnode=(struct cnode*)malloc(sizeof(struct cnode));
		if(newnode == NULL){
			printf("Memory Allocation Failed!\n");
			return;
		}
		printf("Enter Data For Node: %d: ",i+1);
		scanf("%d",&newnode -> data);
		if(chead == NULL){
			chead = newnode;
			newnode -> next = chead;
			temp = newnode;
		} else {
			newnode -> next = chead;
			temp -> next = newnode;
			temp = newnode;
		}
	}
}

void insertCAtBeginning(int data){
	struct cnode *newnode,*temp;
	newnode=(struct cnode*)malloc(sizeof(struct cnode));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	if(chead == NULL){
		chead = newnode;
		newnode -> next = chead;
	} else {
		temp = chead;
		while(temp -> next != chead){
			temp = temp -> next;
		}
		newnode -> next = chead;
		temp -> next = newnode;
		chead = newnode;
	}
	printf("Node Inserted At Beginning...\n");
}

void insertCAtMiddle(int data,int pos){
	struct cnode *newnode,*temp;
	int i;
	if(pos < 1 || chead == NULL){
		printf("Invalid Position Or Empty List!!!\n");
		return;
	}
	temp = chead;
	for(i = 1; i < pos && temp -> next != chead; i++){
		temp = temp -> next;
	}
	if(i != pos){
		printf("Position Not Found!!!\n");
		return;
	}
	newnode=(struct cnode*)malloc(sizeof(struct cnode));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	newnode -> next = temp -> next;
	temp -> next = newnode;
	printf("Node Inserted After Position %d\n", pos);
}

void insertCAtEnd(int data){
	struct cnode *newnode,*temp;
	newnode=(struct cnode*)malloc(sizeof(struct cnode));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	if(chead == NULL){
		chead = newnode;
		newnode -> next = chead;
	} else {
		temp = chead;
		while(temp -> next != chead){
			temp = temp -> next;
		}
		temp -> next = newnode;
		newnode -> next = chead;
	}
	printf("Node Inserted At End\n");
}

void deleteCAtBeginning(){
	struct cnode *temp,*del;
	if(chead == NULL){
		printf("Single Circular Linked List Is Empty...\n");
		return;
	}
	if(chead -> next == chead){
		free(chead);
		chead = NULL;
	} else {
		temp = chead;
		while(temp -> next != chead){
			temp = temp -> next;
		}
		del = chead;
		chead = chead -> next;
		temp -> next = chead;
		free(del);
	}
	printf("Node Deleted From Beginning...\n");
}

void deleteCAtMiddle(int pos){
	struct cnode *temp,*del;
	int i;

	if(chead == NULL || pos < 1){
		printf("Single Circular Linked List Is Empty Or Position Is Invalid...\n");
		return;
	} else if(pos == 1){
		deleteCAtBeginning();
		return;
	} else {
		temp = chead;
		for(i = 1; i < pos - 1 && temp -> next != chead; i++){
			temp = temp -> next;
		}
		if(i != pos - 1 || temp -> next == chead){
			printf("Position Not Found!!!\n");
			return;
		}
		del = temp -> next;
		temp -> next = del -> next;
		free(del);
		printf("Node Deleted From Position %d\n",pos);
	}
}

void deleteCAtEnd(){
	struct cnode *temp,*del;

	if(chead == NULL){
		printf("Single Circular Linked List Is Empty...\n");
	} else if(chead -> next == chead){
		free(chead);
		chead = NULL;
		printf("Node Deleted From End...\n");
	} else {
		temp = chead;
		while(temp -> next -> next != chead){
			temp = temp -> next;
		}
		del = temp -> next;
		temp -> next = chead;
		free(del);
		printf("Node Deleted From End...\n");
	}
}

void displayC(){
	struct cnode *temp = chead;

	if(chead == NULL){
		printf("Single Circular Linked List Is Empty...\n");
	} else {
		printf("Single Circular Linked List: ");
		do{
			printf("%d -> ",temp -> data);
			temp = temp -> next;
		}while(temp != chead);
		printf("(HEAD)\n");
	}
}

// DOUBLE CIRCULAR LINKED LIST FUNCTIONS

void createDCList(int n){
	struct dcnode *newnode, *temp;
	int i;

	for(i = 0; i < n; i++){
		newnode = (struct dcnode*)malloc(sizeof(struct dcnode));

		if(newnode == NULL){
			printf("Memory Allocation Failed!\n");
			return;
		}

		printf("Enter Data For Node: %d: ", i+1);
		scanf("%d", &newnode -> data);

		if(dchead == NULL){
			dchead = temp = newnode;
			newnode -> next = dchead;
			newnode -> prev = dchead;
		} else {
			newnode -> prev = temp;
			newnode -> next = dchead;
			temp -> next = newnode;
			dchead -> prev = newnode;
			temp = newnode;
		}
	}
}

void insertDCAtBeginning(int data){
	struct dcnode *newnode,*last;
	newnode=(struct dcnode*)malloc(sizeof(struct dcnode));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	if(dchead == NULL){
		dchead = newnode;
		newnode -> prev = dchead;
		newnode -> next = dchead;
	} else {
		last = dchead -> prev;
		newnode -> next = dchead;
		newnode -> prev = last;
		last -> next = newnode;
		dchead -> prev = newnode;
		dchead = newnode;
	}
	printf("Node Inserted At Beginning...\n");
}

void insertDCAtMiddle(int data,int pos){
	struct dcnode *newnode,*temp;
	int i;
	if(pos < 1 || dchead == NULL){
		printf("Invalid Position Or Empty List!!!\n");
		return;
	}
	temp = dchead;
	for(i = 1; i < pos && temp -> next != dchead; i++){
		temp = temp -> next;
	}
	if(i != pos){
		printf("Position Not Found!!!\n");
		return;
	}
	newnode=(struct dcnode*)malloc(sizeof(struct dcnode));
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

void insertDCAtEnd(int data){
	struct dcnode *newnode,*last;
	newnode=(struct dcnode*)malloc(sizeof(struct dcnode));
	if(newnode == NULL){
		printf("Memory Allocation Failed!\n");
		return;
	}
	newnode -> data = data;
	if(dchead == NULL){
		dchead = newnode;
		newnode -> prev = dchead;
		newnode -> next = dchead;
	} else {
		last = dchead -> prev;
		newnode -> next = dchead;
		newnode -> prev = last;
		last -> next = newnode;
		dchead -> prev = newnode;
	}
	printf("Node Inserted At End\n");
}

void deleteDCAtBeginning(){
	struct dcnode *temp,*del;
	if(dchead == NULL){
		printf("Double Circular Linked List Is Empty...\n");
		return;
	}
	if(dchead -> next == dchead){
		free(dchead);
		dchead = NULL;
	} else {
		temp = dchead;
		temp = dchead -> prev;
		del = dchead;
		dchead = dchead -> next;
		dchead -> prev = temp;
		temp -> next = dchead;
		free(del);
	}
	printf("Node Deleted From Beginning...\n");
}

void deleteDCAtMiddle(int pos){
	struct dcnode *temp,*del;
	int i;

	if(dchead == NULL || pos < 1){
		printf("Double Circular Linked List Is Empty Or Position Is Invalid...\n");
		return;
	} else if(pos == 1){
		deleteDCAtBeginning();
		return;
	} else {
		temp = dchead;
		for(i = 1; i < pos - 1 && temp -> next != dchead; i++){
			temp = temp -> next;
		}
		if(i != pos - 1 || temp -> next == dchead){
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

void deleteDCAtEnd(){
	struct dcnode *temp,*del;

	if(dchead == NULL){
		printf("Double Circular Linked List Is Empty...\n");
	} else if(dchead -> next == dchead){
		free(dchead);
		dchead = NULL;
		printf("Node Deleted From End...\n");
	} else {
		temp = dchead -> prev;
		del = temp;
		temp -> prev -> next = dchead;
		dchead -> prev = temp -> prev;
		free(del);
		printf("Node Deleted From End...\n");
	}
}

void displayDC(){
	struct dcnode *temp = dchead;

	if(dchead == NULL){
		printf("Double Circular Linked List Is Empty...\n");
	} else {
		printf("Double Circular Linked List: ");
		printf("(HEAD) <-> ");
		do{
			printf("%d <-> ",temp -> data);
			temp = temp -> next;
		}while(temp != dchead);
		printf("(HEAD)\n");
	}
}
