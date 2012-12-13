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
	printf("Node file: ");
	scanf(" %255s", nodefile);
	printf("Track file: ");
	scanf(" %255s", trackfile);
	printf("Course file: ");
	scanf(" %255s", coursefile);
	printf("Entrant file: ");
	scanf(" %255s", entrantfile);

    read_event_file(eventfile);
    read_node_file(nodefile);
    read_track_file(trackfile);
    read_course_file(coursefile);
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
