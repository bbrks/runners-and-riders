#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"

static track *head = NULL;
static track *curr = NULL;

static track* create_list(int track_number, int track_start_node, int track_end_node, int track_avg_time) {
    track *ptr = (track*)malloc(sizeof(track));
    if (NULL == ptr) {
        return NULL;
    }

    ptr->track_number       = track_number;
    ptr->track_start_node   = track_start_node;
    ptr->track_end_node     = track_end_node;
    ptr->track_avg_time     = track_avg_time;
    ptr->next_track   = NULL;

    curr = ptr;
    head = ptr;
    return ptr;
}

static track* add_to_list(int track_number, int track_start_node, int track_end_node, int track_avg_time) {
    if (NULL == head) {
        return (create_list(track_number, track_start_node, track_end_node, track_avg_time));
    }

    track *ptr = (track*)malloc(sizeof(track));
    if (NULL == ptr) {
        return NULL;
    }

    ptr->track_number       = track_number;
    ptr->track_start_node   = track_start_node;
    ptr->track_end_node     = track_end_node;
    ptr->track_avg_time     = track_avg_time;
    ptr->next_track   = NULL;

    curr->next_track  = ptr;
    curr = ptr;
    return ptr;
}

void print_track_list(void) {
    track *ptr = head;
    while (ptr != NULL) {
        printf("Track: %d Start: %d End: %d Avg Time: %d\n", ptr->track_number, ptr->track_start_node, ptr->track_end_node, ptr->track_avg_time);
        ptr = ptr->next_track;
    }
    return;
}

void read_track_file(char filename[FILELENGTH_MAX]) {
    FILE *file;
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open the file \"%s\"! (Does it exist?)\n", filename);
    } else {
        track tmp_track;
        while (fscanf(file, "%d %d %d %d\n", &tmp_track.track_number, &tmp_track.track_start_node, &tmp_track.track_end_node, &tmp_track.track_avg_time) != EOF) {
            add_to_list(tmp_track.track_number, tmp_track.track_start_node, tmp_track.track_end_node, tmp_track.track_avg_time);
        }
    }
}

