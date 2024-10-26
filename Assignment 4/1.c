//Write a Menu driven C program to accomplish the following functionalities in doubly
//linked list.
//a) Create a doubly linked list.
//b) Display the elements of a doubly linked list.
//c) Insert a node at the beginning of a doubly linked list.
//d) Insert a node at the end of a doubly linked list.
//e) Insert a node before a given node of a doubly linked list.
//f) Insert a node after a given node of a doubly linked list.
//g) Delete a node from the beginning of a doubly linked list.
//h) Delete a node from the end of a doubly linked list.
//i) Delete a node after a given node of a doubly linked list.
//j) Delete the entire doubly linked list.



#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
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
    newNode->prev = current;
}

// Function to insert a node before a given node
void insertBefore(struct Node** head, int targetData, int data) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* current = *head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", targetData);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        *head = newNode; // Update head if inserting before the first node
    }
    current->prev = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node** head, int targetData, int data) {
    struct Node* current = *head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", targetData);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL; // List becomes empty
    }
    free(current);
}

// Function to delete a node after a given node
void deleteAfter(struct Node** head, int targetData) {
    struct Node* current = *head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Node with data %d not found or has no next node.\n", targetData);
        return;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = current;
    }
    free(temp);
}

// Function to delete the entire doubly linked list
void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL; // Set head to NULL after deletion
    printf("The entire doubly linked list has been deleted.\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, targetData;

    do {
        printf("\nMenu:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display the elements of the doubly linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire doubly linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating doubly linked list. Please insert nodes one by one.\n");
                break; // Placeholder for creation through insertion
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
