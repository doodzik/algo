/** @file student_list_doubly.h
 *  @brief implements linked list doubly structure
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No know bugs.
 */

#ifndef __algo1__student_list_doubly__
#define __algo1__student_list_doubly__

#include "student_list.h"

#ifdef DOUBLE_LINKED_LIST

#include <stdio.h>
#include "student.h"

/**
 * @brief structure for doubly linked student list
 *
 * @todo make it generic
 */
struct studentList {
    Student* student;
    StudentList* next;
    StudentList* previous;
    StudentList* sentientEnd;
};

#endif /* DOUBLE_LINKED_LIST */
#endif /* defined(__algo1__student_list_doubly__) */
