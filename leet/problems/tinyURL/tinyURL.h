#include "Solution.h"

class tinyURL : public Solution
{
	map<string, string> urlmap;
	unordered_map<int, string> idmap;
	int id = 0;
	string hashmap = "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
	void solve();
	string encode(string longUrl);
	string decode(string shortUrl);
};
