class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i = 0;

        while(i < n){
            vector<int> current_interval = intervals[i];
            while(i < n-1 && intervals[i+1][0] <= current_interval[1]){
                current_interval[0] = min(current_interval[0], intervals[i+1][0]);
                current_interval[1] = max(current_interval[1], intervals[i+1][1]);
                i++;
            }
            ans.push_back(current_interval);
            i++;
        }
        return ans;
    }
};