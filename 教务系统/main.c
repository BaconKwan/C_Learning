#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Global_declare.h"
#include "link.c"
#include "StuFun.c"
#include "TeaFun.c"
#include "AdminFun.c"

//测试用的程序入口
int main(){
/*
	//学生模块测试代码
	STUDENT *head1, *stu1, *stu2, *h1;		//head1为学生链表，stu1为学生1号，stu2为学生2号
	COURSE *head2, *h2;					//课程链表
	head1 = STUDENT_creatLink();
	head2 = COURSE_creatLink();
	printf("--------------------------------------------------------------------------------");
	Display_STULink(head1);				//检查学生链表
	printf("--------------------------------------------------------------------------------");
	Display_COULink(head2);				//检查课程链表
	printf("--------------------------------------------------------------------------------");
	stu1 = SerchSTU_byName("ter", head1);		//通过姓名查找，这里是测试所以用的是常量，下面同理
	Display_STUInfo(stu1);
	printf("--------------------------------------------------------------------------------");
	stu2 = SerchSTU_byNum(2, head1);
	Display_STUInfo(stu2);
	printf("--------------------------------------------------------------------------------");
	Stu_CourseSelecting(1001, head2, stu1);			//学生1号选课
	Stu_CourseSelecting(2003, head2, stu1);
	Stu_CourseSelecting(1004, head2, stu1);
	Stu_CourseSelecting(1005, head2, stu1);
	Stu_CourseRetaking(1005, stu1);

	Stu_CourseSelecting(1001, head2, stu2);			//学生2号选课
	Stu_CourseSelecting(1002, head2, stu2);
	Stu_CourseSelecting(1003, head2, stu2);
	Stu_CourseSelecting(1201, head2, stu2);
	Stu_CourseSelecting(1004, head2, stu2);
	Stu_CourseSelecting(1005, head2, stu2);
	Stu_CourseRetaking(1004, stu2);
	Stu_CourseRetaking(1005, stu2);
	Stu_CourseRetaking(1005, stu2);
	printf("--------------------------------------------------------------------------------");
	Display_STUInfo(stu1);
	printf("--------------------------------------------------------------------------------");
	Display_STUInfo(stu2);
	printf("--------------------------------------------------------------------------------");
	h1 = head1;
	h2 = head2;
	FILE *fp;
	fp = fopen("stufile", "wb+") ;
	while(h1 != NULL){
		fwrite(h1, LEN_student,1,fp);
		h1 = h1->next;
	}
	fclose(fp);
	fp = fopen("coufile", "wb+") ;
	while(h2 != NULL){
		fwrite(h2, LEN_course,1,fp);
		h2 = h2->next;
	}
	fclose(fp);


/*
	system("pause");//屏幕暂停
	system("cls");//清屏

	//教师模块测试代码
	Browse_STUInfo(head1);
	TpyeIn_ALLScore(1001, head1);
	TpyeIn_ALLScore(1005, head1);
	TpyeIn_ONEScore(1003, 1, head1);
	TpyeIn_ONEScore(1003, 123, head1);
	TpyeIn_ONEScore(1004, 2, head1);
	Browse_STUInfo(head1);
	system("pause");//屏幕暂停
	system("cls");//清屏
	Stat_COUscore(1001, head1);
	Stat_COUscore(1002, head1);
	Stat_COUscore(1003, head1);
	Stat_COUscore(1004, head1);
	Stat_COUscore(1005, head1);
	system("pause");//屏幕暂停
	system("cls");//清屏
	Stat_Classscore(0, head1);
	system("pause");//屏幕暂停
	system("cls");//清屏
	Stat_ALLscore(head1);

	ADMIN *a, *b;
	a = (ADMIN *)malloc(LEN_admin);
	strcpy(a->name, "admin");
	strcpy(a->password, "admin");
	a->power = 0;
	a->next = NULL;
	b = (ADMIN *)malloc(LEN_admin);
	strcpy(b->name, "teacher");
	strcpy(b->password, "teacher");
	b->power = 1;
	b->next = a;
	printf("%s,%s,%d,%x\n", a->name, a->password, a->power, a->next);
	printf("%s,%s,%d,%x\n", b->name, b->password, b->power, b->next);
	FILE *fp_user;
	fp_user = fopen("userfile", "wb+") ;
	fwrite(a, LEN_admin,1,fp_user);
	fwrite(b, LEN_admin,1,fp_user);
	fclose(fp_user);
	fp_user = fopen("userfile", "rb") ;
	printf("%d\n",fread(b, LEN_admin,1,fp_user));
	printf("%d\n",fread(a, LEN_admin,1,fp_user));
	fclose(fp_user);

	printf("%s,%s,%d,%x\n", a->name, a->password, a->power, a->next);
	printf("%s,%s,%d,%x\n", b->name, b->password, b->power, b->next);
*/

	printf("\t\t\t  欢迎光临教务信息管理系统\n");
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t系统正在初始化，请稍候...\n");
	printf("\t\t\t----------------------------\n");

	//建立登录信息链表
	printf("\t\t\t正在读取登录信息...");
	FILE *fp_user = fopen("userfile", "rb");
	ADMIN *p1, *p2;
	p1 = p2 = (ADMIN *)malloc(LEN_admin);
	login_ListHead = p1;
		//printf("%s,%s\n", n, p);
	if((fp_user == NULL)){
		printf("Cannot open USER file!\n");
	}
	else{
		while(fread(p1, LEN_admin, 1, fp_user)){
			//printf("%s,%s,%d,%x\n", p1->name, p1->password, p1->power, p1->next);
			p2 = p1;
			p1->next = (ADMIN *)malloc(LEN_admin);
			p1 = p1->next;
		}
		fclose(fp_user);
		p2->next = NULL;
		free(p1);
		printf("完成\n");
	}

	//建立学生信息链表
	printf("\t\t\t正在读取学生信息...");
	FILE *fp_stu= fopen("stufile", "rb");
	STUDENT *s1, *s2;
	s1 = s2 = (STUDENT *)malloc(LEN_student);
	student_ListHead = s1;
		//printf("%s,%s\n", n, p);
	if((fp_stu == NULL)){
		printf("Cannot open STUDENT file!\n");
	}
	else{
		while(fread(s1, LEN_student, 1, fp_stu)){
			//printf("%s,%ld,%x\n", s1->name, s1->num, s1->next);
			s2 = s1;
			s1->next = (STUDENT *)malloc(LEN_student);
			s1 = s1->next;
		}
		fclose(fp_stu);
		s2->next = NULL;
		free(s1);
		printf("完成\n");
	}

	//建立课程信息链表
	printf("\t\t\t正在读取课程信息...");
	FILE *fp_cou= fopen("coufile", "rb");
	COURSE *c1, *c2;
	c1 = c2 = (COURSE *)malloc(LEN_course);
	course_ListHead = c1;
		//printf("%s,%s\n", n, p);
	if((fp_cou == NULL)){
		printf("Cannot open COURSE file!\n");
	}
	else{
		while(fread(c1, LEN_course, 1, fp_cou)){
			//printf("%s,%ld,%f\n", c1->name, c1->num, c1->value);
			c2 = c1;
			c1->next = (COURSE *)malloc(LEN_course);
			c1 = c1->next;
		}
		fclose(fp_cou);
		c2->next = NULL;
		free(c1);
		printf("完成\n");
	}
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t系统初始化完成\n");
	printf("\t\t\t----------------------------\n");
	system("pause");

	while(1){
		char n[24],p[8];
		system("cls");
		printf("\t\t\t  欢迎光临教务信息管理系统\n");
		printf("\t\t\t----------------------------\n");
		printf("请登录：\n");
		printf("-------------------\n\n");
		printf("请输入用户名（输入'0'退出）：");       //身份信息验证
		scanf("%s",n);
		if(n[0] == '0')	exit(0);
		printf("请输入密码：");
		scanf("%s",p);
		printf("-------------------\n");
		ADMIN *p_login = login_ListHead;
		while(p_login != NULL){
			if(strcmp(p_login->name, n) == 0 && strcmp(p_login->password, p) == 0){
				//printf("d");
				strcpy(login_ID, n);
				//strcpy(login_ID, "ter");
				login_power = p_login->power;
				//login_power = 2;
				//printf("%s,%d\n", login_ID, login_power);
				switch(login_power){
					case 0:	admin_Menu();break;
					case 1:	TEA_Menu();break;
					case 2:	STU_Menu();break;
					default:	break;
				}
			}
			//printf("e");
			p_login = p_login->next;
			//printf("f");
		}
		//printf("g");
		printf("登录出错，请联系管理员！\n");
		system("pause");
	}

	return 0;

}
