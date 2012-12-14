/*
 * File:   courses.c
 * Author: Ben Brooks (beb12@aber.ac.uk)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"

static course *head = NULL;
static course *curr = NULL;

static course* create_list(char course_identifier[COURSE_LENGTH], int course_number_of_nodes, int course_nodes[COURSE_NODE_MAX]) {
    course *ptr = (course*)malloc(sizeof(course));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->course_identifier, course_identifier);
    memcpy(ptr->course_nodes, course_nodes, sizeof(ptr->course_nodes));
    ptr->course_number_of_nodes = course_number_of_nodes;
    ptr->next_course            = NULL;

    curr = ptr;
    head = ptr;
    return ptr;
}

static course* add_to_list(char course_identifier[COURSE_LENGTH], int course_number_of_nodes, int course_nodes[COURSE_NODE_MAX]) {
    if (NULL == head) {
        return (create_list(course_identifier, course_number_of_nodes, course_nodes));
    }

    course *ptr = (course*)malloc(sizeof(course));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->course_identifier, course_identifier);
    memcpy(ptr->course_nodes, course_nodes, sizeof(ptr->course_nodes));
    ptr->course_number_of_nodes = course_number_of_nodes;
    ptr->next_course            = NULL;

    curr->next_course    = ptr;
    curr = ptr;
    return ptr;
}

/*
 * Debug function to print courses
 */
void print_course_list(void) {
    course *ptr = head;
    while (ptr != NULL) {
        printf("Course: %s Number of nodes: %d Nodes: ", ptr->course_identifier, ptr->course_number_of_nodes);
        int i;
        for (i=0;i<ptr->course_number_of_nodes;i++) {
            printf("%d ", ptr->course_nodes[i]);
        }
        printf("\n");
        ptr = ptr->next_course;
    }
    return;
}

/*
 * Read course file data and adds to linked list
 */
void read_course_file(char filename[FILE_LENGTH]) {
    FILE *file;
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open the file \"%s\"! (Does it exist?)\n", filename);
    } else {
        course tmp_course;
        char tmpstring[256];
        while (fscanf(file, "%s %d %[0-9 ]\n", tmp_course.course_identifier, &tmp_course.course_number_of_nodes, tmpstring) != EOF) {
            char * pch;
            pch = strtok(tmpstring, " ");
            int i;
            for (i=0;i<tmp_course.course_number_of_nodes;i++) {
                tmp_course.course_nodes[i] = atoi(pch);
                pch = strtok(NULL, " ");
            }
            add_to_list(tmp_course.course_identifier, tmp_course.course_number_of_nodes, tmp_course.course_nodes);
        }
    }
}

/*
 * Returns the starting checkpoint of a course
 */
int get_first_node(char course_identifier[COURSE_LENGTH]) {
    course *ptr = head;
    int first_node = 0;
    while (ptr != NULL) {
        if (strcmp(course_identifier, ptr->course_identifier) == 0) {
            first_node = ptr->course_nodes[0];
        }
        ptr = ptr->next_course;
    }
    return first_node;
}
