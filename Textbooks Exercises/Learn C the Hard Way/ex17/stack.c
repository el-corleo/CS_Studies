#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define STACK_SIZE 32 

struct IntStack
{
	int ind;
	int stack[STACK_SIZE];
};

void die(const char *message, struct IntStack *stack);

void Stack_close(struct IntStack *stack)
{
	free(stack);
}

void Stack_push(struct IntStack *stack, int value)
{
	if (stack->ind < STACK_SIZE-1)	stack->stack[(stack->ind)++] = value;
	else				printf("Stack size exceed.");
}

int Stack_pop(struct IntStack *stack)
{
	if (stack->ind > 0)	return stack->stack[--(stack->ind)];
	else			{ printf("No items on stack."); return -1; }
}

void die(const char *message, struct IntStack *stack)
{
	Stack_close(stack);
	if (errno)	perror(message);
	else		printf("ERROR: %s\n", message);

	exit(1);
}

int main(int argc, char *argv[])
{
	struct IntStack *stack = malloc(sizeof(struct IntStack));

	int value = 0;

	for (int i = 1; i < argc; i++)
	{
		switch ((char) argv[i][0])
		{
			case '+':
				++i; 
				Stack_push(stack, atoi(argv[i]));
				printf("Pushed %d to stack.\n", atoi(argv[i]));
				break;
			case '-':
				printf("Popped %d from stack.\n", Stack_pop(stack));
				break;
			default:
				die("ILLEGAL command.\n", stack);
				break;
		}
	}

	return 0;
}
