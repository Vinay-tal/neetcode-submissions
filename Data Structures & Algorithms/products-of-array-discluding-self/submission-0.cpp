class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        int product = 1;
        for(int i = 1;i<n;i++){
            product *= nums[i-1];
            prefix[i] = product;
        }
        vector<int> suffix(n);
        suffix[n-1] = 1;
        int newproduct = 1;
        for(int i = n-2;i>=0;i--){
            newproduct *= nums[i+1];
            suffix[i] = newproduct;
        }
        vector<int> output(n);
        for(int i =0;i<n;i++){
            output[i] = prefix[i]*suffix[i];
        } 
        return output;


    }
};
