/**
 * @file member.c
 * @brief 客户类及相关操作
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "member.h"

member *member_come(int ID, char *name)
{
    member *m = malloc(sizeof(member));
    m->ID = ID;
    strncpy(m->name, name, NAME_SIZE);
    m->vip = get_vip_level(ID);

    cur_pick_num[m->vip]++;
    cur_common_num++;
    m->vip_pick_num = cur_pick_num[m->vip];
    m->common_pick_num = cur_common_num;
    // log message
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d 姓名: %s, vip：%d) 取到号码为 %d \n", ID, name, m->vip, m->common_pick_num);

    return m;
}

void member_leave(member *m)
{
    // log message
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d 姓名: %s, vip：%d) 离开银行 \n", m->ID, m->name, m->vip);

    safe_free(m);
}

int member_compare(const void *lhs, const void *rhs)
{
    member *lp = (member *)lhs;
    member *rp = (member *)rhs;
    return ((lp->common_pick_num - lp->vip * 3) - (rp->common_pick_num - rp->vip * 3));
}

int get_vip_level(int ID)
{
    FILE *vfile = fopen(vip_level_file, "r");
    int curID, curvip;
    while (~fscanf(vfile, "%d %d", &curID, &curvip))
        if (curID == ID)
            return curvip;
    fclose(vfile);

    vfile = fopen(vip_level_file, "a");
    printf("自动帮您注册账户，感谢您的光临！\n");
    fprintf(vfile, "%d\t %d\n", ID, 0);
    fclose(vfile);

    return 0;
}