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

Student* newStudent (char* firstName, char* lastName, char* subject, int id)
{
    Student* s = (Student*) malloc(sizeof(Student));
    /* if (head == 0L) return EXIT_FAILURE; */
    s->firstName = firstName;
    s->lastName = lastName;
    s->subject = subject;
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

    // TODO don't use atoi
    return newStudent (firstName, lastName, subject, atoi(id));
}

void printStudent (Student* s)
{
    printf("\n\tStudent:\n");
    printf("\t\first name: %s\n", s->firstName);
    printf("\t\tlast name: %s\n", s->lastName);
    printf("\t\t subject: %s\n", s->subject);
    printf("\t\tMatriculation number: %d\n", s->id);
    printf("\n");
}

int matchesStudent(char* lastName, char* firstName, int student_id, char* subject)
{

    return 1;
}
