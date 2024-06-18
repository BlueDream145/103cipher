/*
** EPITECH PROJECT, 2017
** cipher.h
** File description:
**
*/

#ifndef cipher_
#define cipher_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

struct request {
	char *clear_msg;
	char *clear_key;
	int *result;
	int *ascii_msg;
	int *ascii_key;
	float *reversed_key;
	int msg_len;
	int key_len;
	int flag;
};

// main.c
int main(int ac, char **as);
void check(int ac, char **as);
void display(struct request *instance);

// my_cipher_define.c
void set_key(struct request *instance);
void set_msg(struct request *instance);
void set_ascii_msg(struct request *instance, char *msg);
void set_msg_len(struct request *instance, char *msg);

// my_cipher_deter.c
float key_determinant_4(struct request *instance);
float key_determinant_9(struct request *instance);

// my_cipher_rev.c
void cipher_4_rev(struct request *instance, int a, int b);
void cipher_9_rev(struct request *instance, int a, int b, int c);
void cipher_16_rev(struct request *instance, int a, int b, int c, int d);

// my_cipher_reverse.c
void reverse_key(struct request *instance);
void process_reverse_4(float *key, struct request *instance, float deter);
void process_reverse_9(float *key, struct request *instance, float deter);

// my_cipher.c
void process_cipher(struct request *instance);
void cipher_4(struct request *instance, int a, int b);
void cipher_9(struct request *instance, int a, int b, int c);
void cipher_16(struct request *instance, int a, int b, int c, int d);

// my_get.c
struct request *get_request_instance(char *clear_msg, char *clear_key,
char *flag);

// my_put.c
void my_put_matrix(int *m, int size);
void my_put_float_matrix(float *m, int size);
void my_put_result(int *m, int size);
void my_put_string_result(int *m);

// my_report.c
void report_error(const char *str);

// my_utils.c
int number_digits(int nbr);
int get_matrix_size(char *str);
int get_correct_size(struct request *instance, int len);
int get_size(struct request *instance);

#endif /* cipher */