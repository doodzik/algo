//
//  list.h
//  algo1
//
//  Created by Frederik Dudzik on 14.12.14.
//  Copyright (c) 2014 Frederik Dudzik. All rights reserved.
//

#ifndef __algo1__list_singely__
#define __algo1__list_singely__

#ifndef DOUBLE_LINKED_LIST

#include <stdio.h>
#include "student.h"

struct studentList {
  Student* student;
  StudentList* next;
  StudentList* sentientEnd;
};

#endif /* DOUBLE_LINKED_LIST */

#endif /* defined(__algo1__list__) */