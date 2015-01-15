//
//  util.h
//  algAufg
//
//  Created by Frederik Dudzik on 15.01.15.
//  Copyright (c) 2015 Frederik Dudzik. All rights reserved.
//

#ifndef __algAufg__util__
#define __algAufg__util__

#include <stdio.h>

/**
 * define a Boolean Type
 */
typedef enum { false, true } bool;

/** @brief concatinates two strings
 *
 *  @param s1 string1
 *  @param s2 string2 is appended to string1
 *  @return concatinated string
 */
char* concat(char *s1, char *s2);

/** @brief checks if string is in another string
 *    if strToCmpr is empty then it is interpreted as true
 *  @param str
 *  @param strToCmpr
 *  @return void
 */
bool matchesString(char str[], char strToCmpr[]);

/** @brief checks if int is in another int
 *    if intToCmpr is empty then it is interpreted as true
 *  @param intTarget
 *  @param intToCmpr
 *  @return bool
 */
bool matchesInt(int intTarget, int intToCmpr);

#endif /* defined(__algAufg__util__) */
