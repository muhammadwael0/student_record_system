/* **************** Documentation Section Start **************** */
/*        File Name   :  memory_management.c                     */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Implement Dynamic memory allocation     */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "memory_management.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

bool read_string (uint8 *name)
{
    /* used to read string from user and store it using dynamic allocation */
    uint8 size = 10;
    uint8 ch;
    uint8 iter = 0;

    uint8 *str = malloc(size * sizeof(char));
    if (str == NULL)
    {
        printf("Error! No More Space\n");
        return false;
    }
    printf("Enter Name: ");

    while ((ch = getchar() != '\n'))
    {
        if (iter < size - 1)
        {
            str[iter] = ch;
            iter++;
        }
        else {
            size += 5;
            str = realloc(str, size += 5);
            if (str == NULL)
            {
                printf("Error! No More Space\n");
                return false;

            }
        }
    }
    str[iter] = '\0';
    strcpy(name, str);
    free(str);
    return true;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad wael          8/5/2024 20:00           Adding read_string function
 */
/* ****************** History Log Section End ****************** */