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

struct student {
    char* firstName;
    char* lastName;
    int id;
    char* subject;
};
typedef struct student Student;

Student* newStudent (char* firstName, char* lastName, char* subject, int id);
Student* newStudentCli ();
void printStudent (Student* s);

int matchesString(char str[], char strToCmpr[]);
int matchesInt(int intTarget, int intToCmpr);
int matchesEnum(char str[], char strToCmpr[]);
int matchesStudent(Student* s, char lastName[], char firstName[], int student_id, char subject[]);

#endif /* defined(__algo1__student__) */
