/*
 * Author: Mukhammadkhon Asrorov
 * Date: 14/01/2024
 * Name: hw-10
 */

class Problem8 {
public:
    bool bottomUp(int target,vector<int>& nums){
            vector<vector<int>> dp(nums.size()+1,vector<int>( target+1,0));
            for(int i=0;i<nums.size();i++)
                dp[i][0]=1;
            
            for(int index=nums.size()-1;index>=0;index--){
                for(int t=1;t<=target;t++){
                    bool include=0;
                if(t-nums[index]>=0)
                    include=dp[index+1][t-nums[index]];
                    bool exclude=dp[index+1][t];
                    dp[index][t]=(include|| exclude);
                }
            }
            return dp[0][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum& 1)
            return false;
        int target=sum/2;
        int index=0;
        return bottomUp(target,nums);
    }
};
