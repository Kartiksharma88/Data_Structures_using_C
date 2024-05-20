// Implement a doubly linked list and develop functions and develop functions to perform insertion, deletion and linear search operations

#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *prv;
	int data;
	struct Node *next;
};
struct Node *head=NULL, *tail=NULL;
struct Node* createNode(){
	struct Node *t=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter data : ");
	scanf("%d",&t->data);
	t->prv=NULL;
	t->next=NULL;
	return t;
}
void createDoublyLinkedList(){
	int n,i;
	printf("Enter No. of Nodes : ");
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		struct Node *newNode=createNode();
		if(head==NULL){
			head=newNode;
			tail=newNode;
		}
		else{
			newNode->prv=tail;
			tail->next=newNode;
			tail=newNode;
		}
	}
}
void insertNodeInBeg(){
	struct Node *newNode=createNode();
	if(head==NULL){
		head=tail=newNode;
	}
	else{
		newNode->next=head;
		head->prv=newNode;
		head=newNode;
	}
}
void insertNodeInEnd(){
	struct Node *newNode=createNode();
	if(tail==NULL){
		head=tail=newNode;
	}
	else{
		newNode->prv=tail;
		tail->next=newNode;
		tail=newNode;
	}
}
void insertNodeAtAnyLoc(){
	if(head==NULL)
		printf("List is empty !!!!!\n");
	else{
		int pos;
		printf("Enter Position : ");
		scanf("%d",&pos);
		if(pos==1)
		{
			struct Node *newNode=createNode();
			newNode->next=head;
			head->prv=newNode;
			head=newNode;
		}
		else{
			int cnt=1;
			struct Node *temp=head;
			while(temp!= NULL){
				if(cnt==pos)
					break;
				cnt++;
				temp=temp->next;
			}
			if(temp==NULL)
				printf("Invalid position !!!!!!\n");
			else{
				struct Node *newNode=createNode();
				temp->prv->next=newNode;
				newNode->prv=temp->prv;
				temp->prv=newNode;
				newNode->next=temp;
			}
		}
	}
}
void deleteNodeFromAnyPos(){
	if(head==NULL)
		printf("List is empty !!!!\n");
	else{
		int pos;
		printf("Enter Position : ");
		scanf("%d",&pos);
		if(pos==1){
			head=head->next;
		}
		else{
			int cnt=1;
			struct Node *temp=head;
			while(temp!=NULL){
				if(cnt==pos)
					break;
				cnt++;
				temp=temp->next;
			}
			if(temp==NULL)
				printf("Invalid Position !!!!!\n");
			else{
				temp->prv->next=temp->next;
				if(temp->next !=NULL)
					temp->next->prv=temp->prv;
			}
		}
	}
}
void displayListFormBeg(){
	if(head==NULL)
		printf("List is empty !!!!\n");
	else{
		struct Node *temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void displayListFormEnd(){
	if(tail==NULL)
		printf("List is empty !!!!\n");
	else{
		struct Node *temp=tail;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->prv;
		}
	}
}
int main(){
	createDoublyLinkedList();
	while(1){
		system("cls");
		printf("1. Insert Node In Begining\n");
		printf("2. Insert Node In End\n");
		printf("3. Insert Node At Any Position\n");
		printf("4. Delete Node From Given Position\n");
		printf("5. Search Node In List\n");
		printf("6. Display List From Beg\n");
		printf("7. Display List From End\n");
		printf("8. Exit\n");
		int choice;
		printf("Enter Choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insertNodeInBeg();
				break;
			case 2:
				insertNodeInEnd();
				break;
			case 3:
				insertNodeAtAnyLoc();
				break;
			case 4:
				deleteNodeFromAnyPos();
				break;
			case 5:
				break;
			case 6:
				displayListFormBeg();
				break;
			case 7:
				displayListFormEnd();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("Invalid Choice !!!!!\n");
		}
		printf("\n");
		system("pause");
	}
	return 0;
}