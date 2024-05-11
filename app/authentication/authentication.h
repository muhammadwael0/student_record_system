/* **************** Documentation Section Start **************** */
/*        File Name   :  authentication.h                        */
/*        Author      :  Muhammad Wael                           */
/*        Description :  for authenticate admin and student      */
/* ***************** Documentation Section End ***************** */

#ifndef AUTHENTICATION_H_
#define AUTHENTICATION_H_

/* ******************* Include Section Start ******************* */

#include "../../data/std_lib.h"
#include <string.h>
#include "../../data/file_access/file_access.h"

/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */

/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

bool authenticate_admin (uint32 id, uint8 *password);
uint16 authenticate_student_id (uint32 id);
bool authenticate_student_password (uint16 id_check, uint8 *password);

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 22:12          Adding File Layout
 *  Muhammad Wael          10/5/2024 22:29          add authenticate admin function
 *  Mina Nabil             11/5/2024 19:42          add authenticate_student_id & authenticate_student_password functions
 */
/* ****************** History Log Section End ****************** */