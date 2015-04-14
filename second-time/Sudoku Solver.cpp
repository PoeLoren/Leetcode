class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        sudoku(board);
        
    }
    
    bool sudoku(vector<vector<char> > &board)
    {
        for(int i = 0; i < 9;i++)
            for(int j = 0;j < 9;j++)
            {
                if(board[i][j] == '.')
                {
                    for(int k = 0;k < 9;k++)
                    {
                        board[i][j] = '1' + k;
                        if(isValid(board,i,j) && sudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        return true;
    }
    bool isValid(vector<vector<char> > &board,int row,int col)
    {
        for(int i = 0; i < 9;i++)
            if(i != row && board[i][col] == board[row][col])
                return false;
        for(int i = 0; i < 9;i++)
            if(i != col && board[row][col] == board[row][i])
                return false;
        int blocki = row /3 * 3;
        int blockj = col / 3 * 3;
        for(int i = blocki; i < blocki + 3;i++)
            for(int j = blockj;j < blockj + 3;j++)
            {
                if(i != row && j != col && board[i][j] == board[row][col])
                    return false;
            }
        return true;
    }
};