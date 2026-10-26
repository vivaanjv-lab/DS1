#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
typedef struct {
    int rollNo;
    char name[50];
    float marks;
} Student;

// Function Prototypes
void displayStudents(Student s[], int n);
void insertionSortByRoll(Student s[], int n);
void selectionSortByName(Student s[], int n);
void shellSortByMarks(Student s[], int n);
void linearSearchByName(Student s[], int n, char keyName[]);
void binarySearchByRoll(Student s[], int n, int keyRoll);

int main() {
    Student s[MAX_STUDENTS];
    int n = 0, choice, keyRoll;
    char keyName[50];

    printf("=== Student Database System ===\n");
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    while (1) {
        printf("\n------------- MENU -------------");
        printf("\n1. Display Database");
        printf("\n2. Insertion Sort (by Roll No)");
        printf("\n3. Selection Sort (by Name)");
        printf("\n4. Shell Sort (by Marks - Descending)");
        printf("\n5. Linear Search (by Name)");
        printf("\n6. Binary Search (by Roll No)");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStudents(s, n);
                break;
            case 2:
                insertionSortByRoll(s, n);
                printf("\n[Success] Sorted by Roll Number using Insertion Sort.\n");
                displayStudents(s, n);
                break;
            case 3:
                selectionSortByName(s, n);
                printf("\n[Success] Sorted by Name using Selection Sort.\n");
                displayStudents(s, n);
                break;
            case 4:
                shellSortByMarks(s, n);
                printf("\n[Success] Sorted by Marks using Shell Sort.\n");
                displayStudents(s, n);
                break;
            case 5:
                printf("Enter Name to search: ");
                scanf(" %[^\n]s", keyName);
                linearSearchByName(s, n, keyName);
                break;
            case 6:
                // Binary search requires the array to be sorted by Roll Number first
                insertionSortByRoll(s, n);
                printf("Enter Roll Number to search: ");
                scanf("%d", &keyRoll);
                binarySearchByRoll(s, n, keyRoll);
                break;
            case 7:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
void displayStudents(Student s[], int n) {
    if (n == 0) {
        printf("\nDatabase is empty!\n");
        return;
    }
    printf("\n%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-25s %-10.2f\n", s[i].rollNo, s[i].name, s[i].marks);
    }
}
void insertionSortByRoll(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].rollNo > key.rollNo) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}
void selectionSortByName(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(s[j].name, s[minIdx].name) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Student temp = s[i];
            s[i] = s[minIdx];
            s[minIdx] = temp;
        }
    }
}
void shellSortByMarks(Student s[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = s[i];
            int j;
            for (j = i; j >= gap && s[j - gap].marks < temp.marks; j -= gap) {
                s[j] = s[j - gap];
            }
            s[j] = temp;
        }
    }
}
void linearSearchByName(Student s[], int n, char keyName[]) {
    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < n; i++) {
        if (strcasecmp(s[i].name, keyName) == 0) {
            printf("Found -> Roll No: %d | Name: %s | Marks: %.2f\n", 
                   s[i].rollNo, s[i].name, s[i].marks);
            found = 1;
        }
    }
    if (!found) {
        printf("No student found with Name: %s\n", keyName);
    }
}
void binarySearchByRoll(Student s[], int n, int keyRoll) {
    int low = 0, high = n - 1, found = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (s[mid].rollNo == keyRoll) {
            printf("\nFound -> Roll No: %d | Name: %s | Marks: %.2f\n", 
                   s[mid].rollNo, s[mid].name, s[mid].marks);
            found = 1;
            break;
        } else if (s[mid].rollNo < keyRoll) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("\nStudent with Roll No %d not found.\n", keyRoll);
    }
}