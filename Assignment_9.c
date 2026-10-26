#include <stdio.h>
#define len 5

struct Job {
    int ID;
    char title[50];
};

struct Job queue[len];
int front = 0, rear = 0;

int isFull() {
    return (rear + 1) % len == front;
}

int isEmpty() {
    return front == rear;
}

void enqueue() {
    struct Job job;

    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    printf("Enter Job ID: ");
    scanf("%d", &job.ID);
    printf("Enter Document Title: ");
    scanf(" %[^\n]", job.title);

    rear = (rear + 1) % len;
    queue[rear] = job;

    printf("Job Added Successfully\n");
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    front = (front + 1) % len;
    printf("Processing Job ID: %d\n", queue[front].ID);
    printf("Document: %s\n", queue[front].title);
}

void display() {

    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    int i = (front + 1) % len;
    
    while (1) {
        printf("Job ID: %d | Document: %s\n",
               queue[i].ID, queue[i].title);

        if (i == rear)
            break;

        i = (i + 1) % len;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. Display Pending Jobs\n");
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
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}