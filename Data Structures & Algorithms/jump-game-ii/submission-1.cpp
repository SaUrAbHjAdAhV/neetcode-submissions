class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        if(n == 1){
            return 0;
        }

        int i = 0;
        int temp_reach = nums[i] + i;

        while(i < n){
            if(temp_reach >= n-1){
                break;
            }
            for(int j = i; j <= nums[i]+i && j < n; j++){
                temp_reach = max(temp_reach, nums[j]+j);
            }
            count++;
            i = temp_reach;
        }

        return count;
    }
};