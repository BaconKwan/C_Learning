#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>



extern struct dlink //�ṹ�壬���ӱ����ݣ�idΪ�������У��ԼӼ��Ե������У�valueΪ�������ݣ�Ĭ���ԣ�Ϊ���ݷָ����ʹ�������ַ��ָ�
{
    int id;
    char value[50];
    char oval[20];
    struct dlink *dnext;
};

extern struct liblink //������tnameΪ�����ݱ�����lnameΪ��Ӧ���ֶ�����idnoΪ��ǰ�Լ����е�ǰ��¼����dheadΪ��Ӧ������ͷ��ַ
{
    char tname[20];
    char lname[50];
    int idno;
    struct dlink *dhead;
    struct liblink *next;
};

extern struct relink //������������numΪ���ݵ���ţ�ovalueΪ����������ֵ��������ݸ���������valueΪ��Ӧ��������������ֵ
{
    int num;
    char ovalue[10];
    char value[50];
    struct relink *next;
};
//�����ṹ���ʼ��ʱnum��ֵΪ-1�������һ����Ԫ��Ϊ������

/*
struct liblink *libhead;
    struct dlink *dhead;
    ��Ӧ�ṹ��ı�����
*/
    

int count(char str[],char name[],char spchar)
//�����Ӧ�ֶ�������ţ�strΪ����ַ�����nameΪ�����ֶ�����spcharΪ���ݷָ��
{
    int i,n,sum=0;
    char *ps,tstr[50],tname[50];

    strcpy(tstr,str);
    strcpy(tname,name);
    
    ps=strstr(tstr,tname);//����Ӧ�ַ�����λ�ã����ض�Ӧָ���ַ

    if(ps==NULL)
        return sum;

    n=ps-tstr;
    for(i=0;i<=n;i++)
    {
        if(tstr[i]==spchar)
            sum++;
    }    
    return sum;
}

int match(char checkstr[20],int num,char value[20],char spchar)
//����Ӧ��ŵ������������checkstrΪ�����ַ�����numΪ��Ӧ��������֣�valueΪ��ȡ���ַ�����spcharΪ���ݷָ���
{
    int i=0,n=0,brun=0;
    

    while(n!=num)
    {
        if(checkstr[i]==spchar)
            n++;//�ۼƶ�Ӧ�ֶ���ǰ���ֶ���
        i++;
        if((checkstr[i+1]=='-')&&(checkstr[i+2]=='<'))
        {
            brun=0;
            return brun;
        }//"-<"Ϊ���ݽ���������־Ϊ���ݽ������Է�д��ʱ�޷������������Ϣ����־����
    }
    n=0;
    while(checkstr[i]!=spchar)
    {

        if((checkstr[n]=='-')&&(checkstr[n+1]=='<'))
        {
            brun=0;
            return brun;//�ж��Ƿ�Ϊ��¼���ݽ���
        }

        value[n]=checkstr[i];
        i++;
        n++;//��ȡ���ݣ���Ӧ��ֵ
    }
    brun=1;
    return brun;    
}


int chchaint(char str[])
//����Ӧ�ַ���ת��Ϊ����
{
    int i=0,n=0,k=0;

    while (str[i]!='\0')
    {
        i++;
        n++;
     }
    i=0;    
    for(i=0;i<n;i++)
    {
            k=k*10;
      k=k+str[i]-48;
    }
    return k;
}

void garb(char istr[],char ostr[],int n)
//��ȡ��n֮ǰ���ַ���istrΪ�����ַ���ostrΪ����ַ���nΪ������֣���0��ʼ���㣩
{
    int i=0;
    for(i=0;i<=n;i++)
        ostr[i]=istr[i];
    ostr[i++]='\0';
}

void gettname(char istr[],char ostr[])
//��ȡ������istrΪ�������ݣ�ostrΪ�������
{
    int i=0,n=0;
    
    i=6;
    if(istr[i]==':')
    {
        i++;
        while(istr[i]!='\0')
        {
            ostr[n]=istr[i];
            n++;
            i++;
        }
    }
}

int getnum(char tname[])
//��ȡ��Ӧ��������Լ�������
{
    char temp[50];
    int i=0,k=0;

    for(i=0;i<50;i++)
        temp[i]='\0';
    i=0;
    strcpy(temp,tname);
    while(temp[i]!='$')
        i++;
    i++;
    k=i;i=0;
    while(temp[k]!='\0')
    {
        i=i*10;
        i=i+temp[k]-48;
        k++;
    }//��ӦȨ��10����ת�����������
    return i;
}



int openlib(char tlbname[],struct liblink *lhead) //char ftype[],
//�������ݿ⣬ǰ���ʼ������tlbnameΪ��Ӧ���ļ����ļ���������ڱ����ļ�ͬĿ¼�£�lheadΪ����������������Բ�ֲ���Ϊ�ļ������ļ�����������Ӧ����ע���
//�����ж�Ӧ���ļ���������
{
    int i,k,brun=0;
    char checkstr[50]={'\0'},sistr[20]={'\0'},tname[50]={'\0'},lbname[20]={'\0'},temp[10]={'\0'};
    FILE *lib;
    struct liblink *p1=NULL;
    struct dlink *p2=NULL,*p3=NULL;
    
    p1=lhead;
    p1->next=NULL;
    strcpy(lbname,tlbname);
    //strcat(lbname,ftype);
    //�����������ļ�������Ӧ�����������ע�͵Ĳ���
    lib=fopen(lbname,"r");    
    if(lib==NULL)
    {
        brun=-1;
        return brun;
    }//��ȡ��Ӧ���ļ��������ھͳ���

    while(!feof(lib))
    {
        for(i=0;i<50;i++)
            checkstr[i]='\0';
        fscanf(lib,"%s\n",checkstr);
        //ѭ����ȡ���ݣ���ÿ��Ϊ��λ��ȡ
        for(i=0;i<20;i++)
            sistr[i]='\0';
        //��ʼ����Ӧ����

        if(checkstr[0]=='#')
        {
            //��ȡ���ַ�������Ϊ�ṹ���ݺͼ�¼���ݣ�����Ϊ�ṹ���ݣ�|��Ϊ��¼����
            garb(checkstr,sistr,6);
            for(i=0;i<50;i++)
                tname[i]='\0';
            gettname(checkstr,tname);
            /*��ȡ��Ӧ����ַ�������table������Ϊ��ͷ����tbend|����Ϊ��β
            ��Ϊ��ͷ��������Ӧ��ͷ���ݣ���ȡ��������ȡ�Լ���������������Ӧ��Ӧ��¼��������ͷ*/
            if(!strcmp(sistr,"#table:"))
            {            
                strcpy(p1->tname,tname);
                p1->idno=0;
                p1->idno=getnum(p1->tname);//�õ���ǰ��ļ�¼��
                k=0;i=0;
                while(k<20)
                {
                    if(p1->tname[k]=='$')
                        i=1;
                    if(i==1)
                        p1->tname[k]='\0';
                    k++;
                }//��Ǳ�������λ�ã������������ļ�¼������
                fscanf(lib,"%s",p1->lname);
                //���¶�ȡ����ֶ���
                p1->dhead=NULL;
                p2=p1->dhead;
                p3=p2;
                
            }
            else if(!strcmp(sistr,"#tbend|"))
                {
                    /*��Ϊ��β�����ö�Ӧ��һ����ͷ����ʼ��*/
                    if(!feof(lib))//�ж��Ƿ�Ϊ�ļ���������Ϊ�������Ͳ�����
                    {
                        p1->next=(struct liblink *)malloc(sizeof(struct liblink));                    
                        p1=p1->next;
                        p1->next=NULL;
                        p2=p1->dhead;
                    }
                    else
                        p1->next=NULL;
                }

        }
        else if(checkstr[0]=='|')
            {
            /*��Ϊ��¼���ݣ��ڼ�¼���Ͻ��д����ȳ�ʼ��������һ����Ԫ����ȡ��Ӧid�����ͼ�¼��Ӧ���ݶ�*/
                if(p2==NULL)
                {
                    p2=(struct dlink *)malloc(sizeof(struct dlink));//���ټ�¼���ݿռ�
                    p2->id=0;
                    strcpy(p2->value,"");
                    strcpy(p2->oval,"");//��ʼ����Ӧ�ռ�ı���
                    p2->dnext=NULL;
                    if(p3==NULL)
                        p3=p2;//�����һ������Ԫ
                    strcpy(p2->value,"");                    
                    if(p1->dhead==NULL)
                        p1->dhead=p2;//��������ͷ��ֵ���������ݿ��Ķ�Ӧ����λ��                    
                    if(p3!=p2)
                        {
                            p3->dnext=p2;
                            p3=p3->dnext;
                        }//��Ӧָ����λ��Ϊһǰһ���ָ��λ�ã��������                    
                    strcpy(p2->value,checkstr);
                    for(i=0;i<10;i++)
                        temp[i]='\0';
                    match(checkstr,1,temp,'|');    
                    i=0;
                    i=chchaint(temp);
                    p2->id=i;//�����id�ţ�Ϊÿ����¼������
                    
                    p2=p2->dnext;
                }
                
            }
        for(i=0;i<50;i++)
            checkstr[i]='\0';
            //�Լ���ַ��������ظ���ʼ��
    
    }        
    fclose(lib);
    brun=1;
    return brun;
}


int printlib(struct liblink *lhead,char spchar)
//��ӡ��Ӧ������lheadΪ�������ͷ��ַ��spcharΪ���ݷָ������൱�ڱ�����������
{
    int i,lnum,n;
    char oval[10]={'\0'};
    struct liblink *p1;
    struct dlink *p2=NULL;

    if(lhead==NULL)
    {
        printf("No Lib inside!!\n");
        return 0;
    }
    /*������ͷ��ַΪ�գ�����*/

    p1=lhead;

    while(p1!=NULL)
    {
    /*��ȡ��Ķ�Ӧ����*/
        printf("table-> %s\tidno:%d\n",p1->tname,p1->idno);
        printf("\tlinename:%s\n",p1->lname);
        /*��ӡ��Ӧ�����ݱ����Ϣ*/
        if(p1->dhead==NULL)
        {
            printf("\t\tNo data!!\n");
            printf("end table->%s\n\n",p1->tname);
            p1=p1->next;
            continue;
        }
        else
        {
            lnum=0;i=0;//��ʼ����Ӧ�������
            while(p1->lname[i]!='\0')
            {
                if(p1->lname[i]==spchar)
                    lnum++;
                i++;
            }
            lnum--;
            /*�������ֶ���*/
            p2=p1->dhead;
            printf("\t\tdata:\t%d\n",lnum);
            while(p2!=NULL)
            {
                /*�����ļ�¼����*/
                printf("\t\t");
                printf("no.%d\t",p2->id);
                for(i=2;i<=lnum;i++)
                {
                    for(n=0;n<10;n++)
                        oval[n]='\0';
                    match(p2->value,i,oval,'|');
                    printf("%s\t",oval);
                }
                /*ѭ����ӡ��Ӧ�ֶΣ��ӵڶ����ֶο�ʼ����һ����Ϊid��Ϊÿ����¼������*/
                printf("\n");
                //printf("%s\n",p2->value);

                p2=p2->dnext;
            }
            printf("end table->%s\n\n",p1->tname);
            /*������Ӧ�ļ�¼���ݴ�ӡ*/
        }
        p1=p1->next;
        /*ָ������*/
    }
    return 1;
}

int updata(struct liblink *lib,char tname[],char lname[],int id,char newval[],char spchar)
/*���¶�Ӧ���ֶ����ݣ�libΪ��Ӧ�����ݱ�tnameΪ��Ӧ������lnameΪ��Ӧ�ֶ�����idΪ��Ӧ��¼��id����newvalΪ��Ӧ���µ�ֵ��spcharΪ���ݷָ���*/
{
    int i,j,k,q,brun=0,done=0;
    char temp[50],nvaltmp[50],lnametmp[50];
    struct liblink *ptable;
    struct dlink *pdata;

    ptable=lib;
    pdata=NULL;
    strcpy(nvaltmp,newval);
    strcpy(lnametmp,lname);
 /*��ʼ����Ӧ����*/
    if(lib==NULL)
    {
        brun=0;
        return brun;
    }
/*�жϿ�����ͷ��ַΪ�գ�����*/
    while(ptable!=NULL)
    {
        if(!strcmp(ptable->tname,tname))
        /*�ж����Ӧ�����Ƿ����*/
        {
            pdata=ptable->dhead;
            if(pdata==NULL)
            {
                brun=-1;
                return brun;
            }
            while(pdata!=NULL)
            {
                /*������Ӧ��¼����*/
                done=0;
                if(pdata->id==id)
                {
                    /*��λ��Ӧid����*/
                    for(i=0;i<50;i++)
                        temp[i]='\0';
                    i=0;
                    i=count(ptable->lname,lnametmp,spchar);    
                    /*�����Ӧ�ֶε�λ��*/        
                    j=0;k=0;
                    while(pdata->value[j]!='\0'&&k!=i)
                    {
                        if(pdata->value[j]==spchar)
                            k++;
                        temp[j]=pdata->value[j];
                        j++;
                    }
                    /*��ȡ��Ӧ�ֶ�֮ǰ������*/            
                    k=0;                    
                    while(nvaltmp[k]!='\0'&&j<50&&k<50)
                    {
                        temp[j]=nvaltmp[k];                        
                        j++;
                        k++;
                    }    
                    /*��Ӷ�Ӧ��������*/                
                    i++;k=0;q=0;
                    while(pdata->value[k]!='\0'&&q!=i)
                    {
                        if(pdata->value[k]==spchar)
                            q++;
                        k++;
                    }
                    k--;                    
                    while(pdata->value[k]!='\0'&&k<50)
                    {
                        temp[j]=pdata->value[k];
                        j++;
                        k++;
                    }
                    /*���ʣ�µ�����*/                    
                    for(i=0;i<50;i++)
                        pdata->value[i]='\0';                    
                    strcpy(pdata->value,temp);
                    /*����������*/
                    done=1;                    
                }
                if(done==1)
                    break;
                pdata=pdata->dnext;
                /*�жϽ�����ָ�����¸��ڵ��ƶ�*/
            }
        }
        if(done==1)
            break;
        ptable=ptable->next;
    }
    if(done==1)
    {
        brun=1;
        return brun;
    }
    else
    {
        brun=-1;
        return brun;
    }
}

int addre(struct liblink *tlibhead,char tbname[],char tvalue[])
/*����µ����ݣ�tlibheadΪ��Ӧ�Ŀ�����ͷ��ַ��tbnameΪ��Ӧ��ӵı�����tvalueΪ��Ӧ��ӵ������ݣ�ע���Ӧ����Ӧ�ð����ֶ�������������磺|asd|000|dfg|000|-<*/
{
    char tname[10],value[50],avalue[50]="",no[20]="";
    int i,k,m,n,done=0,brun=0;
    struct liblink *libhead,*ptable;
    struct dlink *pdata;

    libhead=tlibhead;
    ptable=libhead;
    pdata=NULL;
    strcpy(tname,tbname);
    strcpy(value,tvalue);
    /*��Ӧ���ݳ�ʼ��*/

    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }
    /*�ж�ͷ��ַ��Ϊ�ձ���*/
    while(ptable!=NULL)
    {
        if(!strcmp(ptable->tname,tname))
            /*���������ṹ���ݣ���λ��Ӧ�ı�*/
        {
            

            done=0;
            i=ptable->idno;
            k=0;
            avalue[k]='|';
            i++;n=0;
            while(i>0)
            {
                no[n]=i%10+48;
                i=i/10;
                n++;
            }
            /*���Լ����б���ַ������ֽ����ֵ�������ַ�����Ϊ��Ӧ����no*/    
            k++;n--;
            while(n!=-1)
            {
                avalue[k]=no[n];
                k++;
                n--;
            }/*�ٽ����鵹���Ž�avalue����*/
            strcat(avalue,value);
            /*�������ݣ���ӽ�����ӵ�����*/
            pdata=ptable->dhead;
            //��λ��Ӧ������ͷ
            if(pdata==NULL)
            {
                pdata=(struct dlink *)malloc(sizeof(struct dlink));
                pdata->id=++ptable->idno;
                pdata->dnext=NULL;
                strcpy(pdata->value,avalue);
                ptable->dhead=pdata;
                done=1;
                brun=1;
                return brun;
            }
            /*��Ϊͷ����ֱ�����*/
            while(pdata->dnext!=NULL)
                pdata=pdata->dnext;
                /*��λ��β��*/
            pdata->dnext=(struct dlink *)malloc(sizeof(struct dlink));
            pdata=pdata->dnext;
            ptable->idno++;
            pdata->id=ptable->idno;
            pdata->dnext=NULL;
            strcpy(pdata->value,avalue);
            brun=1;
            done=1;
            /*��β�����*/
        }
        if(done==1)
            break;
        ptable=ptable->next;
    }
    brun=1;
    return brun;
}

int delre(struct liblink *tlibhead,char tbname[],int tid)
/*ɾ����Ӧ�ļ�¼��tlibhead�����Ŀ⣬tbnameΪ��Ӧ�ı�����tidΪɾ���ļ�¼��Ӧ��id�ţ�idΪ��Ӧ��¼������*/
{
    int done=0,id,brun=0;
    char tname[50];
    struct liblink *libhead;
    struct dlink *pdata,*p1,*p2;

    libhead=tlibhead;
    strcpy(tname,tbname);
    id=tid;
/*��ʼ����Ӧ�ı���*/
    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }
    while(libhead!=NULL)
    {
        if(!strcmp(libhead->tname,tname))
            /*������Ӧ�ı�����Ѱ�Ҷ�Ӧ�ı�*/
        {
            pdata=libhead->dhead;
            if(pdata==NULL)
            {
                brun=-1;
                return brun;
            }
            /*��Ӧ���в��������ݣ������˳�*/
            done=0;
            p1=pdata;
            p2=pdata;
            /*ǰ��˫ָ����б�����Ѱ�ҵ���Ӧid���߽���ʱ����ѭ��*/
            while(p1!=NULL&&p1->id!=id)
            {
                p2=p1;
                p1=p1->dnext;
            }
            if(p1==NULL)
            {
                brun=-1;
                return brun;
            }
            /*�ж��Ƿ�ΪNULL����Ϊ����β��������*/
            if(p1==p2)
            {
                libhead->dhead=pdata->dnext;
                brun=1;
                return brun;
            }
            /*�ж��Ƿ�Ϊ����ͷ������ֱ�Ӷ�ͷָ�루dhead�����и���*/
            p2->dnext=p1->dnext;
            free(p1);
            done=1;
            /*Ϊ�����в�������ɾ��*/
        }
        if(done==1)
        {
            brun=1;
            return brun;
        }
        libhead=libhead->next;
    }
    return brun;
}

int droptb(struct liblink *tlibhead,char tbname[])
/*ɾ����Ӧ�����ݱ�tlibheadΪ��Ӧ���ͷ��ַ��tbnameΪ��Ӧɾ���ı���*/
{
    int brun=0,done=0;
    char tname[50];
    struct liblink *libhead,*flibhead;
    struct dlink *pdata,*p1,*p2;
 
    strcpy(tname,tbname);
    libhead=tlibhead;
    flibhead=tlibhead;
    /*��ʼ����Ӧ�ı���*/

    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }
    /*�ⲻ���ڣ���������*/
    while(libhead!=NULL)
    {        
        if(!strcmp(libhead->tname,tname))
            /*�����⣬Ѱ�Ҷ�Ӧ�ı�*/
        {
            pdata=libhead->dhead;
            p1=pdata;
            p2=pdata;
            /*��ֵ��Ӧ���ݣ���ɾ�����ݣ���ɾ�������ٴ���ռ�*/

            while(pdata->dnext!=NULL&&pdata!=NULL)
            {
                p1=pdata;
                p2=pdata;
                while(p1->dnext!=NULL)
                {                
                    p2=p1;
                    p1=p1->dnext;
                }
                //��λָ�뵽β������ɾ��
                free(p1);
                p2->dnext=NULL;
            }
            free(libhead->dhead);
            libhead->dhead=NULL;
            //ɾ����Ӧ��Ľڵ�����
            if(flibhead==libhead)
            {        
                libhead=libhead->next;                
                brun=-2;
                return brun;
            }
            /*��ӦΪ��ͷ��ַ���ھֲ����������޷����и���,����-2��ʾʶ��*/
            else
            {
                flibhead->next=libhead->next;
                free(libhead);
            }
            done=1;
        }
        if(done==1)
        {
            brun=1;
            return brun;
        }
        flibhead=libhead;
        libhead=libhead->next;
    }
}

int creattb(struct liblink *tlibhead,char tbname[],char tlname[])
/*������tlibheadΪ��Ӧ�Ŀ�ͷ��ַ��tnameΪ������tlnameΪ��Ӧ���ֶ������ֶ��������ݸ�ʽ��ͬ���ö�Ӧ�ķָ����ָ�*/
{
    int brun=0,done=0;
    char tname[20],lname[50]="|id";
    struct liblink *libhead,*p1,*p2;
    struct dlink *pdata;

    libhead=tlibhead;
    p1=libhead;
    strcpy(tname,tbname);
    strcat(lname,tlname);
    pdata=NULL;
    //��ʼ����Ӧ�ı���

    if(p1==NULL)//�жϿ�ͷ��ַ���Ƿ�ΪNULL��ΪNULL�Ļ�ֱ����Ӷ�Ӧ�ı�
    {
        p1=(struct liblink *)malloc(sizeof(struct liblink));
        strcpy(p1->tname,tname);
        strcpy(p1->lname,lname);
        p1->idno=0;
        p1->next=NULL;
        p1->dhead=NULL;
        brun=1;
        return brun;
    }
    while(p1!=NULL)
    {
        p2=p1;
        if(!strcmp(p1->tname,tname))
            {
                brun=-1;
                return brun;
            }            
        p1=p1->next;
    }
    /*�������β����������ӣ������ظ��Ļ���ֱ���������أ�1*/    
    p1=(struct liblink *)malloc(sizeof(struct liblink));
    strcpy(p1->tname,tname);
    strcpy(p1->lname,lname);
    p1->idno=0;
    p1->next=NULL;
    p1->dhead=NULL;
    p2->next=p1;
    brun=1;
    return brun;
}

int search(struct liblink *tlibhead,char tbname[],char tlname[],char value[],int oint,char tolname[],struct relink *stlink,char spchar)
/*����������tlibhead��Ӧ�Ŀ�����tbnameΪ��Ӧ�����ı�����tlnameΪ��Ӧƥ����ֶ�����valueΪ��Ӧ���ֶ�ƥ���ֵ��ointΪ�Ƿ�������жϷ�1Ϊ����0Ϊ��������tolnameΪ������ֶΣ�stlinkΪ�������ص�����spcharΪ���ݷָ���*/
{
    int i,k,n,brun=0,done=0;
    char tname[20],lname[50],olname[20],temp[50];
    struct liblink *libhead;
    struct relink *slink;
    struct dlink *p1,*p2;

    libhead=tlibhead;
    strcpy(tname,tbname);
    strcpy(lname,tlname);
    slink=NULL;
    slink=stlink;
//��ʼ����Ӧ�ı���
    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }//��Ӧ��ͷ��ַΪ�գ���������
    while(libhead!=NULL)
    {
        if(!strcmp(libhead->tname,tname))//����⣬������Ӧ�ı�
        {
            p1=libhead->dhead;
            p2=p1;
            if(p1==NULL)
            {
                brun=-1;
                return brun;
            }//��Ӧ��ͷ��ַ����
            i=count(libhead->lname,lname,spchar);//�ó���Ӧ���ֶε����
            while(p1!=NULL)
            {
                for(n=0;n<50;n++)
                    temp[n]='\0';//��ʼ����ʱ����
                match(p1->value,i,temp,spchar);//��ȡ��Ӧ�ֶ�ֵ���бȽ�
                if(!strcmp(temp,value))//��ȡ���������
                {                
                    if(slink->num==-1)//��־�����������һ����Ԫû��ʹ�ã���ʼ����ʱ��Ҫ��num�ĳ�Ա��ֵΪ��1
                    {
                        strcpy(slink->value,p1->value);
                        slink->num=p1->id;
                        if(oint==1)//��ȡ����������и�ֵ
                        {
                            for(n=0;n<50;n++)
                                temp[n]='\0';
                            k=count(libhead->lname,olname,spchar);
                            match(p1->value,k,temp,spchar);
                            strcpy(slink->ovalue,temp);
                        }
                        else
                        {
                            for(n=0;n<50;n++)
                                temp[n]='\0';
                            k=count(libhead->lname,"id",spchar);
                            match(p1->value,k,temp,spchar);
                            strcpy(slink->ovalue,temp);
                        }
                        slink->next=NULL;
                    }
                    else
                    {
                        slink->next=(struct relink *)malloc(sizeof(struct relink));
                        slink=slink->next;
                        strcpy(slink->value,p1->value);
                        slink->num=p1->id;
                        if(oint==1)
                        {
                            for(k=0;k<50;k++)
                                temp[k]='\0';
                            k=count(libhead->lname,olname,spchar);
                            match(p1->value,k,temp,spchar);
                            strcpy(slink->ovalue,temp);
                        }
                        else
                        {
                            for(k=0;k<50;k++)
                                temp[k]='\0';
                            k=count(libhead->lname,"id",spchar);
                            match(p1->value,k,temp,spchar);
                            strcpy(slink->ovalue,temp);
                        }
                        slink->next=NULL;//β������ֵ
                    }
                }
                p1=p1->dnext;
            }
            done=1;
        }
        if(done==1)
        {
            brun=1;
            return brun;//�ж��˳�
        }
        libhead=libhead->next;//������һ��������ֻ������һ���������
    }
}

int savelib(char tfname[],struct liblink *tlibhead)//char ftype[]
/*�������ݣ�����Ӧ�Ŀ�����д��Ӳ�̣�tfnameΪ������ļ�����libheadΪ��Ӧ�Ŀ�ͷ��ַ��ftype��ע�Ͳ�������ӦΪ�ϳ��ļ������ֿ�Ϊ�ļ����ͺ�����*/
{
    int i,brun=0;
    char fname[50]={'\0'};
    struct liblink *libhead;
    struct dlink *pdata;
    FILE *lib;

    for(i=0;i<50;i++)
        fname[i]='\0';
    strcpy(fname,tfname);
    //strcat(fname,ftype);//��Ӧ����ע�͵��ļ����ͺ�����������
    lib=NULL;
    lib=fopen(fname,"w");
    if(lib==NULL)
    {
        brun=0;
        return brun;
    }//���ļ������˳�
    libhead=tlibhead;
    pdata=NULL;
    //��ʼ����Ӧ�ı���
    if(libhead==NULL)
    {
        brun=0;
        fclose(lib);
        return brun;
    }
    //���ݿⲻ�������ݣ�����
    while(libhead!=NULL)//��ʼд������
    {    
        fprintf(lib,"#table:%s$%d\n",libhead->tname,libhead->idno);
        fprintf(lib,"%s\n",libhead->lname);
        pdata=libhead->dhead;
        if(pdata==NULL)
        {
            fprintf(lib,"#tbend|%s\n",libhead->tname);
            libhead=libhead->next;
            continue;
        }//ѭ��continue��������Ϊ�յĻ�����ѭ����
        while(pdata!=NULL)//д�������
        {
            fprintf(lib,"%s\n",pdata->value);
            pdata=pdata->dnext;
        }
        fprintf(lib,"#tbend|%s\n",libhead->tname);
        libhead=libhead->next;
    }
    fclose(lib);
    brun=1;
    return brun;
    //�ر��ļ������سɹ�ֵ������
}

int creatlib(char tlibname[])
/*���������ݣ�tlibnameΪ��Ӧ���������ݿ���Ψһ����Ӧ�ļ�������¼�������ļ�list.list��*/
{
    int i,brun=0,have=0;
    char libname[50]="",fname[50]="",wstr[100]="",instr[100]="",temp[100]="";
    FILE *ind,*fp;
    struct inlink
    {
        char name[50];
        char fname[50];
        struct inlink *next;
    }*ihead,*p1,*p2;//��������������ȡ���ݿ��¼����ֹ�����ظ����ݿ�

    ihead=(struct inlink *)malloc(sizeof(struct inlink));
    p1=ihead;
    p2=ihead;
    strcpy(libname,tlibname);
    strcpy(fname,"lib_");
    strcat(fname,libname);
    strcat(fname,".lib");
    //���ݿ���Ϊfname��������д������ļ�����������Ҫ���Ծ��и���
    ind=fopen("list.list","r");//��ȡ�����ļ�
    if(ind==NULL)//ΪNULL�Ļ����д����ļ�
    {
        ind=fopen("list.list","w");
        if(ind==NULL)
        {
            brun=-1;            
            return brun;
        }
        strcpy(wstr,"|");
        strcat(wstr,libname);
        strcat(wstr,"|");
        strcat(wstr,fname);
        strcat(wstr,"|-<");
        fprintf(ind,"%s\n",wstr);
        fclose(ind);
        fp=fopen(fname,"w");
        fclose(fp);
        brun=1;
        return brun;//д�����ݿ������ļ�����ʽΪ:|���ݿ���|���ݿ��Ӧ�ļ���|-<
    }
    while(!feof(ind))//���������ݿ⣬�������ݿ�������ų��ظ���
    {
        p2=p1;
        for(i=0;i<100;i++)
            instr[i]='\0';
        fscanf(ind,"%s\n",instr);
        for(i=0;i<50;i++)
            temp[i]='\0';
        for(i=0;i<50;i++)
            p1->name[i]='\0';
            //��ʼ����Ӧ�ı���
        match(instr,1,temp,'|');
        strcpy(p1->name,temp);
        for(i=0;i<50;i++)
            temp[i]='\0';
        match(instr,2,temp,'|');
        strcpy(p1->fname,temp);
        p1->next=(struct inlink *)malloc(sizeof(struct inlink));
        p1=p1->next;
        strcpy(p1->name,"NULLUnit");//���һ����Ԫ��NULLֵ
        p1->next=NULL;
    }
    if(!strcmp(p1->name,"NULLUnit"))//�ж����ĵ�Ԫ��ΪNULL�Ļ�����ɾ����������������
        p2->next=NULL;
    p1=ihead;
    fclose(ind);
    have=0;
    while(p1!=NULL)
    //�������ݵı����������ظ����������������ض�Ӧ�ı�־
    {
        if(!strcmp(p1->name,libname))
        {
            have=1;
            break;
        }
        p1=p1->next;
    }
    if(have==1)
    {
        brun=-2;
        return brun;
    }
    ind=fopen("list.list","a");//��û�г����ظ���������ļ�����β������½������ݿ���
    if(ind==NULL)
    {
        brun=0;
        return brun;
    }
    strcpy(wstr,"|");
    strcat(wstr,libname);
    strcat(wstr,"|");
    strcat(wstr,fname);
    strcat(wstr,"|-<");
    fprintf(ind,"%s\n",wstr);
    fclose(ind);
    fp=fopen(fname,"w");
    fclose(fp);    
    brun=1;
    return brun;
}

int printtb(struct liblink *thead,char ttname[],int olnum,char spchar)
/*��ӡ�ض����ݱ�theadΪ���ڿ�ͷ��ַ��ttnameΪ��Ҫ��ӡ�ı�olnumΪ��Ӧ�Ĳ�������olnumΪ0��Ϊ��ӡȫ���ֶΣ�Ϊ������Ϊ��ӡ����Ӧ���ֶ����Ϊֹ��spcharΪ��Ӧ�ķָ���*/
{
    int i,n,k,brun=0;
    char tname[50]={'\0'},temp[50]={'\0'};
    struct liblink *head;
    struct dlink *pdata;
    
    strcpy(tname,ttname);
    head=thead;
    pdata=NULL;

    if(head==NULL)
    {
        brun=-1;
        return brun;
    }//��ͷ��ַ��������
    while(head!=NULL)//���ж�Ӧ�ı����ݶ�λ
    {
        if(!strcmp(head->tname,tname))
        {
            pdata=head->dhead;
            break;
        }
        head=head->next;
    }
    if(pdata==NULL)
    {
        brun=-2;
        return brun;
    }
    n=0;
    if(olnum==0)//�Բ��������д���
    {
        for(i=0;i<50;i++)
            {
                if(head->lname[i]==spchar)
                    n++;
            }
        n--;
    }
    else
        n=olnum+1;
    printf("Data in table: %s\n",head->tname);
    while(pdata!=NULL)//���ж�Ӧ��Ĵ�ӡ��
    {        
    
        printf("\tNO.%d",pdata->id);
        for(i=2;i<=n;i++)
        {
            for(k=0;k<50;k++)
                temp[k]='\0';
            match(pdata->value,i,temp,spchar);
            printf("\t%s",temp);
            
        }
        printf("\n");
        pdata=pdata->dnext;
    }
    printf("End of table:%s\n",head->tname);
    brun=1;
    return brun;
}


int prilibindex(int opi)
/*��ӡ�����ļ���opiΪ��������1Ϊֻ��ӡ���ڵĿ�����0Ϊ��ӡȫ�����ݣ��������ݿ�Ͷ�Ӧ���ļ���*/
{
    int i,brun=0;
    char indstr[100]="",ostr[100]="";
    FILE *ind;

    ind=fopen("list.list","r");
    if(ind==NULL)
    {
        printf("No index files!please creat a libreary firstly!");
        brun=-1;
        return brun;
    }//���������ݿ������ļ�
    if(opi==1)//�ֱ�Բ��������в���
    {
        for(i=0;i<100;i++)
                indstr[i]='\0';
        printf("list the index file:\n");
        while(!feof(ind))
        {
            fscanf(ind,"%s\n",indstr);
            for(i=0;i<100;i++)
                ostr[i]='\0';
            match(indstr,1,ostr,'|');
            if(!strcmp(ostr,"admin"))
                continue;
            printf("\tlibreary name:%s\n",ostr);
            for(i=0;i<100;i++)
                indstr[i]='\0';
        }
        brun=1;
        return brun;
    }
    if(opi==0)
    {
        for(i=0;i<100;i++)
                indstr[i]='\0';
        printf("list the index file:\n");
        while(!feof(ind))
        {
            fscanf(ind,"%s\n",indstr);
            for(i=0;i<100;i++)
                ostr[i]='\0';
            match(indstr,1,ostr,'|');
            printf("\tlibreary name:%s",ostr);
            for(i=0;i<100;i++)
                ostr[i]='\0';
            match(indstr,2,ostr,'|');
            printf("\t%s (file name)\n",ostr);
            for(i=0;i<100;i++)
                indstr[i]='\0';
        }
        brun=1;
        return brun;
    }//���������������0����
    brun=0;
    return brun;
}


int dellib(char dlibname[])
/*ɾ����Ӧ�����ݿ⣬dlibnameΪ��Ӧ�Ŀ���*/
{
    int i,brun=0;
    char libname[50],instr[100]="",temp[50]="";
    FILE *ind;
    struct inlink
    {
        char name[50];
        char fname[50];
        struct inlink *next;
    }*ihead,*p1,*p2;
    
    strcpy(libname,dlibname);
    ind=fopen("list.list","r");
    if(ind==NULL)
        {
            brun=-1;
            return brun;
        }
    ihead=(struct inlink *)malloc(sizeof(struct inlink));
    p1=ihead;
    p2=ihead;
    while(!feof(ind))
    {
        p2=p1;
        fscanf(ind,"%s\n",instr);
        match(instr,1,temp,'|');
        strcpy(p1->name,temp);
        for(i=0;i<50;i++)
            temp[i]='\0';
        match(instr,2,temp,'|');
        strcpy(p1->fname,temp);
        p1->next=(struct inlink *)malloc(sizeof(struct inlink));
        p1=p1->next;
        strcpy(p1->name,"NULLUnit");
        p1->next=NULL;
    }
    if(!strcmp(p1->name,"NULLUnit"))
        p2->next=NULL;
    /*��ȡ�����ļ���������Ӧ������*/
    p1=ihead;
    p2=ihead;
    while(p1!=NULL)//�������ݵı���
    {
        if(!strcmp(p1->name,libname))//��������ݿ����Ľ���ɾ��
        {
            if(p2==p1)
            {
                ihead=ihead->next;
                brun=1;
                break;
            }
            p2->next=p1->next;
            free(p1);
            brun=1;
            break;
        }
        p2=p1;
        p1=p1->next;
    }
    if(brun==0)
    {
        printf("no delete lib!");
        return brun;
    }//��������ڶ�Ӧ�Ŀ⣬ֱ�ӷ���
    ind=fopen("list.list","w");//ɾ��������д�������ļ�
    p1=ihead;
    while(p1!=NULL)
    {
        for(i=0;i<100;i++)
            instr[i]='\0';
        strcpy(instr,"|");
        strcat(instr,p1->name);
        strcat(instr,"|");
        strcat(instr,p1->fname);
        strcat(instr,"|-<");
        fprintf(ind,"%s\n",instr);
        p1=p1->next;
    }
    fclose(ind);
    return brun;
}

int chosel(char tsname[],char toname[])
/*ѡ���Ӧ�����ݿ⣬tsnameΪѡ������ݿ�����tonameΪ��Ӧ��������ݿ��ļ���*/
{
    int i,brun=0;
    char sname[50]="",oname[50],str[100],temp[50];
    FILE *ind;
    struct ilink
    {
      char lname[50];
      char fname[50];
      struct ilink *next;
    }*ihead,*p1,*p2;
    
    for(i=0;i<50;i++)
        toname[i]='\0';    
    for(i=0;i<50;i++)
            sname[i]='\0';
    for(i=0;i<50;i++)
            oname[i]='\0';
    for(i=0;i<50;i++)
            temp[i]='\0';
    for(i=0;i<100;i++)
            str[i]='\0';
    ihead=(struct ilink *)malloc(sizeof(struct ilink));
    strcpy(sname,tsname);
    ind=fopen("list.list","r");
    
    if(ind==NULL)
    {
        brun=-1;
        return brun;
    }
    p1=ihead;
    p2=ihead;
    while(!feof(ind))
    {
        for(i=0;i<100;i++)
            str[i]='\0';
        fscanf(ind,"%s\n",str);        
        for(i=0;i<50;i++)
            temp[i]='\0';
        match(str,1,temp,'|');
        strcpy(p1->lname,temp);
        for(i=0;i<50;i++)
            temp[i]='\0';
        match(str,2,temp,'|');
        strcpy(p1->fname,temp);
        p2=p1;
        p1->next=(struct ilink *)malloc(sizeof(struct ilink));
        p1=p1->next;
        strcpy(p1->lname,"NULLUnit");
        p1->next=NULL;
    }
    if(!strcmp(p1->lname,"NULLUnit"))
    {
        p2->next=NULL;
        free(p1);
    }
    fclose(ind);
    //��ȡ�����ļ���������Ӧ������
    p1=ihead;
    if(ihead==NULL)
    {
        brun=-1;
        return brun;
    }
    brun=0;
    while(p1!=NULL)//����������ȡ��Ӧ�Ŀ���
    {
        if(!strcmp(p1->lname,sname))
        {
            strcpy(toname,p1->fname);//����ֵ
            brun=1;
            return brun;
        }
        p1=p1->next;
    }
    if(brun==0)//�������ڣ����������и���ֵ
    {
        for(i=0;i<50;i++)
            oname[i]='\0';        
    }
    return brun;
}