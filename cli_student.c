//
//  cli_student.c
//  algAufg
//
//  Created by Frederik Dudzik on 15.01.15.
//  Copyright (c) 2015 Frederik Dudzik. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "cli_student.h"


Student* newStudentCli (Student** s)
{
    char firstName[100];
    char lastName[100];
    char subject[100];
    char id[100];
    
    printf("Enter:\n");
    printf("First Name: \n");
    fgets(firstName, sizeof(firstName), stdin);
    size_t fLn = strlen(firstName) - 1;
    if (firstName[fLn] == '\n')
        firstName[fLn] = '\0';
    else flushStdin();
    if(firstName == 0L || firstName[0] == '\0'|| firstName[0] == '\n') return 0L;
    
    printf("Last Name: \n");
    fgets(lastName, sizeof(lastName), stdin);
    size_t lLn = strlen(lastName) - 1;
    if (lastName[lLn] == '\n')
        lastName[lLn] = '\0';
    else flushStdin();
    if(lastName == 0L || lastName[0] == '\0'|| lastName[0] == '\n') return 0L;
    
    printSubjects();
    printf("subject: \n");
    fgets(subject, sizeof(subject), stdin);
    size_t subLn = strlen(subject) - 1;
    if (subject[subLn] == '\n')
        subject[subLn] = '\0';
    else flushStdin();
    if(subject == 0L || subject[0] == '\0' || subject[0] == '\n') return 0L;
    
    printf("Martikel Number: \n");
    fgets(id, sizeof(id), stdin);
    size_t idLn = strlen(id) - 1;
    if (id[idLn] == '\n')
        id[idLn] = '\0';
    else flushStdin();
    if(id == 0L || id[0] == '\0' || id[0] == '\n') return 0L;
    
    int iId = atoi(id);
    if(iId == -1) return 0L;
    
    return newStudent (s, firstName, lastName, subject, iId);
}

Student* newStudentCliWithoutNullCheck (Student ** s)
{
    // TODO refactor with above function
    char firstName[100];
    char lastName[100];
    char subject[100];
    char id[10];
    printf("Enter:\n");
    printf("First Name: \n");
    fgets(firstName, sizeof(firstName), stdin);
    size_t fLn = strlen(firstName) - 1;
    if (firstName[fLn] == '\n')
        firstName[fLn] = '\0';
    else flushStdin();
    
    printf("Last Name: \n");
    fgets(lastName, sizeof(lastName), stdin);
    size_t lLn = strlen(lastName) - 1;
    if (lastName[lLn] == '\n')
        lastName[lLn] = '\0';
    else flushStdin();
    
    printSubjects();
    printf("subject: \n");
    fgets(subject, sizeof(subject), stdin);
    size_t subLn = strlen(subject) - 1;
    if (subject[subLn] == '\n')
        subject[subLn] = '\0';
    else flushStdin();
    
    printf("Martikel Number: \n");
    fgets(id, sizeof(id), stdin);
    size_t idLn = strlen(id) - 1;
    if (id[idLn] == '\n')
        id[idLn] = '\0';
    else flushStdin();
    
    if(id == 0L || id[0] == '\0' || id[0] == '\n') strcpy(id, "0");
    
    int iId = atoi(id);
    if(iId == -1) iId = 0;
    
    return newStudent (s, firstName, lastName, subject, iId);
}
