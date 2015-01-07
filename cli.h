// author Frederik Dudzik

#include "student_list.h"

char* concat(char *s1, char *s2);
int is_function(char function[], char str[]);
int cli_push(StudentList* sl, int* sl_length);
int cli_unshift(StudentList* sl, int* sl_length);
int cli_print_all(StudentList* sl);
int cli_length(int* sl_length);
int cli_delete(StudentList* sl, int* sl_length);
int cli_delete_all(StudentList* sl, int* sl_length);
int cli_find_id(StudentList* sl);
int cli_query(StudentList* sl);
int cli_sort_studiengang(StudentList* sl);
int cli_sort_martikel(StudentList* sl);
void print_possible_functions();
int cli_get_student_id();
int cli_function(char str[], StudentList* sl, int* sl_length);
