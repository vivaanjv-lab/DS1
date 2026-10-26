#include <stdio.h>
#include <stdlib.h>

#define Max 5
int isFull(int Front, int Rear) {
    if (Rear != -1 && Front == (Rear + 1) % Max)
        return 1;
    return 0;
}
int isEmpty(int Front, int Rear) {
    if (Rear == -1)
        return 1;
    return 0;
}
int Insert(int Q[Max], int Front, int Rear, int Data) {
    if (!(isFull(Front, Rear))) {
        if (isEmpty(Front, Rear)) {
            Front = 0;
        }
        Rear = (Rear + 1) % Max;
        Q[Rear] = Data;
        printf("\nInserted Data: %d\n", Data);
    } else {
        printf("\nQueue Full!\n");
    }
    return Rear;
}
int Remove(int Q[Max], int *Front, int *Rear) {
    int E = -1;
    if (!(isEmpty(*Front, *Rear))) {
        E = Q[*Front];
        printf("\nRemoved Data: %d\n", E);
        Q[*Front] = -1;
        if (*Front == *Rear) {
            *Front = 0;
            *Rear = -1;
        } else {
            *Front = (*Front + 1) % Max;
        }
    } else {
        printf("\nQueue Empty!\n");
    }
    return E;
}
void Display(int Q[Max], int Front, int Rear) {
    if (isEmpty(Front, Rear)) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue Elements: ");
    int i = Front;
    while (1) {
        printf("%d ", Q[i]);
        if (i == Rear)
            break;
        i = (i + 1) % Max;
    }
    printf("\n");
}
int main() {
    int Q[Max];
    int Front = 0;
    int Rear = -1;
    int choice, data;
    do {
        printf("\nCircular Queue Menu\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Remove (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                Rear = Insert(Q, Front, Rear, data);
                break;
            case 2:
                Remove(Q, &Front, &Rear);
                break;
            case 3:
                Display(Q, Front, Rear);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
