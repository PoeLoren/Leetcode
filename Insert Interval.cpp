/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto it = intervals.begin();
        while(it != intervals.end())
        {
            if(newInterval.end < it->start)
            {
                intervals.insert(it,newInterval);
                break;
            }
            else if(newInterval.start > it->end)
            {
                it++;
            }
            else
            {
                newInterval.start = min(newInterval.start,it->start);
                newInterval.end = max(newInterval.end,it->end);
                it->start = INT_MIN;
                it++;
            }
        }
        if(it == intervals.end())
        {
            intervals.push_back(newInterval);
        }
        vector<Interval> res;
        for(int i = 0;i < intervals.size();i++)
        {
            if(intervals[i].start != INT_MIN)
                res.push_back(intervals[i]);
        }
        
        return res;
    }
};