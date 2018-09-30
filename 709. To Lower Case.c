//Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

#include <stdio.h>
#include <string.h>

char* toLowerCase(char* str)
{
	int i = 0;
	for (i = 0; i < strlen(str); i++)
	{
		//only uppercase letter perform operation
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 0x20;
		}
	}
	return str;
}


int main(int argc, char* argv[])
{
	char* input;
	char* output;

	if (argc == 1)
	{
		printf("please input a string after xx.exe or xx.out\n");
		return -1;
	}

	if (argc > 2)
	{
		printf("please input only one string!\n");
		return -1;
	}
	
	//get input string from argv[1]
	input = argv[1];
	printf("Input: \"%s\"\n", input);

	output = toLowerCase(input);
	printf("Output: \"%s\"\n", output);
	

	return 0;
}