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

void free_list(Node* head) {
    Node* current = head;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

void insert_after(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        return;
    }
    Node* new_node = create_node(new_data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Create a linked list data structure and perform operations on it
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Initialize a new linked list
LinkedList* create_linked_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

// Append a new node to the linked list
void linked_list_append(LinkedList* list, int new_data) {
    append(&(list->head), new_data);
}

// Print the linked list
void linked_list_print(LinkedList* list) {
    print_list(list->head);
}

// Pop the head node from the linked list
void linked_list_pop(LinkedList* list) {
    pop(&(list->head));
}
// Free the entire linked list
void linked_list_free(LinkedList* list) {
    free_list(list->head);
    free(list);
}
// Insert a new node after a given node in the linked list
void linked_list_insert_after(Node* prev_node, int new_data) {
    insert_after(prev_node, new_data);
}
// Example usage of the linked list
int main(void) {
    LinkedList* list = create_linked_list();
    if (list == NULL) {
        return 1;
    }
    linked_list_append(list, 1);
    linked_list_append(list, 2);
    linked_list_append(list, 3);
    // Time passes
    linked_list_append(list, 4);
    linked_list_print(list);
    linked_list_insert_after(list->head, 5); // Insert 5 after the head node
    linked_list_print(list);
    linked_list_pop(list);
    linked_list_print(list);
    linked_list_free(list);
    return 0;
}