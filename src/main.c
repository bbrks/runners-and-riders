#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners-and-riders.h"

int main(int argc, char** argv) {

	char eventfile[FILELENGTH_MAX];

	/* Todo: implement FILELENGTH_MAX into scanf format */
	printf("Event file: ");
	scanf(" %255s", eventfile);
//    strcpy(&eventfile, "/Users/ben/Dropbox/Aber/CS237/runners-and-riders/data/main/name.txt");
    readname(eventfile);

	return (EXIT_SUCCESS);

}

void readname(char filename[FILELENGTH_MAX]) {
    event event;
    FILE *file;

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Can't open file \"%s\"! (Does it exist?)\n", filename);
    } else {
        fgets(event.name, sizeof(event.name), file);
        fgets(event.date, sizeof(event.date), file);
        fgets(event.time, sizeof(event.time), file);
    }
    fclose(file);
}
