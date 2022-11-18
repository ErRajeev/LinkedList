#include <stdio.h>
#include <stdlib.h>
void append(void);
void display(void);
struct node
{
    struct node *link;
    int data;
};
struct node *root = NULL;
int main(void)
{
    unsigned short ch;
    while (1)
    {
        printf("1 : Append Data\n");
        printf("2 : Display Data\n");
        printf("3 : Exit\n");
        printf("Enter Your Choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice...!!\n");
            break;
        }
    }
    return 0;
}
void append()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = root;
    printf("Enter Element :\n");
    scanf("%d", &temp->data);
    if (root == NULL || temp->data < p->data)
    {
        temp->link = root;
        root = temp;
    }
    else
    {
        while (p->link != NULL && p->link->data < temp->data)
            p = p->link;
        temp->link = p->link;
        p->link = temp;
    }
}
void display()
{
    if (root == NULL)
        printf("LinkedList is Empty...!!\n");
    else
    {
        struct node *p = root;
        while (p != NULL)
        {
            printf("%d", p->data);
            p = p->link;
            if (p != NULL)
                printf(" ----> ");
            else
                printf("\n");
        }
    }
}
