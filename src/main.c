/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "cipher.h"

int main(int ac, char **as)
{
	const char *error_malloc = "Fatal error: malloc failed.\n";
	struct request *instance;

	check(ac, as);
	instance = get_request_instance(as[1], as[2], as[3]);
	set_key(instance);
	if (instance->flag == 0)
		set_msg(instance);
	else if (instance->flag == 1) {
		set_ascii_msg(instance, as[1]);
		reverse_key(instance);
	}
	instance->result = malloc(sizeof(int) * instance->msg_len);
	if (instance->result == NULL)
		report_error(error_malloc);
	process_cipher(instance);
	display(instance);
	free(instance);
	return (0);
}

void check(int ac, char **as)
{
	const char *error_usage = "Bad usage.\n";
	const char *error_syntax = "Bad syntax.\n";
	unsigned int i;

	if (ac != 4)
		report_error(error_usage);
	if (strlen(as[1]) == 0 || strlen(as[2]) == 0)
		report_error(error_syntax);
	if (atoi(as[3]) != 0 && atoi(as[3]) != 1)
		report_error(error_syntax);
	if (atoi(as[3]) == 1) {
		for (i = 0; i < strlen(as[1]); i++)
			if (!(as[1][i] >= '0' && as[1][i] <= '9')
			&& as[1][i] != ' ')
				report_error(error_syntax);
	}
}

void display(struct request *instance)
{
	const char *key_header = "Key matrix :\n";
	const char *msg_header_crypt = "Encrypted message :\n";
	const char *msg_header_decrypt = "Decrypted message :\n";

	printf("%s", key_header);
	if (instance->flag == 0) {
		my_put_matrix(instance->ascii_key, instance->key_len);
		printf("%s", msg_header_crypt);
		my_put_result(instance->result, instance->msg_len);
	}
	else {
		my_put_float_matrix(instance->reversed_key, instance->key_len);
		printf("%s", msg_header_decrypt);
		my_put_string_result(instance->result);
	}
	printf("%c", '\n');
}