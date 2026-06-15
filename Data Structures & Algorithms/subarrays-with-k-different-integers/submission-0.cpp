class Solution {
public:
    int subarrayWithMaxKDistinct(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int count = 0;
        vector<int> freq(n+1,0);

        if(k == 0){
            return 0;
        }

        while(r<n){
            if(freq[nums[r]] == 0){
                count++;
            }
            freq[nums[r]]++;
            while(count > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    count--;
                }
                l++;
            }
            ans = ans + r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = 0;
        int b = 0;
        a = subarrayWithMaxKDistinct(nums, k);
        b = subarrayWithMaxKDistinct(nums, k-1);
        return a-b;
    }
};