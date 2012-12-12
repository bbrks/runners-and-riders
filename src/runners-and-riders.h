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
    char event_name[80];
    char event_date[80];
    char event_time[6];
} event;

typedef struct node {
    int node_number;
    char node_type[3];
    struct node *next_node;
} node;

typedef struct track {
    int track_number;
    int start_node;
    int end_node;
    int avg_time;
    struct track *next_track;
} track;

void read_event_file(char *str);
void read_node_file(char *str);
void read_track_file(char *str);

#ifdef	__cplusplus
}
#endif

#endif	/* RUNNERS_AND_RIDERS_H */

