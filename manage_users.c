#include "manage_users.h"
#include "string.h"

char command[100];



Bool add_user(User* new_user){

    sprintf(command, "sudo useradd -m %s", new_user->name);

    int res = system(command);

    if(res == 0) return True;
    else return False;

}


Bool del_user(User* user){
    sprintf(command, "sudo userdel -r %s", user->name);

    int res = system(command);

    if(res == 0) return True;
    else return False;

}


Bool change_user_info(User* user){
    sprintf(command, "sudo chfn %s", user->name);

    int res = system(command);

    if(res == 0) return True;
    else return False;
}


Bool change_user_acc_info(User* user){
    char choice = '\0';
    char resume = 'y';



    while(resume == 'y' || resume == 'Y'){

        printf("    1- Change username.\n");
        printf("    2- change password.\n");
        printf("    3- change password expiration.\n");
        printf("    4- exit from account modification.\n");

        printf("Choose from the list: ");
        scanf("%c", &choice);
        getchar();

        switch(choice){
            case '1':
                if(change_username(user) == 0)
                    printf("username is changed successfully.\n");
            break;
            case '2':
                change_user_pass(user);
            break;
            case '3':
                if(change_user_expd_pass(user))
                    printf("password expiration date is set successully.\n");
            break;
            case '4':
                return True;
            default:
                printf("This option doesn't exist on the menu.\n");
        }
        printf("Do you want to continue in modifying user account? (y/n): ");
        scanf("%c", &resume);
        getchar();
    }

    return True;
}

Bool change_username(User* user){
    char new_username[100];

    printf("New username: ");
    scanf("%s", new_username);
    getchar();

    sprintf(command, "sudo usermod -l %s %s", new_username ,user->name);

    int res = system(command);

    if(res == 0){
        strcpy(user->name, new_username);
        return True;
    }
    else return False;
}

Bool change_user_pass(User* user){
    sprintf(command, "sudo passwd %s", user->name);

    int res = system(command);

    if(res == 0)
        return True;
    else return False;
}

Bool change_user_expd_pass(User* user){

    char date[30];

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%[^\n]", date);
    getchar();


    sprintf(command, "sudo chage -E %s %s", date ,user->name);

    int res = system(command);

    if(res == 0)
        return True;
    else return False;


}

Bool add_user_to_group(User* user, Group* group){

    sprintf(command, "sudo usermod -aG %s %s", group->name, user->name);

    int res = system(command);

    if(res == 0)
        return True;
    else return False;

}
