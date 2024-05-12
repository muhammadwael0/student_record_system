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
    fprintf(file, "ID,Name,Password\n");
    for (iter = 0; iter < size; ++iter) {
        fprintf(file, "%ld,%s,%s\n", admins[iter].ID, admins[iter].name, admins[iter].password);
    }
    fclose(file);
    file = NULL;
    return true;
}

bool write_data_to_students (Student *students, uint16 size)
{
    /* write_data_to_students Function used to write to students.csv
     * it takes array of students and size of array */
    FILE *file = fopen(STUDENTS, "w"); /* open students.csv in write mode */
    if (file == NULL) {
        printf("Error in open %s\n", STUDENTS);
        return false;
    }
    uint16 iter; /* to iterate through Array of Students */
    fprintf(file, "ID,Password\n");
    for (iter = 0; iter < size; ++iter) {
        fprintf(file, "%lu,%s\n", students[iter].ID, students[iter].password);
    }
    fclose(file);
    file = NULL;
    return true;
}

bool write_data_to_records (Record *records, uint16 size)
{
    /* write_data_to_records Function used to write to records.csv
     * it takes array of records and size of array */
    FILE *file = fopen(RECORDS, "w"); /* open records.csv in write mode */
    if (file == NULL) {
        printf("Error in open %s\n", RECORDS);
        return false;
    }
    uint16 iter; /* to iterate through Array of records */
    fprintf(file, "ID,Name,Age,Gender,Total Grade\n");
    for (iter = 0; iter < size; ++iter) {
        fprintf(file, "%lu,%s,%u,%s,%u\n", records[iter].ID, records[iter].name,
                records[iter].age, records[iter].gender, records[iter].total_grade);
    }
    fclose(file);
    file = NULL;
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
    int ch = getc(file);
    while (ch != EOF) /* read char by char til the EOF */
    {
        if (ch == '\n')
            count++;
        ch = getc(file);
    }

    rewind(file); /*to return to first line of the file ofter finishing*/
    return --count;
}

//bool read_data_from_admins (Admin *admin)
//{
//    /* read_data_from_admins Function used to read from admins.csv
//     * it takes array of admin*/
//    FILE *admin_file = fopen(ADMINS, "r");
//    if (admin_file == NULL)
//    {
//        printf("Error! Can't open file %s\n", ADMINS);
//        return false;
//    }
//    uint8 admin_line_num = 0;/* for counting line number as moving in the loop */
//    char *line_buffer = (char*)calloc(80, sizeof(char));/* buffer for temporary storing every line in the admins.csv file (one line for every iteration) */
//    admin_file = fopen(ADMINS, "r");/* open admins.csv in read mode */
//    fgets(line_buffer, 80, admin_file);/* for removing the label line of admins.csv before accessing the struct */
//    while(fgets(line_buffer, 80, admin_file) != NULL) /* the loop for assigning the read data line by line to the admin struct */
//    {
//        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
//        sscanf(strtok(line_buffer, ","), "%d", &admin[admin_line_num].ID);
//        sscanf(strtok(NULL, ","), "%s", admin[admin_line_num].name);
//        sscanf(strtok(NULL, ""), "%s", admin[admin_line_num].password);
//        admin_line_num++;
//    }
//    free(line_buffer);
//    line_buffer = NULL;
//    fclose(admin_file);
//    return true;
//}

bool read_data_from_admins (Admin **admin, int16 *size)
{
    /* read_data_from_admins Function used to read from admins.csv
     * it takes pointer to admin to allocate data to it and pointer to size */
    FILE *file = fopen(ADMINS, "r");
    if (file == NULL)
    {
        printf("Error! Can't open file %s\n", ADMINS);
        return false;
    }

    /* get number of lines in file */
    *size = get_num_lines(file);

    if (*size == -1)
        return false;

    /* dynamic allocate array of admins */
    *admin = malloc(*size * sizeof (Admin));

    if (*admin == NULL)
    {
        printf("Error! Can't Allocate space for admin structure\n");
        fclose(file);
        file = NULL;
        return false;
    }

    uint16 iter = 0; /* iterate through lines */

    /* buffer for temporary storing every line in the admins.csv file (one line for every iteration) */
    char *line_buffer = (char*)calloc(80, sizeof(char));

    if (line_buffer == NULL)
    {
        printf("Error! Can't Allocate space\n");
        fclose(file);
        file = NULL;
        return false;
    }

    /* for removing the label line of admins.csv before accessing the struct */
    fgets(line_buffer, 80, file);

    while(fgets(line_buffer, 80, file) != NULL) /* the loop for assigning the read data line by line to the admin struct */
    {
        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
        sscanf(strtok(line_buffer, ","), "%ld", &(*admin)[iter].ID);
        sscanf(strtok(NULL, ","), "%s", (*admin)[iter].name);
        sscanf(strtok(NULL, ""), "%s", (*admin)[iter].password);
        iter++;
    }

    free(line_buffer);
    line_buffer = NULL;
    fclose(file);
    file = NULL;
    return true;
}

//bool read_data_from_records (Record *record)
//{
//    /* read_data_from_records Function used to read from records.csv
//     * it takes array of record*/
//    FILE *record_file;
//    uint8 record_line_num = 0;/* for counting line number as moving in the loop */
//    char *line_buffer = (char*)calloc(80, sizeof(char));/* buffer for temporary storing every line in the records.csv file (one line for every iteration) */
//    record_file = fopen(RECORDS, "r");/* open records.csv in read mode */
//    if (record_file == NULL)
//    {
//        printf("Error! Can't open file %s\n", RECORDS);
//        return false;
//    }
//    fgets(line_buffer, 80, record_file);/* for removing the label line of records.csv before accessing the struct */
//    while(fgets(line_buffer, 80, record_file) != NULL) /* the loop for assigning the read data line by line to the record struct */
//    {
//        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
//        sscanf(strtok(line_buffer, ","), "%ld", &record[record_line_num].ID);
//        sscanf(strtok(NULL, ","), "%[^,]s", record[record_line_num].name);
//        sscanf(strtok(NULL, ","), "%d", &record[record_line_num].age);
//        sscanf(strtok(NULL, ","), "%s", record[record_line_num].gender);
//        sscanf(strtok(NULL, ""), "%d", &record[record_line_num].total_grade);
//        record_line_num++;
//    }
//    free(line_buffer);
//    line_buffer = NULL;
//    fclose(record_file);
//    return true;
//}

//bool read_data_from_students (Student *student)
//{
//    /* read_data_from_students Function used to read from students.csv
//     * it takes array of student*/
//    FILE *student_file;
//    uint8 student_line_num = 0;/* for counting line number as moving in the loop */
//    char *line_buffer = (char*)calloc(80, sizeof(char));/* buffer for temporary storing every line in the students.csv file (one line for every iteration) */
//    student_file = fopen(STUDENTS, "r");/* open students.csv in read mode */
//    if (student_file == NULL)
//    {
//        printf("Error! Can't open file %s\n", STUDENTS);
//        return false;
//    }
//    fgets(line_buffer, 80, student_file);/* for removing the label line of students.csv before accessing the struct */
//    while(fgets(line_buffer, 80, student_file) != NULL) /* the loop for assigning the read data line by line to the student struct */
//    {
//        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
//        sscanf(strtok(line_buffer, ","), "%ld", &student[student_line_num].ID);
//        sscanf(strtok(NULL, ""), "%s", student[student_line_num].password);
//        student_line_num++;
//    }
//    free(line_buffer);
//    line_buffer = NULL;
//    fclose(student_file);
//    return true;
//}

bool read_data_from_records (Record *record, uint16 *size)
{
    /* read_data_from_records Function used to read from records.csv
     * it takes pointer to record to point data to it and pointer to point to size */
    FILE *file = fopen(RECORDS, "r");
    if (file == NULL)
    {
        printf("Error! Can't open file %s\n", RECORDS);
        return false;
    }

    /* get number of lines in file */
    *size = get_num_lines(file);

    /* dynamic allocate array of records */
    record = malloc(*size * sizeof (Record));

    if (record == NULL)
    {
        printf("Error! Can't Allocate Space for records\n");
        fclose(file);
        file = NULL;
        return false;
    }

    uint16 iter = 0; /* iterate through lines */

    /* buffer for temporary storing every line in the records.csv file (one line for every iteration) */
    uint8 *line_buffer = (uint8*)calloc(80, sizeof(uint8));

    if (line_buffer == NULL)
    {
        printf("Error! Can't Allocate Space\n");
        fclose(file);
        file = NULL;
        return false;
    }

    /* for removing the label line of records.csv before accessing the struct */
    fgets(line_buffer, 80, file);

    while(fgets(line_buffer, 80, file) != NULL) /* the loop for assigning the read data line by line to the record struct */
    {
        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
        sscanf(strtok(line_buffer, ","), "%ld", &record[iter].ID);
        sscanf(strtok(NULL, ","), "%[^,]s", record[iter].name);
        sscanf(strtok(NULL, ","), "%u", &record[iter].age);
        sscanf(strtok(NULL, ","), "%s", record[iter].gender);
        sscanf(strtok(NULL, ""), "%u", &record[iter].total_grade);
        iter++;
    }
    free(line_buffer);
    line_buffer = NULL;
    fclose(file);
    file = NULL;
    return true;
}

bool read_data_from_students (Student *student, uint16 *size)
{
    /* read_data_from_students Function used to read from students.csv
     * it takes pointer to student to point data to it and pointer to point to size */
    FILE *file = fopen(STUDENTS, "r");
    if (file == NULL)
    {
        printf("Error! Can't open file %s\n", STUDENTS);
        return false;
    }

    /* get number of lines in file */
    *size = get_num_lines(file);

    /* dynamic allocate array of students */
    student = malloc(*size * sizeof (Student));

    if (student == NULL)
    {
        printf("Error! Can't Allocate space for student\n");
        fclose(file);
        file = NULL;
        return false;
    }

    uint16 iter = 0; /* iterate through lines */

    /* buffer for temporary storing every line in the students.csv file (one line for every iteration) */
    uint8 *line_buffer = (uint8*)calloc(80, sizeof(uint8));

    if (line_buffer == NULL)
    {
        printf("Error! Can't Allocate space\n");
        fclose(file);
        file = NULL;
        return false;
    }

    /* for removing the label line of students.csv before accessing the struct */
    fgets(line_buffer, 80, file);
    while(fgets(line_buffer, 80, file) != NULL) /* the loop for assigning the read data line by line to the student struct */
    {
        /* assigning data (from the buffer string) token by token using the strtok function by using "," as a delimiter */
        sscanf(strtok(line_buffer, ","), "%ld", &student[iter].ID);
        sscanf(strtok(NULL, ""), "%s", student[iter].password);
        iter++;
    }
    free(line_buffer);
    line_buffer = NULL;
    fclose(file);
    file = NULL;
    return true;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          3/5/2024 23:18           Adding File Layout
 *  Muhammad Wael          5/5/2024 22:35           Adding read and write admin function
 *  Muhammad Wael          5/5/2024 23:26           modifying read admin.csv function "Not complete"
 *  Mina Nabil             9/5/2024 22:30           Adding read student and record function
 *  Mina Nabil             10/5/2024 14:10          Adding file existence check to read_data_from_students & read_data_from_records functions
 *  Mina Nabil             10/5/2024 14:24          Reading and modifying read_data_from_admins function
 *  Mina Nabil             10/5/2024 14:47          Adding write to records & write to students functions
 *  Mina Nabil             10/5/2024 14:58          splitting read student and record function into two functions
 *  Muhammad Wael          10/5/2024 21:06          modifying read functions and add dynamic allocation
 *  Muhammad Wael          10/5/2024 21:46          modifying read functions and add dynamic allocation
 *  Mina Nabil             11/5/2024 12:49          fixing get_num_lines function to return to first line after finishing
 *  Muhammad Wael          12/5/2024 01:39          big fix to all function handle fclose and free functions
 * */
/* ****************** History Log Section End ****************** */