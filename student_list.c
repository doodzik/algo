/** @file student_list.c
 *  @brief implementation of student_list.h for api that is shared between doubly and singlely linked list
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No know bugs.
 */

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
  StudentList* node;
  for(node = sl->next; node->next!=0L; node = node->next){
      printf("------\n");
      printStudent(node->student);
  }
  printf("------\n");
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

StudentList* queryStudentList(StudentList* sl, Student* s)
{
    StudentList* node = sl->next;
    while (node->next != NULL)
    {
        if(matchesStudent(node->student ,s)) {
            printf("------\n");
            printStudent(node->student);
        }
        node = node->next;
    }
    printf("------\n");
    return 0L;
}

void swapStudents(StudentList* prev, StudentList* next)
{
    Student* tmp = prev->student;
    prev->student = next->student;
    next->student = tmp;
}

void sortMatrikel(StudentList* sl)
{
    //Selection
    StudentList* j   = 0L;
    StudentList* min = 0L;
    StudentList* i   = sl;

    // after each iteration shift the list List (f x:xs = xs)
    while(i->next->next != 0L) {
        i   =i->next;
        min = i;
        j   = i;
        // iterate over the tail (xs)
        while (j->student != 0L){
            // get the smalles element in the tail and assign it to min
            if (j->student->id < min->student->id) min = j;
            j = j->next;
        }
        // swap the smallest element with the tails head
        if(min != i) swapStudents(min, i);
    }
}

void sortStudiengang(StudentList* sl)
{
    //Bubble
    StudentList* i = sl;
    int swaped = false;
    // iterate until nothing was swaped in one run
    do {
        swaped = false;
        // move window one field to the right
        while (i->next->next->student != 0L) {
            i=i->next;
            // if two fields in window are (right > left) swap
            if (i->student->subject > i->next->student->subject) {
                swapStudents(i, i->next);
                swaped = true;
            }
        }
        i = sl;
    } while (swaped);
}
