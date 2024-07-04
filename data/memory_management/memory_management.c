/* **************** Documentation Section Start **************** */
/*        File Name   :  memory_management.c                     */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Implement Dynamic memory allocation     */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "memory_management.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

bool read_string_name (char *name)
{
    /* used to read string from user and store it using dynamic allocation */

    char *str = NULL;

    int c, i = 0;
    int allocated_size = 10; /* Initial allocation size */

    str = (char *) malloc(sizeof (char) * allocated_size);

    if (str == NULL) {
        printf("Error! No space\n");
        return false;
    }

    printf("Enter Name: ");
    fflush(stdin);
    c = getchar();
    /* Read characters until newline or EOF */
    while (c != '\n' && c != EOF) {
        /* Reallocate memory if needed (initial allocation or buffer full) */
        if (i < allocated_size - 1) {
            str[i++] = c;
        }
        else
        {
            allocated_size *= 2; /* Double the allocated size */
            str = (char *)realloc(str, allocated_size * sizeof(char));
            if (str == NULL) {
                printf("Memory allocation failed!\n");
                return false;
            }
            str[i++] = c;
        }
        c = getchar();
    }
    str[i] = '\0';

    if (i < NAME_SIZE)
        strcpy(name, str);
    else
    {
        *name = '\0';
        printf("Max allow = %d", NAME_SIZE);
    }
    /* Free the allocated memory */
    free(str);
    str = NULL;
    return true;
}

bool read_string_password (char *password) {
    /* used to read password string from user and store it using dynamic allocation */
    char *str = NULL;

    int c, i = 0;
    int allocated_size = 10; /* Initial allocation size */

    str = (char *) malloc(sizeof (char) * allocated_size);

    if (str == NULL) {
        printf("Error! No space\n");
        return false;
    }

    printf("Enter Password: ");
    fflush(stdin);
    c = getchar();
    /* Read characters until newline or EOF */
    while (c != '\n' && c != EOF) {
        /* Reallocate memory if needed (initial allocation or buffer full) */
        if (i < allocated_size - 1) {
            str[i++] = c;
        }
        else
        {
            allocated_size *= 2; /* Double the allocated size */
            str = (char *)realloc(str, allocated_size * sizeof(char));
            if (str == NULL) {
                printf("Memory allocation failed!\n");
                return false;
            }
            str[i++] = c;
        }
        c = getchar();
    }
    str[i] = '\0';

    if (i < PASSWORD_SIZE)
        strcpy(password, str);
    else
    {
        *password = '\0';
        printf("Max allow = %d", PASSWORD_SIZE);
    }
    /* Free the allocated memory */
    free(str);
    str = NULL;
    return true;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad wael          8/5/2024 20:00           Adding read_string function
 *  Mina Nabil             11/5/2024 13:46          small fix & adding a read_string_password function
 *  Muhammad Wael          13/5/2024 01:14          edit two function to handle segmentation fault
 */
/* ****************** History Log Section End ****************** */