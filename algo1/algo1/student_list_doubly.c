//
//  student_list_doubly.c
//  algo1
//
//  Created by Frederik Dudzik on 15.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//
/*
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "student_list_doubly.h"

StudentList* initStudentList ()
{
    StudentList* head = (StudentList*) malloc(sizeof(StudentList));
    //if (head == 0L) return EXIT_FAILURE;
    head->next = 0L;
    head->previous = 0L;
    head->student = (Student*) malloc(sizeof(Student));
    return head;
}

void unshift (StudentList* sl, Student* s)
{
    StudentList* slNew;
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
    StudentList* nNew;
    nNew->student = s;
    StudentList* node = sl->next;
    while (node->next != NULL)
        node = node->next;
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
 
 void sortMatrikel(StudentList* sl)
 {
 
 //Selection
 }
 
 void sortStudiengang(StudentList* sl)
 {
 
 //Bubble
 }
 
*/
