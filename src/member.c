#include "member.h"

member* member_come(int ID, char* name)
{
    member* m = malloc(sizeof(member));
    m->ID = ID;
    strncpy(m->name, name, NAME_SIZE);
    cur_pick_num++;
    m->pick_num = cur_pick_num;
    
    // log message
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d name: %s) pick number %d \n", ID, name, cur_pick_num);

    return m;
}

void member_leave(member* m)
{
    // log message
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d name: %s) leave \n", m->ID, m->name);

    safe_free(m);
}