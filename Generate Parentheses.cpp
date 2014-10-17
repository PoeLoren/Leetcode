class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string s;
        genPar(0,0,s,n);
        return res;
    }
    void genPar(int l,int r,string &s,int n){
        if(l == r && l + r == 2 *n)
            res.push_back(s);
        else if(l  < r || l > n || r > n)
            return ;
        else{
            s.push_back('(');
            genPar(l+1,r,s,n);
            s.pop_back();
            s.push_back(')');
            genPar(l,r+1,s,n);
            s.pop_back();
        }
    }
};