// [Easy] Pangrams
// 
// "A pangram or holoalphabetic sentence for a given alphabet is a sentence using 
// every letter of the alphabet at least once." A good example is the English-language 
// sentence "The quick brown fox jumps over the lazy dog"; note how all 26 
// English-language letters are used in the sentence.
// 
// Input Description
// 
// On standard console input, you will be given a single integer on the first line 
// of input. This integer represents the number of lines you will then receive, each 
// being a string of alpha-numeric characters ('a'-'z', 'A'-'Z', '0'-'9') as well as 
// spaces and period.
// 
// Output Description
// 
// For each line of input, print either "True" if the given line was a pangram, or 
// "False" if not.

// UNFINISHED

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isPangram(char *);

int main()
{
	char input[] = "3\nThe quick brown fox jumps over the lazy dog.\nPack my box with five dozen liquor jugs.\nSaxophones quickly blew over my jazzy hair.";
	const char delimiter[] = "\n";
	char *sentence;
	
	strtok(input, delimiter);
	
	while(sentence != NULL) {
		sentence = strtok(NULL, delimiter);
		
		if (sentence == NULL)
			break;
		
 		if (isPangram(sentence) == TRUE) {
 			printf("True\n");
 		} else {
 			printf("False\n");
 		}
	}
}

/* tests if a string is a pangram */
int isPangram(char *line)
{
	char letter;
	
// 	for each letter from a-z, checks if line contains it and returns false if not
	for (letter = 'a'; letter != 'z'; letter++) {
		if (strchr(line, letter) == NULL) {
			return FALSE;
		}
	}
	
	return TRUE;
}
