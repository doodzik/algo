// author Frederik Dudzik

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"
#include "student.h"

#define DOUBLE_LINKED_LIST 0

#if DOUBLE_LINKED_LIST == 1
#include "student_list_doubly.h"
#else
#include "student_list.h"
#endif


char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int is_function(char function[], char str[])
{
  char* str2 = concat(function, "\n");
  return (strncmp(str, str2, 100) == 0);
}

int cli_push(StudentList* sl, int* sl_length)
{
  // TODO: push to return status code
  push(sl, newStudentCli());
  ++*sl_length;
  return 0;
}

int cli_unshift(StudentList* sl, int* sl_length)
{
  // TODO: unshift to return status code
  unshift(sl, newStudentCli());
  ++*sl_length;
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
  destroyList(sl);
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
  printStudent(studentFindById(sl, cli_get_student_id()));
  return 1;
}

int cli_query(StudentList* sl)
{
  return 1;
  /*     // (i) Implementieren Sie Funktionalität zum Suchen eines oder mehrerer Studenten nach Vor- und */
  /*     // Nachname, Matrikelnummer und Studiengang. */
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
  printf("What function do you want to run?\n");
  printf("PUSH, UNSHIFT, PRINT, LENGTH, DELETE, DELETE_ALL, FIND_ID, QUERY, SORT_MATRIKEL, SORT_STUDIENGANG, QUIT\n");
}

int cli_function(char str[], StudentList* sl, int* sl_length)
{
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
