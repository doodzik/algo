//
//  student_list_doubly.h
//  algo1
//
//  Created by Frederik Dudzik on 15.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#ifndef __algo1__student_list_doubly__
#define __algo1__student_list_doubly__

#ifdef DOUBLE_LINKED_LIST

#include <stdio.h>
#include "student.h"

struct studentList {
    Student* student;
    StudentList* next;
    StudentList* previous;
    StudentList* sentientEnd;
};

#endif /* DOUBLE_LINKED_LIST */
#endif /* defined(__algo1__student_list_doubly__) */
