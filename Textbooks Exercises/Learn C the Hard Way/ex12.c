#include <stdio.h>

int main(int argc, char *argv[])
{
	char arr[4] = { 'A', 's', 's', '\0' };
	printf("%s", arr);

	// yields a stack smashing detected error from OS
	// arr[4] = 's';

	printf("%c", arr[10]);

	return 0;	
}
