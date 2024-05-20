// Implement a priority queue using linked list and develop functions to perform enqueue and dequeue operations

#include <stdio.h>
#include <stdlib.h>

// Node structure for the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int d, int p) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

// Function to insert a new node into the priority queue based on priority
void enqueue(struct Node** head, int d, int p) {
    struct Node* start = (*head);
	struct Node* temp = newNode(d, p);
    if ((*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = *head;
    printf("Deleted item is: %d\n", temp->data);
    (*head) = (*head)->next;
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Priority Queue:\n");
    while (head != NULL) {
        printf("Data: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}

int main() {
    struct Node* pq = newNode(0, 0);
    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(&pq, data, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(pq->next); 
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}