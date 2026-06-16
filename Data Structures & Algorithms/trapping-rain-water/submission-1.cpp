class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 2){
            return 0;
        }
        int sum = 0;
        int r = height.size()-1;
        int l = 0;
        int leftmax = height[l];
        int rightmax = height[r];

        while(l < r){
            if(leftmax <= rightmax){
                l++;
                if(leftmax - height[l] > 0){
                    sum = sum + leftmax - height[l];
                }
                leftmax = max(leftmax,height[l]);
            }
            else{
                r--;
                if(rightmax - height[l] > 0){
                    sum = sum + rightmax - height[r];
                }
                rightmax = max(rightmax,height[r]);
            }
        }
        return sum;
    }
};
