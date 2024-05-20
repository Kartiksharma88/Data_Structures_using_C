//  Implement a circular linked list and develop functions and develop functions to perform insertion, deletion and linear search operations

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL,*tail=NULL;
struct Node* createNode(){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Data : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	return temp;
}
void createList(){
	int n,i;
	printf("Enter total elements : ");
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		struct Node *newNode = createNode();
		if(head==NULL){
			head = newNode;
		}
		else{
			tail->next = newNode;
		}
		tail=newNode;
	}
	if(tail!=NULL)
		tail->next=head;
}
void display(){
	if(head==NULL)
		printf("List is Empty !!!!\n");
	else{
		struct Node *temp=head;
		do{
			printf("%d ",temp->data);
			temp = temp->next;
		}while(temp!=head);
	}
}
void insertNodeInBegin(){
	struct Node *newNode=createNode();
	newNode->next=head;
	head=newNode;
	tail->next=head;
}
void insertNodeInEnd(){
	struct Node *newNode=createNode();
	if(head==NULL){
		head=tail=newNode;
		newNode->next=head;
	}
	else{
		tail->next=newNode;
		newNode->next=head;
		tail=newNode;
	}	
}
void insertNodeAtAnyPosition(){
	if(head==NULL)
		printf("List is empty !!!!");
	else{
		int pos;
		printf("Enter Position : ");
		scanf("%d",&pos);
		if(pos==1){
			insertNodeInBegin();
		}
		else{
			int i=1;
			struct Node *temp = head;
			do{
				if(i==pos-1){
					struct Node *newNode=createNode();
					newNode->next=temp->next;
					temp->next=newNode;
					break;
				}
				temp=temp->next;
				i++;
			}while(temp!=head);
			if(temp==head)
				printf("Invalid Position !!!!!\n");
		}
	}	
}
void deleteNode(){
	if(head==NULL)
		printf("List is empty !!!!!!\n");
	else{
		int pos;
		printf("Enter Position : ");
		scanf("%d",&pos);
		if(pos==1 && head != tail){
			head=head->next;
			tail->next=head;
		}
		else if(pos==1 && head==tail)		
			head=tail=NULL;
		else{
			struct Node *temp=head;
			int i=1;
			do{
				if(i==pos-1){
					temp->next=temp->next->next;
					tail=temp;
					break;
				}
				temp=temp->next;
				i++;
			}while(temp!=head);
			if(temp==head)
				printf("Invalid Position !!!!\n");
		}
	}
}
void searchList(){
	if(head==NULL)
		printf("List is empty !!!!!\n");
	else{
		int val;
		printf("Enter Search Value : ");
		scanf("%d",&val);
		struct Node *temp=head;
		do{
			if(temp->data==val){
				break;
			}
			else
				temp=temp->next;
		}while(temp!=head);
		if(temp==head)
			printf("Not Found !!!!!\n");
		else
			printf("Found !!!!!\n");
	}
}
int main(){
	int choice,pos,data;
	createList();
	while(1){
		system("cls");
		printf("\n******* Implementation of circular singly linked list. *******\n\n");
		printf("1. Insert Element In Begining Of Linked List\n");
		printf("2. Insert Element In End Of Linked List\n");
		printf("3. Insert Element In Any Location Of Linked List\n");
		printf("4. Delete Element From Linked List\n");
		printf("5. Search Element In Linked List\n");
		printf("6. Display All Elements Of Linked List\n");
		printf("7. Exit\n\n");
		printf("Enter Choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insertNodeInBegin();
				break;
			case 2:
				insertNodeInEnd();
				break;
			case 3:
				insertNodeAtAnyPosition();
				break;
			case 4:
				deleteNode();
				break;
			case 5:
				
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("Invalid choice !!!!!\n");
		}
		printf("\n");
		system("pause");
	}
	return 0;
}