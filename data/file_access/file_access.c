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

bool read_data_from_records (Record *record)
{
    /* read_data_from_records Function used to read from records.csv
     * it takes array of record*/
    FILE *record_file;
    uint8 record_line_num = 0;/* for counting line number as moving in the loop */
    char *line_buffer = (char*)calloc(80, sizeof(char));/* buffer for temporary storing every line in the records.csv file (one line for every iteration) */
    record_file = fopen(RECORDS, "r");/* open records.csv in read mode */
    if (record_file == NULL)
    {
        printf("Error! Can't open file %s\n", RECORDS);
        return false;
    }
    fgets(line_buffer, 80, record_file);/* for removing the label line of records.csv before accessing the struct */
    while(fgets(line_buffer, 80, record_file) != NULL) /* the loop for assigning the read data line by line to the record struct */
    {
        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
        sscanf(strtok(line_buffer, ","), "%d", &record[record_line_num].ID);
        sscanf(strtok(NULL, ","), "%[^,]s", record[record_line_num].name);
        sscanf(strtok(NULL, ","), "%d", &record[record_line_num].age);
        sscanf(strtok(NULL, ","), "%s", record[record_line_num].gender);
        sscanf(strtok(NULL, ""), "%d", &record[record_line_num].total_grade);
        record_line_num++;
    }
    free(line_buffer);
    line_buffer = NULL;
    fclose(record_file);
    return true;
}
bool read_data_from_students (Student *student)
{
    /* read_data_from_students Function used to read from students.csv
     * it takes array of student*/
    FILE *student_file;
    uint8 student_line_num = 0;/* for counting line number as moving in the loop */
    char *line_buffer = (char*)calloc(80, sizeof(char));/* buffer for temporary storing every line in the students.csv file (one line for every iteration) */
    student_file = fopen(STUDENTS, "r");/* open students.csv in read mode */
    if (student_file == NULL)
    {
        printf("Error! Can't open file %s\n", STUDENTS);
        return false;
    }
    fgets(line_buffer, 80, student_file);/* for removing the label line of students.csv before accessing the struct */
    while(fgets(line_buffer, 80, student_file) != NULL) /* the loop for assigning the read data line by line to the student struct */
    {
        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
        sscanf(strtok(line_buffer, ","), "%d", &student[student_line_num].ID);
        sscanf(strtok(NULL, ""), "%s", student[student_line_num].password);
        student_line_num++;
    }
    free(line_buffer);
    line_buffer = NULL;
    fclose(student_file);
    return true;
}


/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad Wael          5/5/2024 22:35           Adding read and write admin function
 *  Muhammad Wael          5/5/2024 23:26           modifying read admin.csv function "Not complete"
 *  Mina Nabil             9/5/2024 22:30           Adding read student and record function
 *  Mina Nabil             10/5/2024 14:58          splitting read student and record function into two functions
 *  Mina NAbil             10/5/2024 14:10          Adding file existance check to read_data_frrom_students & read_data_from_records functions
 * */
/* ****************** History Log Section End ****************** */