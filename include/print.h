#pragma once
#include <iostream>
#include <ostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		if(i == v.size()-1)
			os<<v[i];
		else
			os<<v[i]<<", ";
	}
	os<<endl;
	return os;
}

template<>
inline ostream& operator<<(ostream& os, const vector<bool>& v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		if(i == v.size()-1)
			os<< (v[i] ? "true":"false");
		else
			os<<(v[i] ? "true":"false")<<", ";
	}
	os<<endl;
	return os;
}

template<typename T>
inline ostream& operator<<(ostream& os, const vector<vector<T>>& v)
{
	for(int i = 0; i < v.size(); ++i)
		os<<v[i];
	return os;
}

template<typename T>
inline ostream& operator<<(ostream& os, const vector<pair<T, T>>& v)
{
	for(int i = 0; i < v.size(); ++i)
	{
		if(i == v.size()-1)
			os<<"["<<v[i].first<<","<<v[i].second<<"]" ;
		else
			os<<"["<<v[i].first<<","<<v[i].second<<"], " ;
	}
	os<<endl;
	return os;
}

inline ostream& operator<<(ostream& os, ListNode* n)
{
	while(n)
	{
		if(n->next)
			os<<n->val<<" -> ";
		else
			os<<n->val;
		n = n->next;
	}
	os<<endl;
	return os;
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

inline ostream& operator<<(ostream& os, pair<int, int> p)
{
	os<<p.first<<", "<<p.second;
	return os;
}
