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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BRAILLESIZE 6

char brailleLetter(char [BRAILLESIZE]);


int main()
{
	char input[] = "O. O. O. O. O. .O O. O. O. OO\nOO .O O. O. .O OO .O OO O. .O\n.. .. O. O. O. .O O. O. O. ..";
	const char delimiter[] = "\n", delimiter2[] = " ";
	char *row1, *row2, *row3, brl_digits[BRAILLESIZE];
	int x = 0, no_of_letters, i, j, start, adder = 0;
	
	no_of_letters = (strlen(input) + 1) / 9;
	
//	find the position of the "bumps"
	for (i = 1; i <= no_of_letters; i++) {
		for (j = 1; j <= 6; j++) {
				start = (i - 1) * 3; // used to find the first braille "bump"
				adder = 0;			 // used to find the other five braille "bumps"
			if (j == 3 || j == 4)
				adder += no_of_letters * 3;
			else if (j == 5 || j == 6)
				adder += no_of_letters * 6;
			adder += (j - 1) % 2;
		
// 	Convert the braille to 6 digits then pass the digits to brailleLetter
			if (input[start + adder] == 'O') {
				brl_digits[j - 1] = '1';
			} else if (input[start + adder] == '.') {
				brl_digits[j - 1] = '0';
			} else if (input[start + adder] == ' ') {
			}
			
		}
		printf("%c", brailleLetter(brl_digits));
	}
	printf("\n\n");
	
	return 0;	
} 

/* inputs Braille as 6 bit binary number eg. 101011 where 1s are raised and 0s are lowered,
	and the bumps are read left to right one row at a time - returns a letter */
char brailleLetter(char braille[BRAILLESIZE])
{
	int brl_binary;
	char braille_letters[] = "                     s i   jwt a kue ozb lvh r  cm dxnyf p g q ";
	
// 	finds the decimal representation of the 6 binary digits
	brl_binary = strtol(braille, (char **)0, 2);
//	returns where it is in the braile_letters string
	return braille_letters[brl_binary - 1];

}