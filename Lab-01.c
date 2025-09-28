#include<stdio.h>
#define SIZE 4

int stack[SIZE],top=-1;
void push(int value)
{
    if(top==SIZE-1)
    {
        printf("Overflow.Insertion not possible");
    }
    else{
        top++;
        stack[top]=value;
        printf("Insertion done");
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Underflow.Stack is empty.");
    }
    else{
        printf("\nDeleted: %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty.");
    }
    else{
        printf("Stack elements:");
        for(int i=top;i>=0;i--)
        {
            printf("%d  ",stack[i]);
        }
    }
}
int main(){
    int value,choice;
    while(1){
        printf("\n Stack Menu");
        printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
        printf("\n Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
       {
        case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.");
            return 0;
        default:
            printf("Invalid choice.");
       }

    }
}
