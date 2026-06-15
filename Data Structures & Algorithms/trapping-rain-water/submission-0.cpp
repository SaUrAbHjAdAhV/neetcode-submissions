class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        vector<int> prefix_max(n);
        vector<int> suffix_max(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= height[i]){
                st.pop();
            }
            if(!st.empty()){
                suffix_max[i] = st.top();
            }
            else{
                suffix_max[i] = height[i];
                st.push(height[i]);
            } 
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() <= height[i]){
                st.pop();
            }
            if(!st.empty()){
                prefix_max[i] = st.top();
            }
            else{
                prefix_max[i] = height[i];
                st.push(height[i]);
            }
        }

        int sum = 0;

        for(int i = 0; i < n; i++){
            sum = sum + min(prefix_max[i],suffix_max[i]) - height[i]; 
        }

        return sum;
    }
};
