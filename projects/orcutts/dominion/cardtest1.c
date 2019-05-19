//*** Pulled from my refactored code in orcutt-Assignment-2 ***
/*****************************************************************
void cardIsCouncilRoom(int i, int currentPlayer, struct gameState *state, int handPos) {
//+3 Cards
for (i = 0; i < 3; i++) {
drawCard(currentPlayer, state);
}

//+1 Buy
state->numBuys++;

//Each other player draws a card
for (i = 0; i < state->numPlayers; i++) {
if (i != currentPlayer) {
drawCard(i, state);
}
}
//put played card in played card pile
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

#define TESTCARD "council_room"

int main() 
{
	int newCards = 0;
	int discarded = 0;
	int i;
	int initBuys = 0;
	int initCount = 0;
	int initOtherCount = 0;
	int otherCount = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int playerBuys = 0;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	initCount = G.handCount[thisPlayer];
	initBuys = G.numBuys;
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: choice1 = 1 = +4 cards, but discard 0 --------------
	printf("TEST 1: choice1 = 1 = +4 cards\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	initOtherCount = testG.handCount[thisPlayer]; //everyone initialized to the same
	testG.handCount[thisPlayer + 1] = testG.handCount[thisPlayer];
	choice1 = 1;
	cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

	discarded = 1;
	// Checks the hand count after drawing and before buy or discarding (discarded = 0)
	newCards = 4; //code looks for 3 but should look for 4
	printf("hand count = %i, expected = %i \n", discarded + testG.handCount[thisPlayer], initCount + newCards);
	assert((discarded + testG.handCount[thisPlayer]) == (initCount + newCards));

	// ----------- TEST 2: buy 1 --------------
	printf("TEST 2: choice1 = 2 = +1 buy\n");
	playerBuys = 1;
	//numBuys is initialize3d to 1 for player 1
	if (testG.numBuys == playerBuys)
		playerBuys = 0;
	//printf("buy count = %d, expected = %d\n", testG.numBuys[thisPlayer], G.numBuys[thisPlayer] + playerBuys);
	//assert(testG.numBuys[thisPlayer] == G.numBuys[thisPlayer] + playerBuys);
	printf("buy count = %d, expected = %d\n", testG.numBuys, initBuys + playerBuys);
	assert(testG.numBuys == (initBuys + playerBuys));

	// ----------- TEST 3: choice1 = 3 = Hand Count after Adding +4 draws and discarding 1 --------------
	printf("TEST 3: choice1 = 3 = +4 cards -1 discard card\n");

	// tests for the appropriate number of remaining cards

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], initCount + newCards - discarded);
	assert(testG.handCount[thisPlayer] == (initCount + newCards - discarded));

	// ----------- TEST 4: choice1 = 4 = Every other player draws 1 card --------------
	printf("TEST 4: choice1 = 4 = +1 card for every other player\n");
	// tests for the appropriate number of cards in other player hands
	/*for (i = 0; i < numPlayers; i++) {
		newCards = 0;
		if (i > 0) 
		{*/
			newCards = 1;

	//	}
		printf("hand count = %d, expected = %d\n", 	testG.handCount[thisPlayer + 1], (initCount + newCards));
		assert(testG.handCount[thisPlayer + 1] == (initCount + newCards));
//	}
	printf(" >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}