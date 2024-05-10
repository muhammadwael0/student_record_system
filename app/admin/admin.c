/* **************** Documentation Section Start **************** */
/*        File Name   :  admin.c                                 */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Functions for admin                     */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "admin.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

void view_student_record (uint32 ID)
{
    /* view_student_record function takes ID if ID found return record */
    Record *records = NULL;
    uint16 size; /* number of records */

    if (!read_data_from_records(records, &size)) /* if there is error exit */
        return;

    uint16 iter = 0; /* to iterate through array of records */

    for (iter = 0; iter < size; ++iter) {
        if (ID == records[iter].ID)
        {
            printf("ID: %ld\n", records[iter].ID);
            printf("Name: %s\n", records[iter].name);
            printf("Age: %u\n", records[iter].age);
            printf("Gender: %s\n", records[iter].gender);
            printf("Total Grade: %u\n", records[iter].total_grade);
            return;
        }
    }
    printf("Wrong ID\n");
}

bool edit_grade (uint32 ID)
{
    /* edit_grade function takes ID if ID found edit grade record */
    Record *records = NULL;
    uint16 size; /* number of records */

    if (!read_data_from_records(records, &size)) /* if there is error exit */
        return false;

    uint16 iter = 0; /* to iterate through array of records */

    for (iter = 0; iter < size; ++iter) {
        if (ID == records[iter].ID)
        {
            uint8 new_grade;
            printf("Enter New Grade: ");
            scanf("%d", &new_grade);
            edit_record(&records[iter], new_grade); /* assign new grade to records */

            /* write data to records.csv for permanent change */
            if (!write_data_to_records(records, size))
                return false;

            return true;
        }
    }
    return false;
}

bool edit_password_of_admin (uint32 ID)
{
    /* edit_admin_password function takes ID and modify admin pass */
    Admin *admins = NULL;
    uint16 size; /* number of records */

    if (!read_data_from_admins(admins, &size)) /* if there is error exit */
        return false;

    uint16 iter = 0; /* to iterate through array of admins */

    for (iter = 0; iter < size; ++iter) {
        if (ID == admins[iter].ID)
        {
            uint8 pass[20];
            if (!read_string(pass))
            {
                return false;
            }
             /* assign password to admins */
            edit_admin_password(&admins[iter], pass);

            /* write data to admins.csv for permanent change */
            if (!write_data_to_admins(admins, size))
                return false;

            return true;
        }
    }
    return false;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 00:44           Adding File Layout
 *  Muhammad Wael          10/5/2024 22:41           Adding view student record function
 *  Muhammad Wael          11/5/2024 00:11           Adding edit password and edit grade functions
 * */
/* ****************** History Log Section End ****************** */