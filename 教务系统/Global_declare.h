#define LEN_admin sizeof(struct user)
#define LEN_course sizeof(struct course)
#define LEN_student sizeof(struct student)

typedef struct user{
	//������
	char name[24];								//�û���
	char password[8];							//����
	int power;									//Ȩ��
	//ָ����
	struct user *next;
}ADMIN;

typedef struct course{
	//������
	long num;									//�γ̱��
	char name[30];								//�γ�����
	float score[3], retake_score, value;				//�ɼ������޳ɼ���ѧ��
	int Isretake;									//���޴�����0Ϊû�����ޣ�
	//ָ����
	struct course *next;
}COURSE;

typedef struct student{
	//������
	long num, dor_num, birth, tel_Bnum;			//ѧ��ѧ�š�����š����������ա��绰������λ
	int grade_class, tel_Fnum, cAmount;			//ѧ���༶���绰����ǰ��λ���γ�����
	char sex;									//ѧ���Ա�
	char name[24];								//ѧ������
	struct course course[50];						//��ѡ�γ�
	//ָ����
	struct student *next;
}STUDENT;

char login_ID[24];
int login_power;
ADMIN *login_ListHead;
COURSE *course_ListHead;
STUDENT *student_ListHead;

