#pragma once

#include "utils.h"
#include "Solution.h"
#include "complexNumberMultiply.h"
#include "singleNonDuplicate.h"
#include "countBattleships.h"
#include "reconstructQueue.h"
#include "tinyURL.h"
#include "twoKeys.h"
#include "numMatrix.h"
#include "findMaxForm.h"
#include "wiggleMaxLength.h"
#include "predictTheWinner.h"
#include "findUnsortedSubarray.h"
#include "findMaxLength.h"
#include "removeKdigits.h"
#include "mergeKLists.h"
#include "updateBoard.h"
#include "findWords.h"
#include "nextGreaterElements.h"

using namespace std;

extern const char* homedir;

class LeetRunner
{
	Solution* createNewSolution(const char *pname);
public:
	void run(const char *pname);
};
