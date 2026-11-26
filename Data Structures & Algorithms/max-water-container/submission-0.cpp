class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        int p1 = 0;
        int p2 = n-1;
        while(p1<p2){
            int area = min(heights[p1],heights[p2]) * (p2-p1);
            result = max(result,area);
            if(heights[p1] <= heights[p2]){
                p1++;
            }
             else{
                p2--;

            }


        }
        return result;

        
    }
};
