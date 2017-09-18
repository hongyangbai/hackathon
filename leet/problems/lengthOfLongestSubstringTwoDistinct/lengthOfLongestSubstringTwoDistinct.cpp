#include "lengthOfLongestSubstringTwoDistinct.h"

void lengthOfLongestSubstringTwoDistinct::solve()
{
	//cout<<solveLengthOfLongestSubstringTwoDistinct("eceba")<<endl;
	//cout<<solveLengthOfLongestSubstringTwoDistinct("aaabba")<<endl;
	//cout<<solveLengthOfLongestSubstringTwoDistinct("acaabba")<<endl;
	cout<<solveLengthOfLongestSubstringTwoDistinct("abcabc")<<endl;
}

int lengthOfLongestSubstringTwoDistinct::solveLengthOfLongestSubstringTwoDistinct(string s)
{
	int l = 0;
	int r = 0;

	unordered_map<char, int> cnt;

	int curmax = 0;

	for(int i = 0; i < s.size(); ++i)
	{
		if(cnt.size() < 2)
		{
			++cnt[s[i]];
			++r;
		}
		else
		{
			if(cnt.find(s[i]) == cnt.end())
			{
				curmax = max(curmax, r-l);
				cout<<curmax<<" "<<l<<" "<<r<<endl;
				while(cnt.size() >= 2)
				{
					if(cnt[s[l]] > 0)
						--cnt[s[l]];
					if(cnt[s[l]] == 0)
						cnt.erase(s[l]);
					++l;
				}
				cout<<l<<" "<<r<<endl;
				++cnt[s[i]];
				++r;
			}
			else
			{
				++r;
				++cnt[s[i]];
			}
		}
	}

	curmax = max(curmax, r-l);
	return curmax;
}
