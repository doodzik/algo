//
//  main.c
//  algo1
//
//  Created by Frederik Dudzik on 10.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"

#define DOUBLE_LINKED_LIST 0

#if DOUBLE_LINKED_LIST == 1
//#include "student_list_doubly.h"
#else
#include "student_list.h"
#endif



int main(int argc, const char * argv[])
{
    char* str = malloc(100);
    StudentList* sl = initStudentList();
    int sl_length = 0;
    char* stundent_id;
    while(1)
    {
        printf("What function do you want to run?\n");
        printf("PUSH, UNSHIFT, PRINT, LENGTH, DELETE, DELETE_ALL, FIND_ID, QUERY, SORT_MATRIKEL, SORT_STUDIENGANG, QUIT\n");
        
        fgets(str, sizeof(str), stdin);

        if        (strncmp(str, "PUSH\n",        100) == 0) {
            push(sl, newStudentCli());
            sl_length++;
        } else if (strncmp(str, "UNSHIFT\n",     100) == 0) {
            unshift(sl, newStudentCli());
            sl_length++;
        } else if (strncmp(str, "PRINT_ALL\n",   100) == 0) {
            printStudentList(sl);
        } else if (strncmp(str, "LENGTH\n",      100) == 0) {
            printf("\nLength: %d", sl_length);
        } else if (strncmp(str, "DELETE\n",      100) == 0) {
            printf("enter student id:\n");
            fgets(stundent_id, sizeof(stundent_id), stdin);
            // TODO don't use atoi
            destroy(sl, atoi(stundent_id));
            sl_length--;
        } else if (strncmp(str, "DELETE_ALL\n",  100) == 0) {
            destroyList(sl);
            sl_length = 0;
        } else if (strncmp(str, "FIND_ID\n",     100) == 0) {
            printf("enter student id:\n");
            fgets(stundent_id, sizeof(stundent_id), stdin);
            printStudent(studentFindById(sl, atoi(stundent_id)));
        } else if (strncmp(str, "QUERY\n",       100) == 0) {
            /*
             (i) Implementieren Sie Funktionalität zum Suchen eines oder mehrerer Studenten nach Vor- und
             Nachname, Matrikelnummer und Studiengang.
            */
        } else if (strncmp(str, "SORT_STUDIENGANG\n", 100) == 0) {
            sortStudiengang(sl);
            /*
             buuble
             (j) Implementieren Sie Funktionalität zum Sortieren der Datensätze der Studenten, Matrikel-
             nummer und Studiengang nach zwei selbstgewählten Sortierverfahren.
             */
        } else if (strncmp(str, "SORT_MATRIKEL\n",  100) == 0) {
            sortMatrikel(sl);
          /*
             Selection
          */
        } else if (strncmp(str, "QUIT\n",        100) == 0) {
            return 0;
        
        }
    }
    return 0;
}
