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
    char names[20];
    int exes[10];
    int loc;
    int size;
} ind[10];

void main()
{
    int b, flag[20] = {0}, i = 0, j, k, cl = 0, n, count = 0;
    char name[20], ch;
    printf("Enter the total number of blocks : ");
        scanf("%d", &n);
    do{        
        printf("\n Enter name of the file : ");
        scanf("%s", name);
        printf("\n Enter the number of blocks in the file : ");
        scanf("%d", &b);
        if (n - count < b + 1)
            printf(" File cannot be allocated");
        else
        {
            strcpy(ind[i].names, name);
            do
                k = rand() % n + 1;
            while (flag[k] == 1);
            flag[k] = 1;
            count++;
            ind[i].loc = k;
            for (j = 0; j < b; j++)
            {
                do
                    k = rand() % n + 1;
                while (flag[k] == 1);
                flag[k] = 1;
                ind[i].exes[j] = k;
            }
            count += b;
            ind[i].size = b;
            i++;
        }
        printf("\nDo you want to add more files ?(y/n)");
        scanf("%s", &ch);
    } while (ch == 'y' || ch == 'Y');
    printf("\n \tAllocation table\nIndex\tFile Name\tFile Size\tBlocks Allocated\n");
    for (j = 0; j < i; j++)
    {
        printf("%d\t%s\t\t%d\t\t", ind[j].loc, ind[j].names, ind[j].size);
        for (k = 0; k <= ind[j].size; k++)
            printf("%d ", ind[j].exes[k]);
        printf("\n");
    }
}