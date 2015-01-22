/** @file student_list.h
 *  @brief defines api of the doubly/singlely linked student lists
 *
 *  This contains the prototypes for the student_list api
 *  This includes singlely or doubly list if DOUBLE_LINKED_LIST is defined or not
 *  The only difference between student_list_doubly.h and student_list_sindely.h is that
 *  student_list_doubly.h has an additional field previous in the studentList struct.
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No known bugs.
 */

#ifndef __algo1__list__
#define __algo1__list__

#include <stdio.h>
#include "student.h"

typedef struct studentList StudentList;

#ifdef DOUBLE_LINKED_LIST
#include "student_list_doubly.h"
#else
#include "student_list_singely.h"
#endif

/** @brief initializes a new StudentList
 *
 *  @return StudentList*
 */
void initStudentList (StudentList **sl);

/** @brief pushes node to the top of the list
 *
 *  @param sl the Head of the List (StudentList)
 *  @param s  the Data(Student) that has to be unshifted
 *  @return Void.
 */
void unshift (StudentList* sl, Student* s);

/** @brief pushes node to the end of the list
 *
 *  @param sl the Head of the List (StudentList)
 *  @param s  the Data(Student) that has to be pushed
 *  @return Void.
 */
void push (StudentList* sl, Student* s);

/** @brief Prints the entire Student list to STDOUT
 *
 *  @param sl Head of the list(StudentList)
 *  @return Void.
 */
void printStudentList  (StudentList* sl);

/** @brief finds student in a list by student->id
 *
 *  @param sl Head of the list(StudentList)
 *  @param s_id id of the student
 *  @return Student
 */
Student* studentFindById(StudentList* sl, int s_id);

/** @brief returns length of the list
 *
 *  @param sl Head of the list(StudentList)
 *  @return length of the list
 */
int length (StudentList* sl);

/** @brief removes an element by Id from the list
 *
 *  @param sl Head of the list(StudentList)
 *  @param s_id id of the student
 *  @return status code
 */
int destroy (StudentList* sl, int stundent_id);

/** @brief removes the whole list
 *
 *  @param sl addr to pointer to Head of the list(StudentList)
 *  @return Void.
 */
void destroyList (StudentList** sl);

/** @brief sorts the list by student_id
 *
 *   Selectionsort O(n^2) Ω(n^2)
 *
 *  @param sl Head of the list(StudentList)
 *  @return Void.
 */
void sortMatrikel(StudentList* sl);

/** @brief sorts the list by student subject
 *
 *   Bubblesort O(n^2) Ω(n^2)
 *
 *  @param sl Head of the list(StudentList)
 *  @return Void.
 */
void sortStudiengang(StudentList* sl);

/** @brief swaps two nodes in the list
 *
 *  @param prev node which is going forward
 *  @param next node which is going backward
 *  @return Void.
 */
void swapStudents(StudentList* prev, StudentList* next);

/** @brief queries the student list by student
 *
 *  @param sl Head of the list(StudentList)
 *  @param s  student to query against
 *  @return StudentList*
 */
StudentList* queryStudentList(StudentList* sl, Student* s);

#endif /* defined(__algo1__list__) */
