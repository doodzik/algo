//
//  main.c
//
// Author Frederik Dudzik

#include <stdlib.h>
#include <stdio.h>
#include "cli.h"
#include "student.h"

#define DOUBLE_LINKED_LIST 0

#if DOUBLE_LINKED_LIST == 1
#include "student_list_doubly.h"
#else
#include "student_list.h"
#endif

int main(int argc, const char * argv[])
{
  char str[100];
  StudentList* sl = initStudentList();
  int iSlLength = 0;
  int* sl_length = &iSlLength;
  /* char* stundent_id = 0L; */
  while(1)
  {
    print_possible_functions();
    fgets(str, sizeof(str), stdin);
    if(cli_function(str, sl, sl_length)) break;
  }
  return 0;
}
