//*** Pulled from my refactored code in orcutt-Assignment-2 ***
/*****************************************************************
void cardIsAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int temphand[MAX_HAND]) {
while (drawntreasure < 2) {
if (state->deckCount[currentPlayer] < 2) {
//if the deck is empty we need to shuffle discard and add to deck
shuffle(currentPlayer, state);
}
drawCard(currentPlayer, state);
cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
drawntreasure++;
else {
temphand[z] = cardDrawn;
state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
z++;
}
}

while (z - 1 >= 0) {
state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
z = z - 1;
}
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

#define TESTCARD "adventurer"

int main() {
	int newCards = 0;
	int cardTrigger = 0;
	int discarded = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int initCount = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	initCount = G.handCount[thisPlayer];
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

	// ----------- TEST 1: choice1 = 1 = do shuffle if low on cards --------------
	printf("TEST 1: choice1 = 1 = do shuffle if low on cards\n");
	cardTrigger = 2;
	printf("deck count = %i, expected > = %i \n", testG.deckCount[thisPlayer], cardTrigger);
	assert(testG.deckCount[thisPlayer] >= cardTrigger);

	// ----------- TEST 2: choice1 = 2 = Draw a card --------------
	printf("TEST 2: choice1 = 2 = +2 card - discard\n");
	newCards = 2;
	discarded = 1;
	printf("hand count = %d, expected = %d\n", (testG.handCount[thisPlayer]), (initCount + newCards));
	assert((testG.handCount[thisPlayer]) == (initCount + newCards));

	// ----------- TEST 4: choice1 = 4 = total cards at the end = +2 --------------
	//This is needed because tests  only tested that if a card is treasure they will keep it else discard
	printf("TEST 3: choice1 = 3 = +2cards from initial hand\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], initCount + cardTrigger);
	assert(testG.handCount[thisPlayer] == initCount + cardTrigger);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	return 0;
}