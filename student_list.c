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


StudentList* queryStudentList(StudentList* sl, char lastName[], char firstName[], int student_id, char subject[])
{
    StudentList* newSL = initStudentList();
    StudentList* i;
    for (i = sl->next; i != 0L; i=i->next) {
        if(matchesStudent(i->student ,lastName, firstName, student_id, subject)) {
            push(newSL, i->student);
        }
    }
    return newSL;
}

