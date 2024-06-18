/*
** EPITECH PROJECT, 2017
** my_cipher_reverse.c
** File description:
**
*/

#include "cipher.h"

void reverse_key(struct request *instance)
{
	const char *error_reverse = "Unable to reverse matrix.\n";
	float deter;
	float *key = malloc(sizeof(float) * instance->key_len);

	if (instance->key_len == 4)
		deter = key_determinant_4(instance);
	if (instance->key_len == 9)
		deter = key_determinant_9(instance);
	if (deter == 0)
		report_error(error_reverse);
	if (instance->key_len == 4)
		process_reverse_4(key, instance, deter);
	if (instance->key_len == 9)
		process_reverse_9(key, instance, deter);
}

void process_reverse_4(float *key, struct request *instance, float deter)
{
	key[0] = instance->ascii_key[3] / deter;
	key[1] = - (instance->ascii_key[1]) / deter;
	key[2] = - (instance->ascii_key[2]) / deter;
	key[3] = instance->ascii_key[0] / deter;
	instance->reversed_key = key;
}

void process_reverse_9(float *key, struct request *instance, float deter)
{
	key[0] = (instance->ascii_key[4] * instance->ascii_key[8]
	- instance->ascii_key[5] * instance->ascii_key[7]) / deter;
	key[1] = - (instance->ascii_key[1] * instance->ascii_key[8]
	- instance->ascii_key[2] * instance->ascii_key[7]) / deter;
	key[2] = (instance->ascii_key[1] * instance->ascii_key[5]
	- instance->ascii_key[2] * instance->ascii_key[4]) / deter;
	key[3] = - (instance->ascii_key[3] * instance->ascii_key[8]
	- instance->ascii_key[5] * instance->ascii_key[6]) / deter;
	key[4] = (instance->ascii_key[0] * instance->ascii_key[8]
	- instance->ascii_key[2] * instance->ascii_key[6]) / deter;
	key[5] = - (instance->ascii_key[0] * instance->ascii_key[5]
	- instance->ascii_key[2] * instance->ascii_key[3]) / deter;
	key[6] = (instance->ascii_key[3] * instance->ascii_key[7]
	- instance->ascii_key[4] * instance->ascii_key[6]) / deter;
	key[7] = - (instance->ascii_key[0] * instance->ascii_key[7]
	- instance->ascii_key[1] * instance->ascii_key[6]) / deter;
	key[8] = (instance->ascii_key[0] * instance->ascii_key[4]
	- instance->ascii_key[1] * instance->ascii_key[3]) / deter;
	instance->reversed_key = key;
}