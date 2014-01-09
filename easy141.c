// [Easy] Monty Hall Simulation
// 
// The Monty Hall Problem is a probability puzzle that has a very non-intuitive answer 
// for the average person. Here's the problem description taken from Wikipedia:
// 
// "Suppose you're on a game show, and you're given the choice of three doors: Behind one 
// door is a car; behind the others, goats. You pick a door, say No. 1, and the host, who 
// knows what's behind the doors, opens another door, say No. 3, which has a goat. He then 
// says to you, "Do you want to pick door No. 2?" Is it to your advantage to switch your 
// choice?"
// 
// Your goal is to simulate two tactics to this puzzle, and return the percentage of 
// successful results. The first tactic is where you stick with your initial choice. 
// The second tactic is where you always switch doors.
// 
// Input Description
// 
// On standard console input, you will be given a single integer ranging inclusively 
// from 1 to 4,294,967,295 (unsigned 32-bit integer). This integer is the number of 
// times you should simulate the game for both tactics. Remember that a single "game 
// simulation" is your program randomly placing a car behind one door and two goats 
// behind the two remaining doors. You must then randomly pick a door, have one of the 
// two remaining doors open, but only open if it's a goat behind said door! After that, 
// if using the first tactic, you may open the picked door, or if using the second tactic, 
// you may open the other remaining door. Keep track if your success rates in both 
// simulations.
// 
// Output Description
// 
// On two seperate lines, print "Tactic 1: X% winning chance" and "Tactic 2: Y% winning 
// chance", where X and Y are the percentages of success for the respective tactics

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, car_box, choice_box, simsi;
	char sims[8];
	double tactic_one_prob, tactic_two_prob, success_count, failure_count;
	srand(time(0));

	printf("How many simulations do you want to run? (max: 1,000,000\n");
	fgets(sims, sizeof(sims), stdin);
	sscanf(sims, "%d", &simsi);

// Tactic 1 - Stick with original choice
	
	for (i = 1; i <= simsi; i++) {
		car_box = (rand() % 3) + 1;
		choice_box = (rand() % 3) + 1;
	
		if (car_box == choice_box) {
			success_count++;
		} else {
			failure_count++;
		}
	}
	printf("%d simulations being run with tactic 1 (original choice)...\n\n", simsi);
	printf("The number of successes (win a car): %0.0f\n", success_count);
	printf("The number of failures (didn't win a car): %0.0f\n", failure_count);
	tactic_one_prob = success_count / simsi;
	printf("Tactic 1: %0.1f%% winning chance\n\n", tactic_one_prob * 100);
	
	success_count = 0;
	failure_count = 0;
	
// Tactic 2 - Change door when asked
	
	for (i = 1; i <= simsi; i++) {
		car_box = (rand() % 3) + 1;
		choice_box = (rand() % 3) + 1;
	
		if (car_box == choice_box) {
			failure_count++;
		} else {
			success_count++;
		}
	}
	printf("%d simulations being run with tactic 2 (change door)...\n\n", simsi);
	printf("The number of successes (win a car): %0.0f\n", success_count);
	printf("The number of failures (didn't win a car): %0.0f\n", failure_count);
	tactic_two_prob = success_count / simsi;
	printf("Tactic 2: %0.1f%% winning chance\n\n", tactic_two_prob * 100);
	
	return 0;
}
