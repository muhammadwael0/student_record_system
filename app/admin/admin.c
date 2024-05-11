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
    uint16 size = 0; /* number of records */

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
            free(records);
            records = NULL;
            return;
        }
    }
    printf("Wrong ID\n");
    free(records);
    records = NULL;
}

bool edit_grade (uint32 ID)
{
    /* edit_grade function takes ID if ID found edit grade record */
    Record *records = NULL;
    uint16 size = 0; /* number of records */

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
            if (!write_data_to_records(records, size)) {
                free(records);
                records = NULL;
                return false;
            }
            free(records);
            records = NULL;
            return true;
        }
    }
    free(records);
    records = NULL;
    return false;
}

bool edit_password_of_admin (uint32 ID)
{
    /* edit_admin_password function takes ID and modify admin pass */
    Admin *admins = NULL;
    uint16 size = 0; /* number of records */

    if (!read_data_from_admins(admins, &size)) /* if there is error exit */
        return false;

    uint16 iter = 0; /* to iterate through array of admins */

    for (iter = 0; iter < size; ++iter) {
        if (ID == admins[iter].ID)
        {
            uint8 pass[PASSWORD_SIZE];
            if (!read_string_password(pass))
            {
                free(admins);
                admins = NULL;
                return false;
            }
             /* assign password to admins */
            edit_admin_password(&admins[iter], pass);

            /* write data to admins.csv for permanent change */
            if (!write_data_to_admins(admins, size)) {
                free (admins);
                admins = NULL;
                return false;
            }
            free (admins);
            admins = NULL;
            return true;
        }
    }
    free (admins);
    admins = NULL;
    return false;
}

void view_all_records (void)
{
    /* view_all_records function takes nothing and view all records of students */
    Record *records = NULL;
    uint16 size = 0; /* number of records */

    if (!read_data_from_records(records, &size)) /* if there is error exit */
        return;

    uint16 iter = 0; /* to iterate through array of records */

    for (iter = 0; iter < size; ++iter) {
        printf("Record %d\n", iter);
        printf("  ID: %ld\n", records[iter].ID);
        printf("  Name: %s\n", records[iter].name);
        printf("  Age: %u\n", records[iter].age);
        printf("  Gender: %s\n", records[iter].gender);
        printf("  Total Grade: %u\n", records[iter].total_grade);
    }
    free (records);
    records = NULL;
}

bool remove_student_record (uint32 ID)
{
    /* remove_student_record function takes ID if found remove record */

    Record *records = NULL;
    uint16 size_of_records = 0; /* number of records */

    if (!read_data_from_records(records, &size_of_records)) /* if there is error return false */
        return false;

    Student *students = NULL;
    uint16 size_of_students = 0; /* number of students */

    if (!read_data_from_students(students, &size_of_students)) /* if there is error return false */
    {
        free (records);
        records = NULL;
        return false;
    }

    uint16 iter; /* to iterate through array of records and students */
    uint16 iter_of_new_array; /* to iterate through new array of records and students */
    /* new records that hold the new data */
    Record *new_records = malloc((size_of_records - 1) * sizeof (Record));
    if (new_records == NULL) {
        free(records);
        free(students);
        records = NULL;
        students = NULL;
        return false;
    }
    /* new students that hold the new data */
    Student *new_students = malloc((size_of_students - 1) * sizeof (Student));

    if (new_students == NULL)
    {
        free (records);
        free (students);
        free (new_records);
        records = NULL;
        students = NULL;
        new_records = NULL;
        return false;
    }

    bool is_id_in_records = false;
    /* checks if id in records */
    for (iter = 0; iter < size_of_records; ++iter) {
        if (ID == records[iter].ID) {
            is_id_in_records = true;
        }
    }

    if (!is_id_in_records)
    {
        free (records);
        free (students);
        free(new_records);
        free(new_students);
        records = NULL;
        students = NULL;
        new_records = NULL;
        new_students = NULL;
        return false;
    }
    /* assign new data to new array */
    for (iter = 0, iter_of_new_array = 0; iter < size_of_records; ++iter) {
        if (ID != records[iter].ID) {
            new_records[iter_of_new_array] = records[iter];
            iter_of_new_array++;
        }
    }

    bool is_id_in_students = false;
    /* checks if id in students */
    for (iter = 0; iter < size_of_students; ++iter) {
        if (ID == students[iter].ID) {
            is_id_in_students = true;
        }
    }

    if (!is_id_in_students)
    {
        free (records);
        free (students);
        free (new_records);
        free (new_students);
        records = NULL;
        students = NULL;
        new_records = NULL;
        new_students = NULL;
        return false;
    }
    /* assign new data to new array */
    for (iter = 0, iter_of_new_array = 0; iter < size_of_students; ++iter) {
        if (ID != students[iter].ID) {
            new_students[iter_of_new_array] = students[iter];
            iter_of_new_array++;
        }
    }
    /* write new data to records */
    if(!write_data_to_records(new_records, size_of_records - 1))
    {
        free (records);
        free (students);
        free (new_records);
        free (new_students);
        records = NULL;
        students = NULL;
        new_records = NULL;
        new_students = NULL;
        return false;
    }
    /* write new data to students */
    if(!write_data_to_students(new_students, size_of_students - 1))
    {
        free (records);
        free (students);
        free (new_records);
        free (new_students);
        records = NULL;
        students = NULL;
        new_records = NULL;
        new_students = NULL;
        return false;
    }

    free (records);
    free (students);
    free(new_records);
    free(new_students);
    records = NULL;
    students = NULL;
    new_records = NULL;
    new_students = NULL;
    return true;
}

bool add_student_record (void)
{
    /* add_student_record function to add record to records */
    Record *records = NULL;
    uint16 size_of_records = 0; /* number of records */

    if (!read_data_from_records(records, &size_of_records)) /* if there is error return false */
        return false;

    Student *students = NULL;
    uint16 size_of_students = 0; /* number of students */

    if (!read_data_from_students(students, &size_of_students)) /* if there is error return false */
    {
        free (records);
        records = NULL;
        return false;
    }
    uint16 iter; /* to iterate through array of records and students */

    records = realloc(records, size_of_records + 1);

    if (records == NULL)
    {
        free(records);
        free(students);
        records = NULL;
        students = NULL;
        return false;
    }

    /* new students that hold the new data */
    students = realloc(students, size_of_students + 1);

    if (students == NULL)
    {
        free (records);
        free (students);
        records = NULL;
        students = NULL;
        return false;
    }

    students[size_of_students].ID = students[size_of_students - 1].ID + 1;
    strcpy(students[size_of_students].password, DEFAULT_PASSWORD);

    records[size_of_records].ID = students[size_of_students - 1].ID + 1;
    if (!read_string_name(records[size_of_records].name)) /* take a string name from user */
    {
        free (records);
        free (students);
        records = NULL;
        students = NULL;
        return false;
    }
    /* take necessary data from user */
    printf("Enter Gender (Male / Female): ");
    scanf("%s", records[size_of_records].gender);
    printf("Enter Age: ");
    scanf("%u", records[size_of_records].age);
    printf("Enter total grade: ");
    scanf("%u", records[size_of_records].total_grade);
    /* write new data to records */
    if(!write_data_to_records(records, size_of_records + 1))
    {
        free (records);
        free (students);
        records = NULL;
        students = NULL;
        return false;
    }
    /* write new data to students */
    if(!write_data_to_students(students, size_of_students + 1))
    {
        free (records);
        free (students);
        records = NULL;
        students = NULL;
        return false;
    }

    free (records);
    free (students);
    records = NULL;
    students = NULL;
    return true;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 00:44           Adding File Layout
 *  Muhammad Wael          10/5/2024 22:41           Adding view student record function
 *  Muhammad Wael          11/5/2024 00:11           Adding edit password and edit grade functions
 *  Muhammad wael          11/5/2024 23:11           Adding view all records function
 *  Muhammad Wael          12/5/2024 00:16           Adding remove record function
 *  Muhammad Wael          12/5/2024 00:49           Adding add record function
 *  Muhammad Wael          12/5/2024 01:52           modify all functions to handle free function
 */
/* ****************** History Log Section End ****************** */