class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        if(n == k){
            for(int i = 0; i < n; i++){
                sum = sum + cardPoints[i];
            }
            return sum;
        }
        vector<int> prefix_sum(n+1);
        prefix_sum[0] = 0;
        for(int i = 1; i <= n; i++){
            prefix_sum[i] = cardPoints[i-1]+prefix_sum[i-1];
        }
        vector<int> prefix_sum_reverse(n+1);
        prefix_sum_reverse[0] = 0;
        for(int i = n-1; i >= 0 ; i--){
            prefix_sum_reverse[n-i] = cardPoints[i]+prefix_sum_reverse[n-1-i];
        }
        int r = n-1;
        int l = 0;
        int k_loop = k;
        while(k_loop > 0){
            if((prefix_sum[k_loop +(l)] - prefix_sum[l]) >= (prefix_sum_reverse[k_loop+(n-1-r)] - prefix_sum_reverse[n-1-r])){
                sum = sum + cardPoints[l];
                l++;
                k_loop--;
            }
            else{
                sum = sum + cardPoints[r];
                r--;
                k_loop--;
            }
        }
        return sum;
    }
};