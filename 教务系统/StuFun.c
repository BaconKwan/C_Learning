//遍历课程链表
void Display_COULink(COURSE * Link){
	printf("课程信息：\n");
	printf("================================================================================");
	if(Link != NULL){
		int i = 0;
		while(Link != NULL){
				printf("课程代码：%8ld\t课程名称：%s\t学分：%4.1f\n", Link->num, Link->name, Link->value);
				i++;
				Link = Link->next;
		}
		printf("================================================================================");
		printf("总共有%d门课程\n", i);
		printf("================================================================================");
	}
	else
		printf("暂无信息\n");
	return;
}

//返回一个通过学号在学生链表p中查找了出来的学生结构体地址
STUDENT *SerchSTU_byNum(long num_S, STUDENT *p){
	if(p != NULL){	//检查链表是否存在
		while(p != NULL){			//判断结点位置
			if(p->num == num_S){		//比较学号
				return p;		//返回学生位置，用于定位该学生
			}
			p = p->next;		//指针后移
		}
	}
	return NULL;			//查询失败返回空
}
//返回一个通过姓名在学生链表p中查找了出来的学生结构体地址
STUDENT *SerchSTU_byName(char name_S[], STUDENT *p){
	if(p != NULL){	//检查链表是否存在
		while(p != NULL){		//判断指针位置
			//printf("%s, %s\n",p->name,name);
			if ((strcmp(p->name, name_S)) == 0){		//比较学生姓名
				return p;		//返回学生位置，用于定位该学生
			}
			p = p->next;			//指针后移
		}
	}
	return NULL;			//查询失败返回空
}

//该函数用课程编号进行选课，参数第一个为课程代码，第二个为课程信息所存的链表（即为管理员生成的存放在文件里读出来的那个链表）
//第三个为对应选课的学生（上面两个函数的返回类型就是用于这里定位学生的，或者用登录时所产生的信息）
int Stu_CourseSelecting(long num_C, COURSE *pc, STUDENT *ps){
	if(pc != NULL){	//检查链表是否存在
		while(pc != NULL){		//判断指针位置（要遍历课程信息进行选择）
			if (num_C == pc->num){		//判断当前节点是否为所选课程
				//在对应的学生信息中添加该课程的信息
				strcpy(ps->course[ps->cAmount].name, pc->name);		//课程名称
				ps->course[ps->cAmount].num = pc->num;			//课程代码
				ps->course[ps->cAmount].score[0] = 0.0;				//平时成绩
				ps->course[ps->cAmount].score[1] = 0.0;				//考试成绩
				ps->course[ps->cAmount].score[2] = 0.0;				//总评成绩
				ps->course[ps->cAmount].retake_score = 0.0;			//重修成绩
				ps->course[ps->cAmount].Isretake = 0;				//重修记录
				ps->course[ps->cAmount].value = pc->value;			//课程学分
				printf("恭喜%s，课程：%s（课程代码：%ld）选课成功！\n", ps->name, ps->course[ps->cAmount].name, ps->course[ps->cAmount].num);//学生选课总量加1
				(ps->cAmount)++;	//所选课程数量+1
				return 1;
			}
			pc = pc->next;				//指针后移
		}
	}
	//printf("选课失败！请联系管理员。\n");
	return 0;
}

//重修选课
int Stu_CourseRetaking(long num_C, STUDENT *ps){
	if(ps != NULL){	//检查链表是否存在
		int i;
		for(i = 0; i < ps->cAmount; i++){
			if(ps->course[i].num == num_C){
				ps->course[i].Isretake++;		//重修记录+1
				ps->course[i].retake_score = 0.0;	//重修成绩清空
				printf("恭喜%s，课程：%s（课程代码：%ld）选课（重修）成功！\n", ps->name, ps->course[i].name, ps->course[i].num);
				return 1;
			}
		}
	}
	//printf("选课失败！请联系管理员。\n");
	return 0;
}
//输出学生信息
void Display_STUInfo(STUDENT *p){
	if(p != NULL){	//检查链表是否存在
		printf("您好%s，你的信息如下：\n", p->name);
		printf("================================================================================");
		printf("学号:%ld\n", p->num);
		printf("姓名:%s\n", p->name);
		printf("班级:%d\n", p->grade_class);
		printf("性别:%c\n", p->sex);
		printf("出生年月:%8.8ld\n", p->birth);
		printf("电话号码:%3.3d%8.8ld\n", p->tel_Fnum, p->tel_Bnum);
		printf("宿舍号:%ld\n", p->dor_num);
		printf("所选课程有：");
		if(p->cAmount > 0){
			printf("总共选了%d门课程\n", p->cAmount);
			printf("================================================================================");
			printf("课程编号        课程名称          成绩(平时/考试/总评) 重修次数 重修成绩\n");
			int i;
			for(i = 0; i < p->cAmount; i++)		//输出所选课程
				printf("%8ld    %-24.24s   %4.1f/%4.1f/%4.1f        %2d     %4.1f\n", p->course[i].num, p->course[i].name, p->course[i].score[0], p->course[i].score[1], p->course[i].score[2], p->course[i].Isretake, p->course[i].retake_score);
		}
		else{
			printf("暂无\n");
		}
		return;
	}
	printf("学生信息有误，请联系管理员。\n");
	return;
}


int STU_Menu()
{
	STUDENT *stu = SerchSTU_byName(login_ID, student_ListHead);
	while(1){
		system("cls");
		printf("您的身份是学生！\n");
		printf("-------------------\n\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t 学生功能主菜单！\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t #[1]---基本信息;\n");
		printf("\t\t\t #[2]---选课;\n");
		printf("\t\t\t #[0]---退出;\n");
		printf("\t\t\t-------------------------------------------\n");
		printf("注意：为保证程序正确顺利运行，请务必按照指定要求输入数据！\n");
		printf("-------------------------------------------------------------------\n");
		printf("请输入功能选项序号并按Enter键确认：");
		int i;
		scanf("%d",&i);
		switch(i){
			case 1:
				system("cls");
				Display_STUInfo(stu);
				system("pause");
				break;
			case 2:
				system("cls");
				Display_COULink(course_ListHead);
				printf("请输入您要选修的课程代码：");
				long seletion;
				scanf("%ld", &seletion);
				if(1 == Stu_CourseRetaking(seletion, stu)){}
				else if(1 == Stu_CourseSelecting(seletion, course_ListHead, stu)){}
				else{printf("选课失败！请联系管理员。\n");}
				system("pause");
				break;
			case 0:
				exit(0);
			default:
				break;
		}
	}
}
