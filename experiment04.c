// Implement a queue using array and develop functions to perform enqueue and dequeue operations

#include<stdio.h>
#define MAX 100
int queue[MAX], front=-1,rear=-1;
int isFull(){
	return rear==MAX-1;
}
int isEmpty(){
	return front==-1;
}
void enqueue(int value){
	if(isFull()){
		printf("Queue Overflow !!!!");
	}
	else{
		queue[++rear]=value;
		if(front==-1)
			front=rear;
		printf("%d added in queue !!!!",value);
	}
}
void dequeue(){
	if(isEmpty() || front>rear){
		printf("Queue Onderflow !!!!");
	}
	else{
		int value=queue[front++];
		if(front>rear)
			front=rear=-1;
		printf("%d remove from the queue !!!!",value); 
	}
}
int peek(){
	if(isEmpty() || front>rear)
		return -1;
	else
		return queue[front];
}
void display(){
	int i;
	if(isEmpty())
		printf("Queue is empty !!!!");
	else{
		for(i=front; i<=rear; i++) 
			printf("%d\t",queue[i]);
	}
}
int main(){
	int choice,val;
	while(1){
		system("cls");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter Value : ");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				val=peek();
				if(val==-1)
					printf("Queue is empty !!!!");
				else
					printf("%d is avaiable in front of queue !!!!",val);
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid choice !!!!!");
		}
		printf("\n");
		system("pause");
	}
	return 0;
}