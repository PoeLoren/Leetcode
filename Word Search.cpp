class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool res = false;
        vector<vector<bool> > visited(m,vector<bool> (n,false));
        
        for(int i = 0; i < board.size();i++)
            for(int j = 0; j < board[0].size();j++){
                    if(bt(board,word,i,j,visited,0))
                        return true;
                }
            
        return res;
    }
    
    bool bt(const vector<vector<char> > &board,const string &word,int i,int j,vector<vector<bool> > &visited,int cur){
        if(cur == word.size())
            return true;
        if(i < 0 || i > board.size()-1 || j < 0 || j > board[0].size()-1)
            return false;
        if(visited[i][j] || board[i][j] != word[cur])
            return false;
        visited[i][j] = true;
        bool ret = bt(board,word,i+1,j,visited,cur+1) ||
                   bt(board,word,i,j+1,visited,cur+1) ||
                   bt(board,word,i-1,j,visited,cur+1) ||
                   bt(board,word,i,j-1,visited,cur+1);
        visited[i][j] = false;
        return ret;
    }
    
};