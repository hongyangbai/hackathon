#pragma once
#include <iostream>

using namespace std;

void print(const vector<int>& v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		if(i == v.size()-1)
			printf("%d", v[i]);
		else
			printf("%d, ", v[i]);
	}
	printf("\n");
}

void print(const vector<pair<int, int>>& v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		if(i == v.size()-1)
			printf("[%d %d]", v[i].first, v[i].second);
		else
			printf("[%d %d], ", v[i].first, v[i].second);
	}

	printf("\n");
}
