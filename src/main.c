#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "runners-and-riders.h"

int main(int argc, char** argv) {

	char eventfile[FILELENGTH_MAX];
	char nodefile[FILELENGTH_MAX];

	/* Todo: implement FILELENGTH_MAX into scanf format */
	printf("Event file: ");
	scanf(" %255s", eventfile);
	printf("Node file: ");
	scanf(" %255s", nodefile);
	read_event_file(eventfile);
	read_node_file(nodefile);

	return (EXIT_SUCCESS);

}
