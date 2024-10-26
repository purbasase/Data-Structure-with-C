//Write a Menu driven C program to accomplish the following functionalities in single linked list.a) Create a single linked list.b) Display the elements of a single linked list.c) Insert a node at the beginning of a single linked list.d) Insert a node at the end of a single linked list.e) Insert a node before a given node of a single linked list.f) Insert a node after a given node of a single linked list.g) Delete a node from the beginning of a single linked list.h) Delete a node from the end of a single linked list.i) Delete a node after a given node of a single linked list.j) Delete the entire single linked list.
#include <stdio.h>
#include <stdlib.h>
// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
// Function to insert a node before a given node
void insertBefore(struct Node** head, int targetData, int data) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if ((*head)->data == targetData) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data != targetData) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Node with data %d not found.\n", targetData);
    } else {
        struct Node* newNode = createNode(data);
        newNode->next = current->next;
        current->next = newNode;
    }
}
// Function to insert a node after a given node
void insertAfter(struct Node** head, int targetData, int data) {
    struct Node* current = *head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", targetData);
    } else {
        struct Node* newNode = createNode(data);
        newNode->next = current->next;
        current->next = newNode;
    }
}
// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
// Function to delete a node after a given node
void deleteAfter(struct Node** head, int targetData) {
    struct Node* current = *head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Node with data %d not found or has no next node.\n", targetData);
    } else {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}
// Function to delete the entire linked list
void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
    printf("The entire linked list has been deleted.\n");
}
// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, targetData;
    do {
        printf("\nMenu:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the elements of the linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Creating linked list. Please insert nodes one by one.\n");
                break; // Just a placeholder, as creation is done through insertion
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                printf("Enter target node data to insert before: ");
                scanf("%d", &targetData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBefore(&head, targetData, data);
                break;
            case 6:
                printf("Enter target node data to insert after: ");
                scanf("%d", &targetData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfter(&head, targetData, data);
                break;
            case 7:
                deleteFromBeginning(&head);
                break;
            case 8:
                deleteFromEnd(&head);
                break;
            case 9:
                printf("Enter target node data to delete after: ");
                scanf("%d", &targetData);
                deleteAfter(&head, targetData);
                break;
            case 10:
                deleteList(&head);
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 11);
    return 0;
}

