/** @file student_list_doubly.c
 *  @brief implementation of student_list.h for api that is between doubly and singlely linked list for doubly
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No know bugs.
 */

#include "student_list.h"

#ifdef DOUBLE_LINKED_LIST

#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "student_list_doubly.h"

void initStudentList (StudentList **sl)
{
    *sl = (StudentList*) malloc(sizeof(StudentList));
    (*sl)->sentientEnd = (StudentList*) malloc(sizeof(StudentList));

    (*sl)->next = (*sl)->sentientEnd;
    (*sl)->previous = 0L;
    (*sl)->student = 0L;

    (*sl)->sentientEnd->next = 0L;
    (*sl)->sentientEnd->previous = (*sl);
    (*sl)->sentientEnd->student = 0L;
}

void unshift (StudentList** sl, Student* s)
{
  StudentList* slNew = (StudentList*) malloc(sizeof(StudentList));
  slNew->previous = 0L;
  slNew->student = s;
  slNew->next = (*sl)->next;
  slNew->next->previous = slNew;
  (*sl)->next = slNew;
}

void push (StudentList** sl, Student* s)
{
  StudentList* nNew = (StudentList*) malloc(sizeof(StudentList));
  nNew->student = s;
  StudentList* node = (*sl)->sentientEnd->previous;
  (*sl)->sentientEnd->previous = nNew;
  nNew->previous = node;
  nNew->next     = (*sl)->sentientEnd;
  node->next     = nNew;
}


int destroy (StudentList** sl, int stundent_id)
{
  StudentList* node = (*sl)->next;
  StudentList* lastNode = node;
  while (node->next != NULL)
  {
    if (node->student->id == stundent_id) {
        lastNode->next = node->next;
        node->next->previous = lastNode;
        free(node->student);
        free(node);
        return 1;
    }
    lastNode = node;
    node = node->next;
  }
  return 0;
}

void destroyList (StudentList** sl)
{
    StudentList* node = (*sl)->next;
    while (node->next->next != NULL)
    {
        node = node->next;
        free(node->previous->student);
        free(node->previous);
    }
    free(node);
    (*sl)->next = (*sl)->sentientEnd;
    (*sl)->sentientEnd->previous = *sl;
}

#endif /* DOUBLE_LINKED_LIST */
