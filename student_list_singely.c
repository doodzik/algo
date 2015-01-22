/** @file student_list_singely.h
 *  @brief implements linked list sinely structure
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No know bugs.
 */

#include "student_list.h"
#ifndef DOUBLE_LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "student_list_singely.h"


void initStudentList (StudentList **sl)
{
    *sl = (StudentList*) malloc(sizeof(StudentList));
    (*sl)->sentientEnd = (StudentList*) malloc(sizeof(StudentList));
    (*sl)->sentientEnd->next = 0L;
    (*sl)->next = (*sl)->sentientEnd;
    (*sl)->student = 0L;
    (*sl)->sentientEnd->student = 0L;
    
    /*
    StudentList *head = (StudentList*) malloc(sizeof(StudentList));
    StudentList *tail = (StudentList*) malloc(sizeof(StudentList));
    tail->next = 0L;
    head->next = tail;
    head->sentientEnd = tail;
    head->student = 0L;
    tail->student = 0L;
     */
}

void push (StudentList** sl, Student* s)
{
    StudentList* nNew = (StudentList*) malloc(sizeof(StudentList));
    StudentList* node = *sl;
    nNew->student = s;
    nNew->next = (*sl)->sentientEnd;
    while (node->next->next != 0L)
        node = node->next;
    node->next = nNew;
}

void unshift (StudentList** sl, Student* s)
{
  StudentList* slNew = (StudentList*) malloc(sizeof(StudentList));
  slNew->student = s;
  slNew->next = (*sl)->next;
  (*sl)->next = slNew;
}

int destroy (StudentList** sl, int stundent_id)
{
    StudentList* node = *sl;
    StudentList* lastNode = node;
    while (node->next->next != 0L)
    {
        node = node->next;
        if (node->student->id == stundent_id) {
            lastNode->next = node->next;
            free(node->student);
            free(node);
            return 1;
        }
        lastNode = node;
    }
    return 0;
}

void destroyList (StudentList** sl)
{
    StudentList* node = (*sl)->next;
    StudentList* nOld = 0L;
    while (node->next->next != NULL)
    {
        nOld = node;
        node = node->next;
        free(nOld->student);
        free(nOld);
    }
    (*sl)->next = (*sl)->sentientEnd;
}

#endif /* DOUBLE_LINKED_LIST */
