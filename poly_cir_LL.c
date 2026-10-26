#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};
struct Node* createNode(int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node **head, int coeff, int exp) {
    struct Node *newNode, *temp;
    if (coeff == 0) return;
    newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}
struct Node* createPolynomial() {
    struct Node *head = NULL;
    int n, coeff, exp, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(&head, coeff, exp);
    }
    return head;
}
void displayPolynomial(struct Node *head) {
    struct Node *temp;
    int first = 1;
    if (head == NULL) {
        printf("0");
        return;
    }
    temp = head;
    do {
        if (!first) {
            if (temp->coeff >= 0)
                printf(" + ");
            else
                printf(" - ");
        } else if (temp->coeff < 0) {
            printf("-");
        }
        int c = abs(temp->coeff);
        if (temp->exp == 0)
            printf("%d", c);
        else if (temp->exp == 1) {
            if (c != 1) printf("%d", c);
            printf("x");
        } else {
            if (c != 1) printf("%d", c);
            printf("x^%d", temp->exp);
        }
        first = 0;
        temp = temp->next;
    } while (temp != head);
}
struct Node* addPolynomials(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL, *t1, *t2, *temp;
    int found;
    if (p1 != NULL) {
        t1 = p1;
        do {
            insertTerm(&result, t1->coeff, t1->exp);
            t1 = t1->next;
        } while (t1 != p1);
    }
    if (p2 != NULL) {
        t2 = p2;
        do {
            found = 0;
            if (result != NULL) {
                temp = result;
                do {
                    if (temp->exp == t2->exp) {
                        temp->coeff += t2->coeff;
                        found = 1;
                        break;
                    }
                    temp = temp->next;
                } while (temp != result);
            }
            if (!found)
                insertTerm(&result, t2->coeff, t2->exp);
            t2 = t2->next;
        } while (t2 != p2);
    }
    return result;
}
int main() {
    struct Node *p1, *p2, *sum;
    printf("Enter first polynomial:\n");
    p1 = createPolynomial();
    printf("Enter second polynomial:\n");
    p2 = createPolynomial();
    printf("\nFirst Polynomial: ");
    displayPolynomial(p1);
    printf("\nSecond Polynomial: ");
    displayPolynomial(p2);
    sum = addPolynomials(p1, p2);
    printf("\nResultant Polynomial: ");
    displayPolynomial(sum);
    return 0;
}

