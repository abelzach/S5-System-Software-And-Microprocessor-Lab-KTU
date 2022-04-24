#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct directory
{
    char dirName[10];
    char fileName[10][10];
    int filect;
} dir[10];
void main()
{
    int i, ch, dirct, flag, flag1, j, k;
    char f[30], d[30], name[10], x[10];
    dirct = 0;
    printf("\n Enter the name of the base directory ");
    scanf("%s", x);
X:
    printf("\n\t\tMENU\n 1. Create \n 2. Create File\n 3. Delete File\n 4. Search File\n 5. Display\n 6. Exit \n Enter choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\n Enter name of directory ");
        scanf("%s", dir[dirct].dirName);
        dir[dirct].filect = 0;
        dirct++;
        printf("Directory created");
        goto X;

    case 2:
        printf("\nEnter name of the directory ");
        scanf("%s", d);
        flag = 0;
        for (i = 0; i < dirct; i++)
        {
            if (strcmp(d, dir[i].dirName) == 0)
            {
                flag = 1;
                printf("Enter name of the file ");
                scanf("%s", name);
                flag1 = 0;
                for (k = 0; k < dir[k].filect; k++)
                {
                    if (strcmp(name, dir[i].fileName[k]) == 0)
                    {
                        printf("File already exists.\n");
                        flag1 = 1;
                    }
                }
                if (flag1 == 0)
                {
                    strcpy(dir[i].fileName[dir[i].filect], name);
                    dir[i].filect++;
                    printf("File created");
                    break;
                }
            }
        }
        if (flag == 0)
            printf("Directory %s not found", d);
        goto X;

    case 3:
        printf("\nEnter name of the directory ");
        scanf("%s", d);
        flag = 0;
        for (i = 0; i < dirct; i++)
        {
            if (strcmp(d, dir[i].dirName) == 0)
            {
                flag = 1;
                printf("Enter name of the file ");
                scanf("%s", f);
                flag1 = 0;
                for (k = 0; k < dir[i].filect; k++)
                {
                    if (strcmp(f, dir[i].fileName[k]) == 0)
                    {
                        flag1 = 1;
                        printf("File is deleted ");
                        for (j = k; j < dir[i].filect - 1; j++)
                            strcpy(dir[i].fileName[j], dir[i].fileName[j + 1]);
                        dir[i].filect--;
                    }
                }
                if (flag1 == 0)
                    printf("File %s not found", f);
            }
        }
        if (flag == 0)
            printf("Directory %s not found", d);
        goto X;

    case 4:
        printf("Enter the file to be searched ");
        scanf("%s", name);
        flag1 = 0;
        for (i = 0; i < dirct; i++)
        {
            for (k = 0; k < dir[i].filect; k++)
            {
                if (strcmp(name, dir[i].fileName[k]) == 0)
                {
                    flag1 = 1;
                    printf("File %s is found in directory %s", name, dir[i].dirName);
                }
            }
        }
        if (flag1 == 0)
            printf("File %s not found", name);
        goto X;

    case 5:
        if (dirct == 0)
            printf("\nNo Directory ");
        else
        {
            printf("\n%s", x);
            printf("\n Directory\tFiles");
            for (i = 0; i < dirct; i++)
            {
                printf("\n   %s\t\t", dir[i].dirName);
                for (k = 0; k < dir[i].filect; k++)
                    printf("%s\t", dir[i].fileName[k]);
            }
        }
        goto X;
    case 6:
        exit(0);
    }
}