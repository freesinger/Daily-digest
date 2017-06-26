/* Verity the Goldbache conjecture within 2017 */

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int x)
{
	int t;

	for (t = 2; t * t < x; t++)
		if (x % t == 0)
			return false;
	return true;
}

int main(void)
{
	int number, x, y;
	bool judge[2017] = { false };

	for (number = 6; number < 2017; number += 2) {
		for (x = 1; x < number; x++) {
			y = number - x;
			if (is_prime(x) && is_prime(y))
				judge[number] = true;
		}
	}

	for (number = 6; number < 2017; number += 2)
		if (judge[number] == false)
			printf("Wrong guess\n");

	printf("Right guess\n");

	return 0;
}