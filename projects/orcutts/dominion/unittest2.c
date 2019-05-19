/*---------------------------------------------------------------
void cardIsSmithy(int i, int currentPlayer, struct gameState *state, int handPos)
**-------------------------------------------------------------------
** BOUNDARY CONDITIONS		EXPECTED RESULTS
** currentPlayer right		PASS
** currentPlayer wrong		FAIL
** gameState is correct		PASS
** gameState is wrong		FAIL
** handPos is right			PASS
** handPos is wrong			FAIL
-------------------------------------------------------------------------------------*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testSmithy() {
	//Create gameStates for each boundary condition being tested
	int currentPlayer0 = 0;
	int currentPlayer3 = 2;
	int handPos = 0;
	int handPos0 = 0;
	int handPos5 = 5;
    int numPlayer = 2;
    int playerBool = 0;
    int positionBool = 0;
    int seed = 1000;
    int k[10] = {adventurer, council_room, feast, gardens, mine, 
    	remodel, smithy, village, baron, great_hall};

    struct gameState G, testG;

	printf("----- Unit Testing for smithy card effect. ----- \n");

	//set the parameters to the values identified in the tests above
	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	//call cardEffect for each of the parameter configurations identified above
	for (int i = 0; i < numPlayer; i++)
	{
		testG.whoseTurn = i;
		if ((testG.whoseTurn == currentPlayer0)||((testG.whoseTurn > 0)&&(testG.whoseTurn< currentPlayer3)))
			playerBool = 0;
		else 
		{
			playerBool = 1;
			printf("Current Player Test Failed. Expected  = %d; Actual = %d \n", testG.whoseTurn, currentPlayer3);
		}

		handPos = i;
		if ((handPos == handPos0)||((handPos > 0)&&(handPos < handPos5)))
			positionBool = 0;
		else 
		{
			positionBool = 1;
			printf("Current Hand Position Test Failed. Expected  = %d; Actual = %d \n", handPos, handPos5);
		}

	}
	//Compare actual vs expected results and post
	if ((playerBool)&&(positionBool))
		printf("All unit tests passed for smithy. \n");
	else
		printf("One of more tests failed above. \n");	
}

int main(int argc, char *argv[])
{
	testSmithy();
	return 0;
}