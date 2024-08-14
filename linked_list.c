#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *addr
            };

struct node *head = NULL;
struct node *temp = NULL;
struct node *new1 = NULL;
struct node *prev = NULL;
struct node *next = NULL;

void create_list()
{
    int n,n1,i=1;
    head = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value \n ");
    scanf("%d",&n);
    head->data = n;
    head->addr = NULL;
    temp = head;
    printf("Enter the number of node \n");
    scanf("%d",&n1);
    while(i < n1)
    {
        int n;
        new1 = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value\n");
        scanf("%d",&n);
        new1 -> data = n;
        new1 -> addr = NULL;

        temp -> addr=new1;
        temp  = temp -> addr;
        i++;
    }

}
void insert_at_beg()
{
     if(head == NULL)
    {
         printf("list is empty\n");
    }
    else
    {
        int n;
        new1 = (struct node*)malloc(sizeof(struct node));
        printf("Enter the number\n");
        scanf("%d",&n);
        //temp= head;
        new1->data = n;
        new1 ->addr =NULL;
         new1 ->addr=head;
         head = new1;
    }


}



void display()
{
    if(head == NULL)
    {
         printf("list is empty\n");
    }
    else
    {
     printf("element are :\n");
     temp = head;
    while(temp != NULL)
    {
         printf("%d\n",temp->data);
         temp = temp->addr;
    }
    }
}
void insert_at_end()
{
    if(head == NULL)
    {
         printf("list is empty\n");
    }
    else
    {
      int n;
        new1 = (struct node*)malloc(sizeof(struct node));
        printf("Enter the number\n");
        scanf("%d",&n);
        temp= head;
        new1->data = n;
        new1 ->addr =NULL;
        while(temp->addr != NULL)
        {
            temp = temp->addr;
        }
        temp->addr =new1;
    }
}
void insert_at_middle()
{
    if(head == NULL)
    {
         printf("list is empty\n");
    }
    else
    {
      int n,pos,i=1;
        new1 = (struct node*)malloc(sizeof(struct node));
        printf("Enter the number\n");
        scanf("%d",&n);
        new1->data = n;
        new1->addr =NULL;
        temp= head;
        printf("enter the position where you want to insert node\n ");
        scanf("%d",&pos);
        while(i < pos)
        {
            prev = temp;
            temp = temp->addr;
            i++;
        }
        prev ->addr =new1;
        new1->addr =temp;
    }
}
void delete_at_beg()
{
    if(head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp = head;
        head = temp->addr;
        free(temp);
    }
}

void delete_at_end()
{
    if(head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp  =head;
        while(temp->addr != NULL)
        {
            prev = temp;
            temp = temp->addr;
        }
        prev->addr = NULL;
        free(temp);
    }
}

void delete_at_middle()
{
    if(head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
     temp = head;
     int pos,i=1;
     printf("Enter the pos\n");
     scanf("%d",&pos);
     while(i < pos)
     {
         prev = temp;
         temp = temp->addr;
         next=temp->addr;
         i++;
     }
     prev -> addr =next;
     free(temp);
    }
}
void reverse_list()
{
     if(head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=next=head;
        prev=NULL;
        while(next != NULL)
        {
            next =next->addr;
            temp->addr =prev;
            prev = temp;
            temp = next;
        }
        head = prev;
    }

}
void main()
{
    int choice;
    while(1)
        {
        printf("-------------linked list--------------------\n");
        printf("\n\n1.create_list\n2.insert_at_beg\n3.insert_at_end\n4.insert_at_middle\n5.delete_at_beg\n6.delete_at_end\n7.delete_at_middle\n8.reverse_list\n9.display\n10.exit");
        printf("\nenter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create_list();
            break;

        case 2:
            insert_at_beg();
            break;

        case 3:
            insert_at_end();
            break;

        case 4:
            insert_at_middle();
            break;

        case 5:
            delete_at_beg();
            break;

        case 6:
            delete_at_end();
            break;

        case 7:
            delete_at_middle();
            break;

        case 8:
            reverse_list();
            break;

        case 9:
            display();
            break;

        case 10:
            exit(1);

        default:
             printf("invaild input");

        }
    }
}
