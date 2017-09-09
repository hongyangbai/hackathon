#include "decodeString.h"

void decodeString::solve()
{
	//string s = "3[a10[bc]]";
	string s = "sd2[f2[e]g]i";
	//string s = "3[a2[c]]";
	//string s = "2[2[b]]";
	//string s = "3[a]2[bc]";
	//string s = "leetcode";
	//string s = "10[leetcode]";
	//string s = "2[abc]3[cd]ef";
	cout<<solveDecodeString(s)<<endl;
}

string decodeString::repeatString(string s, int n)
{
	string res;
	while(n-->0)
		res += s;
	return res;
}

string decodeString::solveDecodeString(string s, int i)
{
	string res;

	while (i < s.length() && s[i] != ']')
	{
		if (!isdigit(s[i]))
			res += s[i++];
		else
		{
			int n = 0;
			while (i < s.length() && isdigit(s[i]))
				n = n * 10 + s[i++] - '0';

			i++; // '['
			string t = solveDecodeString(s, i);
			i++; // ']'

			while (n-- > 0)
				res += t;
		}
	}

return res;
}

string decodeString::solveDecodeString(string s)
{
	return solveDecodeString(s, 0);
}
