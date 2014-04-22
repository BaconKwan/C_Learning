#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>



extern struct dlink //结构体，链接表数据，id为数据序列，自加加性递增序列，value为数据内容，默认以｜为数据分割，可以使用其他字符分隔
{
    int id;
    char value[50];
    char oval[20];
    struct dlink *dnext;
};

extern struct liblink //库链表，tname为表数据表名，lname为对应的字段名，idno为当前自加序列当前记录数，dhead为对应表数据头地址
{
    char tname[20];
    char lname[50];
    int idno;
    struct dlink *dhead;
    struct liblink *next;
};

extern struct relink //搜索数据链表，num为数据的序号，ovalue为数据排序数值，排序根据该数据排序，value为对应搜索出来的数据值
{
    int num;
    char ovalue[10];
    char value[50];
    struct relink *next;
};
//搜索结构体初始化时num的值为-1，否则第一个单元会为空数据

/*
struct liblink *libhead;
    struct dlink *dhead;
    对应结构体的变量名
*/
    

int count(char str[],char name[],char spchar)
//计算对应字段名的序号，str为检测字符串，name为计算字段名，spchar为数据分割号
{
    int i,n,sum=0;
    char *ps,tstr[50],tname[50];

    strcpy(tstr,str);
    strcpy(tname,name);
    
    ps=strstr(tstr,tname);//检测对应字符串的位置，返回对应指针地址

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
//将对应序号的数据提出来，checkstr为检测的字符串，num为对应的序号数字，value为提取的字符串，spchar为数据分隔符
{
    int i=0,n=0,brun=0;
    

    while(n!=num)
    {
        if(checkstr[i]==spchar)
            n++;//累计对应字段名前的字段数
        i++;
        if((checkstr[i+1]=='-')&&(checkstr[i+2]=='<'))
        {
            brun=0;
            return brun;
        }//"-<"为数据结束符，标志为数据结束，以防写入时无法擦除后面的信息，标志结束
    }
    n=0;
    while(checkstr[i]!=spchar)
    {

        if((checkstr[n]=='-')&&(checkstr[n+1]=='<'))
        {
            brun=0;
            return brun;//判断是否为记录数据结束
        }

        value[n]=checkstr[i];
        i++;
        n++;//提取数据，对应赋值
    }
    brun=1;
    return brun;    
}


int chchaint(char str[])
//将对应字符串转换为数字
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
//提取从n之前的字符，istr为输入字符，ostr为输出字符，n为标记数字（从0开始计算）
{
    int i=0;
    for(i=0;i<=n;i++)
        ostr[i]=istr[i];
    ostr[i++]='\0';
}

void gettname(char istr[],char ostr[])
//提取表名，istr为输入数据，ostr为输出数据
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
//读取对应表名后的自加序列数
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
    }//对应权重10进行转化，变成整型
    return i;
}



int openlib(char tlbname[],struct liblink *lhead) //char ftype[],
//建立数据库，前提初始化链表，tlbname为对应库文件的文件，其必须在编译文件同目录下，lhead为建立输出的链表，可以拆分参数为文件名和文件后序名（对应上面注释项）
//下面有对应的文件名连接项
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
    //上面是连接文件名；对应函数名后面的注释的参数
    lib=fopen(lbname,"r");    
    if(lib==NULL)
    {
        brun=-1;
        return brun;
    }//读取对应库文件，不存在就出错

    while(!feof(lib))
    {
        for(i=0;i<50;i++)
            checkstr[i]='\0';
        fscanf(lib,"%s\n",checkstr);
        //循环读取数据，以每行为单位读取
        for(i=0;i<20;i++)
            sistr[i]='\0';
        //初始化对应变量

        if(checkstr[0]=='#')
        {
            //读取首字符，区别为结构数据和记录数据，＃号为结构数据，|号为记录数据
            garb(checkstr,sistr,6);
            for(i=0;i<50;i++)
                tname[i]='\0';
            gettname(checkstr,tname);
            /*提取对应标记字符串，＃table：区分为表头，＃tbend|区分为表尾
            若为表头，建立对应表头数据，提取表名，提取自加序列数，建立对应对应记录数据链表头*/
            if(!strcmp(sistr,"#table:"))
            {            
                strcpy(p1->tname,tname);
                p1->idno=0;
                p1->idno=getnum(p1->tname);//得到当前表的记录数
                k=0;i=0;
                while(k<20)
                {
                    if(p1->tname[k]=='$')
                        i=1;
                    if(i==1)
                        p1->tname[k]='\0';
                    k++;
                }//标记表名结束位置，并且清除后面的记录数数据
                fscanf(lib,"%s",p1->lname);
                //向下读取表的字段名
                p1->dhead=NULL;
                p2=p1->dhead;
                p3=p2;
                
            }
            else if(!strcmp(sistr,"#tbend|"))
                {
                    /*若为表尾，设置对应下一个表头并初始化*/
                    if(!feof(lib))//判断是否为文件结束，若为结束，就不创建
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
            /*若为记录数据，在记录表上进行处理，先初始化链表下一个单元，提取对应id名，和记录对应数据段*/
                if(p2==NULL)
                {
                    p2=(struct dlink *)malloc(sizeof(struct dlink));//开辟记录数据空间
                    p2->id=0;
                    strcpy(p2->value,"");
                    strcpy(p2->oval,"");//初始化对应空间的变量
                    p2->dnext=NULL;
                    if(p3==NULL)
                        p3=p2;//标记上一个链表单元
                    strcpy(p2->value,"");                    
                    if(p1->dhead==NULL)
                        p1->dhead=p2;//数据链表头赋值，给回数据库表的对应变量位置                    
                    if(p3!=p2)
                        {
                            p3->dnext=p2;
                            p3=p3->dnext;
                        }//对应指针移位，为一前一后的指针位置，标记连接                    
                    strcpy(p2->value,checkstr);
                    for(i=0;i<10;i++)
                        temp[i]='\0';
                    match(checkstr,1,temp,'|');    
                    i=0;
                    i=chchaint(temp);
                    p2->id=i;//分离出id号，为每条记录的主键
                    
                    p2=p2->dnext;
                }
                
            }
        for(i=0;i<50;i++)
            checkstr[i]='\0';
            //对检测字符串进行重复初始化
    
    }        
    fclose(lib);
    brun=1;
    return brun;
}


int printlib(struct liblink *lhead,char spchar)
//打印对应库链表，lhead为库链表的头地址，spchar为数据分隔符，相当于遍历整个链表
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
    /*库链表头地址为空，报错*/

    p1=lhead;

    while(p1!=NULL)
    {
    /*读取表的对应数据*/
        printf("table-> %s\tidno:%d\n",p1->tname,p1->idno);
        printf("\tlinename:%s\n",p1->lname);
        /*打印对应的数据表的信息*/
        if(p1->dhead==NULL)
        {
            printf("\t\tNo data!!\n");
            printf("end table->%s\n\n",p1->tname);
            p1=p1->next;
            continue;
        }
        else
        {
            lnum=0;i=0;//初始化对应所需变量
            while(p1->lname[i]!='\0')
            {
                if(p1->lname[i]==spchar)
                    lnum++;
                i++;
            }
            lnum--;
            /*计算总字段数*/
            p2=p1->dhead;
            printf("\t\tdata:\t%d\n",lnum);
            while(p2!=NULL)
            {
                /*进入表的记录数据*/
                printf("\t\t");
                printf("no.%d\t",p2->id);
                for(i=2;i<=lnum;i++)
                {
                    for(n=0;n<10;n++)
                        oval[n]='\0';
                    match(p2->value,i,oval,'|');
                    printf("%s\t",oval);
                }
                /*循环打印对应字段，从第二个字段开始，第一个都为id，为每条记录的主键*/
                printf("\n");
                //printf("%s\n",p2->value);

                p2=p2->dnext;
            }
            printf("end table->%s\n\n",p1->tname);
            /*结束对应的记录数据打印*/
        }
        p1=p1->next;
        /*指针下跳*/
    }
    return 1;
}

int updata(struct liblink *lib,char tname[],char lname[],int id,char newval[],char spchar)
/*更新对应的字段数据，lib为对应的数据表，tname为对应表名，lname为对应字段名，id为对应记录的id名，newval为对应更新的值，spchar为数据分隔符*/
{
    int i,j,k,q,brun=0,done=0;
    char temp[50],nvaltmp[50],lnametmp[50];
    struct liblink *ptable;
    struct dlink *pdata;

    ptable=lib;
    pdata=NULL;
    strcpy(nvaltmp,newval);
    strcpy(lnametmp,lname);
 /*初始化对应变量*/
    if(lib==NULL)
    {
        brun=0;
        return brun;
    }
/*判断库连表头地址为空，报错*/
    while(ptable!=NULL)
    {
        if(!strcmp(ptable->tname,tname))
        /*判断与对应表名是否相符*/
        {
            pdata=ptable->dhead;
            if(pdata==NULL)
            {
                brun=-1;
                return brun;
            }
            while(pdata!=NULL)
            {
                /*遍历对应记录数据*/
                done=0;
                if(pdata->id==id)
                {
                    /*定位对应id数据*/
                    for(i=0;i<50;i++)
                        temp[i]='\0';
                    i=0;
                    i=count(ptable->lname,lnametmp,spchar);    
                    /*计算对应字段的位置*/        
                    j=0;k=0;
                    while(pdata->value[j]!='\0'&&k!=i)
                    {
                        if(pdata->value[j]==spchar)
                            k++;
                        temp[j]=pdata->value[j];
                        j++;
                    }
                    /*提取对应字段之前的数据*/            
                    k=0;                    
                    while(nvaltmp[k]!='\0'&&j<50&&k<50)
                    {
                        temp[j]=nvaltmp[k];                        
                        j++;
                        k++;
                    }    
                    /*添加对应的新数据*/                
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
                    /*添加剩下的数据*/                    
                    for(i=0;i<50;i++)
                        pdata->value[i]='\0';                    
                    strcpy(pdata->value,temp);
                    /*拷入新数据*/
                    done=1;                    
                }
                if(done==1)
                    break;
                pdata=pdata->dnext;
                /*判断结束和指针向下个节点移动*/
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
/*添加新的数据，tlibhead为对应的库链表头地址，tbname为对应添加的表名，tvalue为对应添加的新数据，注意对应数据应该按照字段名处理好数据如：|asd|000|dfg|000|-<*/
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
    /*对应数据初始化*/

    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }
    /*判断头地址，为空报错*/
    while(ptable!=NULL)
    {
        if(!strcmp(ptable->tname,tname))
            /*遍历整个结构数据，定位对应的表*/
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
            /*将自加序列变成字符串。现将数字倒序组成字符串，为对应数组no*/    
            k++;n--;
            while(n!=-1)
            {
                avalue[k]=no[n];
                k++;
                n--;
            }/*再将数组倒序排进avalue数组*/
            strcat(avalue,value);
            /*整合数据，添加进新添加的数据*/
            pdata=ptable->dhead;
            //定位对应的链表头
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
            /*若为头部，直接添加*/
            while(pdata->dnext!=NULL)
                pdata=pdata->dnext;
                /*定位到尾部*/
            pdata->dnext=(struct dlink *)malloc(sizeof(struct dlink));
            pdata=pdata->dnext;
            ptable->idno++;
            pdata->id=ptable->idno;
            pdata->dnext=NULL;
            strcpy(pdata->value,avalue);
            brun=1;
            done=1;
            /*在尾部添加*/
        }
        if(done==1)
            break;
        ptable=ptable->next;
    }
    brun=1;
    return brun;
}

int delre(struct liblink *tlibhead,char tbname[],int tid)
/*删除对应的记录，tlibhead操作的库，tbname为对应的表名，tid为删除的记录对应的id号，id为对应记录的主键*/
{
    int done=0,id,brun=0;
    char tname[50];
    struct liblink *libhead;
    struct dlink *pdata,*p1,*p2;

    libhead=tlibhead;
    strcpy(tname,tbname);
    id=tid;
/*初始化对应的变量*/
    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }
    while(libhead!=NULL)
    {
        if(!strcmp(libhead->tname,tname))
            /*遍历对应的表名，寻找对应的表*/
        {
            pdata=libhead->dhead;
            if(pdata==NULL)
            {
                brun=-1;
                return brun;
            }
            /*对应表中不存在数据，报错退出*/
            done=0;
            p1=pdata;
            p2=pdata;
            /*前后双指针进行遍历，寻找到对应id或者结束时跳出循环*/
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
            /*判断是否为NULL，是为数据尾部，跳出*/
            if(p1==p2)
            {
                libhead->dhead=pdata->dnext;
                brun=1;
                return brun;
            }
            /*判断是否为数据头部，是直接对头指针（dhead）进行更改*/
            p2->dnext=p1->dnext;
            free(p1);
            done=1;
            /*为数据中部，进行删除*/
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
/*删除对应的数据表，tlibhead为对应库的头地址，tbname为对应删除的表名*/
{
    int brun=0,done=0;
    char tname[50];
    struct liblink *libhead,*flibhead;
    struct dlink *pdata,*p1,*p2;
 
    strcpy(tname,tbname);
    libhead=tlibhead;
    flibhead=tlibhead;
    /*初始化对应的变量*/

    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }
    /*库不存在，报错跳出*/
    while(libhead!=NULL)
    {        
        if(!strcmp(libhead->tname,tname))
            /*遍历库，寻找对应的表*/
        {
            pdata=libhead->dhead;
            p1=pdata;
            p2=pdata;
            /*赋值对应数据，先删除数据，再删除表，减少储存空间*/

            while(pdata->dnext!=NULL&&pdata!=NULL)
            {
                p1=pdata;
                p2=pdata;
                while(p1->dnext!=NULL)
                {                
                    p2=p1;
                    p1=p1->dnext;
                }
                //定位指针到尾部进行删除
                free(p1);
                p2->dnext=NULL;
            }
            free(libhead->dhead);
            libhead->dhead=NULL;
            //删除对应表的节点数据
            if(flibhead==libhead)
            {        
                libhead=libhead->next;                
                brun=-2;
                return brun;
            }
            /*对应为库头地址，在局部函数里面无法经行更改,返回-2以示识别*/
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
/*创建表，tlibhead为对应的库头地址，tname为表名，tlname为对应的字段名，字段名与数据格式相同，用对应的分隔符分隔*/
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
    //初始化对应的变量

    if(p1==NULL)//判断可头地址，是否为NULL，为NULL的话直接添加对应的表
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
    /*跳到库的尾部，进行添加，出现重复的话，直接跳出返回－1*/    
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
/*搜索函数，tlibhead对应的库名，tbname为对应搜索的表名，tlname为对应匹配的字段名，value为对应的字段匹配的值，oint为是否排序的判断符1为排序，0为不需排序，tolname为排序的字段，stlink为搜索返回的链表，spchar为数据分隔符*/
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
//初始化对应的变量
    if(libhead==NULL)
    {
        brun=-1;
        return brun;
    }//对应库头地址为空，报错跳出
    while(libhead!=NULL)
    {
        if(!strcmp(libhead->tname,tname))//进入库，跳到对应的表
        {
            p1=libhead->dhead;
            p2=p1;
            if(p1==NULL)
            {
                brun=-1;
                return brun;
            }//对应库头地址出错
            i=count(libhead->lname,lname,spchar);//得出对应的字段的序号
            while(p1!=NULL)
            {
                for(n=0;n<50;n++)
                    temp[n]='\0';//初始化临时数组
                match(p1->value,i,temp,spchar);//提取对应字段值进行比较
                if(!strcmp(temp,value))//提取相符的数据
                {                
                    if(slink->num==-1)//标志搜索的链表第一个单元没有使用，初始化的时候要对num的成员赋值为－1
                    {
                        strcpy(slink->value,p1->value);
                        slink->num=p1->id;
                        if(oint==1)//提取排序变量经行赋值
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
                        slink->next=NULL;//尾部赋空值
                    }
                }
                p1=p1->dnext;
            }
            done=1;
        }
        if(done==1)
        {
            brun=1;
            return brun;//判断退出
        }
        libhead=libhead->next;//遍历下一个表，但是只会搜索一个表的数据
    }
}

int savelib(char tfname[],struct liblink *tlibhead)//char ftype[]
/*保存数据，将对应的库数据写入硬盘，tfname为保存的文件名，libhead为对应的库头地址，ftype对注释参数，对应为合成文件名，分开为文件名和后序名*/
{
    int i,brun=0;
    char fname[50]={'\0'};
    struct liblink *libhead;
    struct dlink *pdata;
    FILE *lib;

    for(i=0;i<50;i++)
        fname[i]='\0';
    strcpy(fname,tfname);
    //strcat(fname,ftype);//对应上面注释的文件名和后序名的连接
    lib=NULL;
    lib=fopen(fname,"w");
    if(lib==NULL)
    {
        brun=0;
        return brun;
    }//打开文件出错，退出
    libhead=tlibhead;
    pdata=NULL;
    //初始化对应的变量
    if(libhead==NULL)
    {
        brun=0;
        fclose(lib);
        return brun;
    }
    //数据库不存在数据，跳出
    while(libhead!=NULL)//开始写入数据
    {    
        fprintf(lib,"#table:%s$%d\n",libhead->tname,libhead->idno);
        fprintf(lib,"%s\n",libhead->lname);
        pdata=libhead->dhead;
        if(pdata==NULL)
        {
            fprintf(lib,"#tbend|%s\n",libhead->tname);
            libhead=libhead->next;
            continue;
        }//循环continue，表数据为空的话继续循环表
        while(pdata!=NULL)//写入表数据
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
    //关闭文件，返回成功值，跳出
}

int creatlib(char tlibname[])
/*创建库数据，tlibname为对应库名，数据库名唯一，对应文件名，记录在索引文件list.list里*/
{
    int i,brun=0,have=0;
    char libname[50]="",fname[50]="",wstr[100]="",instr[100]="",temp[100]="";
    FILE *ind,*fp;
    struct inlink
    {
        char name[50];
        char fname[50];
        struct inlink *next;
    }*ihead,*p1,*p2;//建立索引链表，提取数据库记录，防止建立重复数据库

    ihead=(struct inlink *)malloc(sizeof(struct inlink));
    p1=ihead;
    p2=ihead;
    strcpy(libname,tlibname);
    strcpy(fname,"lib_");
    strcat(fname,libname);
    strcat(fname,".lib");
    //数据库名为fname，对其进行处理变成文件名，按照需要可以经行更改
    ind=fopen("list.list","r");//读取索引文件
    if(ind==NULL)//为NULL的话经行创建文件
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
        return brun;//写入数据库索引文件，格式为:|数据库名|数据库对应文件名|-<
    }
    while(!feof(ind))//若存在数据库，经行数据库遍历，排除重复项
    {
        p2=p1;
        for(i=0;i<100;i++)
            instr[i]='\0';
        fscanf(ind,"%s\n",instr);
        for(i=0;i<50;i++)
            temp[i]='\0';
        for(i=0;i<50;i++)
            p1->name[i]='\0';
            //初始化对应的变量
        match(instr,1,temp,'|');
        strcpy(p1->name,temp);
        for(i=0;i<50;i++)
            temp[i]='\0';
        match(instr,2,temp,'|');
        strcpy(p1->fname,temp);
        p1->next=(struct inlink *)malloc(sizeof(struct inlink));
        p1=p1->next;
        strcpy(p1->name,"NULLUnit");//最后一个单元赋NULL值
        p1->next=NULL;
    }
    if(!strcmp(p1->name,"NULLUnit"))//判断最后的单元，为NULL的话经行删除，减少冗余数据
        p2->next=NULL;
    p1=ihead;
    fclose(ind);
    have=0;
    while(p1!=NULL)
    //经行数据的遍历，若有重复项跳出函数，返回对应的标志
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
    ind=fopen("list.list","a");//若没有出项重复项，对索引文件经行尾部添加新建的数据库项
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
/*打印特定数据表，thead为对于库头地址，ttname为需要打印的表，olnum为对应的操作数，olnum为0即为打印全部字段，为其他数为打印到对应的字段序号为止，spchar为对应的分隔符*/
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
    }//库头地址出错，跳出
    while(head!=NULL)//进行对应的表数据定位
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
    if(olnum==0)//对操作数进行处理
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
    while(pdata!=NULL)//进行对应表的打印，
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
/*打印索引文件，opi为操作数。1为只打印存在的库名，0为打印全部数据，包括数据库和对应的文件名*/
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
    }//不存在数据库索引文件
    if(opi==1)//分别对操作数进行操作
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
    }//若操作数出错，输出0跳出
    brun=0;
    return brun;
}


int dellib(char dlibname[])
/*删除对应的数据库，dlibname为对应的库名*/
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
    /*读取索引文件，建立对应的链表*/
    p1=ihead;
    p2=ihead;
    while(p1!=NULL)//进行数据的遍历
    {
        if(!strcmp(p1->name,libname))//对相符数据库名的进行删除
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
    }//如果不存在对应的库，直接返回
    ind=fopen("list.list","w");//删除后，重新写入索引文件
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
/*选择对应的数据库，tsname为选择的数据库名，toname为对应输出的数据库文件名*/
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
    //读取索引文件，建立对应的链表
    p1=ihead;
    if(ihead==NULL)
    {
        brun=-1;
        return brun;
    }
    brun=0;
    while(p1!=NULL)//遍历链表，提取对应的库名
    {
        if(!strcmp(p1->lname,sname))
        {
            strcpy(toname,p1->fname);//相符项赋值
            brun=1;
            return brun;
        }
        p1=p1->next;
    }
    if(brun==0)//若不存在，对输出项进行赋空值
    {
        for(i=0;i<50;i++)
            oname[i]='\0';        
    }
    return brun;
}