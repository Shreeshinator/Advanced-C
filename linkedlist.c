// Linked list implementation in C
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; // Stores the data of the node
    struct Node* next; // Also stores the pointer to the next node in the linked list
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    if (new_node == NULL) { // Check if memory allocation was successful
        return NULL; // Return NULL if memory allocation failed
    }
    new_node->data = data; // Initialize the data of the new node
    new_node->next = NULL; // Initialize the next pointer of the new node to NULL
    return new_node; // Return the pointer to the newly created node
}

void append(Node** head_ref, int new_data) { // Takes a pointer to the head pointer and the new data to be added
    Node* new_node = create_node(new_data); // Create a new node with the given data
    if (new_node == NULL) { // Check if memory allocation was successful
        return; // Return if memory allocation failed
    }
    if (*head_ref == NULL) { // If the linked list is empty, make the new node the head
        *head_ref = new_node; // Set the head pointer to point to the new node
        return; // Return after adding the new node as the head
    }
    Node* last = *head_ref; // Start from the head of the list
    while (last->next != NULL) {// Traverse to the end of the list
        last = last->next;
    }
    last->next = new_node; // Link the new node at the end of the list, when last->next is NULL, it means we are at the last node, so we set its next pointer to the new node
}

void print_list(Node* node) {
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

void pop(Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    Node* temp = *head_ref;// Store the pointer to the current head
    *head_ref = (*head_ref)->next; // Move the head pointer to the next node
    free(temp); // Free the memory of the old head node
}

void free_list(Node* head) { // Free the entire linked list starting from the head node
    Node* current = head;    // Start from the head node
    Node* next_node;         // Pointer to store the next node
    while (current != NULL) {// Traverse the list until the end
        next_node = current->next;// Store the pointer to the next node before freeing the current node
        free(current);// Free the memory of the current node
        current = next_node;// Move to the next node in the list
    }
} // End of free_list function

void insert_after(Node* prev_node, int new_data) { // Insert a new node after the given previous node
    if (prev_node == NULL) { // Check if the previous node is NULL
        return; // If the previous node is NULL, we cannot insert after it, so we return without doing anything
    }
    Node* new_node = create_node(new_data); // Create a new node with the given data
    if (new_node == NULL) { // Check if memory allocation was successful
        return; // Return if memory allocation failed
    }
    new_node->next = prev_node->next; // Set the next pointer of the new node to the next pointer of the previous node
    prev_node->next = new_node; // Set the next pointer of the previous node to the new node
}

// Create a linked list data structure and perform operations on it
typedef struct LinkedList { // Define a structure for the linked list
    Node* head; // Pointer to the head node of the linked list
} LinkedList; // End of LinkedList structure definition

// Initialize a new linked list
LinkedList* create_linked_list() { // Allocate memory for a new linked list structure 
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList)); // Allocate memory for the linked list structure
    if (list == NULL) { // Check if memory allocation was successful
        return NULL; // Return NULL if memory allocation failed
    }
    list->head = NULL; // Initialize the head pointer of the linked list to NULL
    return list; // Return the pointer to the newly created linked list structure
}

// Append a new node to the linked list
void linked_list_append(LinkedList* list, int new_data) { // Append a new node with the given data to the linked list
    append(&(list->head), new_data); // Call the append function to add the new node to the linked list, passing the address of the head pointer and the new data
}

// Print the linked list
void linked_list_print(LinkedList* list) { // Print the data of each node in the linked list
    print_list(list->head); // Call the print_list function to print the data of each node in the linked list, passing the head pointer
}

// Pop the head node from the linked list
void linked_list_pop(LinkedList* list) { // Remove the head node from the linked list
    pop(&(list->head)); // Call the pop function to remove the head node from the linked list, passing the address of the head pointer
}
// Free the entire linked list
void linked_list_free(LinkedList* list) { // Free the memory allocated for the linked list and its nodes
    free_list(list->head); // Call the free_list function to free the memory of all nodes in the linked list, passing the head pointer
    free(list); // Free the memory allocated for the linked list structure itself
}
// Insert a new node after a given node in the linked list
void linked_list_insert_after(Node* prev_node, int new_data) { // Insert a new node with the given data after the specified previous node in the linked list
    insert_after(prev_node, new_data); // Call the insert_after function to insert the new node after the specified previous node, passing the previous node pointer and the new data
}
// Example usage of the linked list
int main(void) {
    LinkedList* list = create_linked_list(); // Return a pointer to a newly created linked list structure
    if (list == NULL) { // Check if memory allocation for the linked list was successful
        return 1; // Return 1 to indicate an error if memory allocation failed
    }
    linked_list_append(list, 1); // Append a new node with data 1 to the linked list
    linked_list_append(list, 2); // Append a new node with data 2 to the linked list
    linked_list_append(list, 3); // Append a new node with data 3 to the linked list
    // Time passes  
    linked_list_append(list, 4); // Append a new node with data 4 to the linked list
    linked_list_print(list);     // Print the data of each node in the linked list
    linked_list_insert_after(list->head, 5); // Insert 5 after the head node
    linked_list_print(list);     // Print the data of each node in the linked list
    linked_list_pop(list);       // Remove the head node from the linked list
    linked_list_print(list);     // Print the data of each node in the linked list
    linked_list_free(list);      // Free the memory allocated for the linked list and its nodes
    return 0;
}