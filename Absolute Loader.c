#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    FILE *f;
    f = fopen("objextfile.txt", "r");
    int loc = 0;
    int start = 0x0;
    int i, k;
    char startaddr[10];

    char row[100];
    fscanf(f, "%s", row);
    do
    {
        fscanf(f, "%s", row);
        if (row[0] == 'T')
        {
            // printf("Inside");
            for (i = 2, k = 0; i < 8; i++, k++)
                startaddr[k] = row[i];
            startaddr[k] = '\0';
            // printf("%s",startaddr);
            loc = strtol(startaddr, NULL, 16);
            // printf("\n%x", loc);
            i = 12;
            while (row[i] != '$')
            {
                if (row[i] != '^')
                {
                    printf("\n00%x\t%c%c", loc, row[i], row[i + 1]);
                    loc += 1;
                    i += 2;
                }
                else
                    i += 1;
            }
        }
        if(row[0]=='E')
            break;
    }while((!feof(f)));

}