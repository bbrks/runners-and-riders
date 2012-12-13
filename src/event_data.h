/*
 * File:   event_data.h
 * Author: ben
 *
 * Created on 08 December 2012, 17:15
 */

#ifndef RUNNERS_AND_RIDERS_H
#define	RUNNERS_AND_RIDERS_H

#ifdef	__cplusplus
extern "C" {
#endif


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
        int track_start_node;
        int track_end_node;
        int track_avg_time;
        struct track *next_track;
    } track;

    typedef struct course {
        char course_identifier[2];
        int course_number_of_nodes;
        int course_nodes[20]; /* Todo: clean up array size */
        struct course *next_course;
    } course;

    void read_event_file(char *str);
    void read_event_data(void);
    void read_node_file(char *str);
    void print_node_list(void);
    void read_track_file(char *str);
    void print_track_list(void);
    void read_course_file(char *str);
    void print_course_list(void);


#ifdef	__cplusplus
}
#endif

#endif	/* RUNNERS_AND_RIDERS_H */
