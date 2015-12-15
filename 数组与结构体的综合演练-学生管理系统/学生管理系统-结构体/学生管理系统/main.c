//
//  main.c
//  学生管理系统
//
//  Created by zhufengzhu on 15/9/29.
//  Copyright (c) 2015年 朱凤珠. All rights reserved.
//

#include <stdio.h>
#include "student.h"
int main(int argc, const char * argv[]) {
    int choice;
    while (1) {
        print_menu();
        scanf("%d",&choice);
        action(choice);
    }
    return 0;
}
