#include <stdio.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[50];
    float marks;
};

void accept(struct Student s[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollno);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void display(struct Student s[], int n)
{
    int i;

    printf("\n--------------------------------------------------\n");
    printf("Roll No.\tName\t\tMarks\n");
    printf("--------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%.2f\n",
               s[i].rollno, s[i].name, s[i].marks);
    }
}

void linearSearch(struct Student s[], int n, int key)
{
    int i, found = 0;

    for(i = 0; i < n; i++)
    {
        if(s[i].rollno == key)
        {
            printf("\nStudent found!\n");
            printf("Roll Number: %d\n", s[i].rollno);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

void binarySearch(struct Student s[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    int found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(s[mid].rollno == key)
        {
            printf("\nStudent found!\n");
            printf("Roll Number: %d\n", s[mid].rollno);
            printf("Name: %s\n", s[mid].name);
            printf("Marks: %.2f\n", s[mid].marks);
            found = 1;
            break;
        }
        else if(key < s[mid].rollno)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

void insertionSort(struct Student s[], int n)
{
    int i, j;
    struct Student temp;

    for(i = 1; i < n; i++)
    {
        temp = s[i];
        j = i - 1;

        while(j >= 0 && s[j].rollno > temp.rollno)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = temp;
    }

    printf("\nStudents sorted using Insertion Sort.\n");
}

void selectionSort(struct Student s[], int n)
{
    int i, j, min;
    struct Student temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(s[j].rollno < s[min].rollno)
            {
                min = j;
            }
        }

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }

    printf("\nStudents sorted using Selection Sort.\n");
}

void shellSort(struct Student s[], int n)
{
    int gap, i, j;
    struct Student temp;

    for(gap = n / 2; gap > 0; gap = gap / 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = s[i];

            for(j = i; j >= gap && s[j - gap].rollno > temp.rollno; j = j - gap)
            {
                s[j] = s[j - gap];
            }

            s[j] = temp;
        }
    }

    printf("\nStudents sorted using Shell Sort.\n");
}

int main()
{
    struct Student s[50];
    int n, choice, key;

    printf("Enter number of students: ");
    scanf("%d", &n);

    accept(s, n);

    do
    {
        printf("\n\n========== STUDENT DATABASE ==========\n");
        printf("1. Display Students\n");
        printf("2. Linear Search\n");
        printf("3. Binary Search\n");
        printf("4. Insertion Sort\n");
        printf("5. Selection Sort\n");
        printf("6. Shell Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display(s, n);
                break;

            case 2:
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &key);
                linearSearch(s, n, key);
                break;

            case 3:
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &key);
                printf("\nNote: Binary Search requires the records to be sorted by Roll Number.\n");
                binarySearch(s, n, key);
                break;

            case 4:
                insertionSort(s, n);
                display(s, n);
                break;

            case 5:
                selectionSort(s, n);
                display(s, n);
                break;

            case 6:
                shellSort(s, n);
                display(s, n);
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}