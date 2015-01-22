/** @file student.c
 *  @brief implements student.h
 *
 *  @author Frederik Dudzik (doodzik)
 *  @bug No know bugs.
 */

#include <stdlib.h>
#include <string.h>
#include "student.h"

Student* newStudent (Student ** s, char firstName[], char lastName[], char subject[], int id)
{
    
    *s = (Student*) malloc(sizeof(Student));
    char last[100];
    if(lastName != 0L) strcpy(last, lastName);
    char first[100];
    if(lastName != 0L) strcpy(first, firstName);
    strcpy((*s)->firstName, first);
    strcpy((*s)->lastName, last);
    (*s)->subject = subjectByName(subject);
    (*s)->id = id;
    return *s;
}

void printStudent (Student* s)
{
    printf("Student:\n");
    printf("first name: %s\n", s->firstName);
    printf("last name: %s\n",  s->lastName);
    printf("subject: %s\n", SUBJECT_STRING[s->subject]);
    printf("Student Id: %d\n", s->id);
}

bool matchesStudent(Student* s, Student* s2)
{
    if(matchesString(s->lastName, s2->lastName)
       && matchesString(s->firstName, s2->firstName)
       && matchesInt(s->id, s2->id)
       && (s2->subject == 0L || s2->subject == 0 || s->subject == s2->subject))
        return true;
    else
        return false;
}

int subjectByName(char name[])
{
  if(name == 0L) return 0;
  for(int i = 0; i < SUBJECT_COUNT; i++)
      if(strcmp(SUBJECT_STRING[i], name) == 0) return i;
  return 0;
}

void printSubjects()
{
    printf("possible subjects: ");
    for(int i = 0; i < SUBJECT_COUNT; i++) printf("%s ", SUBJECT_STRING[i]);
    printf("\n");
}

