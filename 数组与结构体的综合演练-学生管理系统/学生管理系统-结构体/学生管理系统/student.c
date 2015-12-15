//
//  student.c
//  学生管理系统
//
//  Created by zhufengzhu on 15/9/29.
//  Copyright (c) 2015年 朱凤珠. All rights reserved.
//

#include "student.h"
#include <string.h>
stu stuArray[100] = {};
int gStuNumber = 0;
void print_menu()
{
    printf("欢迎使用学生管理系统\n");
    printf("请选择操作:\n");
    printf("1、增加学生\n");
    printf("2、删除学生\n");
    printf("3、查找学生\n");
    printf("4、按照分数排序\n");
    printf("5、按照年龄排序\n");
    printf("6、打印全部学生信息\n");
    printf("7、退出\n");
}
//默认加到最后面
void addToArray(stu new)
{
    stuArray[gStuNumber] = new;
    gStuNumber ++;
}
void addStudent()
{
    stu new = {};
    if(gStuNumber>=100){
        printf("对不起，学生系统已满\n");
        return;
    }
    printf("请输入新增学生的名字\n");
    scanf("%s",new.name);
    printf("请输入新增学生的成绩\n");
    scanf("%d",&new.score);
    printf("请输入新增学生的年龄\n");
    scanf("%d",&new.age);
    addToArray(new);
    
}
void printStudentsArray()
{
    printf("学生系统中一共有%d位学生信息\n",gStuNumber);
    for (int i=0; i<gStuNumber; i++) {
        printf("姓名:%s,成绩:%d,年龄:%d\n",stuArray[i].name,stuArray[i].score,stuArray[i].age);
        
    }
}
void sortByScore()
{
    stu temp={};
    for (int i=0; i<gStuNumber-1; i++) {
        for (int j=0; j<gStuNumber-1-i; j++) {
            if(stuArray[j].score>stuArray[j+1].score){
                temp = stuArray[j];
                stuArray[j] = stuArray[j+1];
                stuArray[j+1] = temp;
            }
        }
    }
}
void sortByAge()
{
    stu temp={};
    for (int i=0; i<gStuNumber-1; i++) {
        for (int j=0; j<gStuNumber-1-i; j++) {
            if(stuArray[j].age>stuArray[j+1].age){
                temp = stuArray[j];
                stuArray[j] = stuArray[j+1];
                stuArray[j+1] = temp;
            }
        }
    }
}

//找到返回数组下标，否则返回 NOTFOUND
int searchStudentByName(char name[]){
    for (int i=0; i<gStuNumber; i++) {
        if(strcmp(stuArray[i].name,name)==0){
            return i;
        }
    }
    return NOTFOUND;
}//根据名字查询学生
void searchStudent()
{
    char name[30] = {};
    printf("请输入要查询的学生姓名\n");
    scanf("%s",name);
    
    int index = searchStudentByName(name);
    if(index == NOTFOUND){
        printf("没有找到该学生信息");
    }
    else{
        printf("您要查询的学生信息是 姓名:%s,成绩:%d,年龄:%d",stuArray[index].name,stuArray[index].score,stuArray[index].age);
    }
    return;
}

void deletStudent()
{
    char name[30]={};
    int index;
    printf("请输入您要删除的学生姓名\n");
    scanf("%s",name);
    index = searchStudentByName(name);
    if(index == NOTFOUND){
        printf("您要删除的学生不存在\n");
    }
    else{
        //数组删除一个学生，下标是index,数据左移
        for (int i=index; i<gStuNumber-1; i++) {
            stuArray[i] = stuArray[i+1];
        }
        gStuNumber --;
    }
}
void action(int choice)
{
    switch (choice) {
        case ADD:
            addStudent();
            break;
        case DEL:
            deletStudent();
            break;
        case SER:
            searchStudent();
            break;
        case SORT_SCORE:
            sortByScore();
            break;
        case SORT_AGE:
            sortByAge();
            break;
        case PRINT:
            printStudentsArray();
            break;
        default:
            printf("选项错误\n");
            break;
    }
}
