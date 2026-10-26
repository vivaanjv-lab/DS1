#include <stdio.h>
#define len 5

struct Job {
    int ID;
    char title[50];
};

struct Job queue[len];
int front = -1, rear = -1;

int isFull() {
    return rear == len - 1;
}

int isEmpty() {
    return front == rear;
}

void enqueue() {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }

    struct Job job;

    printf("Enter Job ID: ");
    scanf("%d", &job.ID);
    printf("Enter Document Title: ");
    scanf(" %[^\n]", job.title);

    rear++;
    queue[rear] = job;

    printf("Job added successfully.\n");
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    front++;
    printf("Processing Job ID: %d\n", queue[front].ID);
    printf("Document: %s\n", queue[front].title);
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("\nPrint Queue:\n");

    for (int i = front + 1 ; i <= rear; i++) {
        printf("Job ID: %d | Document: %s\n",
               queue[i].ID, queue[i].title);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}