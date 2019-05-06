/*---------------------------------------------------------------
void cardIsSmithy(int i, int currentPlayer, struct gameState *state, int handPos)
**-------------------------------------------------------------------
** BOUNDARY CONDITIONS							EXPECTED RESULTS
** Right currentPlayer, right state->whoseTurn		PASS // Assumes currentPlayer is passed in rather than taken from state
** Right currentPlayer, wrong state->whoseTurn		FAIL
** Wrong currentPlayer, right state->whoseTurn		FAIL //Is this redundant?
** Wrong currentPlayer, wrong state->whoseTurn		FAIL
** 5 cards in hand, expect 7 afterwards				PASS
** 1 card in hand, expect 3 afterwards				PASS
** 0 cards in hand, cannot run because no smithy	FAIL
** 5 cards in hand, handPos = 4						PASS // Assumes hand position = 0 -> 4
** 1 card in hand, handPos = 0						FAIL
----------------------------------------------------------------*/

void testSmithy() {
	//Create gameStates for each boundary condition being tested

	//set the parameters to the values identified in the tests above

	//call cardEffect for each of the parameter configurations identified above

	//Compare actual vs expected results and post
}

int main(int argc, char *argv[])
{
	testSmithy();
	return 0;
}