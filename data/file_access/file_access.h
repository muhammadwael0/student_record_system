/* **************** Documentation Section Start **************** */
/*        File Name   :  file_access.h                           */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Functions to read and write data        */
/* ***************** Documentation Section End ***************** */

#ifndef FILE_ACCESS_H_
#define FILE_ACCESS_H_

/* ******************* Include Section Start ******************* */
#include "../std_lib.h"
#include <stdio.h>
#include <stdlib.h>
/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */
#define ADMINS "admins.csv"
#define STUDENTS "students.csv"
#define RECORDS "records.csv"
#define STRING_SIZE 20
/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool write_data_to_admins (Admin *admins, uint16 size);

int16 get_num_lines (FILE *file);

bool read_data_from_admins (Admin *admins, uint16 size);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad Wael          5/5/2024 22:35           Adding read and write admin function
 */
/* ****************** History Log Section End ****************** */