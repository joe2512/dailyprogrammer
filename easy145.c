// [Easy] Tree Generationn
//
// Input Description
// 
// You will be given one line of text on standard-console 
// input: an integer and two characters, all space-delimited. 
// The integer, N, will range inclusively from 3 to 21 and 
// always be odd. The next character will be your trunk 
// character. The next character will be your leaves 
// character. Draw the trunk and leaves components with 
// these characters, respectively.
// 
// Output Description
// 
// Given the three input arguments, draw a centered-tree. 
// It should follow this pattern: (this is the smallest 
// tree possible, with a base of 3)
//    *
//   ***
//   ###
// Here's a much larger tree, of base 7:
//    *
//   ***
//  *****
// *******
//   ###
  
#include <stdio.h>
#include <string.h>

void makeTree(char []);

int main()
{
	char ex1_input[] = "3 # *";
	char ex2_input[] = "5 = +";
	char ex3_input[] = "9 _ o";
	
	makeTree(ex1_input);
	makeTree(ex2_input);
 	makeTree(ex3_input);
}

/* makeTree: prints a tree given size dimensions and ASCII characters */
void makeTree(char input[])
{
	const char delimiter[] = " ";
	char *size, *base, *tree; 		/* 3 values that will be obtained from input */
	int height, width, i, j;
	
// uses strtok to get the three delimited values
	size = strtok(input, delimiter);
	base = strtok(NULL, delimiter);
	tree = strtok(NULL, delimiter);

	width = *size - '0';
	height = (width - 1) * 2;
	
// 	prints one line at a time of the tree, determines number of " " and "+" to be printed
	for (i = 1; i <= width; i += 2) {
		for (j = 1; j <= (width - i); j += 2)
			printf(" ");
		for (j = 1; j <= i; j += 1)
			printf("%s", tree);
		printf("\n");
	}
	
// prints last line
	for (j = 1; j <= (width - 3); j += 2)
		printf(" ");
	for (j = 1; j <= 3; j++)
		printf("%s", base);
	printf("\n\n");
}

// SHOULD MAINS ALWAYS END return 0; ??
// think easy 143 is now possible
// SHOULD USE *another = "name" syntax for making strings
// check if as many variables as in easy 143 is ok
// do we need to delare functions? it seems like in C the hard way he doesn't but does in K&R