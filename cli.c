/** @file cli.c
 *  @brief implementation of cli.h
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"
#include "util.h"
#include "student.h"
#include "cli_student.h"
#include "student_list.h"


int is_function(char function[], char str[])
{
  if(strlen(str) > 99 || strlen(function) > 99) return 1;
  char* str2 = concat(function, "\n");
  int i = (strncmp(str, str2, 100) == 0);
  free(str2);
  return i;
}

int cli_push(StudentList* sl, int* sl_length)
{
    Student* s = newStudentCli();
    // TODO get to know why lastName is empty
    if (s == 0L) {
        printf("please varify your input\n");
    }else{
        push(sl, s);
        ++*sl_length;
    }
    return 0;
}

int cli_unshift(StudentList* sl, int* sl_length)
{
    // TODO: unshift to return status code
    Student* s = newStudentCli();
    if (s == 0L) {
        printf("please varify your input\n");
    }else{
        unshift(sl, s);
        ++*sl_length;
    }
    return 0;
}

int cli_print_all(StudentList* sl)
{
  // TODO: this to return status code
  printStudentList(sl);
  return 0;
}

int cli_length(int* sl_length)
{
  printf("\nLength: %d\n", *sl_length);
  return 0;
}

int cli_delete_all(StudentList* sl, int* sl_length)
{
  destroyList(&sl);
  *sl_length = 0;
  return 0;
}

int cli_get_student_id()
{
  char stundent_id[100];
  printf("enter student id:\n");
  fgets(stundent_id, sizeof(stundent_id), stdin);
  return atoi(stundent_id);
}

int cli_delete(StudentList* sl, int* sl_length)
{
  destroy(sl, cli_get_student_id());
  --*sl_length;
  return 0;
}

int cli_find_id(StudentList* sl)
{
  Student* s = studentFindById(sl, cli_get_student_id());
  if (s == 0L)
    printf("NO SUCH STUDENT\n");
  else
    printStudent(s);
  return 0;
}

int cli_query(StudentList* sl)
{
    printf("IF YOU DONT CARE FOR AN ATTRIBUTE JUST CLICK ENTER\n");
    printf("ALL SPECIFIED VALUES CHECK IF THE STUDENT CONTAINS THE GIVEN VALUE WITHIN ITS VALUE\n\n");
    Student* s = newStudentCliWithoutNullCheck();
    queryStudentList(sl, s);
    return 0;
}

int cli_sort_studiengang(StudentList* sl)
{
  sortStudiengang(sl);
  return 0;
}

int cli_sort_martikel(StudentList* sl)
{
  sortMatrikel(sl);
  return 0;
}

void print_possible_functions()
{
    printf("\n");
    printf("What function do you want to run?\n");
    printf("PUSH, UNSHIFT, PRINT_ALL, LENGTH, DELETE, DELETE_ALL, FIND_ID, QUERY, SORT_MARTRIKEL, SORT_STUDIENGANG, QUIT\n");
    printf("\n");
}

int cli_function(char str[], StudentList* sl, int* sl_length)
{
    printf("\n");
    if(is_function("PUSH", str)) return cli_push(sl, sl_length);
    if(is_function("UNSHIFT", str)) return cli_unshift(sl, sl_length);
    if(is_function("PRINT_ALL", str)) return cli_print_all(sl);
    if(is_function("LENGTH", str)) return cli_length(sl_length);
    if(is_function("DELETE", str)) return cli_delete(sl, sl_length);
    if(is_function("DELETE_ALL", str)) return cli_delete_all(sl, sl_length);
    if(is_function("FIND_ID", str)) return cli_find_id(sl);
    if(is_function("QUERY", str)) return cli_query(sl);
    if(is_function("SORT_STUDIENGANG", str)) return cli_sort_studiengang(sl);
    if(is_function("SORT_MARTRIKEL", str)) return cli_sort_martikel(sl);
    if(is_function("QUIT", str)) return 1;

    printf("No such Function\n");
    return 0;
}
