/*
** EPITECH PROJECT, 2017
** my_put_extra.c
** File description:
**
*/

#include "cipher.h"

void my_put_matrix(int *m, int size)
{
	int i = 0;
	int modulo = 2;

	if (size <= 16)
		modulo = 4;
	if (size <= 9)
		modulo = 3;
	if (size <= 4)
		modulo = 2;
	while (i < size) {
		if ((i + 1) % modulo != 0)
			printf("%-11d", m[i]);
		else
			printf("%d", m[i]);
		i++;
		if (i % modulo == 0)
			printf("%c", '\n');
	}
}

void my_put_float_matrix(float *m, int size)
{
	int i = 0;
	int modulo = 2;

	if (size <= 16)
		modulo = 4;
	if (size <= 9)
		modulo = 3;
	if (size <= 4)
		modulo = 2;
	while (i < size) {
		if (m[i] == 0)
			printf("%-11s", "0.0");
		else if ((i + 1) % modulo != 0)
			printf("%-11.3f", m[i]);
		else
			printf("%.3f", m[i]);
		i++;
		if (i % modulo == 0)
			printf("\n");
	}
}

void my_put_result(int *m, int size)
{
	int i;

	for (i = 0; i < size; i++) {
		if (m[i] != 0)
			printf("%d", m[i]);
		else
			continue;
		if (i < size && m[i + 1] != 0)
			printf("%c", ' ');
	}
}

void my_put_string_result(int *m)
{
	int i;

	for (i = 0; m[i]; i++)
		printf("%c", m[i]);
}