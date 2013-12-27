#include<stdio.h>
#include<malloc.h>
#include"Global_declare.h"

STUDENT *creatLink()//函数首先读取文件内学生信息，然后建立新的学生信息并连接到已存在的链表尾部
{                  //建表函数（学生）
	STUDENT *head=NULL, *p1, *p2;
	STUDENT *p,*q;
	FILE *fp /*= fopen("stufile","rb")*/;//读取文件内学生信息
	if((fp=fopen("stufile","rb"))==NULL)
	    {
	     printf("can not open file!");
	     //exit(1);
	    }
    p=(struct student *)malloc(LEN_student);
	if(!p)
	    {
	    printf("空间分配失败！");
	    return head;
	    }

	head=p;
	q = p;
	while(!feof(fp))//读取文件内学生信息
       {
         if(fread(p,LEN_student,1,fp)!=1)
             {
                printf("未发现学生信息！\n");
                break;
             }
         p->next=(STUDENT *)malloc(LEN_student);
         if(!p->next)
	         {
	           printf("空间分配失败！");
	         }
         q=p;
         p=p->next;

       }
	q->next=NULL;
	fclose(fp);


	char s;
	q->next=p1 = p2 = (STUDENT *)malloc(LEN_student); //添加学生信息到链表
	p2->next = NULL;
	//head->length = 0;
	    printf("---------------------------------\n");
		printf("请输入学号：");
        scanf("%ld",&p1->num);
        printf("请输入宿舍号码：");
        scanf("%d",&p1->dor_num);
		printf("请输入姓名（2~24个字母）：");
		scanf("%s", p1->name);
		printf("请输入学生的班级：");
		scanf("%d",&p1->grade_class);
		printf("请输入出生年月日：");
		scanf("%ld",&p1->birth);
		printf("请输入电话号码：");
		scanf("%3d%8ld",&p1->tel_Fnum,&p1->tel_Bnum);
		printf("请输入性别：");
		getchar();
		scanf("%c",&p1->sex);
		printf("要继续输入吗？（Y/N）");
		getchar();
		scanf("%c", &s);
	while(1&&(s== 'Y' || s =='y'))
	 {
		p1 = (STUDENT *)malloc(LEN_student);
		p2->next = p1;
		p2 = p1;
		p2->next =NULL;
		//head->length++;
		printf("---------------------------------\n");
		printf("请输入学号：");
        scanf("%ld",&p1->num);
        printf("请输入宿舍号码：");
        scanf("%d",&p1->dor_num);
		printf("请输入姓名（2~24个字母）：");
		scanf("%s", p1->name);
		printf("请输入学生的班级：");
		scanf("%d",&p1->grade_class);
		printf("请输入出生年月日：");
		scanf("%ld",&p1->birth);
		printf("请输入电话号码：");
		scanf("%3d%8ld",&p1->tel_Fnum,&p1->tel_Bnum);
		printf("请输入性别：");
		getchar();
		scanf("%c",&p1->sex);
		printf("要继续输入吗？（Y/N）");
		getchar();
		scanf("%c", &s);
		if(s == 'N' || s =='n')
		    {
                break;
            }
	 }
	return head;
}

COURSE *COU_creatLink()
{              //建表函数（课程）
	COURSE *head1, *p1, *p2;
	char s;
	p1 = p2 = head1 = (COURSE *)malloc(LEN_course);
	p2->next = NULL;
	//head1->length = 0;
	while(1)
	 {
		p1 = (COURSE *)malloc(LEN_course);
		p2->next = p1;
		p2 = p1;
		p2->next =NULL;
		//head1->length++;
		printf("---------------------\n");
		printf("请输入课程编号：");
        scanf("%ld",&p1->num);
        printf("请输入课程名称：");
        scanf("%s",p1->name);
        printf("请输入课程学分：");getchar();
        scanf("%f",&p1->value);


		printf("要继续输入吗？（Y/N）:");
        getchar();
		scanf("%c", &s);
		if(s == 'N' || s =='n')
		   {
			 break;
           }
	 }
	return head1;
}

Insert_stu(STUDENT *head)                          //插入学生信息函数
{
    struct student *p,*p1,*r;
    p=p1=head->next;
    while(p!=NULL)
        {  p1=p;
           p=p->next;
        }
    r=(struct student *)malloc(LEN_student);
    r->next=NULL;
    if(r==NULL)
      printf("分配空间失败！");
    if(p1==NULL) head=r;
    else  p1->next=r;
    printf("-------------------------------------\n");
    printf("请输入插入学生信息！\n");
    printf("请输入学号：");
    scanf("%ld",&r->num);
    printf("请输入宿舍号码：");
    scanf("%d",&r->dor_num);
    printf("请输入姓名（2~24个字母）：");
    scanf("%s", r->name);
    printf("请输入学生的班级：");
    scanf("%d",&r->grade_class);
    printf("请输入出生年月日：");
    scanf("%ld",&r->birth);
    printf("请输入电话号码：");
    scanf("%3d%8ld",&r->tel_Fnum,&r->tel_Bnum);
    printf("请输入性别：");
    getchar();
    scanf("%c",&r->sex);


}

Delete_stu(STUDENT *head)                              //删除学生信息函数
{  long i;
   int flog=1;
   printf("请输入要删除学生的学号：");
   scanf("%ld",&i);
   struct student *p,*p1;
   p=p1=head;
   while(p!=NULL)
   {
      if(p->num==i)
      {
          if(p==head)//删除节点为头结点
          {
             head=p->next;
             free(p);
          }
          else
          {
             p1->next=p->next;//删除节点为普通节点
             free(p);
          }
          flog=0;
      }
      else
      {
          p1=p;
          p=p->next;//走针   p1为p的前驱节点
      }
   }

}

Load_stu(STUDENT *head)                                 //浏览学生信息函数
{  int i=0,j=0;
   STUDENT *p;
   p=head;

   if(p!=NULL)
        {  p=p->next;
           i++;
           if(i==1)
            {
              printf("学号  宿舍号码    姓名\t \t班级\t出生年月日\t性别\t电话号码\n");
              printf("----------------------------------------------------------------------------\n");
            }
           printf("%ld    %ld \t%s  \t%d   \t%ld\t%c\t%d%ld\n",p->num,p->dor_num,p->name,p->grade_class,p->birth,p->sex,p->tel_Fnum,p->tel_Bnum);
           p=p->next;
        }
    else
           printf("未找到学生数据！\n");
}

change_ps()               //修改密码函数
{     int i;
      FILE *fp;char s[8];
      struct user *p;
      if((fp=fopen("userfile","rb"))==NULL)
      printf("cannot open file");
      p=(struct user *)malloc(LEN_user);
      fread(p,LEN_user,1,fp);
      while(1)
      {
        printf("请输入新密码：");
        scanf("%s",s);
        printf("请确认新密码：");
        scanf("%s",p->ps);
        if(strcmp(s,p->ps)==0)
          {
           if((fp=fopen("userfile","wb"))==NULL)
              printf("cannot open file");
           i=fwrite(p,LEN_user,1,fp);
           if(i==1)
            {
               printf("恭喜您，密码修改成功！\n");
               break;
            }
           else
            {
               printf("修改失败！\n");
               break;
            }
           }
         else
           {
               printf("输入错误！\n");
               continue;
           }
     }
}

save_stufile(STUDENT *head)   //保存学生信息到文件stufile
{
    FILE *fp;
    struct student *p;
    p=head;
    p=p->next;
    if((fp=fopen("stufile","wb"))==NULL)
    printf("cannot open file");
    while(p!=NULL)
     {
        fwrite(p,LEN_student,1,fp);
        p=p->next;
     }
    fclose(fp);
}

save_coufile(struct course *head)//保存课程信息到文件coufile
{
    FILE *fp;
    struct course *p;
    p=head;
    p=p->next;
    if((fp=fopen("coufile","wb"))==NULL)
        printf("cannot open file");
    while(p!=NULL)
    {
        fwrite(p,LEN_course,1,fp);
        p=p->next;
    }
    fclose(fp);
}
main()//测试函数（无意义）
{
    STUDENT *head;
    head = creatLink();
    // COURSE *HEAD;
    // HEAD=COU_creatLink();
    //save_stufile(head);
    Load_stu(head);
}

