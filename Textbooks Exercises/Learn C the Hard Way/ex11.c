#include <stdio.h>

int main(int argc, char *argv[])
{
	int nums[4] = { 0 };

	printf("%d, %d, %d, %d, %d are all nums", nums[0], nums[1], nums[2], nums[3], nums[4]);

	char name[4] = { 'a' };
	
	printf("\n%s", name);
	
	char *newName = "Bobo";

	printf("\n%s", newName);

	char name_2[4] = { 'a', 's', 's', '\0'};

	int i = (int) name_2;

	printf("\n%d (char array name as int)\n", i);	

	return 0;
}
