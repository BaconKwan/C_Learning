#include<stdio.h>
#include<malloc.h>
#include"��ʦ���ܺ���.c"

int teacher()
{
    printf("��������ǽ�ʦ��\n");
    printf("-------------------\n\n");
  while(1)
    {int i=0;
    printf("\t\t\t ------------------------------------------\n");
    printf("\t\t\t ��ʦ�������˵���                          \n");
    printf("\t\t\t ------------------------------------------\n");
    printf("\t\t\t #[1]---���ѧ����Ϣ;                      \n");
    printf("\t\t\t #[2]---¼��ѧ���ɼ�;                      \n");
    printf("\t\t\t #[3]---����ͳ��ѡ������������Գɼ�;      \n");
    printf("\t\t\t #[4]---���γ�ͳ��ѧ�����������Գɼ�;      \n");
    printf("\t\t\t #[5]---ͳ��ѧ������ѧ�ּ�������ɼ�;      \n");
    printf("\t\t\t #[6]---�޸ĵ�½����;                      \n");
    printf("\t\t\t #[0]---�˳�;                              \n");
    printf("\t\t\t-------------------------------------------\n");
    printf("ע�⣺Ϊ��֤������ȷ˳�����У�����ذ���ָ��Ҫ���������ݣ�\n");
    printf("-------------------------------------------------------------------\n");
    printf("�����빦��ѡ����Ų���Enter��ȷ�ϣ�");
    scanf("%d",&i);
    getchar();
    switch(i)
    {
        case 1://H = creatLink();break;
        case 2://h=COU_creatLink();break;
        case 3://Insert_stu(H);break;
        case 4://Delete_stu(H);break;
        case 5://Load_stu(H);break;
        case 6:change_ps1();break;
        case 0:return 1;
        default:break;

    }
    char c;
    printf("#�Ƿ������Y/N��");
    scanf("%s",&c);
    if(c=='Y'||c=='y') continue;
    else break;

  }
}
