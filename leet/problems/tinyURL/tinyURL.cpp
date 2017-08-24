#include "tinyURL.h"

void tinyURL::solve()
{
	string url = "https://leetcode.com/problems/design-tinyurl";
	cout<<decode(encode(url))<<endl;
}

string tinyURL::encode(string longUrl)
{
	auto it = urlmap.find(longUrl);
	if(urlmap.find(longUrl) != urlmap.end())
	{
		return urlmap[longUrl];
	}

	++id;
	int tmpid = id;
	string shortUrl = "";
	while(tmpid > 0)
	{
		shortUrl = hashmap[tmpid%hashmap.size()] + shortUrl;
		tmpid  /= hashmap.size();
	}

	urlmap[longUrl] = shortUrl;
	idmap[id] = longUrl;

	return shortUrl;
}

string tinyURL::decode(string shortUrl)
{
	int curid = 0;
	for(int i = 0; i < shortUrl.size(); ++i)
		curid = curid*10 + hashmap.find(shortUrl);

	if(idmap.find(curid) == idmap.end())
		return string();
	else
		return idmap[curid];
}
