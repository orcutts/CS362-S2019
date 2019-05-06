//*** Pulled from my refactored code in orcutt-Assignment-2 ***
/*****************************************************************
void cardIsSmithy(int i, int currentPlayer, struct gameState *state, int handPos) {
//+4 Cards
for (i = 0; i < 4; i++) {
drawCard(currentPlayer, state);
}

//discard card from hand
discardCard(handPos, currentPlayer, state, 0);
}
*****************************************************************/
//Using the example cardTest.c provided in the assignment description as a template.
/*-------------------------------------------------------------------
** NOTE TO GRADER: Prof said in Piazza ("Assignment 3, Part 2.a", 4/26/2019) do 4 of my refactored (unitTest#.c) plus 4 other cards in dominion.c (cardTest#.c)
** But I think the assignment was misconstrued.  The unit tests should be on 4 functions in dominion.c and the cardTests
** Should be on the refactored cards.  Regardless, I am going with what the prof said on Piazza.
--------------------------------------------------------------------*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main() {
	int newCards = 0;
	int discarded = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +3 cards, but discard 0 --------------
	printf("TEST 1: choice1 = 1 = +3 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	// Checks the hand count after drawing and before buy or discarding (discarded = 0)
	newCards = 3;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards);

	// ----------- TEST 2: choice1 = 2 = Hand Count after Adding +3 draws and discarding 1 --------------
	printf("TEST 2: choice1 = 2 = +3 cards -1 discard card\n");
	choice1 = 2;

	// tests for the appropriate number of remaining cards
	discarded = 1;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}


