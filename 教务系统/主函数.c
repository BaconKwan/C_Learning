#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"admin.c"
#include"teacher.c"

void main()
{
    char n[24],p[8];
    printf("\t\t\t  ��ӭ���ٽ�����Ϣ����ϵͳ\n");
    printf("\t\t\t----------------------------\n");
   while(1)
   {
    printf("�������û�����");       //�����Ϣ��֤
    scanf("%s",n);
    printf("���������룺");
    scanf("%s",p);
    printf("-------------------\n");

/*
      FILE *fp,*fp1;
      struct user *p3;             //�����û��ļ�
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
      else {printf("�û������������\n");continue;}
      fclose(fp1);
      fclose(fp);
   }
*/
}
