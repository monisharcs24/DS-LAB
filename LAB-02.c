#include<stdio.h>
#include<string.h>

char stack[100];
int top=-1,index=0;

void push(char value)
{
    stack[++top]=value;
}
char pop()
{
    return(stack[top--]);
}
int precedence(char value)
{
    if(value=='^')
    {
        return 3;
    }
    else if(value=='/' || value=='*' || value=='%')
    {
        return 2;
    }
    else if(value=='+' || value=='-')
    {
        return 1;
    }
    else return 0;
}

int main()
{
    char infix[100],postfix[100];
    char ch,value;
    printf("Enter the infix expression:");
    scanf("%s",infix);
    push('#');
    for(int i=0;i<strlen(infix);i++)
    {
        ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix[index++] = ch;
        }
        else
        {
            switch (ch)
            {
                case '(':
                    push(ch);
                    break;
                case ')':
                    value = pop();
                    while (value != '(')
                    {
                        postfix[index++] = value;
                        value = pop();
                    }
                    break;
                case '+':
                case '-':
                case '/':
                case '*':
                case '%':
                case '^':
                    while (precedence(ch) <= precedence(stack[top]))
                    {
                        value = pop();
                        postfix[index++] = value;
                    }
                    push(ch);
                    break;
            }
        }
    }
    while (stack[top] != '#')
    {
        postfix[index++] = pop();
    }
    postfix[index] = '\0';

    printf("\nGiven infix expression: %s",infix);
    printf("\nPostfix expression: %s",postfix);
    return 0;
}
