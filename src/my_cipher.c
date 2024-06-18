/*
** EPITECH PROJECT, 2017
** my_cipher.c
** File description:
**
*/

#include "cipher.h"

void process_cipher(struct request *instance)
{
	int i;
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int size = get_size(instance);

	for (i = size - 1; i < instance->msg_len; i += size) {
		if (size == 2)
			cipher_4(instance, a, b);
		if (size == 3)
			cipher_9(instance, a, b, c);
		if (size == 4 && instance->flag == 1)
			cipher_16_rev(instance, a, b, c, d);
		else if (size == 4)
			cipher_16(instance, a, b, c, d);
		a = a + size;
		b = b + size;
		c = c + size;
		d = d + size;
	}
}

void cipher_4(struct request *instance, int a, int b)
{
	if (instance->flag == 1) {
		cipher_4_rev(instance, a, b);
		return;
	}
	instance->result[b - 1] = instance->ascii_msg[a] *
	instance->ascii_key[0] + instance->ascii_msg[b] *
	instance->ascii_key[2];
	instance->result[b] = instance->ascii_msg[a] *
	instance->ascii_key[1] + instance->ascii_msg[b] *
	instance->ascii_key[3];
}

void cipher_9(struct request *instance, int a, int b, int c)
{
	if (instance->flag == 1) {
		cipher_9_rev(instance, a, b, c);
		return;
	}
	instance->result[c - 2] = instance->ascii_msg[a] *
	instance->ascii_key[0] + instance->ascii_msg[b] *
	instance->ascii_key[3] + instance->ascii_msg[c] *
	instance->ascii_key[6];
	instance->result[c - 1] = instance->ascii_msg[a] *
	instance->ascii_key[1] + instance->ascii_msg[b] *
	instance->ascii_key[4] + instance->ascii_msg[c] *
	instance->ascii_key[7];
	instance->result[c] = instance->ascii_msg[a] *
	instance->ascii_key[2] + instance->ascii_msg[b] *
	instance->ascii_key[5] + instance->ascii_msg[c] *
	instance->ascii_key[8];
}

void cipher_16(struct request *instance, int a, int b, int c, int d)
{
	instance->result[d - 3] = instance->ascii_msg[a] *
	instance->ascii_key[0] + instance->ascii_msg[b] *
	instance->ascii_key[4] + instance->ascii_msg[c] *
	instance->ascii_key[8] + instance->ascii_msg[d] *
	instance->ascii_key[12];
	instance->result[d - 2] = instance->ascii_msg[a] *
	instance->ascii_key[1] + instance->ascii_msg[b] *
	instance->ascii_key[5] + instance->ascii_msg[c] *
	instance->ascii_key[9] + instance->ascii_msg[d] *
	instance->ascii_key[13];
	instance->result[d - 1] = instance->ascii_msg[a] *
	instance->ascii_key[2] + instance->ascii_msg[b] *
	instance->ascii_key[6] + instance->ascii_msg[c] *
	instance->ascii_key[10] + instance->ascii_msg[d] *
	instance->ascii_key[14];
	instance->result[d] = instance->ascii_msg[a] *
	instance->ascii_key[3] + instance->ascii_msg[b] *
	instance->ascii_key[7] + instance->ascii_msg[c] *
	instance->ascii_key[11] + instance->ascii_msg[d] *
	instance->ascii_key[15];
}