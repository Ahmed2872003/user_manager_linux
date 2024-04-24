#include "manage_groups.h"

char group_command[100];

Bool add_group(Group* group){

    sprintf(group_command, "sudo groupadd %s", group->name);

    if((int)system(group_command) == 0) return True;
    else return False;
}


Bool del_group(Group* group){

    sprintf(group_command, "sudo groupdel %s", group->name);

    if((int)system(group_command) == 0) return True;
    else return False;
}
