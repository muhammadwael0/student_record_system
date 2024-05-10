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

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 00:44           Adding File Layout
 *  Muhammad Wael          10/5/2024 22:41           Adding view student record function
 * */
/* ****************** History Log Section End ****************** */