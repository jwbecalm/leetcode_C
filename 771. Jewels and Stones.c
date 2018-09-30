/*
You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have.  Each character in S is a type of stone you have.  
You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/
#include <stdio.h>
#include <string.h>

int numJewelsInStones(char* jewels, char* stones)
{
	int i, j = 0;
	int num = 0;

	for (i = 0; i < strlen(jewels); i++)
	{
		for (j = 0; j < strlen(stones); j++)
		{
			if (jewels[i] == stones[j])	num++;
		}
	}

	return num;
}

int main(int argc, char* argv[])
{
	char* J = "aA";
	char* S = "aAAbbbb";

	printf("J = %s\n",J);
	printf("S = %s\n",S);

	int num = 0;
	num = numJewelsInStones(J, S);
	printf("num of Jewels In Stones: %d\n", num);
}