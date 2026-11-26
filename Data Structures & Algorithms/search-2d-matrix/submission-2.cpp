class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m-1;
        while(top <= bottom){
            int mid1 = (bottom + top)/2;
            if(matrix[mid1][0] > target){
                bottom = mid1-1;
            }
            else if(matrix[mid1][n-1] < target){
                top = mid1 + 1;
            }
            else{
                break;

            }
            
        }
        if(!(top <= bottom)){
            return false;
        }
        int mid1 = (top + bottom)/2;
        int l = 0, r = n-1;
        while(l <= r){
            int mid2 = (l+r)/2;
            if(target > matrix[mid1][mid2]){
                l = mid2+1;
            }
            else if(target < matrix[mid1][mid2]){
                r = mid2-1;
            }
            else{
                return true;
            }
        }
        return false;



        
    }
};
