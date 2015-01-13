//
//  list.h
//  algo1
//
//  Created by Frederik Dudzik on 14.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#ifndef __algo1__list__
#define __algo1__list__

#include <stdio.h>
#include "student.h"

typedef struct studentList StudentList;

#ifdef DOUBLE_LINKED_LIST
#include "student_list_doubly.h"
#else
#include "student_list_singely.h"
#endif


StudentList* initStudentList ();
void unshift (StudentList* sl, Student* s);
void push (StudentList* sl, Student* s);
/* Implementieren Sie eine Funktion zur Ausgabe eines Elements der Liste. */
void printStudentList  (StudentList* sl);
Student* studentFindById(StudentList* sl, int s_id);
int length (StudentList* sl);
int destroy (StudentList* sl, int stundent_id);
void destroyList (StudentList** sl);
void sortMatrikel(StudentList* sl);
void sortStudiengang(StudentList* sl);
void swapStudents(StudentList* sl, StudentList* prev, StudentList* next);
StudentList* queryStudentList(StudentList* sl, Student* s);

#endif /* defined(__algo1__list__) */
