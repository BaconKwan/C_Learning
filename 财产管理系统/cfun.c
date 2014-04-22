#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<conio.h>
#include "lib.c"

extern int count(char str[],char name[],char spchar);
extern int match(char checkstr[20],int num,char value[20],char spchar);
extern int chchaint(char str[]);
extern void garb(char istr[],char ostr[],int n);
extern void gettname(char istr[],char ostr[]);
extern int getnum(char tname[]);
extern int openlib(char tlbname[],struct liblink *lhead);
extern int printlib(struct liblink *lhead,char spchar);
extern int updata(struct liblink *lib,char tname[],char lname[],int id,char newval[],char spchar);
extern int addre(struct liblink *tlibhead,char tbname[],char tvalue[]);
extern int delre(struct liblink *tlibhead,char tbname[],int tid);
extern int droptb(struct liblink *tlibhead,char tbname[]);
extern int creattb(struct liblink *tlibhead,char tbname[],char tlname[]);
extern int search(struct liblink *tlibhead,char tbname[],char tlname[],char value[],int oint,char tolname[],struct relink *stlink,char spchar);
extern int savelib(char tfname[],struct liblink *tlibhead);
extern int creatlib(char tlibname[]);
extern int printtb(struct liblink *thead,char ttname[],int olnum,char spchar);
extern int prilibindex(int opi);
extern int dellib(char dlibname[]);
extern int chosel(char tsname[],char toname[]);

void encrypt(char instr[])//加密函数，函数接口：instr字符串。作用：直接将原字符串加密，无需输出。算法：将每个字符按照ASCII码推后一位，如果是Z|z|9就变成A|a|0
{
    int i,n;

    for(i=0;i<50;i++)
        if(instr[i]=='\0')
        {
            n=i;
            break;
        }
    printf("%d\n",n);


    for(i=0;i<n;i++)
    {
        if(isdigit(instr[i])||islower(instr[i])||isupper(instr[i]))
        {
            if(instr[i]!='z'&&instr[i]!='Z'&&instr[i]!='9')
                instr[i]++;
        
            else if(instr[i]=='z')
                    instr[i]='a';
                 else if(instr[i]=='Z')
                         instr[i]='A';
                      else
                          instr[i]='0';
        }
    }
}

void disencrypt(char instr[])//解密函数，对应上面的加密的函数的逆运算
{
    int i,n;

    for(i=0;i<50;i++)
        if(instr[i]=='\0')
        {
            n=i;
            break;
        }
    printf("%d\n",n);


    for(i=0;i<n;i++)
    {
        if(isdigit(instr[i])||islower(instr[i])||isupper(instr[i]))
        {
            if(instr[i]!='a'&&instr[i]!='A'&&instr[i]!='0')
                instr[i]--;
        
            else if(instr[i]=='a')
                    instr[i]='z';
                 else if(instr[i]=='A')
                         instr[i]='Z';
                      else
                          instr[i]='9';
        }
    }
}

int face(int f1,int f2)
{
    int n=0,i,brun=-1;
    char ch[11];

    if(f1==0&&f2==0)
    {
        system("cls"); 
        printf("Welcome to use the Financial Management System\n");
        printf("\n");
        printf("\t1.User Login\n");
        printf("\t2.Infomation Search\n");
        printf("\t3.chose another family\n");
        printf("\t0.Exit System");
        printf("\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        for(n=0;n<10;n++)
            ch[n]='\0';
        i=0;ch[10]='\0';
        while(i<10&&(ch[i]=getch()))
        {
            if(ch[i]==13)
            {
                ch[i]='\0';
                break;
            }
            if(ch[i]==8)
            {
                ch[i]='\0';
                i--;
                if(i==-1)
                {
                    i=0;                    
                    continue;
                }
                printf(" ");
                printf("\b\b");
                printf("]");
                printf("\b");
                continue;
            }        
            printf("%c",ch[i]);
            printf("]");
            printf("\b");
            i++;

        }
        n=chchaint(ch);
        return n;
    }
    if(f1==2&&f2==0)
    {
        system("cls");
        printf("Welcome to use the Financial Management System\n");
        printf("\n");
        return brun;
    }
    if(f1==1&&f2==1)
    {
        system("cls"); 
        printf("Welcome to use the Financial Management System\n");
        printf("\n");
        printf("-------------------About User-------------------\n");
        printf("\t1.Creat users\n");
        printf("\t2.Delete user\n");
        printf("\t3.Modify passwords\n");
        printf("\n");
        printf("-------------------About System-----------------\n");
        printf("\t4.Creat Family\n");
        printf("\t5.Change Family\n");
        printf("\t6.Delete Family\n");
        printf("\t7.Add Financial record\n");
        printf("\t8.Updata Financial record\n");
        printf("\t9.Delete Financial record\n");
        printf("\t10.Add family member\n");
        printf("\t11.Updata family member\n");
        printf("\t12.delete family member\n");
        printf("\t13.Infomation search\n");
        printf("\t14.Summarize the member\n");
        printf("\t15.back to the forward page\n");
        printf("\t0.Exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        for(n=0;n<10;n++)
            ch[n]='\0';
        i=0;ch[10]='\0';
        while(i<10&&(ch[i]=getch()))
        {            
            if(ch[i]==13)
            {
                ch[i]='\0';
                break;
            }
            if(ch[i]==8)
            {
                ch[i]='\0';
                i--;
                if(i==-1)
                {
                    i=0;                    
                    continue;
                }
                printf(" ");
                printf("\b\b");
                printf("]");
                printf("\b");
                continue;
            }    
            printf("%c",ch[i]);
            printf("]");
            printf("\b");
            i++;
        }
        n=chchaint(ch);
        return n;
    }
    if(f1==1&&f2==2)
    {
        system("cls");
        printf("Welcome to use the Financial Management System\n");
        printf("\n");
        printf("\t1.Add Financial record\n");
        printf("\t2.Search My infomation\n");
        printf("\t3.choose another family\n");        
        printf("\t4.Back to forward page\n");
        printf("\t0.exit\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        for(n=0;n<10;n++)
            ch[n]='\0';
        i=0;ch[10]='\0';
        while(i<10&&(ch[i]=getch()))
        {            
            if(ch[i]==13)
            {
                ch[i]='\0';
                break;
            }
            if(ch[i]==8)
            {
                ch[i]='\0';
                i--;
                if(i==-1)
                {
                    i=0;                    
                    continue;
                }
                printf(" ");
                printf("\b\b");
                printf("]");
                printf("\b");
                continue;
            }    
            printf("%c",ch[i]);
            printf("]");
            printf("\b");
            i++;
        }
        n=chchaint(ch);
        return n;
    }    
}

int creatuser(struct liblink *thead,int preri,int right)
{
    int i,n,rech=0;
    char uname[50]={'\0'},paswd[50]={'\0'},pasd1[50]={'\0'},pasd2[50]={'\0'},ch[10],str[100],boe,nch;
    struct liblink *head;

    if(head==NULL)
    {
        printf("Sorry with System error NO.0001\n ");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);
        //nch=getchar();
        if(boe=='1')
        {
            rech=-1;
            return rech;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }
creatag:
ippag:    
    head=thead;
    printf("\nPlease input the user name you want to creat!\n");
    for(n=0;n<50;n++)
        uname[n]='\0';
    scanf("%s",uname);
    printf("Please input the passwords of the user(less than 49 letters)\n");
    for(n=0;n<50;n++)
            ch[n]='\0';
    i=0;ch[49]='\0';
    while(i<48&&(ch[i]=getch()))
    {            
        if(ch[i]==13)
        {
            ch[i]='\0';
            break;
        }
        if(ch[i]==8)
        {
            ch[i]='\0';
            i--;
            if(i==-1)
            {
                i=0;
                continue;
            }
            printf("\b");
            printf(" ");
            printf("\b");        
            continue;
        }    
        printf("*");    
        i++;
    }
    strcpy(pasd1,ch);
    printf("\nPlease input the same passwords again\n");
    for(n=0;n<10;n++)
        ch[n]='\0';
    i=0;ch[10]='\0';
    while(i<10&&(ch[i]=getch()))
    {            
        if(ch[i]==13)
        {
            ch[i]='\0';
            break;
        }
        if(ch[i]==8)
        {
            ch[i]='\0';
            i--;
            printf("\b");
            printf(" ");
            printf("\b");        
            continue;
        }    
        printf("*");    
        i++;
    }
    strcpy(pasd2,ch);
    if(preri!=0)
    {
        printf("\nPlease input the right of the user\n");
        printf("\t1.advanced user\n");
        printf("\t2.normal user\n");
        printf("press the number you want to choose [ ]");
        printf("\b\b");
        scanf("%d",&i);
        if(i!=1)
            i=0;        
    }
    else
        i=right;
    boe='0';
    boe=boe+i;
    if(!strcmp(pasd1,pasd2))
    {
        i=0;
        strcpy(paswd,pasd1);
        encrypt(paswd);
        for(n=0;n<100;n++)
            str[n]='\0';
        strcpy(str,"|");
        strcat(str,uname);
        strcat(str,"|");
        strcat(str,paswd);
        strcat(str,"|");
        for(n=0;n<100;n++)
            if(str[n]=='\0')
                break;
        str[n]=boe;
        strcat(str,"|-<");
        i=addre(head,"admin",str);
        boe=0;
        if(i==-1)
        {
            printf("Sorry with System error NO.0001!\n");
recho2:
            printf("\nPlese input the number you want:\n");
            printf("\t1.back to forward page\n");
            printf("\t2.exit system\n");
            printf("Please chose input the number you want to use [ ]");
            printf("\b\b");    
            boe=0;
            scanf("%c",&boe);
            if(boe=='1')
            {
                rech=1;
                return rech;
            }
            if(boe=='2')
            {
                printf("\n");
                savelib("lib_admin.lib",head);
                exit(0);
            }
            if(boe!='1'&&boe!='2')
                goto recho2;
        }
        if(i==1)
        {
            nch=getchar();
            printf("\nCongratulations! Creat user successfully!\n");
recho3:
            printf("\nPlese input the number you want:\n");
            printf("\t1.continue to creat user\n");
            printf("\t2.back to forword page\n");
            printf("\t3.exit system\n");
            printf("Please chose input the number you want to use [ ]");
            printf("\b\b");
            boe=0;
            
            scanf("%c",&boe);    
            if(boe=='1')
                goto creatag;
            if(boe=='2')
            {
                rech=1;
                return rech;
            }
            if(boe=='3')
            {
                savelib("lib_admin.lib",head);
                exit(0);
            }
            if(boe!='1'&&boe!='2'&&boe!='3')
                goto recho3;
        }
    }
    else
    {
        printf("two passwords are different!\n");
recho4:
        printf("\nPlese input the number you want:\n");
        printf("\t1.input them again\n");
        printf("\t2.back to forword page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");    
        boe=0;
        nch=getchar();
        scanf("%c",&boe);
        if(boe=='1')
            goto ippag;
        if(boe=='2')
        {
            rech=1;
            return rech;
        }
        if(boe=='3')
        {            
            savelib("lib_admin.lib",head);
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
            goto recho4;
    }
    return rech;
}

int deluser(struct liblink *thead)
{
    int id,i,brun=0;
    char boe,nch;
    struct liblink *head;

    head=thead;
    
    if(head==NULL)
    {
        printf("Sorry with System error NO.0001\n ");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);
        //nch=getchar();
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            savelib("lib_admin.lib",head);
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }
delag:
    printtb(head,"admin",1,'|');
    printf("Please input the NO of user you want to delete\n");
    scanf("%d",&id);
    i=delre(head,"member",id);
    if(i==-1)
    {
        printf("Sorry with System error NO.0001\n");
recho2:        
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        //scanf("%c",&boe);
        boe=getchar();
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            savelib("lib_admin.lib",head);
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho2;
    }
    if(i==1)
    {
        printf("Congratulations! delete user successfully!\n");
recho3:
        printf("\nPlese input the number you want:\n");
        printf("\t1.continue to delete user\n");
        printf("\t2.back to forword page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        boe=0;
        //scanf("%c",&boe);
        boe=getchar();
        if(boe=='1')
            goto delag;
        if(boe=='2')
        {
            brun=-1;
            return brun;
        }
        if(boe=='3')
        {
            savelib("lib_admin.lib",head);
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
            goto recho3;
    }
    return brun;
}

int modifyuser(struct liblink *thead)
{
    int i,id,brun=0;
    char boe,temp[50]={'\0'},npass[50]={'\0'},nch;
    struct liblink *head;

    head=thead;

    if(head==NULL)
    {
        printf("Sorry about system error NO.0001\n");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",boe);
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }

moag:
    printf("\n");
    printtb(head,"admin",1,'|');
    printf("\nPlease press the user id you want to modify passsword\n");
    scanf("%s",temp);
    id=chchaint(temp);
    printf("Please iuput the new password!\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    i=0;temp[49]='\0';
    while(i<48&&(temp[i]=getch()))
    {            
        if(temp[i]==13)
        {
            temp[i]='\0';
            break;
        }
        if(temp[i]==8)
        {
            temp[i]='\0';
            i--;
            if(i==-1)
            {
                i=0;
                continue;
            }
            printf("\b");
            printf(" ");
            printf("\b");        
            continue;
        }    
        printf("*");    
        i++;
    }
    printf("\n");
    strcpy(npass,temp);
    encrypt(npass);
    i=updata(head,"admin","passwrd",id,npass,'|');
    if(i==-1)
    {
        printf("Sorry about System error NO.0002\n");
recho2:
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        boe=0;
        nch=getchar();
        scanf("%c",&boe);
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho2;
    }
    printf("\nCongratulation! Modify passwords successfully!\n");
recho3:
    printf("\nPlese input the number you want:\n");
    printf("\t1.modify  password of another user\n");
    printf("\t2.back to forward page\n");
    printf("\t3.exit system\n");
    printf("Please chose input the number you want to use [ ]");
    printf("\b\b");
    boe=0;nch=getchar();
    scanf("%c",&boe);
    printf("%c\n",boe);
    
    if(boe=='1')
        goto moag;
    if(boe=='2')
    {
        brun=-1;
        return brun;
    }
    if(boe=='3')
    {
        savelib("lib_admin.lib",head);
        exit(0);
    }
    if(boe!='1'&&boe!='2')
    {
        goto recho3;
    }
    return brun;
}


int creatmember(struct liblink *thead,char ttname[])
{
    int i,n,rech=0;
    char mname[50]={'\0'},tname[50]={'\0'},fname[50],str[100],boe,nch;
    struct liblink *head;

    if(head==NULL)
    {
        printf("Sorry with System error NO.0001\n ");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);
        //nch=getchar();
        if(boe=='1')
        {
            rech=-1;
            return rech;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }
creatag:
    chosel(tname,fname);
    head=thead;
    strcpy(tname,ttname);
    printf("\nPlease input the member name you want to creat!\n");
    for(n=0;n<50;n++)
        mname[n]='\0';
    gets(mname);    

    i=0;
    for(n=0;n<100;n++)
        str[n]='\0';
    strcpy(str,"|");
    strcat(str,mname);
    strcat(str,"|-<");
    i=addre(head,tname,str);
    boe=0;
    if(i==-1)
    {
        printf("Sorry with System error NO.0001!\n");
recho2:
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");    
        boe=0;
        scanf("%c",&boe);
        if(boe=='1')
        {
            rech=1;
            return rech;
        }
        if(boe=='2')
        {            
            savelib(fname,head);
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho2;
    }
    if(i==1)
    {
        nch=getchar();
        printf("\nCongratulations! Creat user successfully!\n");
recho3:
        printf("\nPlese input the number you want:\n");
        printf("\t1.continue to creat member\n");
        printf("\t2.back to forword page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        boe=0;        
        scanf("%c",&boe);
        if(boe=='1')
            goto creatag;
        if(boe=='2')
        {
            rech=1;
            return rech;
        }
        if(boe=='3')
        {
            savelib(fname,head);
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
            goto recho3;
    }    
    return rech;
}    


int delmember(struct liblink *thead,char ttname[])
{
    int id,i,brun=0;
    char boe,nch,tname[50]={'\0'},fname[50]={'\0'};
    struct liblink *head;

    head=thead;
    strcpy(tname,ttname);
    chosel(tname,fname);
    
    if(head==NULL)
    {
        printf("Sorry with System error NO.0001\n ");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);
        //nch=getchar();
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }
delag:
    printtb(head,"member",1,'|');    
    printf("Please input the NO of user you want to delete\n");
    scanf("%d",&id);
    i=delre(head,"admin",id);
    if(i==-1)
    {
        printf("Sorry with System error NO.0001\n");
recho2:        
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        //scanf("%c",&boe);
        boe=getchar();
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            savelib(fname,head);
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho2;
    }
    if(i==1)
    {
        printf("Congratulations! delete member successfully!\n");
recho3:
        printf("\nPlese input the number you want:\n");
        printf("\t1.continue to delete user\n");
        printf("\t2.back to forword page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        boe=0;
        //scanf("%c",&boe);
        boe=getchar();
        if(boe=='1')
            goto delag;
        if(boe=='2')
        {
            brun=-1;
            return brun;
        }
        if(boe=='3')
        {
            savelib(fname,head);
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
            goto recho3;
    }
    return brun;
}


int modifymember(struct liblink *thead,char ttname[])
{
    int i,id,brun=0;
    char boe,nch,temp[50]={'\0'},tname[50]={'\0'},fname[50]={'\0'};
    struct liblink *head;

    head=thead;
    strcpy(tname,ttname);
    chosel(tname,fname);

    if(head==NULL)
    {
        printf("Sorry about system error NO.0001\n");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",boe);
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }

moag:
    printf("\n");
    printtb(head,"member",1,'|');
    printf("\nPlease press the user id you want to modify passsword\n");
    scanf("%s",temp);
    id=chchaint(temp);
    printf("Please input the new member name!\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    gets(temp);    
    printf("\n");
    i=updata(head,"member","mname",id,temp,'|');
    if(i==-1)
    {
        printf("Sorry about System error NO.0002\n");
recho2:
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        boe=0;
        nch=getchar();
        scanf("%c",&boe);
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho2;
    }
    printf("\nCongratulation! Modify passwords successfully!\n");
recho3:
    printf("\nPlese input the number you want:\n");
    printf("\t1.modify  password of another user\n");
    printf("\t2.back to forward page\n");
    printf("\t3.exit system\n");
    printf("Please chose input the number you want to use [ ]");
    printf("\b\b");
    boe=0;nch=getchar();
    scanf("%c",&boe);
    printf("%c\n",boe);
    
    if(boe=='1')
        goto moag;
    if(boe=='2')
    {
        brun=-1;
        return brun;
    }
    if(boe=='3')
    {
        savelib(fname,head);
        exit(0);
    }
    if(boe!='1'&&boe!='2'&&boe!='3')
    {
        goto recho3;
    }
    return brun;
}

int creatfa()
{
    int i,brun=0;
    char faname[50]={'\0'},boe,fname[50]={'\0'};
    FILE *libf;

creatag:
    printf("\nPlease input the family name :\n");
    gets(faname);

    i=creatlib(faname);
    chosel(faname,fname);
    libf=fopen(fname,"w");
    fprintf(libf,"#table:member$1\n");
    fprintf(libf,"|id|mname|\n");
    fprintf(libf,"|0|admin|-<\n");
    fprintf(libf,"#tbend|member\n");
    fprintf(libf,"#table:%s$1\n",faname);
    fprintf(libf,"|id|member|year|month|day|pom|opnum|left|\n");
    fprintf(libf,"|0|admin|0000|0|0|0|0|-<\n");
    fprintf(libf,"#tbend|%s\n",faname);
    fclose(libf);
    if(i==1)
    {
        printf("Congratulation!Creat family successfully!\n");
recho1:
        printf("\nPlese input the number you want:\n");
        printf("\t1.creat another family\n");
        printf("\t2.back to forward page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);        
        if(boe=='1')
            goto creatag;
        if(boe=='2')
        {
            brun=-1;
            return brun;
        }
        if(boe=='3')
        {
            printf("\n");
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
        {
            goto recho1;
        }
        return brun;
    }
    else
    {
        printf("Sorry about the System error NO.0002\n");
recho2:
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);        
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            printf("\n");
            exit(0);
        }
        if(boe!='1'&&boe!='2')
        {
            goto recho2;
        }
    }
}

int delfa()
{
    int i,brun=0;
    char faname[50]={'\0'},boe;

creatag:
    printf("\nPlease input the family name :\n");
    gets(faname);

    i=dellib(faname);
    if(i==1)
    {
        printf("Congratulation!Creat family successfully!\n");
recho1:
        printf("\nPlese input the number you want:\n");
        printf("\t1.creat another family\n");
        printf("\t2.back to forward page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);        
        if(boe=='1')
            goto creatag;
        if(boe=='2')
        {
            brun=-1;
            return brun;
        }
        if(boe=='3')
        {
            printf("\n");
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
        {
            goto recho1;
        }
        return brun;
    }
    else
    {
        printf("Sorry about the System error NO.0002\n");
recho2:
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);        
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            printf("\n");
            exit(0);
        }
        if(boe!='1'&&boe!='2')
        {
            goto recho2;
        }
    }
}

int addfare(struct liblink *thead,char ttname[])
{
    int i,n,brun=0,opmoney=0,left=0,opsigh=1,done=0;
    char str[100]={'\0'},tname[50]={'\0'},temp[50]={'\0'},boe,op=0,temp2[50]={'\0'},fname[50]={'\0'};
    struct liblink *head,*p1;
    struct dlink *pdata;

creatag:
    head=thead;
    p1=head;
    pdata=NULL;
    strcpy(tname,ttname);
    chosel(tname,fname);

    strcpy(str,"|");
    printf("\nPlease input the member of record to add\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    gets(temp);
    strcat(str,temp);
    strcat(str,"|");
    printf("Please input the year of record you want to add\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    gets(temp);
    strcat(str,temp);
    strcat(str,"|");
    printf("Please input the month of record you want to add\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    gets(temp);
    strcat(str,temp);
    strcat(str,"|");
    printf("Please input the day of record you want to add\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    gets(temp);
    strcat(str,temp);
    strcat(str,"|");
    printf("Please input the year of opera sign of the money you want to add\n");
    printf("\t + mean income\n");
    printf("\t - mean outcome\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    scanf("%c",&op);
    if(op=='+')
    {
        opsigh=1;
        strcat(str,"1");
        strcat(str,"|");
    }
    else
    {
        opsigh=0;
        strcat(str,"0");
        strcat(str,"|");
    }
    printf("Please input the money of record you want to add\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    scanf("%s",temp);
    opmoney=chchaint(temp);
    strcat(str,temp);
    strcat(str,"|");
    for(i=0;i<50;i++)
        temp[i]='\0';
    
    done=0;
    while(p1!=NULL)
    {
        if(!strcmp(p1->tname,tname))
        {
            pdata=p1->dhead;
            while(pdata->dnext!=NULL)
                pdata=pdata->dnext;
            strcpy(temp2,pdata->value);
            done=1;
            break;
        }
        p1=p1->next;
    }
    if(done==0)
    {
        brun=-2;
        return brun;
    }
    match(temp2,8,temp,'|');
    left=chchaint(temp);
    if(opsigh==1)
    {
        left=left+opmoney;
    }
    else
    {
        left=left-opmoney;
    }
    for(i=0;i<50;i++)
        temp2[i]='\0';
    for(i=0;i<50;i++)
        temp[i]='\0';
    n=left;i=0;
    while(n!=0)
    {
        temp[i]=n%10+'0';
        n=n/10;
        i++;
    }
    i--;
    n=0;
    while(i!=-1)
    {
        temp2[n]=temp[i];
        n++;
        i--;
    }
    strcat(str,temp2);
    strcat(str,"|-<");
    i=0;
    i=addre(head,tname,str);
    if(i==1)
    {
        printf("Congratulation!Creat finanical records successfully!\n");
recho1:
        printf("\nPlese input the number you want:\n");
        printf("\t1.creat another finanical record\n");
        printf("\t2.back to forward page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);        
        if(boe=='1')
            goto creatag;
        if(boe=='2')
        {
            brun=-1;
            return brun;
        }
        if(boe=='3')
        {
            printf("\n");
            savelib(fname,head);
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
        {
            goto recho1;
        }
    }
    else
    {
        printf("Sorry about the system error NO.0002\n");
recho2:
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);    
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            printf("\n");
            exit(0);
        }
        if(boe!='1'&&boe!='2')
        {
            goto recho2;
        }
    
    }
    brun=-1;
    return brun;
}


int delfare(struct liblink *thead,char ttname[])
{
    int id,i,brun=0;
    char boe,nch,tname[50]={'\0'},fname[50]={'\0'};
    struct liblink *head;

    head=thead;
    strcpy(tname,ttname);
    chosel(tname,fname);
    
    if(head==NULL)
    {
        printf("Sorry with System error NO.0001\n ");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",&boe);
        //nch=getchar();
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }
delag:
    printtb(head,tname,1,'|');    
    printf("Please input the NO of user you want to delete\n");
    scanf("%d",&id);
    i=delre(head,tname,id);
    if(i==-1)
    {
        printf("Sorry with System error NO.0001\n");
recho2:        
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        //scanf("%c",&boe);
        boe=getchar();
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            savelib(fname,head);
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho2;
    }
    if(i==1)
    {
        printf("Congratulations! delete financial record successfully!\n");
recho3:
        printf("\nPlese input the number you want:\n");
        printf("\t1.continue to delete user\n");
        printf("\t2.back to forword page\n");
        printf("\t3.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        boe=0;
        //scanf("%c",&boe);
        boe=getchar();
        if(boe=='1')
            goto delag;
        if(boe=='2')
        {
            brun=-1;
            return brun;
        }
        if(boe=='3')
        {
            savelib(fname,head);
            exit(0);
        }
        if(boe!='1'&&boe!='2'&&boe!='3')
            goto recho3;
    }
    return brun;
}


int modifyfare(struct liblink *thead,char ttname[])
{
    int i,id,brun=0;
    char boe,nch,temp[50]={'\0'},temp2[50]={'\0'},tname[50]={'\0'},fname[50]={'\0'};
    struct liblink *head;

    head=thead;
    strcpy(tname,ttname);
    chosel(tname,fname);

    if(head==NULL)
    {
        printf("Sorry about system error NO.0001\n");
recho1:
        printf("Plese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        scanf("%c",boe);
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho1;
    }

moag:
    printf("\n");
    printtb(head,tname,1,'|');
    printf("\nPlease press the user id you want to modify passsword\n");
    scanf("%s",temp);
    id=chchaint(temp);
    printf("Please input the name of Category!\n");
    printf("member\tyear\tmonth\tday\n");
    for(i=0;i<50;i++)
        temp[i]='\0';
    gets(temp);    
    for(i=0;i<50;i++)
        temp2[i]='\0';
    printf("Please input the new value!\n");
    gets(temp2);
    printf("\n");
    i=updata(head,tname,temp,id,temp2,'|');
    if(i==-1)
    {
        printf("Sorry about System error NO.0002\n");
recho2:
        printf("\nPlese input the number you want:\n");
        printf("\t1.back to forward page\n");
        printf("\t2.exit system\n");
        printf("Please chose input the number you want to use [ ]");
        printf("\b\b");
        boe=0;
        nch=getchar();
        scanf("%c",&boe);
        if(boe=='1')
        {
            brun=-1;
            return brun;
        }
        if(boe=='2')
        {
            exit(0);
        }
        if(boe!='1'&&boe!='2')
            goto recho2;
    }
    printf("\nCongratulation! Modify passwords successfully!\n");
recho3:
    printf("\nPlese input the number you want:\n");
    printf("\t1.modify  password of another user\n");
    printf("\t2.back to forward page\n");
    printf("\t3.exit system\n");
    printf("Please chose input the number you want to use [ ]");
    printf("\b\b");
    boe=0;nch=getchar();
    scanf("%c",&boe);
    printf("%c\n",boe);
    
    if(boe=='1')
        goto moag;
    if(boe=='2')
    {
        brun=-1;
        return brun;
    }
    if(boe=='3')
    {
        savelib(fname,head);
        exit(0);
    }
    if(boe!='1'&&boe!='2'&&boe!='3')
    {
        goto recho3;
    }
    return brun;
}

int libsearch(struct liblink *thead,char ttname[])
{
    int i,n,k,brun=0;
    char smember[50]={'\0'},tname[50]={'\0'},temp[50]={'\0'},boe;
    struct liblink *head;
    struct relink *slink,*ps;

searag:
    head=thead;
    strcpy(tname,ttname);

    slink=(struct relink *)malloc(sizeof(struct relink));
    slink->num=-1;
    slink->next=NULL;
    ps=slink;

    printtb(head,"member",1,'|');
recho1:
    printf("please input the name you want to search\n");
    gets(smember);
    if(!strcmp(smember,""))
    {
        printf("System error ,press any key to continue!\n");
        getch();
        goto recho1;
    }
    i=search(head,tname,"member",smember,0,"",slink,'|');
    if(slink->num==-1)
    {
        printf("no match record\n");
        printf("press any key to back to forward page!\n");
        getch();
        brun=-1;
        return brun;
    }
    ps=slink;
    printf("there are the result of search:\n");
    while(ps!=NULL)
    {
        printf("\tNO.%d",ps->num);
        for(n=2;n<=8;n++)
        {
            for(k=0;k<50;k++)
                temp[k]='\0';
            match(ps->value,n,temp,'|');
            printf("\t%s",temp);
        }
        printf("\n");
        ps=ps->next;
    }
    printf("\nCongratulation! search record successfully!\n");
recho3:
    printf("\nPlese input the number you want:\n");
    printf("\t1.search of another member\n");
    printf("\t2.back to forward page\n");
    printf("\t3.exit system\n");
    printf("Please chose input the number you want to use [ ]");
    printf("\b\b");
    boe=0;
    scanf("%c",&boe);
    if(boe=='1')
        goto searag;
    if(boe=='2')
    {
        brun=-1;
        return brun;
    }
    if(boe=='3')
    {
        printf("\n");
        exit(0);
    }
    if(boe!='1'&&boe!='2'&&boe!='3')
    {
        goto recho3;
    }
    return brun;
}

int summember(struct liblink *thead,char ttname[])
{
    int i,brun=0,plus,minus,left,pom=0;
    char tname[50]={'\0'},tempm[50]={'\0'},temp[50]={'\0'};
    struct liblink *head,*p1;
    struct dlink *pdata;
    struct relink *slink;
    struct sum
    {
        char mname[50];
        int plus;
        int minus;
        int left;
        struct sum *next;
    }*sulink,*ps;


    head=thead;
    strcpy(tname,ttname);
    pdata=NULL;
    sulink=(struct sum *)malloc(sizeof(struct sum));
    strcpy(sulink->mname,"NULLUnit");
    sulink->left=0;
    sulink->plus=0;
    sulink->minus=0;
    sulink->next=NULL;
    sulink->next=NULL;

    slink=(struct relink *)malloc(sizeof(struct relink));
    slink->num=-1;
    slink->next=NULL;

    if(head==NULL)
    {
        printf("\nSystem error NO.0002\n");
        printf("press any key to continue!\n");
        brun=-1;
        return brun;
    }

    p1=head;            
    pdata=p1->dhead;
    ps=sulink;
    while(pdata!=NULL)
    {
        slink=(struct relink *)malloc(sizeof(struct relink));
        slink->num=-1;
        slink->next=NULL;
        for(i=0;i<50;i++)
            tempm[i]='\0';
        match(pdata->value,2,tempm,'|');
        search(head,tname,"member",tempm,0,"",slink,'|');
        if(slink->num==-1)
        {
            strcpy(sulink->mname,tempm);
            sulink->plus=0;
            sulink->minus=0;
            sulink->left=0;
            sulink->next=(struct sum *)malloc(sizeof(struct sum));
            sulink=sulink->next;
            sulink->next=NULL;
            continue;
        }
        strcpy(sulink->mname,tempm);
        plus=0;
        minus=0;
        left=0;

        while(slink!=NULL)
        {            
            for(i=0;i<50;i++)
                temp[i]='\0';
            match(slink->value,5,temp,'|');
            if(temp[0]=='1')
                pom=1;
            else
                pom=0;
            for(i=0;i<50;i++)
                temp[i]='\0';
            match(slink->value,6,temp,'|');
            i=0;
            i=chchaint(temp);
            if(pom==1)
                plus=plus+i;
            else
                minus=minus+i;
            if(slink->next==NULL)
            {
                for(i=0;i<50;i++)
                    temp[i]='\0';
                match(slink->value,7,temp,'|');
                left=chchaint(temp);
            }
            slink=slink->next;
        }
        sulink->left=left;
        sulink->plus=plus;
        sulink->minus=minus;
        sulink->next=(struct sum *)malloc(sizeof(struct sum));
        sulink=sulink->next;
        strcpy(sulink->mname,"NULLUnit");
        sulink->left=0;
        sulink->plus=0;
        sulink->minus=0;
        sulink->next=NULL;
        free(slink);
        pdata=pdata->dnext;
    }
    sulink=ps;
    printf("\nthere is summarize of the famuily member\n");
    printf("\tmember\tplus\tminus\tleft\n");
    while(sulink!=NULL)
    {
        if(!strcmp(sulink->mname,"NULLUnit"))
        {
            sulink=sulink->next;
            continue;
        }
        printf("\t%s",sulink->mname);
        printf("\t%d",sulink->plus);
        printf("\t%d",sulink->minus);
        printf("\t%d\n",sulink->left);
        sulink=sulink->next;
    }
    printf("\nplease press any key to back to forword!\n");
    getch();
    brun=-1;
    return brun;
}



                













/*
main()
{
    int n,i;
    char ch[11]="",temp[50]={'\0'};

    i=face(1,1);
    printf("\n%d\n",i);
    printf("%d\n",chchaint("1456"));
    for(n=0;n<49;n++)
        temp[n]='\0';
    i=0;temp[49]='\0';
    while(i<48&&(temp[i]=getch()))
    {            
        if(temp[i]==13)
        {
            temp[i]='\0';
            break;
        }
        if(temp[i]==8)
        {
            temp[i]='\0';
            i--;
            printf("\b");
            printf(" ");
            printf("\b");        
            continue;
        }    
        printf("*");    
        i++;
    }
    printf("\n%s\n",temp);

}
*/