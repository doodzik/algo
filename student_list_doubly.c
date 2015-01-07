//
//  student_list_doubly.c
//  algo1
//
//  Created by Frederik Dudzik on 15.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#if DOUBLE_LINKED_LIST == 1

#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "student_list_doubly.h"

StudentList* initStudentList ()
{
    StudentList* head = (StudentList*) malloc(sizeof(StudentList));
    StudentList* tail = (StudentList*) malloc(sizeof(StudentList));
    //if (head == 0L) return EXIT_FAILURE;
    head->previous = 0L;
    tail->next = 0L;
    head->next = tail;
    tail->previous = head;
    head->sentientEnd = tail;
    return head;
}

void unshift (StudentList* sl, Student* s)
{
    StudentList* slNew = (StudentList*) malloc(sizeof(StudentList));
    slNew->previous = 0L;
    slNew->student = s;
    if (sl->next != 0L){

        slNew->next = sl->next;
        slNew->next->previous = slNew;
    }
    sl->next = slNew;
}

void push (StudentList* sl, Student* s)
{
    StudentList* nNew = (StudentList*) malloc(sizeof(StudentList));
    nNew->student = s;
    StudentList* node = sl->sentientEnd->previous;
    sl->sentientEnd->previous = nNew
    nNew->previous = node;
    node->next = nNew;
}

Student* studentFindById(StudentList* sl, int s_id)
{
    StudentList* node = sl->next;
    while (node->next != NULL)
    {
        if (node->student->id == s_id)
            return node->student;
        node = node->next;
    }
    return 0L;
}

void printStudentList  (StudentList* sl)
{
    StudentList* node = sl->next;
    while (node->next != NULL)
    {
        printf("\n------\n");
        printStudent(node->student);
        node = node->next;
    }
}

int length (StudentList* sl)
{
    int i = 0;
    StudentList* node = sl->next;
    while (node->next != NULL)
    {
        i++;
        node = node->next;
    }
    return i;
}

int destroy (StudentList* sl, int stundent_id)
{
    StudentList* node = sl->next;
    StudentList* lastNode = node;
    while (node->next != NULL)
    {
        if (node->student->id == stundent_id) {
            lastNode->next = node->next;
            node->next->previous = lastNode;
            free(node->student);
            return 1;
        }
        lastNode = node;
        node = node->next;
    }
    return 0;
}

void destroyList (StudentList* sl)
{
    StudentList* node = sl->next;
    while (node->next != NULL)
    {
        StudentList* nOld = node;
        node = node->next;
        free(nOld->student);
        free(nOld);
    }
    free(node);
 }

 void swapStudents(StudentList* sl, StudentList* prev, StudentList* next)
 {
     StudentList* nextNext = next->next;
     StudentList* prevPrev = prev->previous;

     next->next = prev;
     prev->previous = next;

     next->previous = prevPrev;
     prev->next = nextNext;

     prevPrev->next = next;
     nextNext->previous = prev;
 }

void sortMatrikel(StudentList* sl)
{
    //Selection
    StudentList* j;
    StudentList* i;
    StudentList* min;

    // after each iteration shift the list List (f x:xs = xs)
    for (i = sl->next; i != 0L; i=i->next) {
        min = 0L;
        // iterate over the tail (xs)
        for (j=i->next; j != 0L; j = j->next) {
            // get the smalles element in the tail and assign it to min
            if (min==0L||i->student->id < min->student->id)
                min = j;
        }
        // swap the smallest element with the tails head
        swapStudents(min, i);
    }
}

void sortStudiengang(StudentList* sl)
{
    //Bubble
    StudentList* i;
    int swaped;
    do {
        swaped = 0;
        for (i = sl->next; i != 0L; i=i->next) {
            if (i->student->subject > i->next->student->subject) {
                swapStudents(i, i->next);
                swaped = 1;
            }
        }
    } while (swaped);
}

#endif /* DOUBLE_LINKED_LIST */
