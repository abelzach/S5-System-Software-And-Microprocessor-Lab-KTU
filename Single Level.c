#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char name[10], directory[10], file[20][10];
	int flag = 0, n = 0, i, ch, j;
	printf("\n Enter the name of the directory :");
	scanf("%s", directory);
X:
	printf("\nMENU \n 1. Create\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit \n Enter choice ");
	scanf("%d", &ch);
	switch (ch)
	{

	case 1:
		printf("Enter the file name :");
		scanf("%s", name);
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(name, file[i]) == 0)
			{
				printf("File already exists.\n");
				flag = 1;
			}
		}
		if (flag == 0)
		{
			strcpy(file[n], name);
			n++;
			printf("File created.\n");
		}
		goto X;
	case 2:
		printf("Enter the file name :");
		scanf("%s", name);
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(name, file[i]) == 0)
			{
				flag = 1;
				for (j = i; j < n - 1; j++)
					strcpy(file[i], file[i + 1]);
				n--;
				printf("File deleted");
			}
		}
		if (flag == 0)
		{
			printf("File not deleted");
		}
		goto X;

	case 3:
		printf("Enter the file name :");
		scanf("%s", name);
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(name, file[i]) == 0)
			{
				printf("File present");
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("File does not exist");
		}
		goto X;

	case 4:
		printf("\n FILES UNDER %s", directory);
		for (i = 0; i < n; i++)
			printf("\n - %s", file[i]);
		goto X;

	case 5:
		exit(0);
	}
}