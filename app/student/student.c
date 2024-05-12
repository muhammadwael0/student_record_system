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
    int16 size; /* number of records */

    if (!read_data_from_records(&records, &size)) /* if there is error exit */
        return false;

    if (size == -1)
        return false;

    uint16 iter = 0; /* to iterate through array of records */

    for (iter = 0; iter < size; ++iter) {
        if (ID == records[iter].ID)
        {
            char new_name[NAME_SIZE];
            printf("Enter New Name: ");
            if (!read_string_name (new_name))
            {
                free (records);
                records = NULL;
                return false;
            }
            edit_student_name (&records[iter], new_name); /* assign new name to records */

            /* write data to records.csv for permanent change */
            if (!write_data_to_records(records, size)) {
                free (records);
                records = NULL;
                return false;
            }
            free (records);
            records = NULL;
            return true;
        }
    }
    free (records);
    records = NULL;
    return false;
}

bool edit_password_of_student (uint32 ID)
{
    /* edit_password function takes ID if ID found edit password in students */
    Student *students = NULL;
    int16 size; /* number of students */

    if (!read_data_from_students(&students, &size)) /* if there is error exit */
        return false;

    if (size == -1)
        return false;

    uint16 iter = 0; /* to iterate through array of students */

    for (iter = 0; iter < size; ++iter) {
        if (ID == students[iter].ID)
        {
            char new_password[PASSWORD_SIZE];
            printf("Enter New password: ");
            if (!read_string_password (new_password))
            {
                free (students);
                students = NULL;
                return false;
            }
            edit_student_password (&students[iter], new_password); /* assign new password to students */

            /* write data to students.csv for permanent change */
            if (!write_data_to_students(students, size)) {
                free (students);
                students = NULL;
                return false;
            }
            free (students);
            students = NULL;
            return true;
        }
    }
    free (students);
    students = NULL;
    return false;
}

bool view_student_record_from_student (uint32 ID)
{
    /* view_student_record function takes ID if ID found return record */
    Record *records = NULL;
    int16 size; /* number of records */

    if (!read_data_from_records(&records, &size)) /* if there is error exit */
        return false;

    if (size == -1)
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
            free(records);
            records = NULL;
            return true;
        }
    }
    printf("Wrong ID\n");
    free(records);
    records = NULL;
    return false;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Mina Nabil             11/5/2024 20:15          Adding File Layout
 *  Mina Nabil             11/5/2024 21:48          Adding editing name and password functions
 *  Mina Nabil             11/5/2024 22:21          Adding view student record function
 *  Mina Nabil             12/5/2024 03:31          Changed view_student_record_from_student function return type to bool
 *  Mina Nabil             12/5/2024 16:44          Fix edit_password_of_student function
 *  Muhammad Wael          12/5/2024 23:14          Fix dynamic allocation of array of structs
 * */
/* ****************** History Log Section End ****************** */