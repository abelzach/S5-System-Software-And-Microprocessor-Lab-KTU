#include<stdio.h>
#include<stdlib.h>
int n=0;
struct process{
        int fl;
        int id;
        int size;
        int nf;
        int f[10];
        int fragm;
}p[10];
void main()
{
        int l,i,j,m,f,fs,ch,a[20]={0},rem,frag=0;
        char cho;
        printf("\n Total memory : ");
        scanf("%d",&m);
        printf(" Frame size : ");
        scanf("%d",&fs);
        f = m/fs;
        rem = f;
        do{
                printf("\n\t\tMENU\n 1) Insert \n 2) Delete \n Enter your choice : ");
                scanf("%d",&ch);
                if(ch==1){
                        printf("Process ID : ");
                        scanf("%d",&p[n].id);
                        printf("Process size : ");
                        scanf("%d",&p[n].size);
                        if(p[n].size % fs == 0 )
                                p[n].nf = p[n].size/fs;
                        else{
                                p[n].nf = (p[n].size/fs)+1;
                                if(p[n].nf <= rem){
                                        p[n].fragm = (fs*p[n].nf)-p[n].size;
                                        frag += p[n].fragm;
                                }
                        }
                        if(p[n].nf <= rem)
                        {
                                p[n].fl = 1;
                                for(i = 0;i<p[n].nf;i++)
                                {
                                        while(a[j]!=0)
                                                j = rand()%f;
                                        a[j] = n+1;
                                        p[n].f[i] = j;
                                }
                                rem -= p[n].nf;
                                n++;
                        }
                        else{
                                printf("\nMemory overflow\n");
                        }
                }
                else if(ch == 2){
                        printf("Process id to delete : ");
                        scanf("%d",&l);
                        for(i=0;i<n;i++)
                                if(p[i].id == l)
                                        break;
                        for(int k=0;k<f;k++)
                        {
                                if(a[k] == i+1)
                                        a[k] = 0;
                        }
                        p[i].fl = 0;
                        rem += p[i].nf;
                        frag -= p[i].fragm;
                }
                printf("\n\tPage Table");
                printf("\n Process ID \t Size \t Frames Allocated");
                for(i=0;i<n;i++){
                        if(p[i].fl == 1){
                                printf("\n     %d \t\t %d \t ",p[i].id,p[i].size);
                                for(j=0;j<p[i].nf;j++)
                                        printf("%d ",p[i].f[j]);
                        }
                }
                printf("\n Total internal fragmentation : %d",frag);
                printf("\n Do you want to continue ?");
                scanf("%s",&cho);
        }while(cho=='y'||cho=='Y');
}
