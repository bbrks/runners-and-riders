#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"
#include "entrant_data.h"

#define AUTOREADFILES

int main(int argc, char** argv) {

	char eventfile[FILELENGTH_MAX];
	char nodefile[FILELENGTH_MAX];
	char trackfile[FILELENGTH_MAX];
	char coursefile[FILELENGTH_MAX];
	char entrantfile[FILELENGTH_MAX];

# ifdef AUTOREADFILES
    strcpy(&eventfile, "/Users/ben/Dropbox/Aber/CS237/runners-and-riders/data/main/name.txt");
    strcpy(&nodefile, "/Users/ben/Dropbox/Aber/CS237/runners-and-riders/data/main/nodes.txt");
    strcpy(&trackfile, "/Users/ben/Dropbox/Aber/CS237/runners-and-riders/data/main/tracks.txt");
    strcpy(&coursefile, "/Users/ben/Dropbox/Aber/CS237/runners-and-riders/data/main/courses.txt");
    strcpy(&entrantfile, "/Users/ben/Dropbox/Aber/CS237/runners-and-riders/data/main/entrants.txt");
#else
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
#endif

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

    menu();

	return (EXIT_SUCCESS);

}

void menu() {
	int runloop = 1;
	while (runloop) {
		int selection = NULL;

		printf("  1. Query the current location of a competitor\n");
		printf("  2. List competitors which haven't started yet\n");
		printf("  3. List competitors which are out on the course\n");
		printf("  4. List competitors who have finished\n");
		printf("  5. Manually supply times for a competitor\n");
		printf("  6. Read in a file containing times\n");
		printf("  7. Print a results list\n");
		printf("  0. Quit\n");

		printf("Choose an option: ");
		scanf("%d", &selection);

	    switch (selection) {
		case 1:
			break;
		case 2:
			break;
		case 0:
			printf("Bye Bye!\n");
			runloop = 0;
			break;
		default:
			printf("\nInvalid Selection!\n\n");
			break;
		}
	}
}
