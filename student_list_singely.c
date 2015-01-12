//
//  list.c
//  algo1
//
//  Created by Frederik Dudzik on 14.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//
#include "student_list.h"
#ifndef DOUBLE_LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "student_list_singely.h"
typedef enum { false, true } bool;


StudentList* initStudentList ()
{
    StudentList* head = (StudentList*) malloc(sizeof(StudentList));
    StudentList* tail = (StudentList*) malloc(sizeof(StudentList));
    //if (head == 0L) return EXIT_FAILURE;
    tail->next = 0L;
    head->next = tail;
    head->sentientEnd = tail;
    return head;
}

void push (StudentList* sl, Student* s)
{
    StudentList* nNew = (StudentList*) malloc(sizeof(StudentList));
    StudentList* node = sl;
    nNew->student = s;
    nNew->next = sl->sentientEnd;
    while (node->next->next != 0L ) {
        node = node->next;
    }
    node->next = nNew;
}

void unshift (StudentList* sl, Student* s)
{
  StudentList* slNew = (StudentList*) malloc(sizeof(StudentList));
  slNew->student = s;
  slNew->next = sl->next;
  sl->next = slNew;
}

int destroy (StudentList* sl, int stundent_id)
{
    StudentList* node = sl;
    StudentList* lastNode = node;
    while (node->next->next != 0L)
    {
        node = node->next;
        if (node->student->id == stundent_id) {
            lastNode->next = node->next;
            free(node->student);
            return 0;
        }
        lastNode = node;
    }
    return 0;
}

void swapStudents(StudentList* sl, StudentList* prev, StudentList* next)
{
    Student* tmp = prev->student;
    prev->student = next->student;
    next->student = tmp;

}

// TODO remove prevPrev && next
// TODO merge into student_list
void swapStudentsWithPrev(StudentList* prevPrev, StudentList* prev, StudentList* next)
{
    Student* tmp = prev->student;
    prev->student = prev->next->student;
    prev->next->student = tmp;
}


void sortMatrikel(StudentList* sl)
{
    //Selection
    StudentList* j;
    StudentList* i = sl;
    StudentList* min;

    // after each iteration shift the list List (f x:xs = xs)
    while(i->next->next != 0L) {
        i=i->next;
        min = i;
        j = i;
        // iterate over the tail (xs)
        while (j->student != 0L){
            // get the smalles element in the tail and assign it to min
            if (j->student->id < min->student->id) min = j;
            j = j->next;
        }
        // swap the smallest element with the tails head
        if(min != i) swapStudents(sl, min, i);
    }
}

void sortStudiengang(StudentList* sl)
{
    //Bubble
    StudentList* i = sl;
    StudentList* prev;
    int swaped;
    // iterate until nothing was swaped in one run
    do {
        swaped = false;
        // move window one field to the right
        while (i->next->next != 0L) {
            prev = i;
            i=i->next;
            // if two fields in window are (right > left) swap them
            if (i->next->student == 0L) break;
            if (i->student->subject > i->next->student->subject) {
                swapStudentsWithPrev(prev, i, i->next);
                swaped = true;
            }
        }
    } while (swaped);
}

#endif /* DOUBLE_LINKED_LIST */
