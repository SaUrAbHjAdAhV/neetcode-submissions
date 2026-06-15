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
        if(temp_reach >= n-1){
            return count;
        }

        while(i < n){
            int current_end = temp_reach;
            for(int j = i + 1; j <= current_end && j < n; j++){
                temp_reach = max(temp_reach, nums[j]+j);
            }
            count++;
            i = current_end;
            if(temp_reach >= n-1){
                break;
            }
        }

        return count;
    }
};