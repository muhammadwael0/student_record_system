/* **************** Documentation Section Start **************** */
/*        File Name   :  student.c                               */
/*        Author      :  Mina Nabil                              */
/*        Description :  Functions for student                   */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "student.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

bool edit_name (uint32 ID)
{
    /* edit_name function takes ID if ID found edit name in record */
    Record *records = NULL;
    uint16 size; /* number of records */

    if (!read_data_from_records(records, &size)) /* if there is error exit */
        return false;

    uint16 iter = 0; /* to iterate through array of records */

    for (iter = 0; iter < size; ++iter) {
        if (ID == records[iter].ID)
        {
            uint8 new_name[NAME_SIZE];
            printf("Enter New Name: ");
            if (!read_string_name (new_name))
            {
                return false;
            }
            edit_student_name (&records[iter], new_name); /* assign new name to records */

            /* write data to records.csv for permanent change */
            if (!write_data_to_records(records, size))
                return false;

            return true;
        }
    }
    return false;
}

bool edit_password (uint32 ID)
{
    /* edit_password function takes ID if ID found edit password in record */
    Record *records = NULL;
    uint16 size; /* number of records */

    if (!read_data_from_records(records, &size)) /* if there is error exit */
        return false;

    uint16 iter = 0; /* to iterate through array of records */

    for (iter = 0; iter < size; ++iter) {
        if (ID == records[iter].ID)
        {
            uint8 new_password[PASSWORD_SIZE];
            printf("Enter New password: ");
            if (!read_string_password (new_password))
            {
                return false;
            }
            edit_student_password (&records[iter], new_password); /* assign new password to records */

            /* write data to records.csv for permanent change */
            if (!write_data_to_records(records, size))
                return false;

            return true;
        }
    }
    return false;
}



/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Mina Nabil             11/5/2024 20:15          Adding File Layout
 *  Mina Nabil             11/5/2024 21:48          Adding editing name and password functions
 * */
/* ****************** History Log Section End ****************** */