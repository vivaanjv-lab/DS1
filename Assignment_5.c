#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef, exp;
    struct node *next;
};

void createhead(struct node *head)
{
    head->exp = -1;
    head->next = head;
}

void insert(struct node *head, int coef, int exp)
{
    struct node *temp = head;
    struct node *curr = head->next;
    struct node *nnode;

    if (coef == 0)
        return;

    while (curr != head && curr->exp > exp)
    {
        temp = curr;
        curr = curr->next;
    }

    if (curr != head && curr->exp == exp)
    {
        curr->coef += coef;

        if (curr->coef == 0)
        {
            temp->next = curr->next;
            free(curr);
        }
    }
    else
    {
        nnode = (struct node *)malloc(sizeof(struct node));

        nnode->coef = coef;
        nnode->exp = exp;
        nnode->next = curr;
        temp->next = nnode;
    }
}

void create(struct node *head)
{
    int n, i, coef, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coef, &exp);

        insert(head, coef, exp);
    }
}

void display(struct node *head)
{
    struct node *temp = head->next;

    if (temp == head)
    {
        printf("0\n");
        return;
    }

    while (temp != head)
    {
        printf("%dx^%d", temp->coef, temp->exp);

        temp = temp->next;

        if (temp != head)
            printf(" + ");
    }

    printf("\n");
}

struct node *poly_add(struct node *head1, struct node *head2)
{
    struct node *head3, *t1, *t2, *t3, *ptr;

    head3 = (struct node *)malloc(sizeof(struct node));
    createhead(head3);

    t1 = head1->next;
    t2 = head2->next;
    t3 = head3;

    while (t1 != head1 && t2 != head2)
    {
        ptr = NULL;

        if (t1->exp == t2->exp)
        {
            int sum = t1->coef + t2->coef;

            if (sum != 0)
            {
                ptr = (struct node *)malloc(sizeof(struct node));
                ptr->coef = sum;
                ptr->exp = t1->exp;
            }

            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->exp > t2->exp)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->coef = t1->coef;
            ptr->exp = t1->exp;

            t1 = t1->next;
        }
        else
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->coef = t2->coef;
            ptr->exp = t2->exp;

            t2 = t2->next;
        }

        if (ptr != NULL)
        {
            t3->next = ptr;
            ptr->next = head3;
            t3 = ptr;
        }
    }

    while (t1 != head1)
    {
        if (t1->coef != 0)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->coef = t1->coef;
            ptr->exp = t1->exp;

            t3->next = ptr;
            ptr->next = head3;
            t3 = ptr;
        }

        t1 = t1->next;
    }

    while (t2 != head2)
    {
        if (t2->coef != 0)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            ptr->coef = t2->coef;
            ptr->exp = t2->exp;

            t3->next = ptr;
            ptr->next = head3;
            t3 = ptr;
        }

        t2 = t2->next;
    }

    return head3;
}

void free_poly(struct node *head)
{
    struct node *curr = head->next;
    struct node *temp;

    while (curr != head)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(head);
}

int main()
{
    struct node *head1, *head2, *head3;

    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));

    createhead(head1);
    createhead(head2);

    printf("Create First Polynomial\n");
    create(head1);

    printf("\nCreate Second Polynomial\n");
    create(head2);

    printf("\nFirst Polynomial: ");
    display(head1);

    printf("Second Polynomial: ");
    display(head2);

    head3 = poly_add(head1, head2);

    printf("Sum of Polynomials: ");
    display(head3);

    free_poly(head1);
    free_poly(head2);
    free_poly(head3);

    return 0;
}