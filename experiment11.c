// Implement a queue using linked list and develop functions to perform enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    front = front->next;
	printf("%d dequeue from the queue\n",temp->data);
    free(temp);
}

void display()
{
    struct node *temp = front;
    if(front==NULL)
    	printf("Queue is empty!!!!");
	else{
		while (temp != NULL)
	    {
	        printf("%d ", temp->data);
	        temp = temp->next;
	    }
	}
    printf("\n");
}

int main()
{
    int choice,data;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
