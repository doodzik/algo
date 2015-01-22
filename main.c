/** @file main.c
 *  @brief initializes values and starts cli application
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No know bugs.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "cli.h"
#include "student.h"
#include "student_list.h"

int main(int argc, const char * argv[])
{
    char str[100];
    StudentList *sl;
    initStudentList(&sl);
    int iSlLength = 0;
    int *sl_length = &iSlLength;
    while(true)
    {
        print_possible_functions();
        fgets(str, sizeof(str), stdin);
        size_t strLn = strlen(str) - 1;
        if (str[strLn] != '\n') flushStdin();
        if(cli_function(str, sl, sl_length)) break;
    }
    if(iSlLength > 0) destroyList(&sl);
    free(sl->next);
    free(sl);
    return 0;
}
