/*
 * File:   entrants.c
 * Author: Ben Brooks (beb12@aber.ac.uk)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "entrant_data.h"

static entrant *head = NULL;
static entrant *curr = NULL;

entrant the_entrant;

static entrant* create_list(int entrant_number, char entrant_course[COURSE_LENGTH], char entrant_name[NAME_LENGTH]) {
    entrant *ptr = (entrant*)malloc(sizeof(entrant));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->entrant_name, entrant_name);
    strcpy(ptr->entrant_course, entrant_course);
    strcpy(ptr->start_time, "");
    strcpy(ptr->end_time, "");
    ptr->entrant_number = entrant_number;
    ptr->last_seen      = 0;
    ptr->first_node     = get_first_node(ptr->entrant_course);
    ptr->next_entrant   = NULL;

    curr = ptr;
    head = ptr;
    return ptr;
}

static entrant* add_to_list(int entrant_number, char entrant_course[COURSE_LENGTH], char entrant_name[NAME_LENGTH]) {
    if (NULL == head) {
        return (create_list(entrant_number, entrant_course, entrant_name));
    }

    entrant *ptr = (entrant*)malloc(sizeof(entrant));
    if (NULL == ptr) {
        return NULL;
    }

    strcpy(ptr->entrant_name, entrant_name);
    strcpy(ptr->entrant_course, entrant_course);
    strcpy(ptr->start_time, "");
    strcpy(ptr->end_time, "");
    ptr->entrant_number = entrant_number;
    ptr->last_seen      = 0;
    ptr->first_node     = get_first_node(ptr->entrant_course);
    ptr->next_entrant   = NULL;

    curr->next_entrant  = ptr;
    curr = ptr;
    return ptr;
}

/*
 * Debug function to print entrants
 */
void print_entrant_list(void) {
    entrant *ptr = head;
    while (ptr != NULL) {
        printf("Entrant Number: %d Course: %s Name: %s Last Seen: %d Start Time: %s End Time: %s\n", ptr->entrant_number, ptr->entrant_course, ptr->entrant_name, ptr->last_seen, ptr->start_time, ptr->end_time);
        ptr = ptr->next_entrant;
    }
}

/*
 * Read course entrant data and adds to linked list
 */
void read_entrant_file(char filename[FILE_LENGTH]) {
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
}

/*
 * Prints where a specified entrant was last seen and at what time
 */
void print_current_status(int entrant_number) {
    entrant *ptr = head;
    while (ptr != NULL) {
        if (ptr->entrant_number == entrant_number) {
            if (ptr->last_seen == 0) {
                printf("Entrant \"%s\" has not been seen at any checkpoint yet!\n", ptr->entrant_name);
            } else {
                printf("Entrant \"%s\" was last seen at node %d at %s.\n", ptr->entrant_name, ptr->last_seen, ptr->end_time);
            }
            break;
        } else {
            ptr = ptr->next_entrant;
        }
    }
}

/*
 * Updates the specified entrant's last seen location
 */
void update_entrant_location(int entrant_number, int location, char time[TIME_LENGTH]) {
    entrant *ptr = head;
    while (ptr != NULL) {
        if (ptr->entrant_number == entrant_number) {
            ptr->last_seen = location;
            if (strcmp(ptr->start_time, "") == 0) {
                strcpy(ptr->start_time, time);
            }
            strcpy(ptr->end_time, time);
            break;
        } else {
            ptr = ptr->next_entrant;
        }
    }
}

/*
 * Prints a list of entrants who have not yet started
 */
void print_unstarted_entrants(void) {
    entrant *ptr = head;
    printf("Entrants not started\n-----------------------------------------------------------------\n");
    printf("Competitor ID\tName\n-----------------------------------------------------------------\n");
    while (ptr != NULL) {
        if (ptr->last_seen == 0) {
            printf("%d\t\t%s\n", ptr->entrant_number, ptr->entrant_name);
        }
        ptr = ptr->next_entrant;
    }
}

/*
 * Prints a list of entrants who are currently on the course
 */
void print_on_course_entrants(void) {
    entrant *ptr = head;
    printf("Entrants on course\n-----------------------------------------------------------------\n");
    printf("Competitor ID\tName\t\t\tCheckpoint\tTime\n-----------------------------------------------------------------\n");
    while (ptr != NULL) {
        if (ptr->last_seen != 0 && ptr->last_seen != ptr->first_node) {
            printf("%d\t\t%s\t\t%d\t%s\n", ptr->entrant_number, ptr->entrant_name, ptr->last_seen, ptr->end_time);
        }
        ptr = ptr->next_entrant;
    }
}

/*
 * Prints a list of finished entrants ordered by entrant ID
 */
void print_finished_entrants(void) {
    entrant *ptr = head;
    printf("Finished entrants\n-----------------------------------------------------------------\n");
    printf("Competitor ID\tName\t\t\tFinished at\n-----------------------------------------------------------------\n");
    while (ptr != NULL) {
        if (ptr->first_node == ptr->last_seen && time_diff(ptr->start_time, ptr->end_time) > 0) {
            printf("%d\t\t%s\t\t%s\n", ptr->entrant_number, ptr->entrant_name, ptr->end_time);
        }
        ptr = ptr->next_entrant;
    }
}

/*
 * Prints a list of finished entrants ordered by time taken
 */
void print_results_table(void) {
    entrant *ptr = head;
    int totaltime = 0;
    printf("Results\n-----------------------------------------------------------------\n");
    printf("Competitor ID\tName\t\t\tTime Taken\n-----------------------------------------------------------------\n");
    while (ptr != NULL) {
        if (ptr->first_node == ptr->last_seen && time_diff(ptr->start_time, ptr->end_time) > 0) {
            totaltime = time_diff(ptr->start_time, ptr->end_time);
            printf("%d\t\t%s\t\t%d Minutes\n", ptr->entrant_number, ptr->entrant_name, totaltime);
        }
        ptr = ptr->next_entrant;
    }
}
