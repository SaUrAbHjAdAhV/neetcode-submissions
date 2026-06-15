class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        if(n == 1){
            return 0;
        }
        vector<int> reach(n);
        for(int i = 0; i < n; i++){
            reach[i] = i+nums[i];
        }

        int i = 0;
        int temp_reach = reach[i];

        while(i < n){
            if(temp_reach >= n-1){
                break;
            }
            int k = i;
            for(int j = i; j <= reach[i] && j < n; j++){
                if(temp_reach < reach[j]){
                    temp_reach = reach[j];
                    k = j;
                }
            }
            count++;
            i = k;
        }

        return count;
    }
};