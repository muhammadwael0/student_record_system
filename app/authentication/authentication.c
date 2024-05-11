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

uint16 authenticate_student_id (uint32 id)
{
    /* authenticate_student_id function used to check if id is true */
    Student *students = NULL;
    uint16 size; /* num of students*/
    if (!read_data_from_students(students, &size))
        return false;

    uint16 iter; /* to iterate through array of students */

    for (iter = 0; iter < size; ++iter)
    {
        if (id == admins[iter].ID)
        {
            return iter;
        }
    }
    //printf("Wrong ID\n");
    free(students); /* free allocated memory */
    return false;
}


bool authenticate_student_password (uint16 id_check, uint8 *password)
{
    /* authenticate_student_password function used to check if password of the id is true */
    Student *students = NULL;
    uint16 size; /* num of admins*/
    if (!read_data_from_students(students, &size))
        return false;

    if(id_check)
    {
        if (!strcmp(password, students[id_check].password)) /* compare two strings */
        {
            printf("Login Successful\n");
            free(students); /* free allocated memory */
            return true;
        }
        else
        {
            printf("Wrong password\n");
            free(students); /* free allocated memory */
            return false;
        }
    }
    /*could be removed*/
     else printf("Wrong ID\n");
    /*****************/
    free(students); /* free allocated memory */
    return false;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          10/5/2024 22:10          Adding File Layout
 *  Muhammad Wael          10/5/2024 22:29          add authenticate admin function
 *  Mina Nabil             11/5/2024 19:51          add authenticate_student_id & authenticate_student_password functions
 * */
/* ****************** History Log Section End ****************** */