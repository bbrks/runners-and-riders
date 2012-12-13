#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"
#include "entrant_data.h"

int main(int argc, char** argv) {

	char eventfile[FILELENGTH_MAX];
	char nodefile[FILELENGTH_MAX];
	char trackfile[FILELENGTH_MAX];
	char coursefile[FILELENGTH_MAX];
	char entrantfile[FILELENGTH_MAX];

	/* Todo: implement FILELENGTH_MAX into scanf format */
	printf("Event file: ");
	scanf(" %255s", eventfile);
    read_event_file(eventfile);
	printf("Node file: ");
	scanf(" %255s", nodefile);
    read_node_file(nodefile);
	printf("Track file: ");
	scanf(" %255s", trackfile);
    read_track_file(trackfile);
	printf("Course file: ");
	scanf(" %255s", coursefile);
    read_course_file(coursefile);
	printf("Entrant file: ");
	scanf(" %255s", entrantfile);
    read_entrant_file(entrantfile);

    printf("--------------------\n");
    print_event_data();
    printf("--------------------\n");
    print_node_list();
    printf("--------------------\n");
    print_track_list();
    printf("--------------------\n");
    print_course_list();
    printf("--------------------\n");
    print_entrant_list();
    printf("--------------------\n");

	return (EXIT_SUCCESS);

}
