#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node* next;
    struct node* prev;

};
typedef struct node node_t;

void printlist(node_t *head) {
    node_t *temporary = head;
    while (temporary != NULL) {
        printf("%d - ", temporary->value); // Find temp and print out the value
        temporary = temporary->next;
    }
    printf("\n");
}

node_t *create_new_node(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t* newnode) {
    node_to_insert_after->next = newnode;
    newnode->next = node_to_insert_after->next;

}

void remove_node(node_t **head, node_t *node_to_remove) {
    // sp case if the head is the node to be removed
    if (*head == node_to_remove) {
        *head = node_to_remove->next;
        return; 
    } else {
        // find the previous node in the list
        node_t* temp = *head;
        while (temp != NULL && temp->next != node_to_remove) {
            temp = temp->next;
        }
        if (temp == NULL) return;
        temp->next = node_to_remove->next;
        node_to_remove->next = NULL;
    }
    return;
}

node_t *find_node(node_t *head, int value) {
    node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}



 int main() {
    node_t *head = NULL;
    node_t *tmp;

    for(int i=0; i < 25; i++) {
        tmp = create_new_node(i);
        tmp->next = head;
        head = tmp;
    }


    printlist(head);

    return 0;
 }