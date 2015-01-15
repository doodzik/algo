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
