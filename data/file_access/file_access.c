/* **************** Documentation Section Start **************** */
/*        File Name   :  file_access.c                           */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Functions to read and write data        */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "file_access.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */
bool write_data_to_admins (Admin *admins, uint16 size)
{
    /* write_data_to_admins Function used to write to admins.csv
     * it takes array of admins and size of array */
    FILE *file = fopen("admins.csv", "w"); /* open admins.csv in write mode */
    if (file == NULL)
        return false;
    int iter; /* to iterate through Array of Admins */
    fprintf(file, "ID, Name, Password\n");
    for (iter = 0; iter < size; ++iter) {
        fprintf(file, "%d, %s, %s", admins[iter].ID, admins[iter].name, admins[iter].password);
        if (iter != size - 1)
            fprintf(file, "\n");
    }
    return true;
}
/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 * */
/* ****************** History Log Section End ****************** */