/* **************** Documentation Section Start **************** */
/*        File Name   :  data_management.c                       */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Functions to edit record                */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "data_management.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

void edit_record (Record *record, uint8 new_grade)
{
    record->total_grade = new_grade;
}

/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          5/5/2024 23:41           Adding File Layout
 *  Muhammad Wael          5/5/2024 23:46           Adding edit_record function
 * */
/* ****************** History Log Section End ****************** */