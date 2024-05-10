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
#include <string.h>
/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */
#define ADMINS "admins.csv"
#define STUDENTS "students.csv"
#define RECORDS "records.csv"
/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool write_data_to_admins (Admin *admins, uint16 size);

int16 get_num_lines (FILE *file);

bool read_data_from_admins (Admin *admins, uint16 size);
bool read_data_from_student_record (Record *record, Student *student);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad Wael          5/5/2024 22:35           Adding read and write admin function
 *  Mina Nabil             9/5/2024 22:17           Adding read student and record function
 *  Mina Nabil             10/5/2024 13:25          included string.h library
 */
/* ****************** History Log Section End ****************** */