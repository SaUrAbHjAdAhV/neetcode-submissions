class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s = nums.size();
        int ans = 0;

        for(int i = 0; i < s; i++){
            int sum = nums[i];
            int j = i+1;
            while(j<s){
                if(sum == k){
                    ans++;
                }
                sum = sum + nums[j];
                j++;
            }
            if(sum == k){
                ans++;
            }
        }
        return ans;
    }
};