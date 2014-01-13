// [Easy] Arithmetic Equations
// 
// Arithmetic types out simple arithmetic problems, and waits for an answer to be typed in. If the answer
// is correct, it types back "Right!", and a new problem. If the answer is wrong, it replies "What?", and
// waits for another answer. Every twenty problems, it publishes statistics on correctness and the time
// required to answer.
// 
// Your goal is to implement this game, with some slight changes, to make this an 
// [Easy]-level challenge. You will only have to use three arithmetic operators (addition, 
// subtraction, multiplication) with four integers. An example equation you are to generate 
// is "2 x 4 + 2 - 5".

// unfinished
// 1 - win percentage not worked out yet
// 2 - answer is not coming through clearly (run to check)
// 3 - doesn't receive input to check against answer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

void arithmetic(int *);
void strtolower(char *);

int main()
{
	char want_to_play[4];
	int win_percent;
	
	printf("Do you want to play Arithmetic?\n");
	fgets(want_to_play, sizeof(want_to_play), stdin);
	strtolower(want_to_play);
	
	if (strncmp(want_to_play, "yes", 3) == 0) {
		arithmetic(&win_percent);
		printf("Your winning percentage was %d%%\n", win_percent);
		exit(0);
	} else if (strncmp(want_to_play, "no", 2) == 0) {
		exit(0);
	} else {
		printf("I don't understand your response!\n");
		exit(1);
	}
}

/* plays the game 'Arithmetic' with the user interactively */
void arithmetic(int *winp)
{
	char operators[] = "+-x";
	int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char a, b, c;
	int z, y, x, w, answer, input, temp, win = 0, lose = 0;
	

	int i = 0;
	while (1) {
// 		use sleep here to keep every value random using rand() with a time seed
//      unfortunately each round takes 7 seconds to run
		srand(time(0));
		a = operators[rand() % 3];
		sleep(1);				// sleeps 1001 ms, enough for the seed to change
		b = operators[rand() % 3];
		sleep(1);
		c = operators[rand() % 3];
		sleep(1);
		w = numbers[rand() % 10];
		sleep(1);
		x = numbers[rand() % 10];
		sleep(1);
		y = numbers[rand() % 10];
		sleep(1);
		z = numbers[rand() % 10];
		sleep(1);
		
		
		printf("Your next problem is %d %c %d %c %d %c %d,\nWhat is the answer?\n", w, a, x, b, y, c, z);
		
		if (a == 'x') {
			if (b == 'x') {
				if (c == 'x') {
					answer = w * x * y * z;
				}
			} else if (c == 'x') {
				if (b == '+') {
					answer = w * x + y * z;
				} else if (b == '-') {
					answer = w * x - y * z;
				}
			} else if (b == '+') {
				if (c == '+') {
					answer = w * x + y + z;
				} else if (c == '-') {
					answer = w * x + y - z;
				}
			} else if (b == '-') {
				if (c == '+') {
					answer = w * x - y + z;
				} else if (c == '-') {
					answer = w * x - y - z;
				}
			}
		} else if (a == '+') {
			if (b == 'x') {
				if (c == 'x') {
					answer = w + x * y * z;
				}
			} else if (c == 'x') {
				if (b == '+') {
					answer = w + x + y * z;
				} else if (b == '-') {
					answer = w + x - y * z;
				}
			} else if (b == '+') {
				if (c == '+') {
					answer = w + x + y + z;
				} else if (c == '-') {
					answer = w + x + y - z;
				}
			} else if (b == '-') {
				if (c == '+') {
					answer = w + x - y + z;
				} else if (c == '-') {
					answer = w + x - y - z;
				}
			} 
		} else if (a == '-') {
			if (b == 'x') {
				if (c == 'x') {
					answer = w - x * y * z;
				}
			} else if (c == 'x') {
				if (b == '+') {
					answer = w - x + y * z;
				} else if (b == '-') {
					answer = w - x - y * z;
				}
			} else if (b == '+') {
				if (c == '+') {
					answer = w - x + y + z;
				} else if (c == '-') {
					answer = w - x + y - z;
				}
			} else if (b == '-') {
				if (c == '+') {
					answer = w - x - y + z;
				} else if (c == '-') {
					answer = w - x - y - z;
				}
			} 
		}
		
		printf("The answer is %d", answer);
		
		printf("%c", operators[rand() % 3]);
		printf("%d and win is %d\n", numbers[rand() % 10], *winp);
		*winp += 5;
		
		
		
		if (i == 11) return;
		i++;
	}
}

/* converts a string to all lower case */
void strtolower(char *str)
{
	for(int i = 0; str[i]; i++){
    	str[i] = tolower(str[i]);
	}
}
