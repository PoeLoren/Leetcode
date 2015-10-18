class Solution {
public:

    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0; i < input.size(); ++i)
        {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for(int k = 0; k < left.size(); ++k)
                    for(int j = 0; j < right.size(); ++j)
                    {
                        if(input[i] == '+')
                            res.push_back(left[k] + right[j]);
                        else if(input[i] == '-')
                            res.push_back(left[k] - right[j]);
                        else
                            res.push_back(left[k] * right[j]);
                    }
            }
        }
        if(res.empty())
            res.push_back(atoi(input.c_str()));
        return res;
    }
};