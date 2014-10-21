class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0;i<9;i++){
            unordered_set<char> us;
            for(int j = 0;j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                if(us.find(board[i][j])==us.end())
                    us.insert(board[i][j]);
                else
                    return false;
            }
        }
        for(int j = 0;j<9;j++){
            unordered_set<char> us;
            for(int i = 0;i < 9; i++){
                if(board[i][j] == '.')
                    continue;
                if(us.find(board[i][j])==us.end())
                    us.insert(board[i][j]);
                else
                    return false;
            }
        }
        for(int i = 0; i < 9;i= i + 3)
            for(int j = 0;j < 9; j = j + 3)
                {
                    unordered_set<char> us;
                    for(int p = i;p < i + 3;p++){
                        for(int q = j;q < j + 3;q++){
                            if(board[p][q] == '.')
                                continue;
                            if(us.find(board[p][q]) == us.end())
                                us.insert(board[p][q]);
                            else
                                return false;
                        }
                    }
                }
        return true;
    }
};