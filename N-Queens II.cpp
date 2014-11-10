class Solution {
public:
    int totalNQueens(int n) {
        g.resize(n);
        cnt = 0;
        dfs(0,n);
        return cnt;
    }
    
     void dfs(int row,int n){
        for(int i = 0;i < n;i++){
            if(isValid(i,row)){
                g[row] = i;
                if(row == n-1){
                    cnt++;
                    return;
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
    
private:
    vector<int> g;
    int cnt;
};