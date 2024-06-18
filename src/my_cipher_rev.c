/*
** EPITECH PROJECT, 2017
** my_cipher_rev.c
** File description:
**
*/

#include "cipher.h"

void cipher_4_rev(struct request *instance, int a, int b)
{
	instance->result[b - 1] = round(instance->ascii_msg[a] *
	instance->reversed_key[0] + instance->ascii_msg[b] *
	instance->reversed_key[2]);
	instance->result[b] = round(instance->ascii_msg[a] *
	instance->reversed_key[1] + instance->ascii_msg[b] *
	instance->reversed_key[3]);
}

void cipher_9_rev(struct request *instance, int a, int b, int c)
{
	instance->result[c - 2] = round(instance->ascii_msg[a] *
	instance->reversed_key[0] + instance->ascii_msg[b] *
	instance->reversed_key[3] + instance->ascii_msg[c] *
	instance->reversed_key[6]);
	instance->result[c - 1] = round(instance->ascii_msg[a] *
	instance->reversed_key[1] + instance->ascii_msg[b] *
	instance->reversed_key[4] + instance->ascii_msg[c] *
	instance->reversed_key[7]);
	instance->result[c] = round(instance->ascii_msg[a] *
	instance->reversed_key[2] + instance->ascii_msg[b] *
	instance->reversed_key[5] + instance->ascii_msg[c] *
	instance->reversed_key[8]);
}

void cipher_16_rev(struct request *instance, int a, int b, int c, int d)
{
	instance->result[d - 3] = round(instance->ascii_msg[a] *
	instance->reversed_key[0] + instance->ascii_msg[b] *
	instance->reversed_key[4] + instance->ascii_msg[c] *
	instance->reversed_key[8] + instance->ascii_msg[d] *
	instance->reversed_key[12]);
	instance->result[d - 2] = round(instance->ascii_msg[a] *
	instance->reversed_key[1] + instance->ascii_msg[b] *
	instance->reversed_key[5] + instance->ascii_msg[c] *
	instance->reversed_key[9] + instance->ascii_msg[d] *
	instance->reversed_key[13]);
	instance->result[d - 1] = round(instance->ascii_msg[a] *
	instance->reversed_key[2] + instance->ascii_msg[b] *
	instance->reversed_key[6] + instance->ascii_msg[c] *
	instance->reversed_key[10] + instance->ascii_msg[d] *
	instance->reversed_key[14]);
	instance->result[d] = round(instance->ascii_msg[a] *
	instance->reversed_key[3] + instance->ascii_msg[b] *
	instance->reversed_key[7] + instance->ascii_msg[c] *
	instance->reversed_key[11] + instance->ascii_msg[d] *
	instance->reversed_key[15]);
}