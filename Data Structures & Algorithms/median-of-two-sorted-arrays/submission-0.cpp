class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int m = nums1.size();
        int n = nums2.size();

        vector<int> store;

        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                store.push_back(nums1[i]);
                i++;
            }
            else {
                store.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) store.push_back(nums1[i++]);
        while(j < n) store.push_back(nums2[j++]);

        int mid = store.size()/2;

        if((m+n)%2 == 0) {
            return (store[mid-1] + store[mid]) / 2.0;
        }
        else {
            return store[mid];
        }
    }
};
