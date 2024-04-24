#include<stdio.h>

#include<string.h>


#include "menu.h"
#include "manage_users.h"
#include "manage_groups.h"


void add_user_caller();
void del_user_caller();
void change_user_info_caller();
void change_user_acc_info_caller();
void add_group_caller();
void del_group_caller();
void add_user_to_group_caller();

int main(){


    char choice = '\0';

    while(1){

        show_menu();

        printf("Enter an option: ");

        scanf("%c", &choice);

        getchar(); // removes newline generated when entering a char using scanf

        switch(choice){

            case 'a':
            case 'A':
                add_user_caller();
                break;

            case 'b':
            case 'B':
                del_user_caller();
            break;

            case 'c':
            case 'C':
                add_group_caller();
            break;

            case 'd':
            case 'D':
                del_group_caller();
            break;

            case 'e':
            case 'E':
                change_user_info_caller();
            break;

            case 'f':
            case 'F':
                change_user_acc_info_caller();
            break;

            case 'g':
            case 'G':
                add_user_to_group_caller();
            break;

            case 'q':
            case 'Q':
                return 0;

            default:
                printf("This option doesn't exist on the menu.\n");



        }

    }

    return 0;
}


void add_user_caller(){
    User new_user;
    Bool res;




    printf("username: ");
    scanf("%[^\n]", new_user.name);


    getchar();

    res = add_user(&new_user);

    if(res) printf("User added successfully.\n");
    else printf("Something went wrong.\n");

}


void del_user_caller(){
    User user;
    Bool res;




    printf("username: ");
    scanf("%[^\n]", user.name);


    getchar();

    res = del_user(&user);

    if(res) printf("User deleted successfully.\n");
    else printf("Something went wrong.\n");

}

void change_user_info_caller(){
    User user;
    Bool res;

    printf("username: ");
    scanf("%[^\n]", user.name);


    getchar();

    res = change_user_info(&user);

    if(res) printf("User information is changed successfully.\n");
    else printf("Something went wrong.\n");
}

void change_user_acc_info_caller(){
    User user;
    Bool res = False;
    char command[100];

    printf("username: ");
    scanf("%[^\n]", user.name);
    getchar();


    sprintf(command, "id %s > /dev/null", user.name);

    if((int)system(command) == 0)
        res = change_user_acc_info(&user);

    if(!res) printf("Something went wrong.\n");
}

void add_group_caller(){
    Group group;

    printf("Enter group name: ");
    scanf("%s", group.name);
    getchar();

    if(add_group(&group)) printf("Group added successfully.\n");
    else printf("Something went wrong\n");
}

void del_group_caller(){
    Group group;

    printf("Enter group name: ");
    scanf("%s", group.name);
    getchar();

    if(del_group(&group)) printf("Group deleted successfully.\n");
    else printf("Something went wrong\n");
}

void add_user_to_group_caller(){
    Group group;
    User user;

    printf("Enter username: ");
    scanf("%s", user.name);
    getchar();

    printf("Enter group name: ");
    scanf("%s", group.name);
    getchar();

    if(add_user_to_group(&user, &group)) printf("User added to a group successfully.\n");
    else printf("Something went wrong\n");
}
