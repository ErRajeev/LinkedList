#include <stdio.h>
#include <stdlib.h>
struct node *memory(void); // Function To Create Memory.
void append(void);
void beginAdd(void);
void spcAdd(void);
void spcDel(void);
unsigned int length(void);
void display(void);
struct node
{
    struct node *link;
    int data;
};
struct node *root = NULL;
unsigned int len;
int main(void)
{
    short ch;
    while (1)
    {
        printf("Choose the Operation\n");
        printf("----------------------\n");
        printf("1 : Append Data in LinkedList\n");
        printf("2 : Add Data in Beginning\n");
        printf("3 : Add Data in Specific Position\n");
        printf("4 : Find the Length of LinkedList\n");
        printf("5 : Display All LinkedList\n");
        printf("6 : Detele Data in Specific Position\n");
        printf("7 : Exit\n");
        printf("Enter Your Choese :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            beginAdd();
            break;
        case 3:
            spcAdd();
            break;
        case 4:
            len = length();
            if (len == 0)
                printf("Linked List is Empty...!!\n");
            else
                printf("Length Of LinkedList is : %d\n\n", len);
            break;
        case 5:
            display();
            break;
        case 6:
            spcDel();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Wrong Choice...!!\n");
            break;
        }
    }
    return 0;
}

// Memory Creation Functions
struct node *memory()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

void append()
{
    struct node *temp;
    temp = memory();
    printf("Enter Data :\n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
        root = temp;
    else
    {
        struct node *p = root;
        while (p->link != NULL)
            p = p->link;
        p->link = temp;
    }
}

void beginAdd()
{
    struct node *temp;
    temp = memory();
    printf("Enter Data :\n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
        root = temp;
    else
    {
        temp->link = root;
        root = temp;
    }
}

unsigned int length()
{
    unsigned int count = 0;
    struct node *temp = root;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void display()
{
    if (root == NULL)
        printf("LinkedList is Empty...!!\n");
    else
    {
        struct node *temp = root;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->link;
            if (temp != NULL)
                printf(" ---> ");
            else
                printf("\n");
        }
    }
}

void spcAdd()
{
    int pos, i = 0;
    len = length();
    struct node *temp, *p;
    printf("Enter Position :  ");
    scanf("%d", &pos);
    if (pos < len && pos > 0)
    {
        p = root;
        while (i < pos)
        {
            i++;
            p = p->link;
        }
        temp = memory();
        printf("Enter Data :\n");
        scanf("%d", &temp->data);
        temp->link = NULL;
        temp->link = p->link;
        p->link = temp;
    }
}

void spcDel()
{
    int pos, i = 1;
    len = length();
    struct node *p = root;
    struct node *q = root;
    printf("Enter Position :  ");
    scanf("%d", &pos);
    if ((pos < len) && (0 < pos))
    {
        while (i < pos - 1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
    else
    {
        printf("Wrong Position...!!\n");
        printf("Current LinkedList have %d Nodes...!!\n", len);
    }
}
