//
//  student.h
//  学生管理系统
//
//  Created by zhufengzhu on 15/9/29.
//  Copyright (c) 2015年 朱凤珠. All rights reserved.
//

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
typedef struct student{
    char name[30];
    int score;
    int age;
}stu;

#define ADD 1
#define DEL 2
#define SER 3
#define SORT_SCORE 4
#define SORT_AGE 5
#define PRINT 6
#define NOTFOUND -100
void print_menu();
void action(int choice);
#endif
