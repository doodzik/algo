//
//  cli_student.h
//  algAufg
//
//  Created by Frederik Dudzik on 15.01.15.
//  Copyright (c) 2015 Frederik Dudzik. All rights reserved.
//

#ifndef __algAufg__cli_student__
#define __algAufg__cli_student__

#include <stdio.h>
#include "student.h"

/** @brief create student from STDIN values
 *
 *    if an empty STDIN was made a null pointer is returned
 *
 *  @return Student*
 */
Student* newStudentCli(Student ** s);

/** @brief create student from STDIN values without checking if values are empty
 *
 *  @return Student*
 */
Student* newStudentCliWithoutNullCheck(Student ** s);


#endif /* defined(__algAufg__cli_student__) */
