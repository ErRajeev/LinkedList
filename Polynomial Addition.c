#include <stdio.h>
#include <stdlib.h>
struct node *create(struct node *);
struct node *insert(struct node *, int, int);
void polyadd(struct node *, struct node *);
void display(struct node *);
struct node
{
    struct node *link;
    int expo;
    int coe;
};
int main(void)
{
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    printf("Enter First Polynomial\n");
    root1 = create(root1);
    printf("Enter Second Polynomial\n");
    root2 = create(root2);
    display(root1);
    display(root2);
    polyadd(root1, root2);
    return 0;
}
struct node *create(struct node *root)
{
    int n, i, coeff, expo;
    printf("Enter Number of Terms :\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Coefficient for term %d :\n", i + 1);
        scanf("%d", &coeff);
        printf("Enter the Exponent for term %d :\n", i + 1);
        scanf("%d", &expo);
        root = insert(root, coeff, expo);
    }
    return root;
}
struct node *insert(struct node *root, int co, int ex)
{
    struct node *p;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->coe = co;
    temp->expo = ex;
    temp->link = NULL;
    if (root == NULL || ex > root->expo)
    {
        temp->link = root;
        root = temp;
    }
    else
    {
        p = root;
        while (p->link != NULL && p->link->expo >= ex)
            p = p->link;
        temp->link = p->link;
        p->link = temp;
    }
    return root;
}
void polyadd(struct node *root1, struct node *root2)
{
    printf("-------------------\n");
    struct node *ptr1 = root1;
    struct node *ptr2 = root2;
    struct node *root3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            root3 = insert(root3, ptr1->coe + ptr2->coe, ptr2->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            root3 = insert(root3, ptr1->coe, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            root3 = insert(root3, ptr2->coe, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL)
    {
        root3 = insert(root3, ptr1->coe, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        root3 = insert(root3, ptr2->coe, ptr2->expo);
        ptr2 = ptr2->link;
    }
    display(root3);
}
void display(struct node *root)
{
    if (root == NULL)
        printf("No Polynomial\n");
    else
    {
        struct node *temp = root;
        while (temp != NULL)
        {
            printf("(%dx^%d)", temp->coe, temp->expo);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
