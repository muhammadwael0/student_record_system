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
#define ADMINS "../data/file_access/admins.csv"
#define STUDENTS "../data/file_access/students.csv"
#define RECORDS "../data/file_access/records.csv"
/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool write_data_to_admins (Admin *admins, uint16 size);
bool write_data_to_students (Student *students, uint16 size);
bool write_data_to_records (Record *records, uint16 size);

int16 get_num_lines (FILE *file);

bool read_data_from_admins (Admin **admin, int16 *size);
bool read_data_from_records (Record **record, int16 *size);
bool read_data_from_students (Student **student, int16 *size);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad Wael          5/5/2024 22:35           Adding read and write admin function
 *  Mina Nabil             9/5/2024 22:17           Adding read student and record function
 *  Mina Nabil             10/5/2024 13:25          included string.h library
 *  Mina Nabil             10/5/2024 14:22          Reading and modifying read_data_from_admins function
 *  Mina Nabil             10/5/2024 14:45          Adding write to records & write to students functions
 *  Mina Nabil             10/5/2024 14:53          splitting read student and record function into two functions
 *  Muhammad Wael          10/5/2024 16:36          modify write student and record functions
 *  Muhammad Wael          10/5/2024 21:06          modifying read functions and add dynamic allocation
 *  Muhammad Wael          10/5/2024 21:46          modifying read functions and add dynamic allocation
 */
/* ****************** History Log Section End ****************** */