class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n){
            if(i+nums[i] >= n-1){
                return true;
            }
            else if(nums[i] > 0){
                int num = nums[i];
                int k = i;
                for(int j = 1; j <= num; j++){
                    if(k+j < n && nums[k+j] > nums[k]-j){
                        k = k+j;
                        break;
                    }
                }
                if(k == i){
                    return false;
                }
                i = k;
            }
            else{
                return false;
            }
        }

        return true;
    }
};