class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;

        }
        vector<pair<int,int>> result(freq.begin(),freq.end());
        sort(result.begin(),result.end(),[](auto& a,auto&b){
            return a.second > b.second;
            });
        vector<int> final;
        for(int i = 0;i<k;i++){
            final.push_back(result[i].first);

        }
        return final;

        
    }
};
