#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners-and-riders.h"

event the_event;

void read_event_file(char filename[FILELENGTH_MAX]) {
	FILE *file;

	file = fopen(filename, "r");
	if (!file) {
		fprintf(stderr, "Can't open file \"%s\"! (Does it exist?)\n", filename);
	} else {
		fgets(the_event.name, sizeof(the_event.name), file);
		fgets(the_event.date, sizeof(the_event.date), file);
		fgets(the_event.time, sizeof(the_event.time), file);
	}
	fclose(file);
}
