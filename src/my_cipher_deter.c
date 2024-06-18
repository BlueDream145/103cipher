/*
** EPITECH PROJECT, 2017
** my_cipher_deter.c
** File description:
**
*/

#include "cipher.h"

float key_determinant_4(struct request *instance)
{
	float deter = (instance->ascii_key[0] * instance->ascii_key[3]) -
	(instance->ascii_key[2] * instance->ascii_key[1]);

	return (deter);
}

float key_determinant_9(struct request *instance)
{
	float deter = instance->ascii_key[0]
	* (instance->ascii_key[4] * instance->ascii_key[8]
	- instance->ascii_key[5] * instance->ascii_key[7])
	- instance->ascii_key[3] * (instance->ascii_key[1]
	* instance->ascii_key[8] - instance->ascii_key[2]
	* instance->ascii_key[7]) + instance->ascii_key[6]
	* (instance->ascii_key[1] * instance->ascii_key[5]
	- instance->ascii_key[2] * instance->ascii_key[4]);

	return (deter);
}