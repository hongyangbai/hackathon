#include "LeetRunner.h"

void LeetRunner::solve(const char* pname)
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
	else
		return nullptr;
}
