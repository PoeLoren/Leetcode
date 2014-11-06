class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }
        int stripy = matrix.size()-1;
        int stripx = matrix[0].size()-1;
        spiral(matrix,res,0,0,stripx,stripy);
        return res;
    }
    
    void spiral(vector<vector<int> > &matrix,vector<int> &res,int x,int y,int stripx,int stripy){
        int i,j;
        if(stripy < 0 || stripx < 0)
            return;
        if(stripy == 0){
            for(i = y;i < y + stripx + 1;i++)
                res.push_back(matrix[x][i]);
            return;
        }
        if(stripx == 0){
            for(i = x;i < x + stripy + 1;i++)
                res.push_back(matrix[i][y]);
            return;
        }
        for(i = y;i < stripx + y;i++){
            res.push_back(matrix[x][i]);
        }
        for(j = x;j < stripy + x;j++){
            res.push_back(matrix[j][i]);
        }
        for(;i > x;i--){
            res.push_back(matrix[j][i]);
        }
        for(;j > y;j--)
            res.push_back(matrix[j][i]);
        spiral(matrix,res,x+1,y+1,stripx-2,stripy-2);
    }
};


class Solution {
public:

vector<int> spiralOrder(vector<vector<int> >& matrix) {
vector<int> result;
if (matrix.empty()) return result;
int beginX = 0, endX = matrix[0].size() - 1;
int beginY = 0, endY = matrix.size() - 1;
while (true) {
// From left to right
for (int j = beginX; j <= endX; ++j) result.push_back(matrix[beginY][j]);
if (++beginY > endY) break;
// From top to bottom
for (int i = beginY; i <= endY; ++i) result.push_back(matrix[i][endX]);
if (beginX > --endX) break;
// From right to left
for (int j = endX; j >= beginX; --j) result.push_back(matrix[endY][j]);
if (beginY > --endY) break;
// From bottom to top
for (int i = endY; i >= beginY; --i) result.push_back(matrix[i][beginX]);
if (++beginX > endX) break;
}
return