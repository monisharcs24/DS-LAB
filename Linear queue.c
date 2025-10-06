#include<stdio.h>
#define MAX 3
int queue[MAX];
int front=-1,rear=-1;
void insert()
{
    int value;
    if(rear==MAX-1)
    {
        printf("Queue Overflow!\n");
        return;
    }
    printf("Enter element to insert:");
    scanf("%d",&value);
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=value;
    printf("%d inserted into the queue.\n",value);
}
void delete()
{
    if(front==-1||front>rear)
    {
        printf("Queue Underflow!(Empty Queue)\n");
        return;
    }
    printf("%d deleted from the queue.\n",queue[front]);
    front++;
}
void display()
{
    if(front==-1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:");
    for(int i=front;i<=rear;i++)
    {
        printf("%d  ",queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n---Queue Menu---\n");
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
