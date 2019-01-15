class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int columns = array[0].size();
        
        int row = 0;
        int column = columns - 1;
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