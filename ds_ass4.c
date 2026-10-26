#include <stdio.h>
#include <string.h>

#define SIZE 5
typedef struct
{
    int Job_ID;
    char Title[20];
} Queue;
int isEmpty(int front, int rear)
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}
int isFull(int rear)
{
    if (rear == SIZE - 1)
        return 1;
    else
        return 0;
}
void Enqueue(Queue Q[], int *front, int *rear, Queue Job)
{
    if (isFull(*rear))
    {
        printf("\nQueue is Full!");
        return;
    }
    if (*front == -1)
        *front = 0;
    (*rear)++;
    Q[*rear] = Job;
    printf("\nJob added successfully.");
}
Queue Dequeue(Queue Q[], int *front, int *rear)
{
    Queue Djob;
    Djob.Job_ID = -1;
    strcpy(Djob.Title, "");
    if (isEmpty(*front, *rear))
    {
        printf("\nQueue is Empty!");
        return Djob;
    }
    Djob = Q[*front];
    (*front)++;
    if (*front > *rear)
    {
        *front = -1;
        *rear = -1;
    }
    return Djob;
}
void Display(Queue Q[], int front, int rear)
{
    int i;
    if (isEmpty(front, rear))
    {
        printf("\nQueue is Empty!");
        return;
    }
    printf("\nJob ID\tJob Title");
    for (i = front; i <= rear; i++)
    {
        printf("\n%d\t%s", Q[i].Job_ID, Q[i].Title);
    }
}
int main()
{
    Queue Q[SIZE], NewJob, Djob;
    int Front = -1, Rear = -1;
    int choice;
    do
    {
        printf("\n\nPRINTER QUEUE");
        printf("\n1. Enter a Job");
        printf("\n2. Job Done (Delete)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter Job ID: ");
                scanf("%d", &NewJob.Job_ID);
                printf("Enter Job Title: ");
                scanf("%19s", NewJob.Title);
                Enqueue(Q, &Front, &Rear, NewJob);
                break;
            case 2:
                Djob = Dequeue(Q, &Front, &Rear);
                if (Djob.Job_ID != -1)
                {
                    printf("\nCompleted Job: %d %s",
                           Djob.Job_ID, Djob.Title);
                }
                break;
            case 3:
                Display(Q, Front, Rear);
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice!");
        }
    } while (choice != 4);

    return 0;
}
