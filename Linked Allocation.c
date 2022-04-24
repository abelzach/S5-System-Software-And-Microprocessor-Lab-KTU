#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct block
{
    struct block *next;
    int loc;
} *p = NULL, *c = NULL;
struct file
{
    char name[20];
    struct block *start;
    int size;
} files[10];
void main()
{
    int b, flag[20]={0}, i = 0, j, k=0, cl = 0;
    int n, count = 0;
    char name[20], names[10][20], ch;
    printf("Enter the total number of blocks : ");
    scanf("%d",&n);
    do
    {
        printf("\n Enter name of the file : ");
        scanf("%s", name);
        printf("\n Enter the number of blocks in the file : ");
        scanf("%d", &b);
        if (n - count < b)
            printf(" File cannot be allocated");
        else
        {
            for (j = 0; j < b; j++)
            {
                c = (struct block *)malloc(sizeof(struct block));
                while (flag[k] != 0){
                    k = rand()%(n+1);
                    printf("%d \n",k);
                }
                    
                c->loc = k;
                flag[k] = 1;
                if (j == 0)
                    files[i].start = c;
                else
                {
                    p = files[i].start;
                    while (p->next != NULL)
                        p = p->next;
                    p->next = c;
                }
            }
            count += b;
            files[i].size = b;
            strcpy(files[i++].name, name);
        }
        printf("Do you want to add more files? (y/n): ");
        scanf("\n%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    printf("\nAllocation table\nFile Name\tFile Size\tBlocks Allocated\n");
    for (j = 0; j < i; j++)
    {
        printf("%s\t\t%d\t\t", files[j].name, files[j].size);
        for (p = files[j].start; p != NULL; p = p->next)
            printf("%d ", p->loc);
        printf("\n");
    }
}