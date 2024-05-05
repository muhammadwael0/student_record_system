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
/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */

/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool write_data_to_admins (Admin *admins, uint16 size);

Admin read_data_from_admins ();

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 */
/* ****************** History Log Section End ****************** */