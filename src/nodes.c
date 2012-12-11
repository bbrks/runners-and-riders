#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners-and-riders.h"

node *head = NULL;
node *curr = NULL;

static node* create_list(int node_number, enum node_type type) {

}

static node* add_to_list(int node_number, enum node_type type) {

}

static node* search_in_list(int node_number, enum node_type type, node **prev) {

}

static node* delete_from_list(int node_number) {

}

void print_list(void) {

}

void read_node_file(char filename[FILELENGTH_MAX]) {
    node tmp_node;
    FILE *file;

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open the file \"%s\"! (Does it exist?)\n", filename);
    } else {
        // while !EOF, add to a linked list/array of nodes
        // node = ID + Type (enum) + next_node ptr
    }
}

