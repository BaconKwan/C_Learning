//�����γ�����
void Display_COULink(COURSE * Link){
	printf("�γ���Ϣ��\n");
	printf("================================================================================");
	if(Link != NULL){
		int i = 0;
		while(Link != NULL){
				printf("�γ̴��룺%8ld\t�γ����ƣ�%s\tѧ�֣�%4.1f\n", Link->num, Link->name, Link->value);
				i++;
				Link = Link->next;
		}
		printf("================================================================================");
		printf("�ܹ���%d�ſγ�\n", i);
		printf("================================================================================");
	}
	else
		printf("������Ϣ\n");
	return;
}

//����һ��ͨ��ѧ����ѧ������p�в����˳�����ѧ���ṹ���ַ
STUDENT *SerchSTU_byNum(long num_S, STUDENT *p){
	if(p != NULL){	//��������Ƿ����
		while(p != NULL){			//�жϽ��λ��
			if(p->num == num_S){		//�Ƚ�ѧ��
				return p;		//����ѧ��λ�ã����ڶ�λ��ѧ��
			}
			p = p->next;		//ָ�����
		}
	}
	return NULL;			//��ѯʧ�ܷ��ؿ�
}
//����һ��ͨ��������ѧ������p�в����˳�����ѧ���ṹ���ַ
STUDENT *SerchSTU_byName(char name_S[], STUDENT *p){
	if(p != NULL){	//��������Ƿ����
		while(p != NULL){		//�ж�ָ��λ��
			//printf("%s, %s\n",p->name,name);
			if ((strcmp(p->name, name_S)) == 0){		//�Ƚ�ѧ������
				return p;		//����ѧ��λ�ã����ڶ�λ��ѧ��
			}
			p = p->next;			//ָ�����
		}
	}
	return NULL;			//��ѯʧ�ܷ��ؿ�
}

//�ú����ÿγ̱�Ž���ѡ�Σ�������һ��Ϊ�γ̴��룬�ڶ���Ϊ�γ���Ϣ�����������Ϊ����Ա���ɵĴ�����ļ�����������Ǹ�����
//������Ϊ��Ӧѡ�ε�ѧ�����������������ķ������;����������ﶨλѧ���ģ������õ�¼ʱ����������Ϣ��
int Stu_CourseSelecting(long num_C, COURSE *pc, STUDENT *ps){
	if(pc != NULL){	//��������Ƿ����
		while(pc != NULL){		//�ж�ָ��λ�ã�Ҫ�����γ���Ϣ����ѡ��
			if (num_C == pc->num){		//�жϵ�ǰ�ڵ��Ƿ�Ϊ��ѡ�γ�
				//�ڶ�Ӧ��ѧ����Ϣ����Ӹÿγ̵���Ϣ
				strcpy(ps->course[ps->cAmount].name, pc->name);		//�γ�����
				ps->course[ps->cAmount].num = pc->num;			//�γ̴���
				ps->course[ps->cAmount].score[0] = 0.0;				//ƽʱ�ɼ�
				ps->course[ps->cAmount].score[1] = 0.0;				//���Գɼ�
				ps->course[ps->cAmount].score[2] = 0.0;				//�����ɼ�
				ps->course[ps->cAmount].retake_score = 0.0;			//���޳ɼ�
				ps->course[ps->cAmount].Isretake = 0;				//���޼�¼
				ps->course[ps->cAmount].value = pc->value;			//�γ�ѧ��
				printf("��ϲ%s���γ̣�%s���γ̴��룺%ld��ѡ�γɹ���\n", ps->name, ps->course[ps->cAmount].name, ps->course[ps->cAmount].num);//ѧ��ѡ��������1
				(ps->cAmount)++;	//��ѡ�γ�����+1
				return 1;
			}
			pc = pc->next;				//ָ�����
		}
	}
	//printf("ѡ��ʧ�ܣ�����ϵ����Ա��\n");
	return 0;
}

//����ѡ��
int Stu_CourseRetaking(long num_C, STUDENT *ps){
	if(ps != NULL){	//��������Ƿ����
		int i;
		for(i = 0; i < ps->cAmount; i++){
			if(ps->course[i].num == num_C){
				ps->course[i].Isretake++;		//���޼�¼+1
				ps->course[i].retake_score = 0.0;	//���޳ɼ����
				printf("��ϲ%s���γ̣�%s���γ̴��룺%ld��ѡ�Σ����ޣ��ɹ���\n", ps->name, ps->course[i].name, ps->course[i].num);
				return 1;
			}
		}
	}
	//printf("ѡ��ʧ�ܣ�����ϵ����Ա��\n");
	return 0;
}
//���ѧ����Ϣ
void Display_STUInfo(STUDENT *p){
	if(p != NULL){	//��������Ƿ����
		printf("����%s�������Ϣ���£�\n", p->name);
		printf("================================================================================");
		printf("ѧ��:%ld\n", p->num);
		printf("����:%s\n", p->name);
		printf("�༶:%d\n", p->grade_class);
		printf("�Ա�:%c\n", p->sex);
		printf("��������:%8.8ld\n", p->birth);
		printf("�绰����:%3.3d%8.8ld\n", p->tel_Fnum, p->tel_Bnum);
		printf("�����:%ld\n", p->dor_num);
		printf("��ѡ�γ��У�");
		if(p->cAmount > 0){
			printf("�ܹ�ѡ��%d�ſγ�\n", p->cAmount);
			printf("================================================================================");
			printf("�γ̱��        �γ�����          �ɼ�(ƽʱ/����/����) ���޴��� ���޳ɼ�\n");
			int i;
			for(i = 0; i < p->cAmount; i++)		//�����ѡ�γ�
				printf("%8ld    %-24.24s   %4.1f/%4.1f/%4.1f        %2d     %4.1f\n", p->course[i].num, p->course[i].name, p->course[i].score[0], p->course[i].score[1], p->course[i].score[2], p->course[i].Isretake, p->course[i].retake_score);
		}
		else{
			printf("����\n");
		}
		return;
	}
	printf("ѧ����Ϣ��������ϵ����Ա��\n");
	return;
}


int STU_Menu()
{
	STUDENT *stu = SerchSTU_byName(login_ID, student_ListHead);
	while(1){
		system("cls");
		printf("���������ѧ����\n");
		printf("-------------------\n\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t ѧ���������˵���\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t #[1]---������Ϣ;\n");
		printf("\t\t\t #[2]---ѡ��;\n");
		printf("\t\t\t #[0]---�˳�;\n");
		printf("\t\t\t-------------------------------------------\n");
		printf("ע�⣺Ϊ��֤������ȷ˳�����У�����ذ���ָ��Ҫ���������ݣ�\n");
		printf("-------------------------------------------------------------------\n");
		printf("�����빦��ѡ����Ų���Enter��ȷ�ϣ�");
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
				printf("��������Ҫѡ�޵Ŀγ̴��룺");
				long seletion;
				scanf("%ld", &seletion);
				if(1 == Stu_CourseRetaking(seletion, stu)){}
				else if(1 == Stu_CourseSelecting(seletion, course_ListHead, stu)){}
				else{printf("ѡ��ʧ�ܣ�����ϵ����Ա��\n");}
				system("pause");
				break;
			case 0:
				exit(0);
			default:
				break;
		}
	}
}
