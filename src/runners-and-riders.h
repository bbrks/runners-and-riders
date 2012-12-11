/*
 * File:   runners-and-riders.h
 * Author: ben
 *
 * Created on 08 December 2012, 17:15
 */

#ifndef RUNNERS_AND_RIDERS_H
#define	RUNNERS_AND_RIDERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define FILELENGTH_MAX 256

typedef struct {
	char name[80];
	char date[80];
	char time[6];
} event;

enum node_type {CP, MC, JN};
typedef struct node {
	int node_number;
	enum node_type type;
	struct node *next_node;
} node;

void read_event_file(char *str);
void read_node_file(char *str);

#ifdef	__cplusplus
}
#endif

#endif	/* RUNNERS_AND_RIDERS_H */

