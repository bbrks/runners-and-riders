/*
 * File:   event.c
 * Author: Ben Brooks (beb12@aber.ac.uk)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"

event the_event;

/*
 * Function to print event data
 */
void print_event_data(void) {
    printf("%s%s%s\n", the_event.event_name, the_event.event_date, the_event.event_time);
}

/*
 * Read event file data and add to struct
 */
void read_event_file(char filename[FILE_LENGTH]) {
    FILE *file;

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open file \"%s\"! (Does it exist?)\n", filename);
    } else {
        fgets(the_event.event_name, sizeof(the_event.event_name), file);
        fgets(the_event.event_date, sizeof(the_event.event_date), file);
        fgets(the_event.event_time, sizeof(the_event.event_time), file);
    }
    fclose(file);
}

/*
 * Updates the current time with paramenter
 */
void current_time(char time[TIME_LENGTH]) {
    strcpy(the_event.event_time, time);
}
