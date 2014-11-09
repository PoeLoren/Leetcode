class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int num = 0;
        string res;
        int n = 0;
        while(i >=0 && j >=0){
            n = a[i]-'0' + b[j] - '0' + num;
            res.insert(res.begin(),(n & 0x1) + '0');
            num = n >> 1 ;
            i--;
            j--;
        }
        while(i >= 0){
            n = a[i] - '0' + num;
            res.insert(res.begin(),(n & 0x1) + '0');
            num = n >> 1;
            i--;
        }
        while(j >= 0){
            n = b[j] - '0' + num;
            res.insert(res.begin(), (n & 0x1) + '0');
            num = n >> 1;
            j--;
        }
        if(num == 1)
            res.insert(res.begin(),'1');
        return res;
        
    }
};