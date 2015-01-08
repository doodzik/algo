//
//  student.c
//  algo1
//
//  Created by Frederik Dudzik on 14.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//
#include <stdlib.h>
#include <string.h>
#include "student.h"

int subjectByName(char name[])
{
  for(int i = 0; i < sizeof(SUBJECT_STRING)/ sizeof(char); i++)
  {
    if(SUBJECT_STRING[i] == name)
      return i;
  }
  return 0;
}

Student* newStudent (char* firstName, char* lastName, char* subject, int id)
{
    Student* s = (Student*) malloc(sizeof(Student));
    /* if (head == 0L) return EXIT_FAILURE; */
    s->firstName = firstName;
    s->lastName = lastName;
    s->subject = subjectByName(subject);
    s->id = id;
    return s;
}

Student* newStudentCli ()
{
    char firstName[100];
    char lastName[100];
    char subject[100];
    char id[100];
    printf("Enter:\n");
    printf("First Name: \n");
    fgets(firstName, sizeof(firstName), stdin);
    printf("Last Name: \n");
    fgets(lastName, sizeof(lastName), stdin);
    printf("subject: \n");
    fgets(subject, sizeof(subject), stdin);
    printf("Martikel Number: \n");
    fgets(id, sizeof(id), stdin);

    return newStudent (firstName, lastName, subject, atoi(id));
}

void printStudent (Student* s)
{
    printf("\n\tStudent:\n");
    printf("\t\first name: %s\n", s->firstName);
    printf("\t\tlast name: %s\n", s->lastName);
    printf("\t\t subject: %s\n", SUBJECT_STRING[s->subject]);
    printf("\t\tMatriculation number: %d\n", s->id);
    printf("\n");
}

int matchesString(char* str, char* strToCmpr)
{
  if(strToCmpr[0] != '\0' || strstr(str, strToCmpr))
    return 0;
  else
    return 1;
}

int matchesInt(int intTarget, int intToCmpr)
{
  char str[15];
  sprintf(str, "%d", intTarget);
  char strToCmpr[15];
  sprintf(strToCmpr, "%d", intToCmpr);
  return matchesString(str, strToCmpr);
}

int matchesEnum(Subject subject, char subjectToCmpr[])
{
  if(subjectToCmpr[0] != '\0' || subjectByName(subjectToCmpr) == subject)
    return 0;
  else
    return 1;
}

int matchesStudent(Student* s, char lastName[], char firstName[], int student_id, char subject[])
{
  if(matchesString(s->lastName, lastName) && matchesString(s->firstName, firstName) && matchesInt(s->id, student_id) && matchesEnum(s->subject, subject))
    return 0;
  else
    return 1;
}
