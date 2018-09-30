#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define MAX_WORDS_SIZE 100;
//#define MAX_EACH_WORD_SIZE 12;


char *getmorsecode(char inputchar)
{
	//define the full table for the 26 letters(lowercase) of the English alphabet
	// this vaiable is stored in txt segment, which is readonly and keep in the runtime 
	char* morsecodetable[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

	// define a pointer, point to the txt segment address
	char *p_morsecode = morsecodetable[inputchar - 'a'];

	//printf("p_morsecode = %p\n",p_morsecode);
	//printf("&p_morsecode = %p\n",&p_morsecode);

	//return the address of txt segment, note here &p_morsecode is the local variabl stored in stack.
	return p_morsecode;
}

int uniqueMorseRepresentations(char** words, int wordsSize)
{
	printf("wordsSize:%d\n", wordsSize);
	if (wordsSize == 0) return -1;

	char* p_morsecode_eachletter = NULL;
	int i, j = 0;

	char p_morsecode_concat[100][100] = {0};

	int transformations = 1;
	if (wordsSize == 1) return transformations;

	printf("The transformation of each word is:\n");

	int lenofeachword = 0;
	for (i = 0; i < wordsSize; i++)
	{
		//printf("each word: %s and word length:%d\n", words[i],strlen(words[i]));
		lenofeachword = strlen(words[i]);
		for (j = 0; j < lenofeachword; j++)
		{
			//printf("each char:%c\n", words[i][j]);
			p_morsecode_eachletter = getmorsecode(words[i][j]);
			//printf("coorispongding morse code: %s\n", p_morsecode_eachletter);

			//concat the morse code in each string
			strcat(p_morsecode_concat[i], p_morsecode_eachletter);
			//printf("after concat moresecode:%s\n", p_morsecode_concat[i]);
		}

		printf("%s-->%s\n", words[i], p_morsecode_concat[i]);

		if (i == 0) continue;
		//if not equal, transformations++
		if (strcmp(p_morsecode_concat[i], p_morsecode_concat[i - 1]) != 0)
		{
			transformations++;
		}
	}
	return transformations;
}


int main(int argc, char* argv[])
{
	//input words
	char* words[] = { "gin", "zen", "gig", "msg" };
	int wordsSize = 0;
	int result = 0;

	//printf("sizeof words:%d\n", sizeof(words));
	//printf("sizeof char*:%d\n", sizeof(words[0]));

	wordsSize = sizeof(words) / sizeof(words[0]);

	result = uniqueMorseRepresentations(words, wordsSize);

	printf("unique Morse Representations:%d\n", result);

	return 0;
}
