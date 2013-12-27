#define LEN_admin sizeof(struct user)
#define LEN_course sizeof(struct course)
#define LEN_student sizeof(struct student)

typedef struct user{
	//数据域
	char name[24];								//用户名
	char password[8];							//密码
	int power;									//权限
	//指针域
	struct user *next;
}ADMIN;

typedef struct course{
	//数据域
	long num;									//课程编号
	char name[30];								//课程名称
	float score[3], retake_score, value;				//成绩、重修成绩、学分
	int Isretake;									//重修次数（0为没有重修）
	//指针域
	struct course *next;
}COURSE;

typedef struct student{
	//数据域
	long num, dor_num, birth, tel_Bnum;			//学生学号、宿舍号、出生年月日、电话号码后八位
	int grade_class, tel_Fnum, cAmount;			//学生班级、电话号码前三位、课程数量
	char sex;									//学生性别
	char name[24];								//学生姓名
	struct course course[50];						//所选课程
	//指针域
	struct student *next;
}STUDENT;

char login_ID[24];
int login_power;
ADMIN *login_ListHead;
COURSE *course_ListHead;
STUDENT *student_ListHead;

