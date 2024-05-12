/* **************** Documentation Section Start **************** */
/*        File Name   :  data_management.h                       */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Functions to edit record & admin        */
/* ***************** Documentation Section End ***************** */

#ifndef DATA_MANAGEMENT_
#define DATA_MANAGEMENT_

/* ******************* Include Section Start ******************* */
#include "../std_lib.h"
#include <string.h>
#include <stdio.h>
/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */

/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

void edit_record (Record *record, uint8 new_grade);

bool edit_admin_password (Admin *admin, char *new_password);

bool edit_student_password (Student *student, char *new_password);

bool edit_student_name (Record *record, char *new_name);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          5/5/2024 23:41           Adding File Layout
 *  Muhammad Wael          5/5/2024 23:46           Adding edit_record function
 *  Muhammad Wael          8/5/2024 22:19           Adding function to edit admin password
 *  Muhammad Wael          8/5/2024 22:31           Adding function to edit student password
 *  Muhammad Wael          8/5/2024 22:35           Adding function to edit student name
 *  Muhammad Wael          12/5/2024 1:10           include stdio.h for sscanf
 */
/* ****************** History Log Section End ****************** */