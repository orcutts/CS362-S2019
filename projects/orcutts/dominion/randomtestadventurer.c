/*---------------------------
void cardIsAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int temphand[MAX_HAND]){
	while (drawntreasure < 2){
		if (state->deckCount[currentPlayer] < 2){
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

	while (z - 1 >= 0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
}

adventurer: Sequence of opertations
Begin turn
1. player identifies how many treasure cards in their hand
2  Player draws until two treasure cards are drawn
3. Player discards all the drawn cards that were not treasure
3. player adds to discard pile	-> -1 from handCount
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
void testAdventurer(int p, struct gameState *post)
{
	int newCoins = 0;
	int r;
	int cardDrawn = 0;
	int tempHand[MAX_HAND]; //discard pile while scavenging, from adventurer card function
	int z = 0; //from adventurer card function
	int bonus = 0;
	struct gameState pre;
	memcpy(&pre, post, sizeof(struct gameState));

	//r = cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
	r = cardEffect(adventurer, 0, 0, 0, post, 0, &bonus);
	
	//adventurer draws and discards until coins = coins + 2
	//There is a card to draw, so draw if
	while (newCoins < 2)
	{
	    //if draw a coin then count it, else put it in temphand
		cardDrawn = pre.hand[p][pre.handCount[p] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) 
		{
			newCoins++;
		}
        else
        {   //adds it to temp
            tempHand[z] = cardDrawn;
            pre.handCount[p]--;
            z++;
        }

    }

    //Now do a normal discard for each z
    while(z > 0)
    {
    	//move from the deck to discard
		pre.deckCount[p]--;
        pre.discard[p][pre.discardCount[p]] = tempHand[z];
        z--; 
	}

	assert (r == 0);
	assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);
}

int main()
{
	int p; // players
	struct gameState G;

	printf("--- Testing cardEffect for adventurer. --- \n");
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

		//Use the random values to test adventurer
		testAdventurer(p, &G); 
	}
	return 0;
}
