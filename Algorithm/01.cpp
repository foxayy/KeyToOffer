/*
思路：
    每行从左至右递增，每列从上至下递增，则可以从右上角或者左下角入手
    1.右上角：如果数组元素大于target，则列-1；如果元素小于target，则行+1
    2.左下角：如果数组元素大于target，则行-1；如果元素小于target，则列+1
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int columns = array[0].size();
        
        int row = 0;
        int column = columns - 1;  //此解法是从右上角起
        bool found = false;
        if(rows > 0 && columns > 0){
            while (row < rows && column >= 0) {
                if (array[row][column] == target) {
                    found = true;
                    break;
                }
                else if (array[row][column] > target) {
                    --column;
                }
                else {
                    ++row;
                }
            }
        }
        return found;
    }
};