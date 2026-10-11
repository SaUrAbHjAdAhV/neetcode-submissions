class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int k = nums.size();
        int sum = 0;
        int max_sum = INT_MIN;
        if(k == 1){
            return nums[j];
        }
        while(j < k && i < k){
            sum = sum + nums[j];
            max_sum = max(sum, max_sum);
            while(sum <= 0 && i <= j){
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        return max_sum;
    }
};