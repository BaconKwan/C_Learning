//Ϊ���Է��㶼ֻ�����˳��������ļ������壬ֻΪ������
//����ѧ���������հ��ǿɴ��ļ���������
STUDENT *STUDENT_creatLink(){
	STUDENT *head, *p1, *p2;
	char s;
	p1 = p2 = head = (STUDENT *)malloc(LEN_student);
	p2->next = NULL;
	printf("��ȡ������������'N'��'n'��");
	s = getchar();
	while(s != 'N' && s != 'n'){
		p2->birth = 19901014;
		printf("input student info:\n");
		printf("Name:");
		scanf("%s", p2->name);
		printf("Num:");
		scanf("%ld", &(p2->num));
		p2->next =NULL;
		printf("�Ƿ�������룿��Y��N����");
		s = getchar();
		scanf("%c", &s);
		if(s != 'N' && s != 'n'){
			p1 = (STUDENT *)malloc(LEN_student);
			p2->next = p1;
			p2 = p1;
		}
	}
	return head;
}
//�����γ�����Ϊ�˷������������5��������Ϊ�γ�
COURSE *COURSE_creatLink(){
	COURSE *head, *p1, *p2;
	p1 = p2 =head = (COURSE *)malloc(LEN_course);
	p2->next = NULL;
	strcpy(p2->name, "courseA");
	p2->num = 1001;
	p2->value = 1.0;
	p1 = (COURSE *)malloc(LEN_course);
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;
	strcpy(p2->name, "courseB");
	p2->num = 1002;
	p2->value = 1.5;
	p1 = (COURSE *)malloc(LEN_course);
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;
	strcpy(p2->name, "courseC");
	p2->num = 1003;
	p2->value = 2.0;
	p1 = (COURSE *)malloc(LEN_course);
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;
	strcpy(p2->name, "courseD");
	p2->num = 1004;
	p2->value = 2.5;
	p1 = (COURSE *)malloc(LEN_course);
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;
	strcpy(p2->name, "courseE");
	p2->num = 1005;
	p2->value = 3.0;
	return head;


}
