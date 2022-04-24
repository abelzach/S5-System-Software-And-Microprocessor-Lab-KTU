#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char bit[100];
void convert(char h[]){
    int l;
    l = strlen(h);
    strcpy(bit, "");
    for(int i=0; i<l; i++)
    switch(h[i]) {
        case '0':
            strcat(bit, "0000");
            break;
        case '1':
            strcat(bit, "0001");
            break;
        case '2':
            strcat(bit, "0010");
            break;
        case '3':
            strcat(bit, "0011");
            break;
        case '4':
            strcat(bit, "0100");
            break;
        case '5':
            strcat(bit, "0101");
            break;
        case '6':
            strcat(bit, "0110");
            break;
        case '7':
            strcat(bit, "0111");
            break;
        case '8':
            strcat(bit, "1000");
            break;
        case '9':
            strcat(bit, "1001");
            break;
        case 'A':
            strcat(bit, "1010");
            break;
        case 'B':
            strcat(bit, "1011");
            break;
        case 'C':
            strcat(bit, "1100");
            break;
        case 'D':
            strcat(bit, "1101");
            break;
        case 'E':
            strcat(bit, "1110");
            break;
        case 'F':
            strcat(bit, "1111");
            break;
        default:
            printf("Enter valid");
    }
}
void main() {
    int addr,adhex;
    int len,i=0;
    int op;
    char a[50], b[50],c[50],d[50],ad[50];
    int st = 0x0;
    printf("Enter start address: ");
    scanf("%x", &st);
    FILE *fp = fopen("reloc.txt", "r");
    if(fp != NULL)
    {
        fscanf(fp, "%s%s%x%x", a,b,c,d);
        fscanf(fp, "%s", a);
        while(strcmp(a,"E") != 0){
            if(strcmp(a,"T")==0){
                int flag = 0;
                fscanf(fp, "%x%s%s", &addr, b, c);
                addr += st;
                convert(c);
                for (int i = 0; i < 10;i++){
                    fscanf(fp, "%x%s", &op, ad);
                    if(ad[strlen(ad)-1]=='$'){
                        flag = 1;
                        ad[strlen(ad) - 1] = '\0';
                    }
                    adhex = strtol(ad, NULL, 16);
                    if (bit[i] == '1')
                    {
                        adhex += st;
                    }
                    printf("%x\t%x%x\n",addr,op,adhex);
                    addr += 3;
                    if(flag==1)
                        break;
                }
                fscanf(fp, "%s", a);
            }
        }
    }
}