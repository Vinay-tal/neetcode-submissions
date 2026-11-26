class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        for(int x : nums){
            if(store.count(x)){
                return 1;
            }
            store.insert(x);
        }
        return 0;
        
    }
};