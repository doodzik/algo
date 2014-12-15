//
//  student_list_doubly.h
//  algo1
//
//  Created by Frederik Dudzik on 15.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#ifndef __algo1__student_list_doubly__
#define __algo1__student_list_doubly__

#include <stdio.h>
#include "student.h"

typedef struct studentList StudentList;
struct studentList {
    Student* student;
    StudentList* next;
    StudentList* previous;
};

StudentList* initStudentList ();
void unshift (StudentList* sl, Student* s);
void push (StudentList* sl, Student* s);
/* Implementieren Sie eine Funktion zur Ausgabe eines Elements der Liste. */
void printStudentList  (StudentList* sl);
Student* studentFindById(StudentList* sl, int s_id);
int length (StudentList* sl);
int destroy (StudentList* sl, int stundent_id);
void destroyList (StudentList* sl);

#endif /* defined(__algo1__student_list_doubly__) */
