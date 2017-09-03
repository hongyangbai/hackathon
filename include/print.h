#pragma once
#include <iostream>
#include <ostream>

using namespace std;

inline ostream& operator<<(ostream& os, const vector<int>& v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		if(i == v.size()-1)
			os<<v[i];
		else
			os<<v[i]<<", ";
	}
	os<<endl;
}

inline ostream& operator<<(ostream& os, ListNode* n)
{
	while(n)
	{
		if(n->next)
			os<<n->val<<" <- ";
		else
			os<<n->val;
		n = n->next;
	}
	os<<endl;
}

inline void print(const vector<int>& v)
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

inline void print(const vector<pair<int, int>>& v)
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
