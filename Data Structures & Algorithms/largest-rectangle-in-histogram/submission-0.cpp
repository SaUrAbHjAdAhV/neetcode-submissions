class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left_min(n);
        vector<int> right_min(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right_min[i] = st.top();
            }
            else{
                right_min[i] = n;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                left_min[i] = st.top();
            }
            else{
                left_min[i] = -1;
            }
            st.push(i);
        }

        int area = 0;
        for(int i = 0; i < n; i++){
            int length = right_min[i] - left_min[i] - 1;
            int temp_area = length*heights[i];
            area = max(area, temp_area);
        }
        return area;
    }
};
