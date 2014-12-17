//
//  list.c
//  algo1
//
//  Created by Frederik Dudzik on 14.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "student_list.h"


StudentList* initStudentList ()
{
    StudentList* head = (StudentList*) malloc(sizeof(StudentList));
    //if (head == 0L) return EXIT_FAILURE;
    head->next = 0L;
    head->student = (Student*) malloc(sizeof(Student));
    return head;
}

void unshift (StudentList* sl, Student* s)
{
  StudentList* slNew;
  slNew->student = s;
  if (sl->next != 0L)
    slNew->next = sl->next;
  sl->next = slNew;
}

void push (StudentList* sl, Student* s)
{
  StudentList* nNew;
  nNew->student = s;
  StudentList* node = sl->next;
  while (node->next != NULL)
    node = node->next;
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

//TODO swap students
void swapStudents(StudentList* sl, StudentList* min, StudentList* i)
{

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
        swapStudents(sl, min, i);
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
                swapStudents(sl, i, i->next);
                swaped = 1;
            }
        }
    } while (swaped);
}


