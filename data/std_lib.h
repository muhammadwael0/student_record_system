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

/* Colors */
#define RESET  "\033[0m"
#define RED    "\033[1;31m"
#define BLUE   "\033[0;34m"
#define YELLOW "\033[1;33m"
#define GREEN  "\033[0;32m"

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
    uint32 ID;
    uint8 name[NAME_SIZE];
    uint8 gender[7];
    uint8 age;
    uint8 total_grade;
} Record;

typedef struct {
    uint32 ID;
    uint8 name[NAME_SIZE];
    uint8 password[PASSWORD_SIZE];
} Admin;

typedef struct {
    uint32 ID;
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
 *  Muhammad Wael          8/5/2024 22:05           modifying typedef section
 *  Mina Nabil             9/5/2024 22:42           modified the data type of ID to uint32 in the three structs
 */
/* ****************** History Log Section End ****************** */