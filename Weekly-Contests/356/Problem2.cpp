// Count complete subarrays in an array

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans=0;
        set<int> s(nums.begin(),nums.end()), currSet;
        for(int i=0;i<nums.size();i++){
            
            for(int j=i;j<nums.size();j++){
                currSet.insert(nums[j]);
                if(currSet.size()==s.size()){
                    ans++;
                }
            }
            currSet.clear();
        }
        return ans;
    }
};