#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners-and-riders.h"

static course *head = NULL;
static course *curr = NULL;

static course* create_list(char identifier[2], int number_of_nodes, int nodes[20]) {
    course *ptr = (course*)malloc(sizeof(course));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->identifier, identifier);
    memcpy(ptr->nodes, nodes, sizeof(ptr->nodes));
    ptr->number_of_nodes = number_of_nodes;
    ptr->next_course     = NULL;

    curr = ptr;
    head = ptr;
    return ptr;
}

static course* add_to_list(char identifier[2], int number_of_nodes, int nodes[20]) {
    if (NULL == head) {
        return (create_list(identifier, number_of_nodes, nodes));
    }

    course *ptr = (course*)malloc(sizeof(course));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->identifier, identifier);
    memcpy(ptr->nodes, nodes, sizeof(ptr->nodes));
    ptr->number_of_nodes = number_of_nodes;
    ptr->next_course     = NULL;

    curr->next_course    = ptr;
    curr = ptr;
    return ptr;
}

void print_course_list(void) {
    course *ptr = head;
    while (ptr != NULL) {
        printf("Course: %s\nNumber of nodes: %d\nNodes: ", ptr->identifier, ptr->number_of_nodes);
        int i;
        for (i=0;i<ptr->number_of_nodes;i++) {
            printf("%d ", ptr->nodes[i]);
        }
        printf("\n");
        ptr = ptr->next_course;
    }
    return;
}

void read_course_file(char filename[FILELENGTH_MAX]) {
    FILE *file;
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open the file \"%s\"! (Does it exist?)\n", filename);
    } else {
        course tmp_course;
        char tmpstring[256];
        while (fscanf(file, "%s %d %[0-9 ]\n", tmp_course.identifier, &tmp_course.number_of_nodes, tmpstring) != EOF) {
            char * pch;
            pch = strtok(tmpstring, " ");
            int i;
            for (i=0;i<tmp_course.number_of_nodes;i++) {
                tmp_course.nodes[i] = atoi(pch);
                pch = strtok(NULL, " ");
            }
            add_to_list(tmp_course.identifier, tmp_course.number_of_nodes, tmp_course.nodes);
        }
    }
}
