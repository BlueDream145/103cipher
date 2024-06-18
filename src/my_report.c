/*
** EPITECH PROJECT, 2017
** my_report.c
** File description:
**
*/

#include "cipher.h"

void report_error(const char *str)
{
	int len = 0;

	for (len = 0; str[len]; len++);
	write(2, str, len);
	exit(84);
}