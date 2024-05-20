// Implement a stack using array and develop functions to perform push and pop operations

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE], top=-1;
int isEmpty(){
	return (top==-1) ? 1: 0;
}
int isFull(){
	return (top==SIZE-1)? 1 : 0;
}
void push(){
	if(isFull())
		printf("Stack Overflow !!!!");
	else{
		top++;
		int val;
		printf("Enter Value : ");
		scanf("%d",&val);
		stack[top]=val;
		printf("Element Added !!!!");
	}
}
void show(){
	if(isEmpty())
		printf("Stack is Empty !!!!");
	else{
		int i;
		printf("Stack Elements are : \n");
		for(i=top; i>=0; i--){
			printf("%d\n",stack[i]);
		}
	}
}
void pop(){
	if(isEmpty()){
		printf("Stack Underflow !!!!!");
	}
	else{
		int val = stack[top];
		top--;
		printf("Element %d remove from the stack",val);
	}
}
void peek(){
	if(isEmpty()){
		printf("Stack is empty !!!!!");
	}
	else{
		printf("Top Element in Stack is %d",stack[top]);
	}
}
int main(){
	while(1){
		system("cls");
		printf("1 Push\n");
		printf("2 Pop\n");
		printf("3 Peek\n");
		printf("4 Show\n");
		printf("5 Exit\n");
		int choice;
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				show();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid Choice !!!!!!");
				break;
			
		}
		printf("\n\n");
		system("pause");
	}
	return 0;
}
