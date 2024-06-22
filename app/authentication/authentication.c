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
    int16 size; /* num of admins*/
    if (!read_data_from_admins(&admins, &size))
        return false;

    if (size == -1)
        return false;

    uint16 iter; /* to iterate through array of admins */

    for (iter = 0; iter < size; ++iter) {
        if (id == admins[iter].ID)
        {
            if (!strcmp(password, admins[iter].password)) /* compare two strings */
            {
                printf("Login Successful\n");
                printf("Hello, Mr/Mss %s\n", admins[iter].name);
                free(admins); /* free allocated memory */
                admins = NULL;
                return true;
            }
            else
            {
                printf("Wrong password\n");
                free(admins); /* free allocated memory */
                admins = NULL;
                return false;
            }
        }
    }
    printf("Wrong ID\n");
    free(admins); /* free allocated memory */
    admins = NULL;
    return false;
}

int16 authenticate_student_id (uint32 id)
{
    /* authenticate_student_id function used to check if id is true */
    Student *students = NULL;
    int16 size; /* num of students*/

    if (!read_data_from_students(&students, &size))
        return false;

    if (size == -1)
        return false;

    uint16 iter; /* to iterate through array of students */

    for (iter = 0; iter < size; ++iter)
    {
        if (id == students[iter].ID)
        {
            free(students);
            students = NULL;
            return iter;
        }
    }
    free(students); /* free allocated memory */
    students = NULL;
    return -1;
}


bool authenticate_student_password (int16 id_check, uint8 *password)
{
    /* authenticate_student_password function used to check if password of the id is true */
    Student *students = NULL;
    int16 size; /* num of admins*/
    if (!read_data_from_students(&students, &size))
        return false;

    if (size == -1)
        return false;

    if(id_check >= 0)
    {
        if (!strcmp(password, students[id_check].password)) /* compare two strings */
        {
            printf("Login Successful\n");
            free(students); /* free allocated memory */
            students = NULL;
            return true;
        }
        else
        {
            printf("Wrong password\n");
            free(students); /* free allocated memory */
            students = NULL;
            return false;
        }
    }
    /*could be removed*/
    else
        printf("Wrong ID\n");
    /*****************/
    free(students); /* free allocated memory */
    students = NULL;
    return false;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 22:10          Adding File Layout
 *  Muhammad Wael          10/5/2024 22:29          add authenticate admin function
 *  Mina Nabil             11/5/2024 19:51          add authenticate_student_id & authenticate_student_password functions
 *  Muhammad Wael          12/5/2024 1:26           small fix
 *  Mina Nabil             13/5/2024 03:35          adjustment to the authenticate_student_password function id_check data type & authenticate_student_id return type
 * */
/* ****************** History Log Section End ****************** */