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
struct studentList {
  Student* student;
  StudentList* next;
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
void swapStudents(StudentList* sl, StudentList* min, StudentList* i);
#endif /* defined(__algo1__list__) */
