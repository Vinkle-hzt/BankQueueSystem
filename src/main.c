#include <stdio.h>
#include "display.h"

int main()
{
    printf("Welcome to Bank Queue System :) !\n");
    show_main_menu();
    int i = -1;
    scanf("%d",&i);
    if(i == 0){
        show_exit_menu();
    }
    return 0;
}
