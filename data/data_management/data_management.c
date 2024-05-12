/* **************** Documentation Section Start **************** */
/*        File Name   :  data_management.c                       */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Functions to edit record & admin        */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "data_management.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

void edit_record (Record *record, uint8 new_grade)
{
    /* edit record function */
    record->total_grade = new_grade;
}

bool edit_admin_password (Admin *admin, char *new_password)
{
    /* to edit password of admin */

    /* if pass > allow size return error so iter to keep track pass digits */
    //uint8 iter = 0;
    if (strlen(new_password) >= PASSWORD_SIZE)
        return false;
    sscanf(new_password, "%s", admin->password);
    /*while (*new_password != '\0')
    {
        admin->password[iter] = *new_password;
        new_password++;
        iter++;
    }
    admin->password[iter] = '\0';*/
    return true;
}

bool edit_student_password (Student *student, char *new_password)
{
    /* to edit password of student */

    /* if pass > allow size return error so iter to keep track pass digits */
    //uint8 iter = 0;
    if (strlen(new_password) >= PASSWORD_SIZE)
        return false;
    sscanf(new_password, "%s", student->password);
    /*while (*new_password != '\0')
    {
        student->password[iter] = *new_password;
        new_password++;
        iter++;
    }
    student->password[iter] = '\0';*/
    return true;
}

bool edit_student_name (Record *record, char *new_name)
{
    /* to edit name of student in record */

    /* if name > allow size return error so iter to keep track pass digits */
    //uint8 iter = 0;
    if (strlen(new_name) >= NAME_SIZE)
        return false;
    sscanf(new_name, "%[^\0]s", record->name);
    /*while (*new_name != '\0')
    {
        record->name[iter] = *new_name;
        new_name++;
        iter++;
    }
    record->name[iter] = '\0';*/
    return true;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          5/5/2024 23:41           Adding File Layout
 *  Muhammad Wael          5/5/2024 23:46           Adding edit_record function
 *  Muhammad Wael          8/5/2024 22:19           Adding function to edit admin password
 *  Muhammad Wael          8/5/2024 22:31           Adding function to edit student password
 *  Muhammad Wael          8/5/2024 22:35           Adding function to edit student name
 *  Mina Nabil             11/5/2024 16:55          made some adjustments to the functions to make it simpler (to be viewed)
 *  Muhammad Wael          12/5/2024 1:10           simple fix
 * */
/* ****************** History Log Section End ****************** */