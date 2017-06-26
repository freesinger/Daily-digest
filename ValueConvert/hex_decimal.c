#include<stdio.h>
#include<string.h>

int change(char num[50], int length);

int main(void)
{
	char num[50];
	int number;

	printf("Input a number:0x");
	gets(num);

	number = change(num, strlen(num));
	printf("Result is:%d\n", number);

	return 0;
}

int change(char num[50], int length)
{
	int j;
	int number = 0;

	for (j = 0; j < length; j++)
	{
		if ((*(num + j) >= '0') && (*(num + j) <= '9'))
			number = number * 16 + *(num + j) - '0';
		if ((*(num + j) >= 'A') && (*(num + j) <= 'F'))
			number = number * 16 + *(num + j) - 'A' + 10;
		if ((*(num + j) >= 'a') && (*(num + j) <= 'f'))
			number = number * 16 + *(num + j) - 'a' + 10;
	}

	return number;
}