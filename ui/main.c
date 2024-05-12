/* **************** Documentation Section Start **************** */
/*        File Name   :  main.c                                  */
/*        Author      :  Mina Nabil                              */
/*        Description :  Functions for main                      */
/* ***************** Documentation Section End ***************** */

/* ******************* Include Section Start ******************* */
#include "main.h"
/* ******************** Include Section End ******************** */

/* ***************** Global Sub-program Start ****************** */

int main()
{
    uint16 mode, operation, try_again;
    uint32 admin_id, student_id;
    uint8 admin_password[PASSWORD_SIZE], student_password[PASSWORD_SIZE];
    int iter;
    for (iter = 0; iter < 81; iter++)
        printf("*");
    printf("\n                      Welcome To The Student Record System\n");
    for (iter = 0; iter < 81; iter++)
        printf("*");

    printf("\n\n\nAvailable modes :- \n");
    printf("1- Admin.\n");
    printf("2- Student.\n");
    printf("choose mode : ");
    scanf("%hd", &mode);

    if (mode == M_ADMIN)
    {
        while (true)
        {
            for (iter = 0; iter < TRIES; iter++)
            {
                printf("Enter ID: ");
                scanf("%lu", &admin_id);
                printf("Enter Password: ");
                scanf("%s", admin_password);
                if (authenticate_admin(admin_id, admin_password))
                    break;
                else if (iter == 2)
                {
                    printf("Access denied.");
                    return 0;
                }
            }
            printf("Choose operation:-\n\n");
            printf("1. Add student record.\n");
            printf("2. Remove student record.\n");
            printf("3. View student record.\n");
            printf("4. View all records.\n");
            printf("5. Edit admin password.\n");
            printf("6. Edit student grade.\n\n");
            printf("Enter operation number: ");
            scanf("%hd", &operation);
            switch (operation)
            {
            case 1:
                add_student_record();
                break;
            case 2:
                for (iter = 0; iter < TRIES; iter++)
                {
                    printf("Enter student ID: ");
                    scanf("%ld", &student_id);
                    if (remove_student_record(student_id))
                        break;
                    else if (iter == 2)
                        printf("No More Tries!");
                }
                break;
            case 3:
                for (iter = 0; iter < TRIES; iter++)
                {
                    printf("Enter student ID: ");
                    scanf("%ld", &student_id);
                    if (view_student_record(student_id))
                        break;
                    else if (iter == 2)
                        printf("No More Tries!");
                }
                break;
            case 4:
                view_all_records();
                break;
            case 5:
                edit_password_of_admin(admin_id);
                break;
            case 6:
                for (iter = 0; iter < TRIES; iter++)
                {
                    printf("Enter student ID: ");
                    scanf("%ld", &student_id);
                    if (edit_grade(student_id))
                        break;
                    else if (iter == 2)
                        printf("No More Tries!");
                }
                break;

            default:
                printf("No Matching Operation.");
                break;
            }
            printf("\nDo you want another operation (yes 1/no 0): ");
            scanf("%hd", &try_again);
            if (!try_again)
            {
                printf("\n\nEnd of authorization.");
                break;
            }
        }
    }
    else if (mode == M_STUDENT)
    {
        while (true)
        {
            for (iter = 0; iter < TRIES; iter++)
            {
                printf("Enter ID: ");
                scanf("%ld", &student_id);
                printf("Enter Password: ");
                scanf("%s", student_password);
                if (authenticate_student_password(authenticate_student_id(student_id), student_password))
                    break;
                else if (iter == 2)
                {
                    printf("Access denied.");
                    return 0;
                }
            }
            printf("Choose operation:-\n\n");
            printf("1. View your record.\n");
            printf("2. Edit your password.\n");
            printf("3. Edit your name.\n");
            printf("Enter operation number: ");
            scanf("%hd", &operation);
            switch (operation)
            {
            case 1:
                view_student_record_from_student(student_id);
                break;
            case 2:
                edit_password_of_student(student_id);
                break;
            case 3:
                edit_name_of_student(student_id);
                break;
            default:
                printf("No Matching Operation.");
                break;
            }
            printf("\nDo you want another operation (yes 1/no 0): ");
            scanf("%hd", &try_again);
            if (!try_again)
            {
                printf("\n\nEnd of authorization.");
                break;
            }
        }
    }
    else
        printf("No Matching Mode.");
}
/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Mina Nabil             11/5/2024 23:28          Adding File Layout
 *  Mina Nabil             12/5/2024 03:57          Adding all main functions
 *  Mina Nabil             12/5/2024 14:07          change some style
 * */
/* ****************** History Log Section End ****************** */