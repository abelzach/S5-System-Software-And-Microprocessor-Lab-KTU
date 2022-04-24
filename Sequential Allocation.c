#include<stdio.h>
int n,c=1;
void main(){
        int x,b[20],flag[20]={0},i,l=0;
        char fname[10][10],ch;
        printf(" Enter the total number of blocks : ");
        scanf("%d",&n);
        do{
                printf("\n Enter file name: ");
                scanf("%s", &fname[c]);
                printf(" Enter the number of blocks in the file : ");
                scanf("%d",&b[c]);
                x = n - l;
                if(x < b[c])
                        printf(" File cannot be allocated");
                else{
                        for(i=l;i<l+b[c];i++){
                                flag[i] = c+1;
                        }
                        l += b[c];
                        c++;
                }
                printf("\nDo you want to add more files ?(y/n)");
                scanf("%s",&ch);
        }while(ch == 'y' || ch  == 'Y');
        printf("\n Name \t Size \t Blocks allocated ");
        
        for(i=1;i < c;i++){
                printf("\n %s \t   %d \t ",fname[i],b[i]);
                for(int k=0;k<n;k++){
                        if(flag[k] == (i+1))
                                printf("%d ",k);
                }
                printf("\n");
        }
}
