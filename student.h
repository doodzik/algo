//
//  student.h
//  algo1
//
//  Created by Frederik Dudzik on 14.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#ifndef __algo1__student__
#define __algo1__student__

#include <stdio.h>

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

typedef enum { false, true } bool;

struct student {
    char firstName[100];
    char lastName[100];
    int id;
    Subject subject;
};
typedef struct student Student;

Student* newStudent (char firstName[], char lastName[], char subject[], int id);
Student* newStudentCli();
Student* newStudentCliWithoutNullCheck();
void printStudent (Student* s);
void printSubjects();

int matchesString(char str[], char strToCmpr[]);
int matchesInt(int intTarget, int intToCmpr);
int matchesStudent(Student* s, Student* s2);

#endif /* defined(__algo1__student__) */
