#include<stdio.h>
#define MAX 3
int cqueue[MAX];
int front=-1,rear=-1;
void insert()
{
    int value;
    if((front==0&&rear==MAX-1)||front==rear+1)
    {
        printf("Circular Queue Overflow!\n");
        return;
    }
    printf("Enter element to insert:");
    scanf("%d",&value);
    if(front==-1)
        front=rear=0;
    else if(rear==MAX-1)
        rear=0;
    else
        rear++;
    cqueue[rear]=value;
    printf("%d inserted into the circular queue.\n",value);
}
void delete()
{
    if(front==-1)
    {
        printf("Circular Queue Underflow!\n");
        return;
    }
    printf("%d deleted from the circular queue.\n",cqueue[front]);
    if(front==rear)
        front=rear=-1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
}
void display()
{
    if(front==-1)
    {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements:");
    if(front<=rear)
    {
       for(int i=front;i<=rear;i++)
        {
            printf("%d  ",cqueue[i]);
        }
    }
    else
    {
        for(int i=front;i<MAX;i++)
            printf("%d  ",cqueue[i]);
        for(int i=0;i<=rear;i++)
            printf("%d  ",cqueue[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n---Circular Queue Menu---\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert();break;
            case 2:delete();break;
            case 3:display();break;
            case 4:return 0;
            default:printf("Invalid choice!Try again.\n");
        }
    }
}
