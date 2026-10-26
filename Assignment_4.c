#include <stdio.h>
#include <stdlib.h>

struct node
{
    int reg_no;
    char name[100];
    struct node *next;
};

void create(struct node *head)
{
    struct node *temp, *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter registration number: ");
    scanf("%d", &newnode->reg_no);

    printf("Enter student name: ");
    scanf(" %s", newnode->name);

    newnode->next = NULL; 

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head->next;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("\nRegistration Number: %d", temp->reg_no);
        printf("\nName: %s\n", temp->name);
        temp = temp->next;
    }
}

void delete(struct node *head)
{
    struct node *temp, *prev;
    prev = head;
    temp = head->next;

    int reg_no;

    printf("Enter registration number to delete: ");
    scanf("%d", &reg_no);

    while (temp != NULL && temp->reg_no != reg_no)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student not found\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Student deleted\n");
    }
}

int count(struct node *head)
{
    struct node *temp;
    temp = head->next;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void sort(struct node *head)
{
    struct node *prev, *curr, *nextnode;
    int i, j, n = count(head);

    for (i = 0; i < n - 1; i++)
    {
        prev = head;
        curr = head->next;

        for (j = 0; j < n - i - 1; j++)
        {
            nextnode = curr->next;

            if (curr->reg_no > nextnode->reg_no)
            {
                prev->next = nextnode;
                curr->next = nextnode->next;
                nextnode->next = curr;   
                prev = nextnode;
            }
            else
            {
                prev = curr;
                curr = curr->next; 
            }
        }
    }

    printf("List sorted\n");
}

void reverse(struct node *head)
{
    struct node *prev, *curr, *nextnode;
    prev = NULL;
    curr = head->next;
    while (curr != NULL)
    {
        nextnode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextnode;
    }
    head->next = prev;
    printf("List reversed\n");
}

int main()
{
    struct node *head;
    int choice;

    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;

    do
    {
        printf("\n\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Delete Student");
        printf("\n4. Count Students");
        printf("\n5. Sort Students");
        printf("\n6. Reverse List");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create(head);
                break;

            case 2:
                display(head);
                break;

            case 3:

                delete(head);
                break;

            case 4:
                printf("Total students: %d\n", count(head));
                break;

            case 5:
                sort(head);
                break;

            case 6:
                reverse(head);
                break;

            case 7:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 7);

    free(head);

    return 0;
}
