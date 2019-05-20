/*---------------------------
void cardIsSmithy(int i, int currentPlayer, struct gameState *state, int handPos) {
	//+4 Cards
	for (i = 0; i < 3; i++){
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
}

SMITHY: Sequence of opertations
Begin turn
1. player draws three cards 	-> +3cards to handCount
2. player adds to discard pile	-> -1 from handCount
End turn

NOTE:  Random testing lecture examples used as reference below
-----------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ITERATIONS 2000 //test iterations, 2000 in lecture example

//From "Revise Your Test Oracle" lecture slide
void testSmithy(int p, struct gameState *post)
{
	int r;
	int bonus = 0;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));
	printf("just copied\n");

	//r = cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	r = cardEffect(smithy, 0, 0, 0, post, 0, &bonus);
		printf("i got my r\n");
	//smithy takes 3 cards deck and discards 1
	for (int i = 0; i < 3; i++)
	{
				printf("into 3 card draw \n");
		//There is a card to draw, so draw if
		if (pre.deckCount[p] > 0)
		{
			pre.handCount[p]++; 
			pre.hand[p][pre.handCount[p] - 1] = pre.deck[p][pre.deckCount[p] - 1];
			pre.deckCount[p]--;
			pre.discardCount[p]++;
		}
		else if (pre.discardCount[p] > 0)
		{
			memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
			memcpy(pre.discard[p], post->discard[p], sizeof(int) * pre.discardCount[p]);
			pre.hand[p][post->handCount[p] - 1] = post->hand[p][post->handCount[p] - 1];
			pre.handCount[p]++;
			pre.deckCount[p] = pre.discardCount[p] - 1;
			pre.discardCount[p] = 0;
		}
	}

	assert (r == 0);
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
}

int main()
{
	int p; // players
	struct gameState G;

	printf("--- Testing cardEffect for smithy. --- \n");
	printf("RANDOM TESTS. \n");
	srand(time(NULL));

	//Get all of the randomized bits using dependencies/ranges from documentation
	for (int n = 0; n < MAX_ITERATIONS; n++)
	{
		for (int i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&G)[i] = floor(rand() % 256);
		}
		p = floor((rand() % (4 - 2)) + 2);	//2 to 4 players
		G.handCount[p] = floor(rand() % MAX_HAND);
		G.deckCount[p] = floor(rand() % MAX_DECK);
		G.discardCount[p] = floor(rand() % MAX_DECK);
		G.deck[p][G.deckCount[p]] = floor(rand() % MAX_DECK);
		G.discard[p][G.discardCount[p]] = floor(rand() % MAX_DECK);
		G.hand[p][G.handCount[p]] = floor(rand() % MAX_DECK);

		//Use the random values to test smithy
		testSmithy(p, &G);
	}
	return 0;
}
