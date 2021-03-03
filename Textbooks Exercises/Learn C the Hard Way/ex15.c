#include <stdio.h>
#include <assert.h>

void change_val(int *int_ptr)
{
	(*int_ptr)++;
}


int main(int argc, char *argv[])
{
	int ages[] = {13, 14, 15};
	char *names[] = {"Bobo", "Bob", "Janet"};

	int n_people = sizeof(ages) / sizeof(int);
	int i;
	for (i = 0; i < n_people; i++)
	{
		printf("%s is %d years old.\n", names[i], ages[i]);
	}


	int *curr_age = ages;
	char **curr_name = names;

	for (i = 0; i < n_people; i++)
	{
		printf("%s is %d years old.\n", curr_name[i], curr_age[i]);
	}

	int dog = 8;
	int *dog_ptr = &dog;
	assert(dog == *dog_ptr); //
	dog++;
	assert(dog == *dog_ptr); //
	dog = 90;
	assert(dog == *dog_ptr); //
	int god = 42;
	dog = god;
	assert(dog == *dog_ptr); //
	dog_ptr = &god;
	assert(dog == *dog_ptr); //
	int ogd = 25;
	dog = ogd;	
	assert(dog != *dog_ptr); //
	dog_ptr = dog;	
	//assert(dog == *dog_ptr); // segfault


	unsigned int num[] = { 10000000, 20};
	unsigned short *num_half_ptr = &num;

	printf("[%d, %d]\n", num[0], num[1]);
	printf("%p = address num[0], %p = address num[1]\n", &num[0], &num[1]);
	printf("%d = first, %d = second, %d = third, %d = fourth\n", *num_half_ptr, *(num_half_ptr + 1), *(num_half_ptr + 2), *(num_half_ptr + 3));
	printf("%p = first, %p = second, %p = third, %p = fourth\n", num_half_ptr, num_half_ptr + 1, num_half_ptr + 2, num_half_ptr + 3);

	int bobo = 10;
	int *bobo_ptr = &bobo;
	printf("%d = val bobo.\n", *bobo_ptr);
	change_val(bobo_ptr);
	printf("%d = val bobo.\n", *bobo_ptr);

	return 0;
}
