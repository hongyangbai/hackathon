#include "insertInterval.h"

void insertInterval::solve()
{
	vector<Interval> intervals = {Interval(2,4), Interval(6,8), Interval(10,12)};
	Interval newInterval(3,11);

	vector<Interval> res = insert(intervals, newInterval);
	for(auto each:res)
		cout<<"["<<each.start<<","<<each.end<<"], ";
	cout<<endl;
}

vector<insertInterval::Interval> insertInterval::insert(vector<insertInterval::Interval>& intervals, insertInterval::Interval newInterval)
{
	vector<Interval> res;
	bool inserted = false;
	for(int i = 0; i < intervals.size(); ++i)
	{
		if(!inserted && newInterval.start <= intervals[i].end)
		{
			if(newInterval.end < intervals[i].start)
			{
				res.push_back(newInterval);
				res.push_back(intervals[i]);
			}
			else
			{
				int ns = min(intervals[i].start, newInterval.start);
				while(i < intervals.size() && intervals[i].start <= newInterval.end)
					++i;
				--i;
				int ne = max(intervals[i].end, newInterval.end);
				res.push_back(Interval(ns,ne));
			}
			inserted = true;
		}
		else
			res.push_back(intervals[i]);
	}

	if(inserted == false)
		res.push_back(newInterval);

	return res;
}
