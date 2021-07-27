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
    m->vip = get_vip_level(&m->ID, name);

    // 错误判断
    if (m->vip == member_error_1)
    {
        free(m);
        return (member *)&member_error_1;
    }
    if (m->vip == member_error_2)
    {
        free(m);
        return (member *)&member_error_2;
    }

    return m;
}

void member_leave(member *m)
{
    // 日志信息
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d 姓名: %s, vip：%d) 离开银行 \n", m->ID, m->name, m->vip);

    safe_free(m);
}

int member_compare(const void *lhs, const void *rhs)
{
    member *lp = (member *)lhs;
    member *rp = (member *)rhs;
    return ((rp->common_pick_num - rp->vip * 3) - (lp->common_pick_num - lp->vip * 3));
}

int get_vip_level(int *ID, char *name)
{
    if (*ID != 0)
    {
        sprintf(mysql_buffer, "SELECT * FROM `user` WHERE user_ID = %d", *ID);

        int ret = mysql_query(&mysql_connect, mysql_buffer);
        if (ret != 0)
        {
            printf("Query failed...Error: %s\n", mysql_error(&mysql_connect));
            exit(-1);
        }

        mysql_res = mysql_store_result(&mysql_connect);
        if (mysql_res)
        {
            // int field_count = mysql_field_count(&mysql_connect);
            int row = mysql_num_rows(mysql_res);
            if (row > 0)
            {
                int vip_column = -1;
                int name_column = -1;
                for (int i = 0; (mysql_field = mysql_fetch_field(mysql_res)); i++)
                {
                    // 获取 vip 字段列
                    if (strcmp(mysql_field->name, "vip") == 0)
                        vip_column = i;
                    // 获取 name 字段列
                    if (strcmp(mysql_field->name, "name") == 0)
                        name_column = i;
                }
                mysql_next_row = mysql_fetch_row(mysql_res);

                // 如果姓名不匹配 返回 -1
                if (strcmp(mysql_next_row[name_column], name) != 0)
                    return -1;

                return atoi(mysql_next_row[vip_column]);
            }
            else
                return -2;
        }
    }
    else
    {
        // 未查询到，新建用户
        sprintf(mysql_buffer, "INSERT INTO `user` (name, vip) VALUES ('%s', 0) ", name);
        // printf("sql_buffer :  %s\n", mysql_buffer);
        mysql_query(&mysql_connect, mysql_buffer);

        // 查询分配的 ID 号码
        sprintf(mysql_buffer, "SELECT MAX(user_ID) FROM `user`");
        mysql_query(&mysql_connect, mysql_buffer);
        mysql_res = mysql_store_result(&mysql_connect);
        mysql_next_row = mysql_fetch_row(mysql_res);
        *ID = atoi(mysql_next_row[0]);

        printf("尊敬的%s，已自动为您生成 ID，您的 ID 号为 %d\n", name, *ID);
        system("pause");
        return 0;
    }
    return 0;
}

void update_pick(member *m)
{
    cur_pick_num[m->vip]++;
    cur_common_num++;
    m->vip_pick_num = cur_pick_num[m->vip];
    m->common_pick_num = cur_common_num;
    // 日志信息
    show_date(log_file, get_cur_date());
    fprintf(log_file, " (ID: %d 姓名: %s, vip：%d) 取到号码为 %d \n",
            m->ID, m->name, m->vip, m->common_pick_num);
}