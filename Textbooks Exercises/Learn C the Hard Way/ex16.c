#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


struct Person 
{
	char *name;
	int age;
	int height;
	int weight;	
};

struct Person *Person_create(char *name, int age, int height, int weight) 
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who !=NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);	
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

struct Person makeStruct(char *name, int age, int height, int weight)
{
	struct Person p;
	p.name = strdup(name);
	p.age = age;
	p.height = height;
	p.weight = weight;

	return p;
}

void withoutPointers()
{
	char *name = "Bobo";
	int age = 10;
	int height = 11;
	int weight = 12;
	struct Person bobo = makeStruct(name, age, height, weight);
	
	printf("%s\n", bobo.name);
}

int main(int argc, char *argv[])
{
	struct Person *bobo = Person_create("Bobo Bosephus", 35, 183, 75);

	withoutPointers();
	Person_print(bobo);
	Person_destroy(bobo);	

	return 0;
}
