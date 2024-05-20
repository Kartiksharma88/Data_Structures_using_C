// Implement a singly linked list and develop functions to perform insertion, deletion and linear search operations

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(){
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter data : ");
	scanf("%d",&node->data);
	node->next=NULL;
	return node;
}
void createList(){
	int n,i;
	printf("Enter total number of nodes : ");
	scanf("%d",&n);
	struct Node *temp=NULL;
	for(i=0; i<n; i++){
		struct Node *newNode = createNode();
		if(head==NULL)
			head=newNode;
		else
			temp->next=newNode;
		temp=newNode;
	}
}
void displayList(){
	if(head==NULL)
		printf("List is empty !!!!!\n");
	else{
		struct Node *temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
void insertNodeInBeg(){
	struct Node *newNode=createNode();
	newNode->next=head;
	head=newNode;
}
void insertNodeInEnd(){
	struct Node *newNode=createNode();
	if(head==NULL)
		head=newNode;
	else{
		struct Node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}
void insertNodeAtAnyLoc(){
	if(head==NULL)
		printf("Invalid Position !!!!!\n");
	else{
		int pos,cnt=1;
		printf("Enter Position : ");
		scanf("%d",&pos);
		if(pos==1){
			struct Node *newNode=createNode();
			newNode->next=head;
			head=newNode;
		}
		else{
			struct Node *temp=head;
			while(temp->next != NULL){
				if(cnt == pos-1){
					break;
				}
				cnt++;
				temp = temp->next;
			}
			if(temp->next == NULL)
				printf("Invalid Position !!!!\n");
			else{
				struct Node *newNode=createNode();
				newNode->next=temp->next;
				temp->next=newNode;
			}
		}
	}
}
void deleteNodeAtAnyLoc(){
	if(head==NULL)
		printf("Invalid Position !!!!!\n");
	else{
		int pos,cnt=1;
		printf("Enter Position : ");
		scanf("%d",&pos);
		if(pos==1){
			head=head->next;
		}
		else{
			struct Node *temp=head;
			while(temp->next != NULL){
				if(cnt == pos-1){
					break;
				}
				cnt++;
				temp = temp->next;
			}
			if(temp->next == NULL)
				printf("Invalid Position !!!!\n");
			else{
				temp->next = temp->next->next;
			}
		}
	}
}
void searchElement(){
	if(head==NULL)
		printf("List is empty !!!!!\n");
	else{
		int num,flag=0;
		printf("Enter Data to search : ");
		struct Node *temp=head;
		while(temp != NULL){
			if(temp->data == num){
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(flag==1)
			printf("Found !!!!\n");
		else
			printf("Not Found !!!!!\n");
	}
}
int main(){
	createList();
	while(1){
		system("cls");
		printf("1. Insert Node In Begining\n");
		printf("2. Insert Node In End\n");
		printf("3. Insert Node At Any Position\n");
		printf("4. Delete Node From Given Position\n");
		printf("5. Search Node In List\n");
		printf("6. Display List\n");
		printf("7. Exit\n");
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
				deleteNodeAtAnyLoc();
				break;
			case 5:
				break;
			case 6:
				displayList();
				break;
			case 7:
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