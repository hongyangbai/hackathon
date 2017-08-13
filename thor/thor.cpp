#include "Solution.h"

using namespace std;

int main(int argc, char *argv[])
{	
	Solution *s = Solution::instance();
	vector<string> dict = {"cat", "bat", "rat"};
	string sentence("the cattle was rattled by the battery");
	string res = s->replaceWords(dict, sentence);
	cout<<res<<endl;
	return 0;
}
