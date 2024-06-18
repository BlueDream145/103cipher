/*
** EPITECH PROJECT, 2017
** my_utils.c
** File description:
**
*/

#include "cipher.h"

int number_digits(int nbr)
{
	int n = 1;
	int po = 10;

	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= po) {
		n++;
		if (po > 214748364)
			break;
		po *= 10;
	}
	return (n);
}

int get_matrix_size(char *str)
{
	int len = strlen(str);

	if (len <= 4)
		return (4);
	if (len <= 9)
		return (9);
	if (len <= 16)
		return (16);
	return (4);
}

int get_correct_size(struct request *instance, int len)
{
	int size;

	if (instance->key_len == 4)
		size = 2;
	if (instance->key_len == 9)
		size = 3;
	if (instance->key_len == 16)
		size = 4;
	while (len % size != 0)
		len++;
	return (len);
}

int get_size(struct request *instance)
{
	int size;

	if (instance->key_len == 4)
		size = 2;
	if (instance->key_len == 9)
		size = 3;
	if (instance->key_len == 16)
		size = 4;
	return (size);
}