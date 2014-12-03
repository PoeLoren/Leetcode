/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(Interval a, Interval b)
    {
        if(a.start != b.start)
            return a.start < b.start;
        else
            return a.end < b.end;
    }
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() == 1 || intervals.size() == 0)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        int last = 0;
        vector<Interval> res;
        for(auto it = intervals.begin() + 1;it != intervals.end(); it++)
        {
            if(it->start <= intervals[last].end)   //if current interval's start is smaller than the last interval's end
            {
                intervals[last].end = max(intervals[last].end,it->end);//if current interval's end is larger than the last interval's end
                it->start = -1;     //mark the current interval invalid 
            }
            else    //if current interval is in the right, update the last index
            {
                last = it - intervals.begin();
            }
        }
        for(auto it = intervals.begin();it != intervals.end();it++) 
        {
            if(it->start != -1)
                res.push_back(*it);
        }
        return res;
    }
};