//Write a Menu driven C program to accomplish the following functionalities in circular
//linked list.
//a) Create a circular linked list.
//b) Display the elements of a circular linked list.
//c) Insert a node at the beginning of a circular linked list.
//d) Insert a node at the end of a circular linked list.
//e) Delete a node from the beginning of a circular linked list.
//f) Delete a node from the end of a circular linked list.
//g) Delete a node after a given node of a circular linked list.
//h) Delete the entire circular linked list.


#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
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

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head: %d)\n", head->data); // Show circular nature
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
        *head = newNode; // Update head to new node
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) { // Only one node
        free(temp);
        *head = NULL;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = temp->next; // Bypass the head node
        *head = temp->next; // Update head
        free(temp);
    }
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* current = *head;
    if (current->next == *head) { // Only one node
        free(current);
        *head = NULL;
    } else {
        struct Node* prev = NULL;
        while (current->next != *head) {
            prev = current;
            current = current->next;
        }
        prev->next = *head; // Bypass the last node
        free(current);
    }
}

// Function to delete a node after a given node
void deleteAfter(struct Node** head, int targetData) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* current = *head;
    do {
        if (current->data == targetData) {
            if (current->next == *head) {
                printf("No node exists after the target node.\n");
                return;
            }
            struct Node* temp = current->next;
            current->next = temp->next; // Bypass the next node
            free(temp);
            return;
        }
        current = current->next;
    } while (current != *head);
    printf("Node with data %d not found.\n", targetData);
}

// Function to delete the entire circular linked list
void deleteList(struct Node** head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);
    *head = NULL; // Set head to NULL after deletion
    printf("The entire circular linked list has been deleted.\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the elements of the circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating circular linked list. Please insert nodes one by one.\n");
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
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter target node data to delete after: ");
                scanf("%d", &data);
                deleteAfter(&head, data);
                break;
            case 8:
                deleteList(&head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
