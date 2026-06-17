class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0],cursum=0;
        for(int num : nums){
            if(cursum<0){
                cursum=0;
            }
            cursum += num;
            maxsum =max(cursum,maxsum);
        }
        return maxsum;
    }
};
