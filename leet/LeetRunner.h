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
#include "arrayNesting.h"
#include "decodeString.h"
#include "longestIncreasingPath.h"
#include "buildTree.h"
#include "findNumberOfLIS.h"
#include "findLonelyPixel.h"
#include "maxKilledEnemies.h"
#include "wiggleSort.h"
#include "lengthOfLongestSubstringTwoDistinct.h"
#include "lengthLongestPath.h"
#include "gameOfLife.h"
#include "findMaximumXOR.h"
#include "addTwoNumbers.h"
#include "candy.h"
#include "leastInterval.h"
#include "largestRectangleArea.h"
#include "insertInterval.h"
#include "uniqueSubstring.h"
#include "twoSum.h"
#include "climbStairs.h"
#include "removeInvalidParentheses.h"
#include "knightProbability.h"

using namespace std;

extern const char* homedir;

class LeetRunner
{
	Solution* createNewSolution(const char *pname);
public:
	void run(const char *pname);
};
