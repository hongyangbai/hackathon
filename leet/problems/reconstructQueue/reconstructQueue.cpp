#include "reconstructQueue.h"

void reconstructQueue::solve()
{
	vector<pair<int, int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	vector<pair<int, int>> res = solveReconstructQueue(people);

	for(auto x:res)
		printf("[%d %d] ", x.first, x.second);
	printf("\n");
}

vector<pair<int, int>> reconstructQueue::solveReconstructQueue(vector<pair<int, int>>& people)
{
	vector<pair<int, int>> res;
	if(people.empty()) return res;
	auto comp = [](pair<int, int>& a, pair<int, int>& b)	{ return a.first == b.first ?  a.second<b.second : a.first>b.first;};
	sort(people.begin(), people.end(), comp);
	int pfirst = people[0].first;
	int i = 0;
	while(people[i].first == pfirst)
		res.push_back(people[i++]);
	for(; i < people.size(); ++i)
		res.insert(res.begin() + people[i].second, people[i]);
	return res;
}
