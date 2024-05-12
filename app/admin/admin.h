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
#define DEFAULT_PASSWORD "1234"
/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool view_student_record (uint32 ID);
bool edit_grade (uint32 ID);
bool edit_password_of_admin (uint32 ID);
void view_all_records (void);
bool remove_student_record (uint32 ID);
bool add_student_record (void);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 00:45           Adding File Layout
 *  Muhammad Wael          10/5/2024 22:41           Adding view student record function
 *  Muhammad Wael          11/5/2024 00:11           Adding edit password and edit grade functions
 *  Muhammad wael          11/5/2024 23:11           Adding view all records function
 *  Muhammad Wael          12/5/2024 00:16           Adding remove record function
 *  Muhammad Wael          12/5/2024 00:49           Adding add record function
 *  Muhammad Wael          12/5/2024 01:54           Add DEFAULT_PASSWORD macro
 */
/* ****************** History Log Section End ****************** */