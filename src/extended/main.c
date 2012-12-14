/*
 * File:   main.c
 * Author: Ben Brooks (beb12@aber.ac.uk)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners.h"
#include "event_data.h"
#include "entrant_data.h"
#include "time_data.h"

/*#define DEBUG*/

int main(int argc, char** argv) {

	char eventfile[FILE_LENGTH];
	char nodefile[FILE_LENGTH];
	char trackfile[FILE_LENGTH];
	char coursefile[FILE_LENGTH];
	char entrantfile[FILE_LENGTH];

#ifdef DEBUG
    strcpy(&eventfile, "../../data/main/name.txt");
    strcpy(&nodefile, "../../data/main/nodes.txt");
    strcpy(&trackfile, "../../data/main/tracks.txt");
    strcpy(&coursefile, "../../data/main/courses.txt");
    strcpy(&entrantfile, "../../data/main/entrants.txt");
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

#ifdef DEBUG
    printf("--BEGIN DEBUG INFO--\n");
    print_node_list();
    printf("--------------------\n");
    print_track_list();
    printf("--------------------\n");
    print_course_list();
    printf("--------------------\n");
    print_entrant_list();
    printf("--END DEBUG INFO-----\n\n");
#endif

    menu();
	return (EXIT_SUCCESS);

}

void menu() {
	int runloop = 1;
	while (runloop) {
		int selection = 0;
        int entrant_id = 0;
        int checkpoint_id = 0;
        char time[TIME_LENGTH];
        char timefile[FILE_LENGTH];
        int diff = 0;
        printf("--------------------\n");
        print_event_data();
        printf("--------------------\n");
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
            printf("Enter Entrant ID: ");
            scanf("%d", &entrant_id);
            print_current_status(entrant_id);
			break;
		case 2:
            print_unstarted_entrants();
			break;
        case 3:
            print_on_course_entrants();
            break;
        case 4:
            print_finished_entrants();
            break;
        case 5:
            printf("Enter Entrant ID: ");
            scanf("%d", &entrant_id);
            printf("Enter Checkpoint Number: ");
            scanf("%d", &checkpoint_id);
            printf("Enter Time: ");
            scanf(" %5s", time);
            update_entrant_location(entrant_id, checkpoint_id, time);
            break;
        case 6:
            printf("Enter time file: ");
            scanf(" %255s", timefile);
            read_time_file(timefile);
            break;
        case 7:
            print_results_table();
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
