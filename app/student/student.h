/* **************** Documentation Section Start **************** */
/*        File Name   :  student.h                               */
/*        Author      :  Mina Nabil                              */
/*        Description :  Functions for student                   */
/* ***************** Documentation Section End ***************** */

#ifndef STUDENT_H_
#define STUDENT_H_

/* ******************* Include Section Start ******************* */

#include "../../data/std_lib.h"
#include "../../data/file_access/file_access.h"
#include "../../data/memory_management/memory_management.h"
#include "../../data/data_management/data_management.h"

/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */

/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool edit_name_of_student (uint32 ID);
bool edit_password_of_student (uint32 ID);
bool view_student_record_from_student (uint32 ID);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Mina Nabil             11/5/2024 20:10          Adding File Layout
 *  Mina Nabil             11/5/2024 21:48          Adding editing name and password functions
 */
/* ****************** History Log Section End ****************** */