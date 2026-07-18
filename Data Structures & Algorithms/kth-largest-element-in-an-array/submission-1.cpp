class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        return quickselect(nums, 0, nums.size()-1,k);
    }
    int quickselect(vector<int> nums, int left, int right, int k){
        int p=left;
        int pivot=nums[right];
        for(int i=left ; i<right ; i++){
            if(nums[i]<=pivot){
                swap(nums[p],nums[i]);
                p++;
            }
        }
        swap(nums[p],nums[right]);
        if(p>k){
            return quickselect(nums, left, p-1,k);
        }
        if(p<k){
            return quickselect(nums, p+1, right,k);
        }
        else{
            return nums[p];
        }
    }
};
