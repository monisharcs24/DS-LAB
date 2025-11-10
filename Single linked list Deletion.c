#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("First element deleted successfully.\n");
}
void deleteLast(){
    if (head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("Last element deleted successfully.\n");
}
void deleteSpecific(int value){
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->data == value) {
        head = head->next;
        free(temp);
        printf("Element %d deleted successfully.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
     if (temp == NULL) {
        printf("Element %d not found!\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted successfully.\n", value);
}
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    int n, choice, value;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(n);

    while (1){
        printf("\n--- MENU ---\n");
        printf("1. Display List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Last Element\n");
        printf("4. Delete Specific Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                display();
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                deleteLast();
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                deleteSpecific(value);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
