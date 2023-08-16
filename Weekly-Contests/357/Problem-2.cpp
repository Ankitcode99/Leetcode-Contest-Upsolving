// Check if it is possible to split the array

class Solution {
vector<vector<int>> dp;
private:
    bool solve(int l, int r, vector<int>& pref, int m){
        if(l==r){
            return true;
        }   
        if((l>0 and pref[r]-pref[l-1]<m) || pref[r]<m){
            return false;
        }
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        for(int k=l;k<r;k++){
            if(solve(l,k,pref,m) and solve(k+1,r,pref, m)){
                dp[l][r] = 1;
                return true;;
            }
        }
        return dp[l][r]=false;
    }
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()<=2)
            return true;
        dp = vector<vector<int>>(nums.size()+5, vector<int>(nums.size()+5, -1));
        
        vector<int> pref(nums.size());
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pref[i] = pref[i-1] + nums[i];
        }
        
        return solve(0,nums.size()-1, pref, m);
    }
};