/* **************** Documentation Section Start **************** */
/*        File Name   :  admin.h                                 */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Functions for admin                     */
/* ***************** Documentation Section End ***************** */

#ifndef ADMIN_H_
#define ADMIN_H_

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

void view_student_record (uint32 ID);
bool edit_grade (uint32 ID);
bool edit_password_of_admin (uint32 ID);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 00:45           Adding File Layout
 *  Muhammad Wael          10/5/2024 22:41           Adding view student record function
 *  Muhammad Wael          11/5/2024 00:11           Adding edit password and edit grade functions
 */
/* ****************** History Log Section End ****************** */