//����ѧ������
void Display_STULink(STUDENT * Link){
	printf("ѧ����Ϣ��\n");
	printf("================================================================================");
	if(Link != NULL){
		int i = 0;
		printf("ѧ�����          ѧ������            �༶       �绰����\n");
		while(Link != NULL){	//��һ���ѧ����Ϣ
			printf("%8ld      %-24.24s  %2d    %3.3d%8.8ld\n", Link->num, Link->name, Link->grade_class, Link->tel_Fnum, Link->tel_Bnum);
			i++;
			Link = Link->next;
		}
		printf("================================================================================");
		printf("�ܹ���%d��ѧ��\n", i);
		printf("================================================================================");
	}
	else
		printf("������Ϣ\n");
	return;
}

//����ѡ��ָ���γ̴���num_C������ѧ��¼��ɼ�
void TpyeIn_ALLScore(long num_C, STUDENT *ps){
	if(ps != NULL){	//��������Ƿ����
		while(ps != NULL){	//����ѧ������
			int k;
			for(k = 0; k < ps->cAmount; k++){	//����ÿ��ѧ����ѡ�Ŀε����Ƿ���ָ���Ŀγ�num_C
				if(ps->course[k].num == num_C && ps->course[k].Isretake == 0){	//�жϲ������޵���ִ��
					printf("--------------------------------------------------------------------------------");
					printf("ѧ�ţ�%ld\t������%s\t�������ѧ���ɼ���\n", ps->num, ps->name);
					printf("ƽʱ�ɼ���");
					scanf("%f", &(ps->course[k].score[0]));
					printf("���Գɼ���");
					scanf("%f", &(ps->course[k].score[1]));
					printf("�����ɼ���");
					scanf("%f", &(ps->course[k].score[2]));
				}
				else if(ps->course[k].num == num_C && ps->course[k].Isretake > 0){	//�ж������޵���ִ��
					printf("--------------------------------------------------------------------------------");
					printf("ѧ�ţ�%ld\t������%s\t�������ѧ���ɼ������ޣ���\n", ps->num, ps->name);
					printf("���޳ɼ���");
					scanf("%f", &(ps->course[k].retake_score));
				}
			}
			ps = ps->next;//ָ�����
		}
		printf("--------------------------------------------------------------------------------");
		printf("������ϣ�\n");
	}
	else
		printf("��������ϵ����Ա��\n");
	return;
}

//����ѡ��ָ���γ̴���num_C��ָ��ѧ��Ϊnum_S��ѧ��¼��ɼ�
void TpyeIn_ONEScore(long num_C, long num_S, STUDENT *ps){
	if(ps != NULL){	//��������Ƿ����
		while(ps != NULL){	//����ѧ������
			if(ps->num == num_S){	//����Ƿ���ѧ��Ϊnum_S��ѧ��
				int k;
				for(k = 0; k < ps->cAmount; k++){	//���Ҹ�ѧ����ѡ�Ŀε����Ƿ���ָ���Ŀγ�num_C
					if(ps->course[k].num == num_C && ps->course[k].Isretake == 0){	//�жϲ������޵���ִ��
						printf("--------------------------------------------------------------------------------");
						printf("ѧ�ţ�%ld\t������%s\t�������ѧ���ɼ���\n", ps->num, ps->name);
						printf("ƽʱ�ɼ���");
						scanf("%f", &(ps->course[k].score[0]));
						printf("���Գɼ���");
						scanf("%f", &(ps->course[k].score[1]));
						printf("�����ɼ���");
						scanf("%f", &(ps->course[k].score[2]));
						return;
					}
					else if(ps->course[k].num == num_C && ps->course[k].Isretake > 0){	//�ж������޵���ִ��
						printf("--------------------------------------------------------------------------------");
						printf("ѧ�ţ�%ld\t������%s\t�������ѧ���ɼ������ޣ���\n", ps->num, ps->name);
						printf("���޳ɼ���");
						scanf("%f", &(ps->course[k].retake_score));
						return;
					}
				}
				//�Ӹ�ѧ����ѡ�μ�¼���Ҳ����ÿγ̵���Ϣ��ִ������Ĵ���
				printf("--------------------------------------------------------------------------------");
				printf("��ѧ��û��ѡ��ÿγ̣�\n");
				return;
			}
			ps = ps->next;//ָ�����
		}
		//������ѧ������Ҳ�Ҳ���ѧ��Ϊnum_S��ѧ����ִ������Ĵ���
		printf("--------------------------------------------------------------------------------");
		printf("δ���ҵ���ѧ����\n");
	}
	else
		printf("��������ϵ����Ա��\n");
	return;
}

//���ѧ����Ϣ
void Browse_STUInfo(STUDENT *p){
	Display_STULink(p);//������ѧ���ļ���Ϣ���
	while(1){
		printf("--------------------------------------------------------------------------------");
		printf("������ѧ������Ի�ȡ����ϸ��Ϣ������'0'Ϊȡ������");
		long num_S;
		scanf("%ld", &num_S);
		if(0 != num_S){
			STUDENT *stu;
			stu = SerchSTU_byNum(num_S, p);
			Display_STUInfo(stu);	//���ѡ�е�ѧ������ϸ��Ϣ
		}
		else break;
	}
	return;
}

void Stat_COUscore(long num_C, STUDENT *ps){
	int i, STUcount = 0, flag = 0;	//STUcount��ͳ��ѧ��������������ƽ������j��ȡ������
	float maxScore = 0.0, minScore = 100.0, totalScore = 0.0;
	STUDENT *maxSTU, *minSTU;
	printf("ѡ��γ̴���Ϊ��%ld��ѧ����", num_C);
	if(ps != NULL){
		printf("\n");
		printf("================================================================================");
		printf("ѧ�����          ѧ������            �༶       ���Գɼ�\n");
		while(ps != NULL){//����ѧ������
			int k;
			for(k = 0; k < ps->cAmount; k++){	//����ÿ��ѧ����ѡ�Ŀε����Ƿ���ָ���Ŀγ�num_C
				if(ps->course[k].num == num_C){	//���ݿγ���Ϊ��������
					flag = 1;
					printf("%8ld      %-24.24s  %2d          %4.1f\n", ps->num, ps->name, ps->grade_class, ps->course[k].score[1]);
					if(ps->course[k].score[1] >= maxScore){	//������߷ֺ͸���ѧ����Ϣ
						maxScore = ps->course[k].score[1];
						maxSTU = ps;
					}
					if(ps->course[k].score[1] <= minScore){	//������ͷֺ͸���ѧ����Ϣ
						minScore = ps->course[k].score[1];
						minSTU = ps;
					}
					totalScore += ps->course[k].score[1];	//���з������������ڳ�����������ƽ����
					STUcount++;
				}
			}
			ps = ps->next;//ָ�����
		}
		printf("================================================================================");
		if(flag){//���ͳ�ƽ��
			printf("�ÿγ���߷֣�\n");
			printf("ѧ�ţ�%8ld\t������%-24.24s\t�༶��%2d\t���Գɼ���%4.1f\n", maxSTU->num, maxSTU->name, maxSTU->grade_class, maxScore);
			printf("--------------------------------------------------------------------------------");
			printf("�ÿγ���ͷ֣�\n");
			printf("ѧ�ţ�%8ld\t������%-24.24s\t�༶��%2d\t���Գɼ���%4.1f\n", minSTU->num, minSTU->name, minSTU->grade_class, minScore);
			printf("--------------------------------------------------------------------------------");
			printf("�ÿγ�ѡ����������%d\t\tƽ���֣�%4.1f\n", STUcount, totalScore / STUcount);
		}
		else
			printf("����\n");
	}
	else{
		printf("����\n");
		return;
	}
	return;
}

void Stat_ALLscore(STUDENT *ps){
	printf("ѧ��ѧ��ͳ�ƣ�");
	if(ps != NULL){
		printf("\n");
		printf("================================================================================");
		while(ps != NULL){
			float value = 0.0, total_value = 0.0;
			int k;
			printf("ѧ��:%ld\t", ps->num);
			printf("����:%s\n", ps->name);
			printf("--------------------------------------------------------------------------------");
			for(k = 0; k < ps->cAmount; k++){
				total_value += ps->course[k].value;
				if((ps->course[k].score[2] >= 60.0) || (ps->course[k].score[2] < 60.0 && ps->course[k].retake_score >= 60.0))	//�жϼ������ִ��
					value += ps->course[k].value;	//��ʾͨ�����ˣ��ѻ�ȡ�ÿγ�ѧ��
				else if(ps->course[k].score[2] < 60.0 && ps->course[k].retake_score < 60.0){	//�жϲ��������ִ��
					printf("�γ̣�%s���γ̴��룺%ld��ѧ�֣�%4.1f��δͨ����\n", ps->course[k].name, ps->course[k].num, ps->course[k].value);	//���δͨ���γ�
				}
			}
			printf("��ѡѧ�֣�%4.1f\t���ѧ�֣�%4.1f\tδͨ��ѧ�֣�%4.1f\n", total_value, value, total_value - value);
			printf("--------------------------------------------------------------------------------");
			ps = ps->next;
		}
		printf("================================================================================");
	}
	else
		printf("����ѧ����Ϣ��\n");
	return;
}

void Stat_Classscore(int grade_class, STUDENT *ps){
	int i, STUcount = 0;
	printf("%d���ѧ����", grade_class);
	if(ps != NULL){
		printf("\n");
		printf("================================================================================");
		while(ps != NULL){//����ѧ������
			if(grade_class == ps->grade_class){	//���ݰ༶��Ϊ��������
				printf("ѧ��:%ld\t", ps->num);
				printf("����:%s\n", ps->name);
				printf("��ѡ�γ��У�");
				if(ps->cAmount > 0){
					printf("�ܹ�ѡ��%d�ſγ�\n", ps->cAmount);
					printf("================================================================================");
					printf("�γ̱��        �γ�����          �ɼ�(ƽʱ/����/����) ���޴��� ���޳ɼ�\n");
					int i;
					for(i = 0; i < ps->cAmount; i++)		//�����ѡ�γ�
						printf("%8ld    %-24.24s   %4.1f/%4.1f/%4.1f        %2d     %4.1f\n", ps->course[i].num, ps->course[i].name, ps->course[i].score[0], ps->course[i].score[1], ps->course[i].score[2], ps->course[i].Isretake, ps->course[i].retake_score);
					printf("--------------------------------------------------------------------------------");
				}
				else{
					printf("����\n");
				}
				STUcount++;
			}
			ps = ps->next;//ָ�����
		}
		printf("================================================================================");
		printf("�ð༶��������%d\n", STUcount);
	}
	else{
		printf("����\n");
		return;
	}
	return;
}

int TEA_Menu()
{
	while(1){
		system("cls");
		printf("��������ǽ�ʦ��\n");
		printf("-------------------\n\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t ��ʦ�������˵���\n");
		printf("\t\t\t ------------------------------------------\n");
		printf("\t\t\t #[1]---¼��ѧ����Ϣ;\n");
		printf("\t\t\t #[2]---���ѧ����Ϣ;\n");
		printf("\t\t\t #[3]---ͳ��ѧ���������ɼ�;\n");
		printf("\t\t\t #[4]---ͳ������ѧ�ּ�������ɼ�;\n");
		printf("\t\t\t #[5]---����ͳ��ѡ����������Գɼ�;\n");
		printf("\t\t\t #[0]---�˳�;\n");
		printf("\t\t\t-------------------------------------------\n");
		printf("ע�⣺Ϊ��֤������ȷ˳�����У�����ذ���ָ��Ҫ���������ݣ�\n");
		printf("-------------------------------------------------------------------\n");
		printf("�����빦��ѡ����Ų���Enter��ȷ�ϣ�");
		long num_C, num_S;
		int i;
		scanf("%d",&i);
		switch(i){
			case 1:
				system("cls");
				Display_COULink(course_ListHead);
				printf("��������Ҫ¼��ɼ��Ŀγ̴��룺");
				scanf("%ld", &num_C);
				printf("��������Ҫ¼���ѧ���ɼ�������'0'Ϊ�γ�ȫ��ѧ��¼��ɼ�����");
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
				printf("��������Ҫͳ�Ƴɼ��Ŀγ̴��룺");
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
				printf("��������Ҫͳ�Ƴɼ��İ༶��");
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
