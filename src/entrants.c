#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "entrant_data.h"

static entrant *head = NULL;
static entrant *curr = NULL;

entrant the_entrant;

static entrant* create_list(int entrant_number, char entrant_course[2], char entrant_name[50]) {
    entrant *ptr = (entrant*)malloc(sizeof(entrant));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->entrant_name, entrant_name);
    strcpy(ptr->entrant_course, entrant_course);
    ptr->entrant_number = entrant_number;
    ptr->next_entrant   = NULL;

    curr = ptr;
    head = ptr;
    return ptr;
}

static entrant* add_to_list(int entrant_number, char entrant_course[2], char entrant_name[50]) {
    if (NULL == head) {
        return (create_list(entrant_number, entrant_course, entrant_name));
    }

    entrant *ptr = (entrant*)malloc(sizeof(entrant));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->entrant_name, entrant_name);
    strcpy(ptr->entrant_course, entrant_course);
    ptr->entrant_number = entrant_number;
    ptr->next_entrant   = NULL;

    curr->next_entrant  = ptr;
    curr = ptr;
    return ptr;
}

void print_entrant_list(void) {
    entrant *ptr = head;
    while (ptr != NULL) {
        printf("Entrant Number: %d Course: %s Name: %s\n", ptr->entrant_number, ptr->entrant_course, ptr->entrant_name);
        ptr = ptr->next_entrant;
    }
    return;
}

void read_entrant_file(char filename[FILELENGTH_MAX]) {
    FILE *file;
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open the file \"%s\"! (Does it exist?)\n", filename);
    } else {
        entrant tmp_entrant;
        while (fscanf(file, "%d %1s %[a-zA-Z ]\n", &tmp_entrant.entrant_number, tmp_entrant.entrant_course, tmp_entrant.entrant_name) != EOF) {
            add_to_list(tmp_entrant.entrant_number, tmp_entrant.entrant_course, tmp_entrant.entrant_name);
        }
    }
    return the_entrant;
}
