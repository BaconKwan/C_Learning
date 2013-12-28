#include<stdio.h>
#include<malloc.h>
#include"教师功能函数.c"

int teacher()
{
    printf("您的身份是教师！\n");
    printf("-------------------\n\n");
  while(1)
    {int i=0;
    printf("\t\t\t ------------------------------------------\n");
    printf("\t\t\t 教师功能主菜单！                          \n");
    printf("\t\t\t ------------------------------------------\n");
    printf("\t\t\t #[1]---浏览学生信息;                      \n");
    printf("\t\t\t #[2]---录入学生成绩;                      \n");
    printf("\t\t\t #[3]---按班统计选课情况及及考试成绩;      \n");
    printf("\t\t\t #[4]---按课程统计学生名单及考试成绩;      \n");
    printf("\t\t\t #[5]---统计学生已修学分及不及格成绩;      \n");
    printf("\t\t\t #[6]---修改登陆密码;                      \n");
    printf("\t\t\t #[0]---退出;                              \n");
    printf("\t\t\t-------------------------------------------\n");
    printf("注意：为保证程序正确顺利运行，请务必按照指定要求输入数据！\n");
    printf("-------------------------------------------------------------------\n");
    printf("请输入功能选项序号并按Enter键确认：");
    scanf("%d",&i);
    getchar();
    switch(i)
    {
        case 1://H = creatLink();break;
        case 2://h=COU_creatLink();break;
        case 3://Insert_stu(H);break;
        case 4://Delete_stu(H);break;
        case 5://Load_stu(H);break;
        case 6:change_ps1();break;
        case 0:return 1;
        default:break;

    }
    char c;
    printf("#是否继续（Y/N）");
    scanf("%s",&c);
    if(c=='Y'||c=='y') continue;
    else break;

  }
}
