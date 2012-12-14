/*
 * File:   nodes.c
 * Author: Ben Brooks (beb12@aber.ac.uk)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"

static node *head = NULL;
static node *curr = NULL;

node the_node;

static node* create_list(int node_number, char node_type[NODE_TYPE_LENGTH]) {
    node *ptr = (node*)malloc(sizeof(node));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->node_type, node_type);
    ptr->node_number = node_number;
    ptr->next_node   = NULL;

    curr = ptr;
    head = ptr;
    return ptr;

}

static node* add_to_list(int node_number, char node_type[NODE_TYPE_LENGTH]) {
    if (NULL == head) {
        return (create_list(node_number, node_type));
    }

    node *ptr = (node*)malloc(sizeof(node));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->node_type, node_type);
    ptr->node_number = node_number;
    ptr->next_node   = NULL;

    curr->next_node  = ptr;
    curr = ptr;
    return ptr;
}

/*
 * Debug function to print checkpoints
 */
void print_node_list(void) {
    node *ptr = head;
    while (ptr != NULL) {
        printf("Node: %d Type: %s\n", ptr->node_number, ptr->node_type);
        ptr = ptr->next_node;
    }
    return;
}

/*
 * Read node file data and adds to linked list
 */
void read_node_file(char filename[FILE_LENGTH]) {
    FILE *file;
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open the file \"%s\"! (Does it exist?)\n", filename);
    } else {
        node tmp_node;
        while (fscanf(file, "%d %s\n", &tmp_node.node_number, tmp_node.node_type) != EOF) {
            add_to_list(tmp_node.node_number, tmp_node.node_type);
        }
    }
}

