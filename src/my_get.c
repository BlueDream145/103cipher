/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
**
*/

#include "cipher.h"

struct request *get_request_instance(char *clear_msg, char *clear_key,
char *flag)
{
	const char *error_malloc = "Fatal error: malloc failed.";
	struct request *instance = malloc(sizeof(struct request));

	if (instance == NULL)
		report_error(error_malloc);
	instance->clear_msg = clear_msg;
	instance->clear_key = clear_key;
	if (flag[0] == '0')
		instance->flag = 0;
	else if (flag[0] == '1')
		instance->flag = 1;
	return (instance);
}