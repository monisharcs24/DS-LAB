#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
};
struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node* root,int value){
    if(root==NULL)
        return createNode(value);
    if(value<root->data)
        root->left=insert(root->left,value);
    else if(value>root->data)
        root->right=insert(root->right,value);
    return root;
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct Node* root=NULL;
    int choice,value;
    while(1){
        printf("\n---MENU---\n");
        printf("1.Insert an element into Binary Search tree.\n");
        printf("2.Inorder Traversal.\n");
        printf("3.Preorder Traversal.\n");
        printf("4.Postorder Traversal.\n");
        printf("5.Display elements.\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter value to insert:");
            scanf("%d",&value);
            root=insert(root,value);
            break;
        case 2:
            printf("Inorder Traversal:");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal:");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal:");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Elements in Binary Search Tree(Inoder Display):");
            inorder(root);
            printf("\n");
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice.Try again!\n");
        }
    }
    return 0;
}
