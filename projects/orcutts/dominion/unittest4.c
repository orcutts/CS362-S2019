/*-------------------------------------------------------------------------------------
void cardIsAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int temphand[MAX_HAND])  {...}
**-------------------------------------------------------------------
** BOUNDARY CONDITIONS		EXPECTED RESULTS
** currentPlayer right		PASS
** currentPlayer wrong		FAIL
** gameState is correct		PASS
** gameState is wrong		FAIL
-------------------------------------------------------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testAdventurer() {
	//Create gameStates for each boundary condition being tested
	int currentPlayer0 = 0;
	int currentPlayer3 = 2;
    int numPlayer = 2;
    int playerBool = 0;
    int seed = 1000;
    int k[10] = {adventurer, council_room, feast, gardens, mine, 
    	remodel, smithy, village, baron, great_hall};

    struct gameState G, testG;

	printf("----- Unit Testing for adventurer card effect. ----- \n");
	//set the parameters to the values identified in the tests above
	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	//call cardEffect for each of the parameter configurations identified above
	for (int i = 0; i < numPlayer; i++)
	{
		testG.whoseTurn = i;
		if ((testG.whoseTurn == currentPlayer0)||((testG.whoseTurn > 0)&&(testG.whoseTurn < currentPlayer3)))
			playerBool = 0;
		else 
		{
			playerBool = 1;
			printf("Current Player Test Failed. Expected  = %d; Actual = %d \n", testG.whoseTurn, currentPlayer3);
		}
	}
	//Compare actual vs expected results and post
	if (playerBool)
		printf("All unit tests passed for adventurer. \n");
	else
		printf("One of more tests failed above. \n");	
}

int main(int argc, char *argv[])
{
	testAdventurer();
	return 0;
}