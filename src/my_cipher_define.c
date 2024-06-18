/*
** EPITECH PROJECT, 2017
** my_cipher_define.c
** File description:
**
*/

#include "cipher.h"

void set_key(struct request *instance)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	int len = get_matrix_size(instance->clear_key);
	int str_len = strlen(instance->clear_key);
	int i;

	instance->key_len = len;
	instance->ascii_key = malloc(sizeof(int) * len);
	if (instance->ascii_key == NULL)
		report_error(error_malloc);
	for (i = 0; i < len; i++)
		if (i >= str_len)
			instance->ascii_key[i] = 0;
		else if (i < str_len)
			instance->ascii_key[i] = (int)instance->clear_key[i];
}

void set_msg(struct request *instance)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	int str_len = strlen(instance->clear_msg);
	int i;
	int len = strlen(instance->clear_msg);

	len = get_correct_size(instance, len);
	instance->msg_len = len;
	instance->ascii_msg = malloc(sizeof(int) * len);
	if (instance->ascii_msg == NULL)
		report_error(error_malloc);
	for (i = 0; i < len; i++)
		if (i >= str_len)
			instance->ascii_msg[i] = 0;
		else if (i < str_len)
			instance->ascii_msg[i] = (int)instance->clear_msg[i];
}

void set_ascii_msg(struct request *instance, char *msg)
{
	int i;
	int count = 0;
	int val = 0;

	set_msg_len(instance, msg);
	for (i = 0; msg[i]; i++) {
		if (msg[i] >= '0' && msg[i] <= '9') {
			val *= 10;
			val += msg[i] - '0';
		}
		else if (val > 0) {
			instance->ascii_msg[count] = val;
			val = 0;
			count++;
		}
	}
	if (val != 0)
		instance->ascii_msg[count] = val;
}

void set_msg_len(struct request *instance, char *msg)
{
	const char *error_malloc = "Fatal error: malloc failed.";
	int len = 1;
	int i;

	for (i = 0; msg[i]; i++)
		if (msg[i] == ' ' && msg[i + 1] != ' ')
			len++;
	len = get_correct_size(instance, len);
	instance->ascii_msg = malloc(sizeof(int) * len);
	instance->msg_len = len;
	if (instance->ascii_msg == NULL)
		report_error(error_malloc);
}