// Linked list implementation in C
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    if (new_node == NULL) {
        return;
    }
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
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