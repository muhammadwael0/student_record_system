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
    for (iter = 0; iter < 115; iter++)
        printf("%s=%s", BLUE, RESET);

    printf("\n%s      _____ _             _            _ %s  _____                        _%s  _____           _\n", RED, YELLOW, RED);
    printf("%s     / ____| |           | |          | |%s |  __ \\                      | |%s/ ____|         | |\n", RED, YELLOW, RED);
    printf("%s    | (___ | |_ _   _  __| | ___ _ __ | |_%s| |__) |___  ___ ___  _ __ __| | %s(___  _   _ ___| |_ ___ _ __ ___\n", RED, YELLOW, RED);
    printf("%s     \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __%s|  _  // _ \\/ __/ _ \\| '__/ _` |%s\\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n", RED, YELLOW, RED);
    printf("%s     ____) | |_| |_| | (_| |  __/ | | | |_%s| | \\ \\  __/ (_| (_) | | | (_| |%s____) | |_| \\__ \\ ||  __/ | | | | |\n", RED, YELLOW, RED);
    printf("%s    |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__%s|_|  \\_\\___|\\___\\___/|_|  \\__,_|%s_____/ \\__, |___/\\__\\___|_| |_| |_|\n", RED, YELLOW, RED);
    printf("%s                                                                                  __/ |%s\n", RED, RESET);
    printf("%s                                                                                 |___/%s\n", RED, RESET);
    for (iter = 0; iter < 115; iter++)
        printf("%s=%s", BLUE, RESET);

    printf("\n\n\n%sAvailable modes :- %s\n", YELLOW, RESET);
    printf("%s1- Admin.%s\n", BLUE, RESET);
    printf("%s2- Student.%s\n\n", BLUE, RESET);
    printf("%schoose mode >> %s", GREEN, RESET);
    scanf("%hd", &mode);

    if (mode == M_ADMIN)
    {

        for (iter = 0; iter < TRIES; iter++)
        {
            printf("%sEnter ID: %s", YELLOW, RESET);
            scanf("%lu", &admin_id);
            printf("%sEnter Password: %s", YELLOW, RESET);
            scanf("%s", admin_password);
            if (authenticate_admin(admin_id, admin_password))
                break;
            else if (iter == 2)
            {
                printf("%sAccess denied.%s\n", RED, RESET);
                return 0;
            }
        }
        while (true)
        {
            printf("%s====================================%s\n", BLUE, RESET);
            printf("%sChoose operation:-%s\n\n", YELLOW, RESET);
            printf("%s1. Add student record.\n", BLUE);
            printf("2. Remove student record.\n");
            printf("3. View student record.\n");
            printf("4. View all records.\n");
            printf("5. Edit admin password.\n");
            printf("6. Edit student grade.%s\n\n", RESET);
            printf("%sEnter operation number >> %s", GREEN, RESET);
            scanf("%hd", &operation);
            switch (operation)
            {
            case 1:
                add_student_record();
                break;
            case 2:
                for (iter = 0; iter < TRIES; iter++)
                {
                    printf("%sEnter student ID: %s", YELLOW, RESET);
                    scanf("%ld", &student_id);
                    if (remove_student_record(student_id))
                        break;
                    else if (iter == 2)
                        printf("%sNo More Tries!%s\n", RED, RESET);
                }
                break;
            case 3:
                for (iter = 0; iter < TRIES; iter++)
                {
                    printf("%sEnter student ID: %s", YELLOW, RESET);
                    scanf("%ld", &student_id);
                    if (view_student_record(student_id))
                        break;
                    else if (iter == 2)
                        printf("%sNo More Tries!%s\n", RED, RESET);
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
                    printf("%sEnter student ID: %s", YELLOW, RESET);
                    scanf("%ld", &student_id);
                    if (edit_grade(student_id))
                        break;
                    else if (iter == 2)
                        printf("%sNo More Tries!%s\n", RED, RESET);
                }
                break;

            default:
                printf("%sNo Matching Operation.%s\n", RED, RESET);
                break;
            }
            printf("\n%sDo you want another operation (yes 1/no 0): %s", BLUE, RESET);
            scanf("%hd", &try_again);
            if (!try_again)
            {
                printf("%sEnd of authorization.\n%s", YELLOW, RESET);
                break;
            }
        }
    }
    else if (mode == M_STUDENT)
    {

        for (iter = 0; iter < TRIES; iter++)
        {
            printf("%sEnter ID: %s", YELLOW, RESET);
            scanf("%ld", &student_id);
            printf("%sEnter Password: %s", YELLOW, RESET);
            scanf("%s", student_password);
            if (authenticate_student_password(authenticate_student_id(student_id), student_password))
                break;
            else if (iter == 2)
            {
                printf("%sAccess denied.%s\n", RED, RESET);
                return 0;
            }
        }
        while (true)
        {
            printf("%s===================================%s\n", BLUE, RESET);
            printf("%sChoose operation:-%s\n\n", YELLOW, RESET);
            printf("%s1. View your record.\n", BLUE);
            printf("2. Edit your password.\n");
            printf("3. Edit your name.%s\n\n", RESET);
            printf("\n%sEnter operation number >> %s", GREEN, RESET);
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
                printf("%sNo Matching Operation.%s\n", RED, RESET);
                break;
            }
            printf("\n%sDo you want another operation (yes 1/no 0): %s", BLUE, RESET);
            scanf("%hd", &try_again);
            if (!try_again)
            {
                printf("%sEnd of authorization.%s\n", YELLOW, RESET);
                break;
            }
        }
    }
    else
        printf("%s[%s!%s] %sNo Matching Mode.%s\n", BLUE, RED, BLUE, RED, RESET);
}
/* ****************** Global Sub-program End ******************* */

/* ***************** History Log Section Start ***************** */
/*  User                   Date                     Brief
 *  Mina Nabil             11/5/2024 23:28          Adding File Layout
 *  Mina Nabil             12/5/2024 03:57          Adding all main functions
 *  Mina Nabil             12/5/2024 14:07          change some style
 *  Muhammad Wael          22/6/2024 13:54          Add Colors
 */
/* ****************** History Log Section End ****************** */