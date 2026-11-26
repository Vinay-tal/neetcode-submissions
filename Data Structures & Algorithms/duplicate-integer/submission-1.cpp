class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> store;
        for(int x : nums){
            if(store[x]>0){
                return 1;
            }
            store[x]++;
        }
        return 0;
        
    }
};