/* Test the case-mapping function */

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char *p = (char *)malloc(20);

	printf("Input a string: ");
	gets_s(p, strlen(p) - 1);
	printf("Mapped string is: ");

	for (; *p != '\0'; p++) {
		if (islower(*p))
			putchar(toupper(*p));
		else
			putchar(tolower(*p));
	}
	putchar('\n');

    return 0;
}