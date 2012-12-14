/*
 * File:   entrant_data.h
 * Author: Ben Brooks (beb12@aber.ac.uk)
 */

#ifndef ENTRANT_DATA_H
#define	ENTRANT_DATA_H

#ifdef	__cplusplus
extern "C" {
#endif


    typedef struct entrant {
        int entrant_number;
        char entrant_course[COURSE_LENGTH];
        char entrant_name[NAME_LENGTH];
        int first_node;
        int last_seen;
        char start_time[TIME_LENGTH];
        char end_time[TIME_LENGTH];
        struct entrant *next_entrant;
    } entrant;

    void read_entrant_file(char *str);
    void print_entrant_list(void);
    void print_current_status(int entrant_number);
    void update_entrant_location(int entrant_number, int node, char *str);
    void disqualify_entrant(int entrant_number);
    int  disqualified_entrant(int entrant_number);
    void print_unstarted_entrants(void);
    void print_on_course_entrants(void);
    void print_finished_entrants(void);
    void print_results_table(void);


#ifdef	__cplusplus
}
#endif

#endif	/* ENTRANT_DATA_H */

