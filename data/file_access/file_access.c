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
    FILE *file = fopen(ADMINS, "w"); /* open admins.csv in write mode */
    if (file == NULL) {
        printf("Error in open %s\n", ADMINS);
        return false;
    }
    uint16 iter; /* to iterate through Array of Admins */
    fprintf(file, "ID, Name, Password\n");
    for (iter = 0; iter < size; ++iter) {
        fprintf(file, "%d, %s, %s\n", admins[iter].ID, admins[iter].name, admins[iter].password);
    }
    fclose(file);
    return true;
}
int16 get_num_lines (FILE *file)
{
    /* get_num_lines Function used to get number of lines
     * it takes FILE and return number of lines in that file */
    if (file == NULL)
    {
        printf("Error while opening File\n");
        return -1;
    }
    int16 count = 0; /* count number of lines in .csv */
    uint8 ch;
    while (ch = fgetc(file) != EOF) /* read char by char til the EOF */
    {
        if (ch == '\n')
            count++;
    }
    return --count;
}

bool read_data_from_admins (Admin *admins, uint16 size)
{
    FILE *file = fopen(ADMINS, "r");
    if (file == NULL)
    {
        printf("Error! Can't open file %s\n", ADMINS);
        return false;
    }
    uint16 line = 0;
    uint8 iter = 0;
    uint8 ch;
    uint8 *str = calloc(NAME_SIZE, sizeof(uint8));
    while ((ch = getc(file) != EOF))
    {
        if (!line && ch == '\n')
        {
            ++line;
            continue;
        }
        else if (line)
        {
            if (ch != '\n' && ch != ',') {
                str[iter++] = ch;
            }
            else if (ch == '\n' || ch == ',')
            {

            }
        }
    }
    free(str);
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad Wael          5/5/2024 22:35           Adding read and write admin function
 *  Muhammad Wael          5/5/2024 23:26           modifying read admin.csv function "Not complete"
 * */
/* ****************** History Log Section End ****************** */