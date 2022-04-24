#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char word[100];
    FILE *input = fopen("intermediate.txt", "r");
    FILE *optab = fopen("optab.txt", "r");
    FILE *symtab = fopen("symtab.txt", "r");
    char start[100];
    char label[100];
    int length;
    char opcode[100];
    char operand[100];
    int a[100];
    int t_length = 0;
    int i = 0;
    char opword[100];
    fscanf(input, "%s %s %s %s", start, label, opcode, operand);

    while (fscanf(input, "%s", word) != EOF)
    {
        strcpy(start, word);
        int flag = 0;
        fscanf(input, "%x %s %s %s", &length, label, opcode, operand);
        optab = fopen("optab.txt", "r");
        while (fscanf(optab, "%s", opword) != EOF)
        {
            if (strcmp(opword, opcode) == 0)
            {
                flag = 1;
            }
            fscanf(optab, "%s", opword);
        }
        if (flag == 1 || strcmp(opcode, "BYTE") == 0 || strcmp(opcode, "WORD") == 0)
        {
                if (t_length + length <= 9)
            {
                a[i] = t_length + length;
                t_length += length;
            }
            else
            {
                t_length = length;
                i++;
            }
        }
    }
    a[i] = t_length;
    for (int j = 0; j <= i; j++)
    {
     //   printf(" %d " , a[j] );
    }
    fseek(input, SEEK_SET, 0);
    fscanf(input, "%s %s %s %s", start, label, opcode, operand);
    printf("H^%s^%s^19",label,operand);
    i = 0;
    t_length = 0;
    while (fscanf(input, "%s", word) != EOF)
    {
        int flag = 0;
        fscanf(input, "%x %s %s %s", &length, label, opcode, operand);
        if (t_length == 0)
        {
            printf("\nT^%s^%d", word, a[i]);
        }
        t_length += length;
        if (t_length == a[i])
        {
            t_length = 0;
            i++;
        }

        // printf("%s\n" , opcode);
        optab = fopen("optab.txt", "r");
        while (fscanf(optab, "%s", opword) != EOF)
        {
            if (strcmp(opword, opcode) == 0)
            {
                flag = 1;
                fscanf(optab, "%s", opword);
                printf("^%s", opword);
                break;
            }
            fscanf(optab, "%s", opword);
        }
        if (flag == 1)
        {
            symtab = fopen("symtab.txt", "r");
            while (fscanf(symtab, "%s", opword) != EOF)
            {
                if (strcmp(opword, operand) == 0)
                {
                    flag = 1;
                    // printf("operand....%s\n" , operand);
                    fscanf(symtab, "%s", opword);
                    printf("%s", opword);
                    break;
                }
                fscanf(symtab, "%s", opword);
            }
        }
        else if (strcmp(opcode, "BYTE") == 0)
        {
            printf("^%x", strtol(operand, NULL, 16));
        }
    }
}