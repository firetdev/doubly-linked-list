#include <stdlib.h>
#include <stdio.h>

// Define Node type
typedef struct Node {
	int value;
	struct Node* prev;
	struct Node* next;
} Node;


// Define List type
typedef struct List {
	Node* head;
	Node* tail;
} List;

Node* create_node(int v) {
	Node* new_node = malloc(sizeof(*new_node));  // Allocate memory

	if (new_node == NULL) {
		perror("Failed to allocate memory");
		return NULL;
	}

	new_node->value = v;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

List* create_list() {
	List* new_list = malloc(sizeof(*new_list));  // Allocate memory

	if (new_list == NULL) {
		perror("Failed to allocate memory");
		return NULL;
	}

	new_list->head = NULL;
	new_list->tail = NULL;

	return new_list;
}

List* create_list_by_value(int v) {
	List* new_list = create_list();

	if (new_list == NULL) {
		perror("Failed to create list");
		return NULL;
	}

	Node* head = create_node(v);

	if (head == NULL) {
		perror("Failed to create initial node");
		return NULL;
	}

	new_list->head = head;
	new_list->tail = head;

	return new_list;
}
