/* **************** Documentation Section Start **************** */
/*        File Name   :  std_lib.h                               */
/*        Author      :  Muhammad Wael                           */
/*        Description :  Standard Functions and Macros           */
/* ***************** Documentation Section End ***************** */

#ifndef STD_LIB_
#define STD_LIB_

/* ******************* Include Section Start ******************* */

/* ******************** Include Section End ******************** */

/* ******************** Macro Section Start ******************** */

#define bool _Bool
#define false 0
#define true 1
#define NAME_SIZE 30
#define PASSWORD_SIZE 20

/* ********************* Macro Section End ********************* */

/* ******************* Typedef Section Start ******************* */

typedef unsigned char         uint8;
typedef unsigned short        uint16;
typedef unsigned long         uint32;
typedef unsigned long long    uint64;
typedef signed char           int8;
typedef signed short          int16;
typedef signed long           int32;
typedef signed long long      int64;
typedef float                 float32;
typedef double                float64;

typedef struct {
    uint16 ID;
    uint8 name[NAME_SIZE];
    uint8 gender[8];
    uint8 age;
    uint8 total_grade;
} Record;

typedef struct {
    uint16 ID;
    uint8 *name;
    uint8 *password;
} Admin;

typedef struct {
    uint16 ID;
    uint8 password[PASSWORD_SIZE];
} Student;

/* ******************** Typedef Section End ******************** */

/* *************** Global Variables Section Start ************** */

/* **************** Global Variables Section End *************** */

/* ************** Global Declaration Section Start ************* */

/* *************** Global Declaration Section End ************** */

#endif

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Muhammad Wael          5/5/2024 21:41           Adding File Layout
 *  Muhammad Wael          5/5/2024 22:00           Adding typedef section
 */
/* ****************** History Log Section End ****************** */