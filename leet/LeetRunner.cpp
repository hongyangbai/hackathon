#include "LeetRunner.h"

void LeetRunner::run(const char* pname)
{
	DIR *dir;
	struct dirent *ent;
	Solution* s = nullptr;
	char ppath[100];
	sprintf(ppath, "%s%s", homedir, "/work/hackathon/leet/problems/");
	vector<string> availpnames;
	if ((dir = opendir (ppath)) != NULL) {
		while ((ent = readdir (dir)) != NULL) 
		{
			if(strcmp(".", ent->d_name) == 0 || strcmp("..", ent->d_name) == 0)
				continue;
			availpnames.push_back(string(ent->d_name));
			if(strcmp(ent->d_name, pname) == 0)
				s = createNewSolution(pname);
		}
		closedir (dir);
	}

	if(s != NULL)
	{
		printf("Running solution for [%s]:\n", pname);
		s->solve();
	}
	else
	{
		sort(availpnames.begin(), availpnames.end());
		printf("Error: problem solution not created yet, available problems:\n");
		for(int i = 0; i < availpnames.size(); ++i)
			printf("%d. %s\n", i+1, availpnames[i].c_str());
	}

	delete s;
}

Solution* LeetRunner::createNewSolution(const char* pname)
{
	if(strcmp(pname, "complexNumberMultiply") == 0)
		return new complexNumberMultiply;
	else if(strcmp(pname, "singleNonDuplicate") == 0)
		return new singleNonDuplicate;
	else if(strcmp(pname, "countBattleships") == 0)
		return new countBattleships;
	else if(strcmp(pname, "reconstructQueue") == 0)
		return new reconstructQueue;
	else if(strcmp(pname, "tinyURL") == 0)
		return new tinyURL;
	else if(strcmp(pname, "twoKeys") == 0)
		return new twoKeys;
	else if(strcmp(pname, "numMatrix") == 0)
		return new numMatrix;
	else if(strcmp(pname, "findMaxForm") == 0)
		return new findMaxForm;
	else if(strcmp(pname, "wiggleMaxLength") == 0)
		return new wiggleMaxLength;
	else if(strcmp(pname, "predictTheWinner") == 0)
		return new predictTheWinner;
	else if(strcmp(pname, "findUnsortedSubarray") == 0)
		return new findUnsortedSubarray;
	else if(strcmp(pname, "findMaxLength") == 0)
		return new findMaxLength;
	else if(strcmp(pname, "removeKdigits") == 0)
		return new removeKdigits;
	else if(strcmp(pname, "mergeKLists") == 0)
		return new mergeKLists;
	else if(strcmp(pname, "updateBoard") == 0)
		return new updateBoard;
	else if(strcmp(pname, "findWords") == 0)
		return new findWords;
	else if(strcmp(pname, "nextGreaterElements") == 0)
		return new nextGreaterElements;
	else if(strcmp(pname, "arrayNesting") == 0)
		return new arrayNesting;
	else if(strcmp(pname, "decodeString") == 0)
		return new decodeString;
	else if(strcmp(pname, "longestIncreasingPath") == 0)
		return new longestIncreasingPath;
	else if(strcmp(pname, "buildTree") == 0)
		return new buildTree;
	else if(strcmp(pname, "findNumberOfLIS") == 0)
		return new findNumberOfLIS;
	else if(strcmp(pname, "findLonelyPixel") == 0)
		return new findLonelyPixel;
	else if(strcmp(pname, "maxKilledEnemies") == 0)
		return new maxKilledEnemies;
	else if(strcmp(pname, "wiggleSort") == 0)
		return new wiggleSort;
	else if(strcmp(pname, "lengthOfLongestSubstringTwoDistinct") == 0)
		return new lengthOfLongestSubstringTwoDistinct;
	else if(strcmp(pname, "lengthLongestPath") == 0)
		return new lengthLongestPath;
	else if(strcmp(pname, "gameOfLife") == 0)
		return new gameOfLife;
	else if(strcmp(pname, "findMaximumXOR") == 0)
		return new findMaximumXOR;
	else if(strcmp(pname, "addTwoNumbers") == 0)
		return new addTwoNumbers;
	else if(strcmp(pname, "candy") == 0)
		return new candy;
	else if(strcmp(pname, "leastInterval") == 0)
		return new leastInterval;
	else if(strcmp(pname, "largestRectangleArea") == 0)
		return new largestRectangleArea;
	else if(strcmp(pname, "insertInterval") == 0)
		return new insertInterval;
	else if(strcmp(pname, "uniqueSubstring") == 0)
		return new uniqueSubstring;
	else if(strcmp(pname, "twoSum") == 0)
		return new twoSum;
	else if(strcmp(pname, "climbStairs") == 0)
		return new climbStairs;
	else if(strcmp(pname, "removeInvalidParentheses") == 0)
		return new removeInvalidParentheses;
	else if(strcmp(pname, "knightProbability") == 0)
		return new knightProbability;
	else
		return nullptr;
}
