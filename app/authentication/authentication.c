/* **************** Documentation Section Start **************** */
/*        File Name   :  authentication.c                        */
/*        Author      :  Muhammad Wael                           */
/*        Description :  for authenticate admin and student      */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "authentication.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

bool authenticate_admin (uint32 id, uint8 *password)
{
    /* authenticate_admin function used to check if id and password is true */
    Admin *admins = NULL;
    uint16 size; /* num of admins*/
    if (!read_data_from_admins(admins, &size))
        return false;

    uint16 iter; /* to iterate through array of admins */

    for (iter = 0; iter < size; ++iter) {
        if (id == admins[iter].ID)
        {
            if (!strcmp(password, admins[iter].password)) /* compare two strings */
            {
                printf("Login Successful\n");
                free(admins); /* free allocated memory */
                return true;
            }
            else
            {
                printf("Wrong password\n");
                free(admins); /* free allocated memory */
                return false;
            }
        }
    }
    printf("Wrong ID\n");
    free(admins); /* free allocated memory */
    return false;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 22:10          Adding File Layout
 *  Muhammad Wael          10/5/2024 22:29          add authenticate admin function 
 * */
/* ****************** History Log Section End ****************** */