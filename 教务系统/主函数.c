#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"admin.c"
#include"teacher.c"

void main()
{
    char n[24],p[8];
    printf("\t\t\t  欢迎光临教务信息管理系统\n");
    printf("\t\t\t----------------------------\n");
   while(1)
   {
    printf("请输入用户名：");       //身份信息验证
    scanf("%s",n);
    printf("请输入密码：");
    scanf("%s",p);
    printf("-------------------\n");

/*
      FILE *fp,*fp1;
      struct user *p3;             //读入用户文件
      if((fp=fopen("userfile","rb"))==NULL)printf("cannot open file");
      if((fp1=fopen("userfile1","rb"))==NULL)printf("cannot open file");
      p3=(struct user *)malloc(LEN_user);
      fread(p3,LEN_user,1,fp);
      if(strcmp(p3->name,n)==0&&strcmp(p3->ps,p)==0){ admin();break;}
      else if(strcmp(p3->name,n)!=0||strcmp(p3->ps,p)!=0)
          {
            fread(p3,LEN_user,1,fp1);
            if(strcmp(p3->name,n)==0&&strcmp(p3->ps,p)==0)
                {teacher();break;}
          }
      else {printf("用户名或密码错误！\n");continue;}
      fclose(fp1);
      fclose(fp);
   }
*/
}
