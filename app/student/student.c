/* **************** Documentation Section Start **************** */
/*        File Name   :  student.c                               */
/*        Author      :  Mina Nabil                              */
/*        Description :  Functions for student                   */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "student.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

bool edit_name_of_student (uint32 ID)
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

bool edit_password_of_student (uint32 ID)
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

bool view_student_record_from_student (uint32 ID)
{
    /* view_student_record function takes ID if ID found return record */
    Record *records = NULL;
    uint16 size; /* number of records */

    if (!read_data_from_records(records, &size)) /* if there is error exit */
        return false;

    uint16 iter = 0; /* to iterate through array of records */

    for (iter = 0; iter < size; ++iter) {
        if (ID == records[iter].ID)
        {
            printf("ID: %ld\n", records[iter].ID);
            printf("Name: %s\n", records[iter].name);
            printf("Age: %u\n", records[iter].age);
            printf("Gender: %s\n", records[iter].gender);
            printf("Total Grade: %u\n", records[iter].total_grade);
            return true;
        }
    }
    printf("Wrong ID\n");
    return false;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Mina Nabil             11/5/2024 20:15          Adding File Layout
 *  Mina Nabil             11/5/2024 21:48          Adding editing name and password functions
 *  Mina Nabil             11/5/2024 22:21          Adding view student record function
 *  Mina Nabil             12/5/2024 03:31          Changed view_student_record_from_student function return type to bool
 * */
/* ****************** History Log Section End ****************** */