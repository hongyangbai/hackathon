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
	else
		return nullptr;
}
