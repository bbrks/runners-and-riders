#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"

event the_event;

void print_event_data(void) {
    printf("%s%s%s\n", the_event.event_name, the_event.event_date, the_event.event_time);
}

void read_event_file(char filename[FILELENGTH_MAX]) {
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
