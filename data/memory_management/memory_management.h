/* **************** Documentation Section Start **************** */
/*        File Name   :  memory_management.h                     */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Implement Dynamic memory allocation     */
/* ***************** Documentation Section End ***************** */

#ifndef MEMORY_MANAGEMENT_H_
#define MEMORY_MANAGEMENT_H_

/* ******************* Include Section Start ******************* */
#include "../std_lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */

/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool read_string_name (uint8 *name);
bool read_string_password (uint8 *password);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad wael          8/5/2024 20:00           Adding read_string function
 *  Mina Nabil             11/5/2024 13:46          adding a read_string_password function
 */
/* ****************** History Log Section End ****************** */
