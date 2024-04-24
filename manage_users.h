#ifndef MANAGE_USERS_H_INCLUDED
#define MANAGE_USERS_H_INCLUDED

#include "Bool.h"
#include "manage_groups.h"


typedef struct {
    char name[100];
}User;


Bool add_user(User*);

Bool del_user(User*);

Bool change_user_info(User*);

Bool change_user_acc_info(User*);

Bool change_user_pass(User*);

Bool change_username(User*);

Bool change_user_expd_pass(User*);

Bool add_user_to_group(User*, Group*);



#endif // MANAGE_USERS_H_INCLUDED
