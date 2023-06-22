#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_info - Structure for holding program variables and arguments.
 * @arg: Value argument
 * @file: Pointer to monty file
 * @content: Line content
 * @lifi: Flag to change between stack and queue behavior
 * Description: Structure that carries values and flags throughout the program
 */
typedef struct bus_info
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t interpret;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_op(stack_t **top, unsigned int number);
void pall_op(stack_t **top, unsigned int number);
void pint_op(stack_t **top, unsigned int number);
int executeMonty(char *input, stack_t **data, unsigned int line, FILE *file);
void free_list(stack_t *top);
void pop_op(stack_t **top, unsigned int line);
void swap_op(stack_t **top, unsigned int line);
void add_top(stack_t **top, unsigned int line);
void nop_op(stack_t **top, unsigned int line);
void sub_op(stack_t **top, unsigned int line);
void divide_top_two(stack_t **top, unsigned int line);
void mul_op(stack_t **top, unsigned int line);
void mod_op(stack_t **top, unsigned int line);
void pchar_op(stack_t **top, unsigned int line);
void printString(stack_t **top, unsigned int line);
void rotate_op(stack_t **top, unsigned int line);
void rotate_bottom(stack_t **top, __attribute__((unused)) unsigned int line);
void insertNode(stack_t **top, int n);
void enqueue(stack_t **top, int n);
void queue_op(stack_t **top, unsigned int line);
void stackTop(stack_t **top, unsigned int line);

#endif /* MONTY_H */
