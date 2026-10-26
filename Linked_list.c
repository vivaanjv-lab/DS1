#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int regno;
    char name[20];
    struct node *next;
};
void addStudent(struct node *head)
{
    struct node *curr, *temp;
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    curr = (struct node *)malloc(sizeof(struct node));
    printf("Enter Registration Number: ");
    scanf("%d", &curr->regno);
    printf("Enter Name: ");
    scanf("%19s", curr->name);
    curr->next = NULL;
    temp->next = curr;
    printf("Student added successfully.\n");
}
void removeStudent(struct node *head)
{
    struct node *curr, *temp;
    int regno;
    printf("Enter Registration Number to remove: ");
    scanf("%d", &regno);
    temp = head;
    while(temp->next != NULL &&
          temp->next->regno != regno)
    {
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        printf("Student not found.\n");
        return;
    }
    curr = temp->next;
    temp->next = curr->next;
    free(curr);
    printf("Student removed successfully.\n");
}
void display(struct node *head)
{
    struct node *curr;
    if(head->next == NULL)
    {
        printf("No students registered.\n");
        return;
    }
    curr = head->next;
    printf("\nWorkshop Student List\n");
    while(curr != NULL)
    {
        printf("Reg No: %d, Name: %s\n",
               curr->regno, curr->name);
        curr = curr->next;
    }
}
 void countStudents(struct node *head)
{
    struct node *curr;
    int count = 0;
    curr = head->next;
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    printf("Total Participants: %d\n", count);
}
void sort(struct node *head)
{
    struct node *curr, *prev, *temp;
    int swapped;
    if(head->next == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    do
    {
        swapped = 0;
        prev = head;
        curr = head->next;
        while(curr->next != NULL)
        {
            if(curr->regno > curr->next->regno)
            {
                temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                prev->next = temp;
                prev = temp;
                swapped = 1;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    } while(swapped == 1);
    printf("List sorted by Registration Number.\n");
}
void reverse(struct node *head)
{
    struct node *prev, *curr, *nextnode;
    prev = NULL;
    curr = head->next;
    while(curr != NULL)
    {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    head->next = prev;
    printf("List reversed successfully.\n");
}
int main()
{
    struct node *head;
    int choice;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    do
    {
        printf("\n WORKSHOP ENROLLMENT SYSTEM \n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display List\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addStudent(head);
                break;
            case 2:
                removeStudent(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                countStudents(head);
                break;
            case 5:
                sort(head);
                break;
            case 6:
                reverse(head);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 7);
    while(head != NULL)
    {
        struct node *curr = head;
        head = head->next;
        free(curr);
    }
    return 0;
}              
