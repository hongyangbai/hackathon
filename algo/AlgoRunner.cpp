#include "AlgoRunner.h"

void AlgoRunner::run(char* algoname)
{
	DIR *dir;
	struct dirent *ent;
	
	struct cmp
	{
		bool operator()(int x, int y)
		{
			return x>y;
		}
	};

	priority_queue<int, vector<int>, cmp> pq;
	pq.push(3);
	pq.push(6);
	pq.push(7);
	pq.push(-1);

	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
}
