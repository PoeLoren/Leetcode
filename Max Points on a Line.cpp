/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int maxNum = 0;
        for(int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> m;
            int duplication = 1;
            m[INT_MAX] = 0;
            for(int j = 0; j < points.size();j++)
            {
                if(j != i)
                {
                    if(points[j].x == points[i].x && points[j].y == points[i].y)
                        duplication++;
                    else if (points[j].x == points[i].x)
                        m[INT_MIN]++;
                    else
                    {
                        double k = double(points[j].y - points[i].y) / (points[j].x - points[i].x);
                        m[k]++;
                    }
                }
            }
            for(auto it = m.begin(); it != m.end(); it++)
            {
                maxNum = max(maxNum, it->second + duplication);
            }
        }
        return maxNum;
    }
};