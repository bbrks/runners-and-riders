/*
 * File:   times.c
 * Author: Ben Brooks (beb12@aber.ac.uk)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "entrant_data.h"
#include "event_data.h"
#include "time_data.h"

/*
 * Reads time file data and checks for disqualifications
 */
void read_time_file(char filename[FILE_LENGTH]) {
    FILE *file;
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open the file \"%s\"! (Does it exist?)\n", filename);
    } else {
        int node = 0;
        int competitor_id = 0;
        char type[TIME_TYPE_LENGTH];
        char time[TIME_LENGTH];
        while (fscanf(file, "%s %d %d %s\n", type, &node, &competitor_id, time) != EOF) {
            if (!disqualified_entrant(competitor_id)) {
                if (strcmp(type, "T") == 0) {
                    update_entrant_location(competitor_id, node, time);
                    current_time(time);
                } else if (strcmp(type, "I") == 0) {
                    disqualify_entrant(competitor_id);
                } else {
                    printf("An error occurred somewhere. Is the time file syntax correct?\n");
                }
            }
        }
    }
}

/*
 * Function to calculate difference between two times, in minutes
 */
int time_diff(char time1[TIME_LENGTH], char time2[TIME_LENGTH]) {
    int t1h, t1m, t2h, t2m;
    sscanf(time1, "%2d:%2d", &t1h, &t1m);
    sscanf(time2, "%2d:%2d", &t2h, &t2m);

    t1m += t1h*60;
    t2m += t2h*60;

    return t2m - t1m;
}
