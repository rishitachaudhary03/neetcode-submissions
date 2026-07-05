class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res =nums[0];
        int curmax=1, curmin=1;
        for(int num :nums){
            int temp=curmax*num;
            curmax=max(max(curmax*num,curmin*num),num);
            curmin=min(min(temp,curmin*num),num);
            res=max(res,curmax);
        }
        return res;    
    }
};
