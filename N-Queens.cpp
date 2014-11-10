class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        g.resize(n);
        dfs(0,n);
        return res;
    }
    
    void dfs(int row,int n){
        for(int i = 0;i < n;i++){
            if(isValid(i,row)){
                g[row] = i;
                if(row == n-1){
                    print(n);
                    return ;
                }
                dfs(row + 1,n);
            }
        }
    }
    
    bool isValid(int col,int row){
        int prec,prer;
        for(int i = 0;i < row;i++){
            prec = g[i];
            if(prec == col)
                return false;
            if(prec + i == col + row)
                return false;
            if(prec - i == col - row)
                return false;
        }
        return true;
    }
    
    void print(int n){
        vector<string> tmp;
        for(int i = 0;i < n;i++){
            string s;
            int j = 0;
            s.append(g[i],'.');
            s.append(1,'Q');
            s.append(n-g[i]-1,'.');
            tmp.push_back(s);
        }
        res.push_back(tmp);
    }
private:
    vector<vector<string> > res;
    vector<int> g;
};