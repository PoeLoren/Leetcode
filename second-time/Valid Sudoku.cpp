class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++)
        {
            unordered_set<int> hash;
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                    continue;
                int k = board[i][j] - '0';
                if(hash.find(k) != hash.end())
                    return false;
                else
                    hash.insert(k);
            }
        }
        for(int i = 0; i < 9; i++)
        {
            unordered_set<int> hash;
            for(int j = 0; j < 9; ++j)
            {
                if(board[j][i] == '.')
                    continue;
                int k = board[j][i] - '0';
                if(hash.find(k) != hash.end())
                    return false;
                else
                    hash.insert(k);
            }
        }
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                unordered_set<int> hash;
                for(int k = 0; k < 3; ++k)
                {
                    for(int p = 0; p < 3; ++p)
                    {
                        if(board[i * 3 + k][j * 3 + p] == '.')
                            continue;
                        int num = board[i * 3 + k][j * 3 + p] - '0';
                        if(hash.find(num) != hash.end())
                            return false;
                        else
                            hash.insert(num);
                    }
                }
            }
        }
        return true;
    }
};