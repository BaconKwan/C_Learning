#include<stdio.h>
#include<malloc.h>
#include"Global_declare.h"

STUDENT *creatLink()//�������ȶ�ȡ�ļ���ѧ����Ϣ��Ȼ�����µ�ѧ����Ϣ�����ӵ��Ѵ��ڵ�����β��
{                  //��������ѧ����
	STUDENT *head=NULL, *p1, *p2;
	STUDENT *p,*q;
	FILE *fp /*= fopen("stufile","rb")*/;//��ȡ�ļ���ѧ����Ϣ
	if((fp=fopen("stufile","rb"))==NULL)
	    {
	     printf("can not open file!");
	     //exit(1);
	    }
    p=(struct student *)malloc(LEN_student);
	if(!p)
	    {
	    printf("�ռ����ʧ�ܣ�");
	    return head;
	    }

	head=p;
	q = p;
	while(!feof(fp))//��ȡ�ļ���ѧ����Ϣ
       {
         if(fread(p,LEN_student,1,fp)!=1)
             {
                printf("δ����ѧ����Ϣ��\n");
                break;
             }
         p->next=(STUDENT *)malloc(LEN_student);
         if(!p->next)
	         {
	           printf("�ռ����ʧ�ܣ�");
	         }
         q=p;
         p=p->next;

       }
	q->next=NULL;
	fclose(fp);


	char s;
	q->next=p1 = p2 = (STUDENT *)malloc(LEN_student); //���ѧ����Ϣ������
	p2->next = NULL;
	//head->length = 0;
	    printf("---------------------------------\n");
		printf("������ѧ�ţ�");
        scanf("%ld",&p1->num);
        printf("������������룺");
        scanf("%d",&p1->dor_num);
		printf("������������2~24����ĸ����");
		scanf("%s", p1->name);
		printf("������ѧ���İ༶��");
		scanf("%d",&p1->grade_class);
		printf("��������������գ�");
		scanf("%ld",&p1->birth);
		printf("������绰���룺");
		scanf("%3d%8ld",&p1->tel_Fnum,&p1->tel_Bnum);
		printf("�������Ա�");
		getchar();
		scanf("%c",&p1->sex);
		printf("Ҫ���������𣿣�Y/N��");
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
		printf("������ѧ�ţ�");
        scanf("%ld",&p1->num);
        printf("������������룺");
        scanf("%d",&p1->dor_num);
		printf("������������2~24����ĸ����");
		scanf("%s", p1->name);
		printf("������ѧ���İ༶��");
		scanf("%d",&p1->grade_class);
		printf("��������������գ�");
		scanf("%ld",&p1->birth);
		printf("������绰���룺");
		scanf("%3d%8ld",&p1->tel_Fnum,&p1->tel_Bnum);
		printf("�������Ա�");
		getchar();
		scanf("%c",&p1->sex);
		printf("Ҫ���������𣿣�Y/N��");
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
{              //���������γ̣�
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
		printf("������γ̱�ţ�");
        scanf("%ld",&p1->num);
        printf("������γ����ƣ�");
        scanf("%s",p1->name);
        printf("������γ�ѧ�֣�");getchar();
        scanf("%f",&p1->value);


		printf("Ҫ���������𣿣�Y/N��:");
        getchar();
		scanf("%c", &s);
		if(s == 'N' || s =='n')
		   {
			 break;
           }
	 }
	return head1;
}

Insert_stu(STUDENT *head)                          //����ѧ����Ϣ����
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
      printf("����ռ�ʧ�ܣ�");
    if(p1==NULL) head=r;
    else  p1->next=r;
    printf("-------------------------------------\n");
    printf("���������ѧ����Ϣ��\n");
    printf("������ѧ�ţ�");
    scanf("%ld",&r->num);
    printf("������������룺");
    scanf("%d",&r->dor_num);
    printf("������������2~24����ĸ����");
    scanf("%s", r->name);
    printf("������ѧ���İ༶��");
    scanf("%d",&r->grade_class);
    printf("��������������գ�");
    scanf("%ld",&r->birth);
    printf("������绰���룺");
    scanf("%3d%8ld",&r->tel_Fnum,&r->tel_Bnum);
    printf("�������Ա�");
    getchar();
    scanf("%c",&r->sex);


}

Delete_stu(STUDENT *head)                              //ɾ��ѧ����Ϣ����
{  long i;
   int flog=1;
   printf("������Ҫɾ��ѧ����ѧ�ţ�");
   scanf("%ld",&i);
   struct student *p,*p1;
   p=p1=head;
   while(p!=NULL)
   {
      if(p->num==i)
      {
          if(p==head)//ɾ���ڵ�Ϊͷ���
          {
             head=p->next;
             free(p);
          }
          else
          {
             p1->next=p->next;//ɾ���ڵ�Ϊ��ͨ�ڵ�
             free(p);
          }
          flog=0;
      }
      else
      {
          p1=p;
          p=p->next;//����   p1Ϊp��ǰ���ڵ�
      }
   }

}

Load_stu(STUDENT *head)                                 //���ѧ����Ϣ����
{  int i=0,j=0;
   STUDENT *p;
   p=head;

   if(p!=NULL)
        {  p=p->next;
           i++;
           if(i==1)
            {
              printf("ѧ��  �������    ����\t \t�༶\t����������\t�Ա�\t�绰����\n");
              printf("----------------------------------------------------------------------------\n");
            }
           printf("%ld    %ld \t%s  \t%d   \t%ld\t%c\t%d%ld\n",p->num,p->dor_num,p->name,p->grade_class,p->birth,p->sex,p->tel_Fnum,p->tel_Bnum);
           p=p->next;
        }
    else
           printf("δ�ҵ�ѧ�����ݣ�\n");
}

change_ps()               //�޸����뺯��
{     int i;
      FILE *fp;char s[8];
      struct user *p;
      if((fp=fopen("userfile","rb"))==NULL)
      printf("cannot open file");
      p=(struct user *)malloc(LEN_user);
      fread(p,LEN_user,1,fp);
      while(1)
      {
        printf("�����������룺");
        scanf("%s",s);
        printf("��ȷ�������룺");
        scanf("%s",p->ps);
        if(strcmp(s,p->ps)==0)
          {
           if((fp=fopen("userfile","wb"))==NULL)
              printf("cannot open file");
           i=fwrite(p,LEN_user,1,fp);
           if(i==1)
            {
               printf("��ϲ���������޸ĳɹ���\n");
               break;
            }
           else
            {
               printf("�޸�ʧ�ܣ�\n");
               break;
            }
           }
         else
           {
               printf("�������\n");
               continue;
           }
     }
}

save_stufile(STUDENT *head)   //����ѧ����Ϣ���ļ�stufile
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

save_coufile(struct course *head)//����γ���Ϣ���ļ�coufile
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
main()//���Ժ����������壩
{
    STUDENT *head;
    head = creatLink();
    // COURSE *HEAD;
    // HEAD=COU_creatLink();
    //save_stufile(head);
    Load_stu(head);
}

