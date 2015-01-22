/** @file cli.h
 *  @brief cli interface for working with the student and student_list api
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No known bugs.
 */

#include "student_list.h"

/** @brief checks if provided char[] is a cli cmd
 *
 *  @param function 
 *  @param str
 *  @return status code
 */
int is_function(char function[], char str[]);

/** @brief runs push && inc sl_length
 *
 *  @param sl Head of the list(StudentList)
 *  @param s_length length of the student list
 *  @return status code
 */
int cli_push(StudentList** sl, int* sl_length);

/** @brief runs unshift && inc sl_length
 *
 *  @param sl Head of the list(StudentList)
 *  @param s_length length of the student list
 *  @return status code
 */
int cli_unshift(StudentList** sl, int* sl_length);

/** @brief runs print_students
 *
 *  @param sl Head of the list(StudentList)
 *  @return status code
 */
int cli_print_all(StudentList* sl);

/** @brief STDOUT sl_length
 *
 *  @param s_length length of the student list
 *  @return status code
 */
int cli_length(int* sl_length);

/** @brief runs delete && dec sl_length
 *
 *  @param sl Head of the list(StudentList)
 *  @param s_length length of the student list
 *  @return status code
 */
int cli_delete(StudentList** sl, int* sl_length);

/** @brief runs delete_all && sets sl_length to 0
 *
 *  @param sl Head of the list(StudentList)
 *  @param s_length length of the student list
 *  @return status code
 */
int cli_delete_all(StudentList* sl, int* sl_length);

/** @brief runs find_id
 *
 *  @param sl Head of the list(StudentList)
 *  @return status code
 */
int cli_find_id(StudentList* sl);

/** @brief runs query
 *
 *  @param sl Head of the list(StudentList)
 *  @return status code
 */
int cli_query(StudentList* sl);

/** @brief runs sort_studiengang
 *
 *  @param sl Head of the list(StudentList)
 *  @return status code
 */
int cli_sort_studiengang(StudentList* sl);

/** @brief runs sort martrikel
 *
 *  @param sl Head of the list(StudentList)
 *  @return status code
 */
int cli_sort_martikel(StudentList* sl);

/** @brief STDOUT all posible cli cmds
 *
 *  @return void
 */
void print_possible_functions();

/** @brief prompts user for student Id
 *
 *  @return student_id
 */
int cli_get_student_id();

/** @brief retrieves cli cmd
 *
 *  @param str[] STDIN of the user
 *  @param sl Head of the list(StudentList)
 *  @param s_length length of the student list
 *  @return status code
 */
int cli_function(char str[], StudentList** sl, int* sl_length);
