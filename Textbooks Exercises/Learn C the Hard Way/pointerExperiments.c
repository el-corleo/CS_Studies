#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

struct Person
{
	int id;
	char *name;
};

#define ABNORMAL_TERMINATION -1

typedef int (*compare_person)(struct Person *a, struct Person *b);

void die(struct Person *p, char *message)
{
	free(p);
	
	if (errno)	perror(message);
	else		printf("ERROR: %s\n", message);
	
	exit(ABNORMAL_TERMINATION);
}

void changeRef(struct Person **p)
{
	*p = malloc(sizeof(struct Person));
	if(!*p)	die(*p, "Memory error.");
	
	(*p)->name = "BOBO";
	(*p)->id = 12;
}

void doNotChangeRef(struct Person *p)
{
	p = malloc(sizeof(struct Person));
	if(!p)	die(p, "Memory error.");
	
	p->name = "ROBO";
	p->id = 42;
}

int compare_by_name(struct Person *a, struct Person *b)
{
	if (a->name[0] == b->name[0])		return 0;
	else if(a->name[0] > b->name[0])	return 1;
	else					return -1;
}

int compare_by_id(struct Person *a, struct Person *b)
{
	if (a->id == b->id)	return 0;
	else if(a->id > b->id)	return 1;
	else			return -1;
}

void display_better(struct Person *a, struct Person *b, compare_person cmp)
{
	printf("%d\n", cmp(a, b));
}

int main(int argc, char *argv[])
{

	struct Person *person_1 = malloc(sizeof(struct Person));
	struct Person *person_2 = malloc(sizeof(struct Person));
	if(!person_1)	die(person_1, "Memory error.");
	if(!person_2)	die(person_2, "Memory error.");
	
	person_1->name = "GLOBO";
	person_1->id = 10;
	
	person_2->name = "GSOBO";
	person_2->id = 10;
	
	printf("%s\n", person_1->name);
	printf("%d\n", person_1->id);
	display_better(person_1, person_2, compare_by_name);
	display_better(person_1, person_2, compare_by_id);

	doNotChangeRef(person_1);
	printf("%s\n", person_1->name);
	printf("%d\n", person_1->id);

	struct Person **pers = &person_1; // &var because pointers point to addresses!!
	changeRef(pers);
	printf("%s\n", person_1->name);
	printf("%d\n", person_1->id);
	
	free(person_1);
	free(person_2);
	// free(pers); // created on stack; cannot be freed using free() as it is freed automatically

	return 0;
}
