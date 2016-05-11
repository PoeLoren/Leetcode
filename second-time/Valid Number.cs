public class Solution
{
    enum INPUT
    {
        INVALID,
        DIGIT,
        DOT,
        SIGN,
        SPACE,
        EXPONENT
    }
    public bool IsNumber(string s)
    {
        int[,] transition = {
            {-1, 1, 2, 3, 0, -1},
            {-1, 1, 4, -1, 8, 5},
            {-1, 4, -1, -1, -1, -1},
            {-1, 1, 2, -1, -1, -1},
            {-1, 4, -1, -1, 8, 5},
            {-1, 7, -1, 6, -1, -1},
            {-1, 7, -1, -1, -1, -1},
            {-1, 7, -1, -1, 8, -1},
            {-1, -1, -1, -1, 8, -1}
        
        INPUT input = INPUT.INVALID;
        int state = 0;
        foreach (char c in s)
        {
            if (c == ' '){
                input = INPUT.SPACE;
            }
            else if(Char.IsNumber(c)){
                input = INPUT.DIGIT;
            }
            else if(c == '.'){
                input = INPUT.DOT;
            }
            else if (c == '-' || c == '+'){
                input = INPUT.SIGN;
            }
            else if (c == 'e' || c == 'E'){
                input = INPUT.EXPONENT;
            }
            else{
                input = INPUT.INVALID;
            }
            state = transition[state, (int)input];
            if (state == -1)
                return false;
        }
        return state == 1 || state == 4 || state7 || state == 8;
    }
}