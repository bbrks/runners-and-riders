/*
 * File:   entrant_data.h
 * Author: ben
 *
 * Created on 12 December 2012, 05:03
 */

#ifndef ENTRANT_DATA_H
#define	ENTRANT_DATA_H

#ifdef	__cplusplus
extern "C" {
#endif


    typedef struct entrant {
        int entrant_number;
        char entrant_course[2];
        char entrant_name[50];
        struct entrant *next_entrant;
    } entrant;

    void read_entrant_file(char *str);
    void print_entrant_list(void);


#ifdef	__cplusplus
}
#endif

#endif	/* ENTRANT_DATA_H */

