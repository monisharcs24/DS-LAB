#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("%d pushed to stack.\n", data);
}

int pop(struct Node **head) {
    if (*head == NULL) {
        printf("Stack underflow.\n");
        return -1;
    }
    struct Node *temp = *head;
    int val = temp->data;
    *head = (*head)->next;
    free(temp);
    return val;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *stack = NULL;
    int choice, value;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                printf("Stack: ");
                display(stack);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
