#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "cfun.c"


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
extern void encrypt(char instr[]);
extern void disencrypt(char instr[]);
extern int face(int f1,int f2);
extern int creatuser(struct liblink *head,int preri,int right);

/*
struct dlink
{
    int id;
    char value[50];
    char oval[20];
    struct dlink *dnext;
};

struct liblink
{
    char tname[20];
    char lname[50];
    int idno;
    struct dlink *dhead;
    struct liblink *next;
};

struct relink
{
    int num;
    char ovalue[10];
    char value[50];
    struct relink *next;
};
*/

main()
{
    int f1=0,f2=0,i,n,rech=0,login=0,right=0;
    char str[100]={'\0'},fname[50]={'\0'},temp[50]={'\0'},temp2[50]={'\0'},tname[50]={'\0'};
    struct liblink *lhead,*ahead;
    struct relink *slink;
    FILE *ind,*ifile;



    lhead=(struct liblink *)malloc(sizeof(struct liblink));
    lhead->dhead=(struct dlink *)malloc(sizeof(struct dlink));
    lhead->next=NULL;
    ahead=(struct liblink *)malloc(sizeof(struct liblink));
    ahead->dhead=(struct dlink *)malloc(sizeof(struct dlink));
    ahead->next=NULL;
    slink=(struct relink *)malloc(sizeof(struct relink));
    slink->num=-1;
    slink->next=NULL;
    

    ind=fopen("list.list","r");
    if(ind==NULL)
    {
        printf("Welcome to use the Financial Management System\n\n");
        printf("Initialize the system,please wait for minutes\n");
        printf("Please input the family you want to manage\n");
        gets(str);
        strcpy(temp2,str);
        creatlib("admin");
        i=creatlib(str);
        if(i==1)
        {
            chosel("admin",fname);
            ifile=fopen(fname,"w");
            fprintf(ifile,"#table:admin$0\n");
            fprintf(ifile,"|id|aduser|passwrd|right|\n");
            fprintf(ifile,"#tbend|admin\n");
            fclose(ifile);
            openlib(fname,lhead);
            for(n=0;n<100;n++)
                str[n]='\0';
            printf("Please input the advaned username\n");
            gets(temp);
            strcpy(str,"|");
            strcat(str,temp);
            strcat(str,"|");
            for(n=0;n<50;n++)
                temp[n]='\0';
            printf("Please input the passwords(less than 48 letters)\n");
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
            encrypt(temp);
            strcat(str,temp);
            strcat(str,"|");
            strcat(str,"1|-<");
            addre(lhead,"admin",str);
            savelib(fname,lhead);
            
            chosel(temp2,fname);
            ifile=fopen(fname,"w");
            fprintf(ifile,"#table:member$1\n");
            fprintf(ifile,"|id|mname|\n");
            fprintf(ifile,"|0|admin|-<\n");
            fprintf(ifile,"#tbend|member\n");
            fprintf(ifile,"#table:%s$1\n",temp2);
            fprintf(ifile,"|id|member|year|month|day|pom|opnum|left|\n");
            fprintf(ifile,"|0|admin|0000|0|0|0|0|-<\n");
            fprintf(ifile,"#tbend|%s",temp2);
            fclose(ifile);            
        }
        else
        {
            printf("Special Error!\n");
            printf("Please press any key to close the program\n");
            getch();
            exit(0);
        }
        
    }
    

rechd:
    system("cls");
    lhead=NULL;
    lhead=(struct liblink *)malloc(sizeof(struct liblink));
    lhead->dhead=(struct dlink *)malloc(sizeof(struct dlink));
    lhead->next=NULL;
    ahead=(struct liblink *)malloc(sizeof(struct liblink));
    ahead->dhead=(struct dlink *)malloc(sizeof(struct dlink));
    ahead->next=NULL;

    printf("Welcome to use the Financial Management System\n\n");    
    printf("Please choose the family:\n");
    prilibindex(1);
    printf("Plese input the family you chose\n");
    for(n=0;n<50;n++)
        temp[n]='\0';
    gets(temp);
    chosel("admin",fname);    
    openlib(fname,ahead);
    for(n=0;n<50;n++)
        fname[n]='\0';
    strcpy(tname,temp);
    i=chosel(temp,fname);

    if(i==-1)
    {
        printf("wrong database name!\n");
        printf("press any key to continue!\n");
        getch();
        goto rechd;
    }
    openlib(fname,lhead);
    for(n=0;n<50;n++)
        temp[n]='\0';

face0:
    f1=face(0,0);
    switch(f1)
    {
    case 1:
        {
            printf("\nPlease input the usename\n");
            gets(temp);
            search(ahead,"admin","aduser",temp,0,"",slink,'|');
            printf("Please input the password\n");
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
            for(n=0;n<49;n++)
                temp2[n]='\0';            
            match(slink->value,3,temp2,'|');
            right=-1;login=0;
            disencrypt(temp2);                
            if(!strcmp(temp,temp2))
            {
                login=1;
                match(slink->value,4,temp2,'|');
                right=temp2[0]-48;
            }
            if(login==1&&right==1)
            {
face1:
                f2=0;
                f2=face(1,1);
                switch(f2)
                {
                    case 1:
                        {
                            rech=0;
                            rech=creatuser(ahead,1,0);
                            //printlib(ahead,'|');
                            //getch();
                            savelib("lib_admin.lib",ahead);
                            if(rech==1)
                                goto face1;
                            break;
                        }
                    case 2:
                        {
                            rech=0;
                            rech=deluser(ahead);
                            savelib("lib_admin.lib",ahead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 3:
                        {
                            rech=0;
                            rech=modifyuser(ahead);
                            savelib("lib_admin.lib",ahead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 4:
                        {
                            rech=0;
                            rech=creatfa();
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 5:
                        {
rechlib:
                            savelib(fname,lhead);
                            free(lhead);
                            lhead=(struct liblink *)malloc(sizeof(struct liblink));
                            lhead->dhead=(struct dlink *)malloc(sizeof(struct dlink));
                            lhead->next=NULL;
                            printf("Please choose the family:\n");
                            prilibindex(1);
                            printf("Plese input the family you chose\n");
                            for(n=0;n<50;n++)
                                temp[n]='\0';
                            gets(temp);
                            for(n=0;n<50;n++)
                                fname[n]='\0';
                            for(n=0;n<50;n++)
                                tname[n]='\0';
                            strcpy(tname,temp);
                            i=chosel(temp,fname);
                            if(i==-1)
                            {
                                printf("wrong database name!\n");
                                printf("press any key to continue!\n");
                                getch();
                                goto rechlib;
                            }
                            openlib(fname,lhead);
                            printf("change family database successfully!\n");
                            printf("Press any key to back to forward page!\n");
                            getch();
                            goto face1;
                            break;
                        }
                    case 6:
                        {
                            rech=0;
                            rech=delfa();
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 7:
                        {
                            rech=0;
                            rech=addfare(lhead,tname);    
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 8:
                        {
                            rech=0;
                            rech=modifyfare(lhead,tname);
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                        }
                    case 9:
                        {
                            rech=0;
                            rech=delfare(lhead,tname);
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 10:
                        {
                            rech=0;
                            rech=creatmember(lhead,tname);
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 11:
                        {    
                            rech=0;
                            rech=modifymember(lhead,tname);
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 12:
                        {
                            rech=0;
                            rech=delmember(lhead,tname);
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 13:
                        {
                            rech=0;
                            rech=libsearch(lhead,tname);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 14:
                        {
                            rech=0;
                            rech=summember(lhead,tname);
                            if(rech==1)
                                goto face1;
                            break;
                        }
                    case 15:
                        {
                            printf("\nplease press any key to continue!\n");
                            getch();
                            goto face1;
                            break;
                        }
                    default:
                        {
                            printf("\nwrong order!\n");
                            printf("please press any key to continue\n");
                            getch();
                            goto face1;
                            break;
                        }
                }                                
                
            }
            if(login==1&&right==0)
            {
face2:
                f2=0;
                f2=face(1,2);
                switch(f2)
                {
                    case 1:
                        {
                            rech=0;
                            rech=addfare(lhead,tname);    
                            savelib(fname,lhead);
                            if(rech==-1)
                                goto face2;
                            break;
                        }
                    case 2:
                        {
                            rech=0;
                            rech=libsearch(lhead,tname);
                            if(rech==-1)
                                goto face1;
                            break;
                        }
                    case 3:
                        {
rechlib2:
                            savelib(fname,lhead);
                            free(lhead);
                            lhead=(struct liblink *)malloc(sizeof(struct liblink));
                            lhead->dhead=(struct dlink *)malloc(sizeof(struct dlink));
                            lhead->next=NULL;
                            printf("Please choose the family:\n");
                            prilibindex(1);
                            printf("Plese input the family you chose\n");
                            for(n=0;n<50;n++)
                                temp[n]='\0';
                            gets(temp);
                            for(n=0;n<50;n++)
                                fname[n]='\0';
                            for(n=0;n<50;n++)
                                tname[n]='\0';
                            strcpy(tname,temp);
                            i=chosel(temp,fname);
                            if(i==-1)
                            {
                                printf("wrong database name!\n");
                                printf("press any key to continue!\n");
                                getch();
                                goto rechlib2;
                            }
                            openlib(fname,lhead);
                            printf("change family database successfully!\n");
                            printf("Press any key to back to forward page!\n");
                            getch();
                            goto face1;
                            break;
                        }                        
                    case 4:
                        {
                            savelib(fname,lhead);
                            goto face2;
                            break;
                        }

                    case 0:
                        {
                            savelib(fname,lhead);
                            printf("\n");
                            exit(0);
                            break;
                        }
                    default:
                        {
                            printf("\nWrong order!\n");
                            printf("please any key to back to forword pag!\n");
                            getch();
                            goto face2;
                            break;
                        }
                }
            }
            if(login==0)
            {
                printf("\nThe username didn't match the passwords!\n");
                printf("press any key to continue\n");
                getch();
                goto face0;
            }                    
            break;
        }        
        case 2:
        {        
            rech=0;
            rech=libsearch(lhead,tname);
            if(rech==-1)
                goto face1;
            break;
        }
        case 3:
        {
            savelib(fname,lhead);
            savelib("lib_admin.lib",ahead);
            goto rechd;
            break;

        }
        case 0:
        {
            savelib(fname,lhead);
            savelib("lib_admin.lib",ahead);
            printf("\n");
            exit(0);
            break;
        }
        default:
        {
            printf("\nwrong order!\n");
            printf("please any key to continue\n");
            getch();
            goto face0;
            break;
        }
    }

}