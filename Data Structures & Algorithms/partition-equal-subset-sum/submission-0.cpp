class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set <int> dp;
        dp.insert(0);
        int sum=0;
        for(int num:nums){
            sum += num;
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        for(int i = nums.size()-1; i>=0; i--){
            unordered_set <int> nextdp;
            for(int t: dp){
                if(t+nums[i]==target){
                    return true;
                }
                nextdp.insert(t);
                nextdp.insert(t+nums[i]);
            }
            dp=nextdp;
        }
        return false;
    }
};
