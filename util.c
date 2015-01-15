//
//  util.c
//  algAufg
//
//  Created by Frederik Dudzik on 15.01.15.
//  Copyright (c) 2015 Frederik Dudzik. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include "util.h"


char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

bool matchesString(char* str, char* strToCmpr)
{
    if(strToCmpr == 0L) return true;
    if(strToCmpr[0] == '\0') return true;
    if(strstr(str, strToCmpr) != 0L) return true;
    return false;
}

bool matchesInt(int intTarget, int intToCmpr)
{
    if (intToCmpr == 0L) return true;
    if (intToCmpr == 0) return true;
    char str[15];
    sprintf(str, "%d", intTarget);
    char strToCmpr[15];
    sprintf(strToCmpr, "%d", intToCmpr);
    return matchesString(str, strToCmpr);
}