#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char word[100];
    int length = 0x0;
    int loc = 0x0;
    char label[100];
    char operand[100];
    char opcode[100];

    FILE *input = fopen("input.txt", "r");
    FILE *optab = fopen("optab.txt", "r");
    FILE *symtab = fopen("symtab.txt", "w");

    fscanf(input, "%s", label);
    fscanf(input, "%s", opcode);
    fscanf(input, "%s", operand);
    loc = strtol(operand, NULL, 16);

    printf("%x\t", loc);
    printf("%s\t", "-");
    printf("%s\t", label);
    printf("%s\t", opcode);
    printf("%x\t", loc);

    while (strcmp(opcode, "END") != 0)
    {
        printf("\n%x\t", loc);
        fscanf(input, "%s", label);
        fscanf(input, "%s", opcode);
        fscanf(input, "%s", operand);
        if (strcmp(label, "-") != 0)
        {
            fprintf(symtab, "%s\t%x\n", label, loc);
        }
        optab = fopen("optab.txt", "r");
        int flag = 0;
        while (fscanf(optab, "%s", word) != EOF)
        {
            if (opcode[0] == '+')
            {
                for (int i = 0; i < strlen(opcode) - 1; i++)
                {
                    opcode[i] = opcode[i + 1];
                }
                opcode[strlen(opcode) - 1] = '\0';
            }

            if (strcmp(word, opcode) == 0)
            {
                length = 0x3;
                printf("%x\t", length);
                loc = loc + length;
                flag = 1;
                break;
            }
            fscanf(optab, "%s", word);
        }

        if (flag == 0)
        {
            if (strcmp(opcode, "WORD") == 0)
            {
                length = 0x3;
                printf("%x\t", length);
                loc = length + loc;
            }
            else if (strcmp(opcode, "RESB") == 0)
            {
                length = strtol(operand, NULL, 16);
                printf("%x\t", length);
                loc = length + loc;
            }
            else if (strcmp(opcode, "BYTE") == 0)
            {
                length = strlen(operand) - 2;
                printf("%x\t", length);
                loc = length + loc;
            }
            else if (strcmp(opcode, "RESW") == 0)
            {
                length = atoi(operand) * 3;
                printf("%x\t", length);
                loc = length + loc;
            }
        }

        printf("%s\t", label);
        printf("%s\t", opcode);
        printf("%s\t", operand);
    }

    return 0;
}