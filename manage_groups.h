#ifndef MANAGE_GROUPES_H_INCLUDED
#define MANAGE_GROUPES_H_INCLUDED

#include "Bool.h"

typedef struct {
    char name[100];
}Group;



Bool add_group(Group*);

Bool del_group(Group*);


#endif // MANAGE_GROUPES_H_INCLUDED
