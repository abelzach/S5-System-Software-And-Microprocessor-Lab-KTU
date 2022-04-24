#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct fname{
        char s[20];
        struct fname *next;
};

struct dir{
        int count;
        char id[20];
        struct dir *next[10];
        struct fname *file;
};

bool flag=false;
int check(char checker[], struct dir *root)
{
    struct fname *temp=root->file;
    int count=0;
    while(temp!=NULL)
    {
        if(strcmp(checker,temp->s)==0)
            return -1;
        else if(strcmp(checker,temp->s)<0)
            return count;  
        else
        {
            count++;
            temp=temp->next;
        }    
    }
    if(temp==NULL)
        return count;
}
void display(struct dir *root)
{
    if(root!=NULL)
    {
        printf("FOLDER NAME :%s\n",root->id);
        printf("FILE INSIDE %s : ",root->id);
        struct fname *x1=root->file;
        flag=false;
        while(x1!=NULL)
        {
            flag=true;
            printf("%s ",x1->s);
            x1=x1->next;
        }
        if(flag==false)
        {
            printf("EMPTY");
            flag=true;
        }
        printf("\n");
       
       
        printf("FOLDER INSIDE %s : ",root->id);
        int j=0;
        while(root->next[j]!=NULL)
        {
            printf("%s ",root->next[j]->id);
            j++;
        }
        if(j==0)
            printf("EMPTY\n\n");
        else
        {  
            printf("\n\n");
            j=0;
            while(root->next[j]!=NULL)
            {
                display(root->next[j]);
                j++;
            }
        }
    }
}
void create(struct dir **r)
{
    struct dir *root=*r;
    int ch,i,count;
    if(flag==false)
    {
        for(i=0;i<10;i++)
            root->next[i]=NULL;
        flag=true;
    }
    printf("OPTIONS\n1.CREATE A FILE\n2.ENOUGH\n3.CREATE SUBDIRECTORY\nENTER YOUR CHOICE FOR %s: ",root->id);
    scanf("%d",&ch);
    while(ch!=2)
    {
        switch(ch)
        {
            case 1:
                printf("ENTER FILE NAME : ");
                struct fname *temp=malloc(sizeof(struct fname));
                struct fname *prev,*cur;
                scanf("%s",temp->s);
                temp->next=NULL;
                if((count=check(temp->s,root))!=-1)
                {
                    if(count==0)
                    {
                        if(root->file==NULL)
                            root->file=temp;
                        else
                            temp->next=root->file;
                        root->file=temp;
                    }
                    else
                    {
                        i=0;
                        cur=root->file;
                        while(i<count)
                        {
                            prev=cur;
                            cur=cur->next;
                            i++;
                        }
                        if(cur==NULL)
                            prev->next=temp;
                        else
                        {
                            prev->next=temp;
                            temp->next=cur;
                        }
                    }
                }
                else
                    printf("SAME FILE ALREADY EXISTS\n");
                break;
            case 3:
                printf("ENTER DIRECTORY NAME : ");
                struct dir *root_sub=malloc(sizeof(struct dir));
                scanf("%s",root_sub->id);
                root_sub->count=0;
                root_sub->file=NULL;
                root->next[(root->count)++]=root_sub;
                flag=false;
                create(&root_sub);
                break;
            default:
                printf("ENTER CORRECT CHOICE\n");
        }
        printf("ENTER YOUR CHOICE FOR %s : ",root->id);
        scanf("%d",&ch);
    }
   
}
void delete(struct dir *root)
{
    char del[20],loc[100];
    printf("ENTER THE FILE TO BE DELETED : ");
    scanf("%s",del);
    printf("ENTER THE FILE LOCATION : ");
    scanf("%s",loc);
    if(root==NULL)
        printf("DIRECTORY DOES NOT EXIST\n");
    else
    {
        bool status=true;
        char folder[100]="\0";
        int i=0;
        struct dir *dtemp=root;
        for(;i<strlen(loc);i++)
        {
            if(loc[i]=='/')
            {
                int k=0;
                strcat(folder,"\0");
                while(dtemp!=NULL)
                {
                    if(strcmp(folder,dtemp->id)==0)
                        break;
                    else
                        dtemp=root->next[k++];
                }
                strcpy(folder,"\0");
                if(dtemp==NULL)
                {
                    printf("DIRECTORY DOES NOT EXIST\n");
                    status=false;
                    return;
                }
                root=dtemp;
            }
            else
            {
                char a=loc[i];
                strncat(folder,&a, 1);
            }
        }
        struct fname *temp=dtemp->file;
        struct fname *prev=dtemp->file;
        while(temp!=NULL)
        {
            if(strcmp(temp->s,del)==0)
            {
                if(temp==prev)
                    dtemp->file=temp->next;
                else
                    prev->next=temp->next;
                free(temp);
                break;
            }
            else if(strcmp(del,temp->s)>0)
            {
                prev=temp;
                temp=temp->next;
            }
            else
            {
                printf("FILE NOT FOUND\n");
                return;    
            }
        }
        if(temp==NULL)
        {
            printf("FILE NOT FOUND\n");
            return;
        }
       
    }
    display(root);
}
void search(struct dir *root,char loc[],char key[])
{
    struct dir *dtemp=root;
    if(dtemp!=NULL)
    {
        strcat(loc,dtemp->id);
        strcat(loc,"/\0");
        struct fname *x1=dtemp->file;
        while(x1!=NULL)
        {
            if(strcmp(x1->s,key)==0)
            {
                printf("FOUND AT LOCATION : %s\n",loc);
                break;
            }
            x1=x1->next;
        }
        printf("\n");
    }
    int i=0;
    while(root->next[i]!=NULL)
    {
        search(root->next[i++],loc,key);
        int j=strlen(loc)-2;
        for(;j>=0;j--)
        {
            if(loc[j]=='/')
                break;
        }
        char c[100];
        memcpy(c,&loc[0],j+1);
        c[j+1]='\0';
        strcpy(loc,c);
    }
}
void main()
{
    int ch;
    printf("OPTIONS \n1.CREATE\n2.SEARCH\n3.DISPLAY\n4.DELETE\n5.EXIT\nENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    while(1)
    {
        switch(ch)
        {
            case 1:
                printf("ENTER DIRECTORY NAME : ");
                struct dir *root=malloc(sizeof(struct dir));
                scanf("%s",root->id);
                root->count=0;
                root->file=NULL;
                create(&root);
                break;
            case 2:
                printf("ENTER THE FILE NAME TO BE SEARCHED : ");
                char key[20];
                scanf("%s",key);
                char loc[100]="\0";
                printf("%s\n",loc);
                search(root,loc,key);
                break;
            case 3:
                display(root);
                break;
            case 4:delete(root);
                break;
            case 5:exit(0);
                break;
            default:
                printf("ENTER CORRECT CHOICE\n");
        }
        printf("OPTIONS \n1.CREATE\n2.SEARCH\n3.DISPLAY\n4.DELETE\n5.EXIT\nENTER YOUR CHOICE : ");
        scanf("%d",&ch);
    }
}