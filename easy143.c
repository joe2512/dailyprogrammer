// [Easy] Braille
// 
// Braille is a writing system based on a series of raised / lowered bumps on a material, 
// for the purpose of being read through touch rather than sight. It's an incredibly 
// powerful reading & writing system for those who are blind / visually impaired. Though 
// the letter system has up to 64 unique glyph, 26 are used in English Braille for letters. 
// The rest are used for numbers, words, accents, ligatures, etc.
// 
// Your goal is to read in a string of Braille characters (using standard English Braille 
// defined here) and print off the word in standard English letters. You only have to 
// support the 26 English letters.
// 
// Input Description
// 
// Input will consistent of an array of 2x6 space-delimited Braille characters. This 
// array is always on the same line, so regardless of how long the text is, it will always 
// be on 3-rows of text. A lowered bump is a dot character '.', while a raised bump is an 
// upper-case 'O' character.
// 
// Output Description
// 
// Print the transcribed Braille.

// UNFINISHED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BRAILLESIZE 6

char brailleLetter(char braille[BRAILLESIZE]);
// THINKS ABOUT REMOVING THE VAR NAME IN LINE ABOVE


int main()
{
	char input[] = "O. O. O. O. O. .O O. O. O. OO\nOO .O O. O. .O OO .O OO O. .O\n.. .. O. O. O. .O O. O. O. ..";
	const char delimiter[] = "\n", delimiter2[] = " ";
	char *row1, *row2, *row3, brl_digits[BRAILLESIZE] = "110011";
	int x = 0, no_of_letters, i;
	
// Assign each of the 3 rows of the input to variables.
	printf("Input Braille:\n");
	do {
		if (x == 0) {
			row1 = strtok(input, delimiter);
			printf("%s\n", row1);
		} else if (x == 1) {
			row2 = strtok(NULL, delimiter);
			printf("%s\n", row2);
		} else if (x == 2) {
			row3 = strtok(NULL, delimiter);
			printf("%s\n", row3);
		}
		x++;
	} while (x <= 3);
	
	no_of_letters = (strlen(row1) + 1) / 3;
	
// 	Convert the braille to 6 digits then pass the digits to brailleLetter
// 	for (i = 1; i <= no_of_letters; i++) {
// 	
// 	}
// 	printf("%d", no_of_letters);
	
	brailleLetter(brl_digits);	
}

/* inputs Braille as 6 bit binary number eg. 101011 where 1s are raised and 0s are lowered,
	and the bumps are read left to right one row at a time - returns a letter */
char brailleLetter(char braille[BRAILLESIZE])
{
	int brl_binary;
	char braille_letters[] = "                     s i   j t a kue ozb lvh r c m dxnyf p g q ";
	char a;
	
// 	finds the decimal representation of the 6 binary digits
	brl_binary = strtol(braille, (char **)0, 2);
	printf("%d\n", brl_binary);
	
//  looks up the nth position in the array of the decimal representation which keeps 
//  the values 
	a = braille_letters[51];
	printf("%d\n", braille_letters[brl_binary]);
	printf("%d\n", a);
	/* current problem is this prints out numbers instead of the chars it should */
}