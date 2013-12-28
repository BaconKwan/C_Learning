//遍历学生链表
void Display_STULink(STUDENT * Link){
	printf("学生信息：\n");
	printf("================================================================================");
	if(Link != NULL){
		int i = 0;
		printf("学生编号          学生姓名            班级       电话号码\n");
		while(Link != NULL){	//逐一输出学生信息
			printf("%8ld      %-24.24s  %2d    %3.3d%8.8ld\n", Link->num, Link->name, Link->grade_class, Link->tel_Fnum, Link->tel_Bnum);
			i++;
			Link = Link->next;
		}
		printf("================================================================================");
		printf("总共有%d个学生\n", i);
		printf("================================================================================");
	}
	else
		printf("暂无信息\n");
	return;
}

//给有选择指定课程代码num_C的所有学生录入成绩
void TpyeIn_ALLScore(long num_C, STUDENT *ps){
	if(ps != NULL){	//检查链表是否存在
		while(ps != NULL){	//遍历学生链表
			int k;
			for(k = 0; k < ps->cAmount; k++){	//查找每个学生所选的课当中是否有指定的课程num_C
				if(ps->course[k].num == num_C && ps->course[k].Isretake == 0){	//判断不是重修的则执行
					printf("--------------------------------------------------------------------------------");
					printf("学号：%ld\t姓名：%s\t请输入该学生成绩：\n", ps->num, ps->name);
					printf("平时成绩：");
					scanf("%f", &(ps->course[k].score[0]));
					printf("考试成绩：");
					scanf("%f", &(ps->course[k].score[1]));
					printf("总评成绩：");
					scanf("%f", &(ps->course[k].score[2]));
				}
				else if(ps->course[k].num == num_C && ps->course[k].Isretake > 0){	//判断是重修的则执行
					printf("--------------------------------------------------------------------------------");
					printf("学号：%ld\t姓名：%s\t请输入该学生成绩（重修）：\n", ps->num, ps->name);
					printf("重修成绩：");
					scanf("%f", &(ps->course[k].retake_score));
				}
			}
			ps = ps->next;//指针后移
		}
		printf("--------------------------------------------------------------------------------");
		printf("输入完毕！\n");
	}
	else
		printf("出错，请联系管理员！\n");
	return;
}

//给有选择指定课程代码num_C的指定学号为num_S的学生录入成绩
void TpyeIn_ONEScore(long num_C, long num_S, STUDENT *ps){
	if(ps != NULL){	//检查链表是否存在
		while(ps != NULL){	//遍历学生链表
			if(ps->num == num_S){	//检查是否有学号为num_S的学生
				int k;
				for(k = 0; k < ps->cAmount; k++){	//查找该学生所选的课当中是否有指定的课程num_C
					if(ps->course[k].num == num_C && ps->course[k].Isretake == 0){	//判断不是重修的则执行
						printf("--------------------------------------------------------------------------------");
						printf("学号：%ld\t姓名：%s\t请输入该学生成绩：\n", ps->num, ps->name);
						printf("平时成绩：");
						scanf("%f", &(ps->course[k].score[0]));
						printf("考试成绩：");
						scanf("%f", &(ps->course[k].score[1]));
						printf("总评成绩：");
						scanf("%f", &(ps->course[k].score[2]));
						return;
					}
					else if(ps->course[k].num == num_C && ps->course[k].Isretake > 0){	//判断是重修的则执行
						printf("--------------------------------------------------------------------------------");
						printf("学号：%ld\t姓名：%s\t请输入该学生成绩（重修）：\n", ps->num, ps->name);
						printf("重修成绩：");
						scanf("%f", &(ps->course[k].retake_score));
						return;
					}
				}
				//从该学生的选课记录中找不到该课程的信息则执行下面的代码
				printf("--------------------------------------------------------------------------------");
				printf("该学生没有选择该课程！\n");
				return;
			}
			ps = ps->next;//指针后移
		}
		//遍历完学生链表也找不到学号为num_S的学生则执行下面的代码
		printf("--------------------------------------------------------------------------------");
		printf("未能找到该学生！\n");
	}
	else
		printf("出错，请联系管理员！\n");
	return;
}

//浏览学生信息
void Browse_STUInfo(STUDENT *p){
	Display_STULink(p);//把所有学生的简单信息输出
	while(1){
		printf("--------------------------------------------------------------------------------");
		printf("请输入学生编号以获取更详细信息（输入'0'为取消）：");
		long num_S;
		scanf("%ld", &num_S);
		if(0 != num_S){
			STUDENT *stu;
			stu = SerchSTU_byNum(num_S, p);
			Display_STUInfo(stu);	//输出选中的学生的详细信息
		}
		else break;
	}
	return;
}

void Stat_COUscore(long num_C, STUDENT *ps){
	int i, STUcount = 0, flag = 0;	//STUcount是统计学生个数，用于求平均数；j获取链表长度
	float maxScore = 0.0, minScore = 100.0, totalScore = 0.0;
	STUDENT *maxSTU, *minSTU;
	printf("选择课程代码为：%ld的学生：", num_C);
	if(ps != NULL){
		printf("\n");
		printf("================================================================================");
		printf("学生编号          学生姓名            班级       考试成绩\n");
		while(ps != NULL){//遍历学生链表
			int k;
			for(k = 0; k < ps->cAmount; k++){	//查找每个学生所选的课当中是否有指定的课程num_C
				if(ps->course[k].num == num_C){	//根据课程作为分类依据
					flag = 1;
					printf("%8ld      %-24.24s  %2d          %4.1f\n", ps->num, ps->name, ps->grade_class, ps->course[k].score[1]);
					if(ps->course[k].score[1] >= maxScore){	//保留最高分和该名学生信息
						maxScore = ps->course[k].score[1];
						maxSTU = ps;
					}
					if(ps->course[k].score[1] <= minScore){	//保留最低分和该名学生信息
						minScore = ps->course[k].score[1];
						minSTU = ps;
					}
					totalScore += ps->course[k].score[1];	//所有分数加起来，在除以人数便是平均数
					STUcount++;
				}
			}
			ps = ps->next;//指针后移
		}
		printf("================================================================================");
		if(flag){//输出统计结果
			printf("该课程最高分：\n");
			printf("学号：%8ld\t姓名：%-24.24s\t班级：%2d\t考试成绩：%4.1f\n", maxSTU->num, maxSTU->name, maxSTU->grade_class, maxScore);
			printf("--------------------------------------------------------------------------------");
			printf("该课程最低分：\n");
			printf("学号：%8ld\t姓名：%-24.24s\t班级：%2d\t考试成绩：%4.1f\n", minSTU->num, minSTU->name, minSTU->grade_class, minScore);
			printf("--------------------------------------------------------------------------------");
			printf("该课程选课总人数：%d\t\t平均分：%4.1f\n", STUcount, totalScore / STUcount);
		}
		else
			printf("暂无\n");
	}
	else{
		printf("暂无\n");
		return;
	}
	return;
}

void Stat_ALLscore(STUDENT *ps){
	printf("学生学分统计：");
	if(ps != NULL){
		printf("\n");
		printf("================================================================================");
		while(ps != NULL){
			float value = 0.0, total_value = 0.0;
			int k;
			printf("学号:%ld\t", ps->num);
			printf("姓名:%s\n", ps->name);
			printf("--------------------------------------------------------------------------------");
			for(k = 0; k < ps->cAmount; k++){
				total_value += ps->course[k].value;
				if((ps->course[k].score[2] >= 60.0) || (ps->course[k].score[2] < 60.0 && ps->course[k].retake_score >= 60.0))	//判断及格的则执行
					value += ps->course[k].value;	//表示通过考核，已获取该课程学分
				else if(ps->course[k].score[2] < 60.0 && ps->course[k].retake_score < 60.0){	//判断不及格的则执行
					printf("课程：%s（课程代码：%ld，学分：%4.1f）未通过！\n", ps->course[k].name, ps->course[k].num, ps->course[k].value);	//输出未通过课程
				}
			}
			printf("所选学分：%4.1f\t获得学分：%4.1f\t未通过学分：%4.1f\n", total_value, value, total_value - value);
			printf("--------------------------------------------------------------------------------");
			ps = ps->next;
		}
		printf("================================================================================");
	}
	else
		printf("暂无学生信息！\n");
	return;
}

void Stat_Classscore(int grade_class, STUDENT *ps){
	int i, STUcount = 0;
	printf("%d班的学生：", grade_class);
	if(ps != NULL){
		printf("\n");
		printf("================================================================================");
		while(ps != NULL){//遍历学生链表
			if(grade_class == ps->grade_class){	//根据班级作为分类依据
				printf("学号:%ld\t", ps->num);
				printf("姓名:%s\n", ps->name);
				printf("所选课程有：");
				if(ps->cAmount > 0){
					printf("总共选了%d门课程\n", ps->cAmount);
					printf("================================================================================");
					printf("课程编号        课程名称          成绩(平时/考试/总评) 重修次数 重修成绩\n");
					int i;
					for(i = 0; i < ps->cAmount; i++)		//输出所选课程
						printf("%8ld    %-24.24s   %4.1f/%4.1f/%4.1f        %2d     %4.1f\n", ps->course[i].num, ps->course[i].name, ps->course[i].score[0], ps->course[i].score[1], ps->course[i].score[2], ps->course[i].Isretake, ps->course[i].retake_score);
					printf("--------------------------------------------------------------------------------");
				}
				else{
					printf("暂无\n");
				}
				STUcount++;
			}
			ps = ps->next;//指针后移
		}
		printf("================================================================================");
		printf("该班级总人数：%d\n", STUcount);
	}
	else{
		printf("暂无\n");
		return;
	}
	return;
}

int TEA_Menu()
{
	while(1){
		system("cls");
		printf("您的身份是教师！\n");
		printf("-------------------\n\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t 教师功能主菜单！\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t #[1]---录入学生信息;\n");
		printf("\t\t\t #[2]---浏览学生信息;\n");
		printf("\t\t\t #[3]---统计学生名单及成绩;\n");
		printf("\t\t\t #[4]---统计已修学分及不及格成绩;\n");
		printf("\t\t\t #[5]---按班统计选课情况及考试成绩;\n");
		printf("\t\t\t #[0]---退出;\n");
		printf("\t\t\t-------------------------------------------\n");
		printf("注意：为保证程序正确顺利运行，请务必按照指定要求输入数据！\n");
		printf("-------------------------------------------------------------------\n");
		printf("请输入功能选项序号并按Enter键确认：");
		long num_C, num_S;
		int i;
		scanf("%d",&i);
		switch(i){
			case 1:
				system("cls");
				Display_COULink(course_ListHead);
				printf("请输入需要录入成绩的课程代码：");
				scanf("%ld", &num_C);
				printf("请输入需要录入的学生成绩（输入'0'为课程全部学生录入成绩）：");
				scanf("%ld", &num_S);
				if(num_S == 0){
					TpyeIn_ALLScore(num_C, student_ListHead);
				}
				else{
					TpyeIn_ONEScore(num_C, num_S, student_ListHead);
				}
				system("pause");
				break;
			case 2:
				system("cls");
				Browse_STUInfo(student_ListHead);
				system("pause");
				break;
			case 3:
				system("cls");
				Display_COULink(course_ListHead);
				printf("请输入需要统计成绩的课程代码：");
				scanf("%ld", &num_C);
				Stat_COUscore(num_C, student_ListHead);
				system("pause");
				break;
			case 4:
				system("cls");
				Stat_ALLscore(student_ListHead);
				system("pause");
				break;
			case 5:
				system("cls");
				printf("请输入需要统计成绩的班级：");
				scanf("%ld", &num_C);
				Stat_Classscore(num_C, student_ListHead);
				system("pause");
				break;
			case 0:
				exit(0);
			default:
				break;
		}
	}
}
