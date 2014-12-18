class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        set<vector<int> > tmpRes;
        vector<vector<int> > res;
        if(num.size() < 4)
            return res;
        for(int i = 0; i < num.size(); i++)
            for(int j = i + 1;j < num.size();j++)
            {
                int l = j + 1;
                int r = num.size() - 1;
                while(l < r)
                {
                    int sum = num[i] + num[j] + num[l] + num[r];
                    if(sum == target)
                    {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        tmpRes.insert(tmp);
                        l++;
                        r--;
                    }
                    else if(sum < target)
                        l++;
                    else
                        r--;
                }
            }
        for(auto it = tmpRes.begin(); it != tmpRes.end(); it++)
        {
            res.push_back(*it);
        }
        return res;
    }
};