#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = *front;
    int value = temp->data;

    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;

    free(temp);
    return value;
}

void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *front = NULL, *rear = NULL;
    int choice, value;

    while (1) {
        printf("\nQUEUE MENU\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                value = dequeue(&front, &rear);
                if (value != -1)
                    printf("Dequeued element: %d\n", value);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
