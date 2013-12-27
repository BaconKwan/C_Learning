#include<stdio.h>

change_ps1()
{     int i;
      FILE *fp;char s[8];
      struct user *p;
      if((fp=fopen("userfile1","rb"))==NULL)printf("cannot open file");
      p=(struct user *)malloc(LEN_user);
      fread(p,LEN_user,1,fp);
      while(1)
     {printf("请输入新密码：");
      scanf("%s",s);
      printf("请确认新密码：");
      scanf("%s",p->ps);
      if(strcmp(s,p->ps)==0)
          {if((fp=fopen("userfile1","wb"))==NULL)printf("cannot open file");
            i=fwrite(p,LEN_user,1,fp);
            if(i==1){printf("恭喜您，密码修改成功！\n");break;}
            else    {printf("修改失败！\n");break;}
          }
      else {printf("输入错误！\n");continue;}
     }
}
