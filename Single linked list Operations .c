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

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void sortList(struct Node *head) {
    if (head == NULL) return;
    struct Node *current = head, *index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, value, list_choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display Lists\n");
        printf("4. Sort List\n");
        printf("5. Reverse List\n");
        printf("6. Concatenate Lists\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List 1: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;
            case 2:
                printf("Enter value to insert in List 2: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;
            case 3:
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;
            case 4:
                printf("Sort which list (1 or 2)? ");
                scanf("%d", &list_choice);
                if (list_choice == 1)
                    sortList(list1);
                else
                    sortList(list2);
                break;
            case 5:
                printf("Reverse which list (1 or 2)? ");
                scanf("%d", &list_choice);
                if (list_choice == 1)
                    list1 = reverseList(list1);
                else
                    list2 = reverseList(list2);
                break;
            case 6:
                list1 = concatenate(list1, list2);
                list2 = NULL;
                printf("Lists concatenated. List 1 now contains both lists.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
