#include "complexNumberMultiply.h"

void complexNumberMultiply::solve()
{
	cout<<solveComplexNumberMultiply("13+1i", "-1+4i")<<endl;
}

int complexNumberMultiply::getReal(string s)
{
	string r = "";
	bool neg = s[0] == '-' ? true:false;
	int i = 0;
	if(s[0] == '-')
		i = 1;

	for(; i < s.size(); ++i)
	{
		if(s[i] == '+' || s[i] == '-')
			break;
		r += s[i];
	}
	return neg ? -stoi(r):stoi(r);
}

int complexNumberMultiply::getComplex(string s)
{
	string r = "";
	int i = s[0] == '-' ? 1:0;
	while(s[i] != '+')
		++i;
	bool neg = s[i+1] == '-' ? true:false;
	i = s[i+1] == '-' ? i+2:i+1;
	for(; i<s.size()-1; ++i)
		r += s[i];
	return neg ? -stoi(r):stoi(r);
}

string complexNumberMultiply::solveComplexNumberMultiply(string a, string b)
{
	string res = "";       
	int areal = getReal(a);
	int breal = getReal(b);
	int acomp = getComplex(a);
	int bcomp = getComplex(b);

	int rreal = areal*breal - acomp*bcomp;
	int rcomp = areal*bcomp + acomp*breal;

	return to_string(rreal) + "+" + to_string(rcomp) + "i";
}
