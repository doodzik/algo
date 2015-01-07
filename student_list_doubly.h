//
//  student_list_doubly.h
//  algo1
//
//  Created by Frederik Dudzik on 15.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#ifndef __algo1__student_list_doubly__
#define __algo1__student_list_doubly__

#if DOUBLE_LINKED_LIST == 1

#include <stdio.h>
#include "student.h"

typedef struct studentList StudentList;
struct studentList {
    Student* student;
    StudentList* next;
    StudentList* previous;
    StudentList* sentientEnd;
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
void sortMatrikel(StudentList* sl);
void sortStudiengang(StudentList* sl);
void swapStudents(StudentList* sl, StudentList* prev, StudentList* next);
StudentList* queryStudentList(StudentList* sl, char* lastName, char* firstName, int student_id, char* subject);

#endif /* DOUBLE_LINKED_LIST */
#endif /* defined(__algo1__student_list_doubly__) */
