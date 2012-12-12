#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners-and-riders.h"

static node *head = NULL;
static node *curr = NULL;

static node* create_list(int node_number, char node_type[3]) {
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

static node* add_to_list(int node_number, char node_type[3]) {
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

void print_node_list(void) {
    node *ptr = head;
    while (ptr != NULL) {
        printf("Node: %d\nType: %s\n", ptr->node_number, ptr->node_type);
        ptr = ptr->next_node;
    }
    return;
}

void read_node_file(char filename[FILELENGTH_MAX]) {
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

