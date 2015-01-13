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

Student* newStudent (char firstName[], char lastName[], char subject[], int id)
{
    
    Student* s = (Student*) malloc(sizeof(Student));
    char last[100];
    if(lastName != 0L) strcpy(last, lastName);
    char first[100];
    if(lastName != 0L) strcpy(first, firstName);
    strcpy(s->firstName, first);
    strcpy(s->lastName, last);
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
    bool error = false;
    printf("Enter:\n");
    printf("First Name: \n");
    fgets(firstName, sizeof(firstName), stdin);
    if(firstName == 0L || firstName[0] == '\0'|| firstName[0] == '\n') error = true;
    printf("Last Name: \n");
    fgets(lastName, sizeof(lastName), stdin);
    if(lastName == 0L || lastName[0] == '\0'|| lastName[0] == '\n') error = true;
    printSubjects();
    printf("subject: \n");
    fgets(subject, sizeof(subject), stdin);
    if(subject == 0L || subject[0] == '\0' || subject[0] == '\n') error = true;
    printf("Martikel Number: \n");
    fgets(id, sizeof(id), stdin);
    if(id == 0L || id[0] == '\0' || id[0] == '\n') error = true;
    
    if (error) return 0L;
    return newStudent (strtok(firstName, "\n"), strtok(lastName, "\n"), strtok(subject, "\n"), atoi(strtok(id, "\n")));
}

Student* newStudentCliWithoutNullCheck ()
{
    // TODO refactor with above function
    char firstName[100];
    char lastName[100];
    char subject[100];
    char id[100];
    printf("Enter:\n");
    printf("First Name: \n");
    fgets(firstName, sizeof(firstName), stdin);
    printf("Last Name: \n");
    fgets(lastName, sizeof(lastName), stdin);
    printSubjects();
    printf("subject: \n");
    fgets(subject, sizeof(subject), stdin);
    printf("Martikel Number: \n");
    fgets(id, sizeof(id), stdin);
    
    size_t fLn = strlen(firstName) - 1;
    if (firstName[fLn] == '\n')
        firstName[fLn] = '\0';
    
    size_t lLn = strlen(lastName) - 1;
    if (lastName[lLn] == '\n')
        lastName[lLn] = '\0';
    
    size_t subLn = strlen(subject) - 1;
    if (subject[subLn] == '\n')
        subject[subLn] = '\0';
    
    size_t idLn = strlen(id) - 1;
    if (id[idLn] == '\n')
        id[idLn] = '\0';
    
    if(id == 0L || id[0] == '\0' || id[0] == '\n') strcpy(id, "0");
    
    return newStudent (firstName, lastName, subject, atoi(id));
}

void printStudent (Student* s)
{
    printf("Student:\n");
    printf("first name: %s\n", s->firstName);
    printf("last name: %s\n",  s->lastName);
    printf("subject: %s\n", SUBJECT_STRING[s->subject]);
    printf("Student Id: %d\n", s->id);
}

int matchesString(char* str, char* strToCmpr)
{
    if(strToCmpr == 0L) return true;
    if(strToCmpr[0] == '\0') return true;
    if(strstr(str, strToCmpr) != 0L) return true;
    return false;
}

int matchesInt(int intTarget, int intToCmpr)
{
  if (intToCmpr == 0L) return true;
  if (intToCmpr == 0) return true;
  char str[15];
  sprintf(str, "%d", intTarget);
  char strToCmpr[15];
  sprintf(strToCmpr, "%d", intToCmpr);
  return matchesString(str, strToCmpr);
}

int matchesStudent(Student* s, Student* s2)
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

