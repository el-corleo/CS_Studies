# include <stdio.h>

int main(int argc, char *argv[])
{
	char nul_byte = '\0';
	int bugs = 1231231;
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n", care_percentage);
}
