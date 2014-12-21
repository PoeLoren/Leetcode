class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1, s2;
        string::size_type st1e = version1.find('.'), st1s = 0;
        string::size_type st2e = version2.find('.'), st2s = 0;
        if(st1e == string::npos)
        {
            if(version1 == "")
            {
                s1 = 0;
                st1e = -1;
            }
            else
            {
                st1e = version1.size()-1;
                s1 = atoi(version1.substr(st1s).c_str());
            }
        }
        else
            s1 = atoi(version1.substr(st1s,st1e - st1s).c_str());
        if(st2e == string::npos)
        {
            if(version2 == "")
            {
                s2 = 0;
                st2e = -1;
            }
            else
            {
                s2 = atoi(version2.substr(st2s).c_str());
                st2e = version2.size() - 1;
            }
        }
        else
            s2 = atoi(version2.substr(st2s,st2e - st2s).c_str());
        if(s1 < s2)
            return -1;
        else if(s1 > s2)
            return 1;
        else
        {
            if(version1.find('.') == string::npos && version2.find('.') == string::npos)
                return 0;
            return compareVersion(version1.substr(st1e + 1),version2.substr(st2e + 1));
        }
    }
};