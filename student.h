/** @file student_list.h
 *  @brief defines api of the doubly/singlely linked student lists
 *
 *  This contains the prototypes for the student_list api
 *  This includes singlely or doubly list if DOUBLE_LINKED_LIST is defined or not
 *  The only difference between student_list_doubly.h and student_list_sindely.h is that
 *  student_list_doubly.h has an additional field previous in the studentList struct.
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No known bugs.
 */

#ifndef __algo1__student__
#define __algo1__student__

#include <stdio.h>
#include "util.h"

/* DEFINE SUBJECT ENUM */
#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

#define SUBJECT_COUNT 4

#define FOREACH_SUBJECT(SUBJECT) \
        SUBJECT(blank)    \
        SUBJECT(cs)       \
        SUBJECT(math)     \
        SUBJECT(fashion)  \
        SUBJECT(economy)  \

typedef enum SUBJECT_ENUM {
    FOREACH_SUBJECT(GENERATE_ENUM)
} Subject;

static const char *SUBJECT_STRING[] = {
    FOREACH_SUBJECT(GENERATE_STRING)
};

int subjectByName(char name[]);

/* DEFINE_END SUBJECT ENUM */


/**
 *  structure for a student
 */
struct student {
    char firstName[100];
    char lastName[100];
    int id;
    Subject subject;
};
typedef struct student Student;

/** @brief creates new student structure instance
 *
 *  @param firstName
 *  @param lastName
 *  @param subject
 *  @param id
 *  @return Student*
 */
Student* newStudent (char firstName[], char lastName[], char subject[], int id);

/** @brief STDOUT student structure
 *
 *  @return void
 */
void printStudent (Student* s);

/** @brief STDOUT all possible subjects
 *
 *  @return void
 */
void printSubjects();

/** @brief checks if two student matches
 *
 *    if a field is not set in s2 it is interpreted as matching
 *
 *  @param s student to match against
 *  @param s2 student to compare
 *  @return bool
 */
bool matchesStudent(Student* s, Student* s2);

#endif /* defined(__algo1__student__) */
