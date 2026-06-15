class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // vector<vector<int>> ans;
        // int n = intervals.size();
        // int i = 0;

        // while(i < n){
        //     int ifmerge = false;
        //     vector<int> current_interval = newInterval;
        //     while(i < n && intervals[i][0] <= current_interval[1]){
        //         current_interval[0] = min(current_interval[0], intervals[i][0]);
        //         current_interval[1] = max(current_interval[1], intervals[i][1]);
        //         ifmerge = true;
        //         i++;
        //     }
        //     if(ifmerge){
        //         ans.push_back(current_interval);
        //     }
        //     else{
        //         ans.push_back(intervals[i]);
        //     }
        //     i++;
        // }

        vector<vector<int>> ans1 = intervals;
        vector<vector<int>> ans2;
        ans1.push_back(newInterval);
        sort(ans1.begin(), ans1.end());
        int n = ans1.size();
        int i = 0;

        while(i < n){
            vector<int> current_interval = ans1[i];
            while(i < n-1 && ans1[i+1][0] <= current_interval[1]){
                current_interval[0] = min(current_interval[0], ans1[i+1][0]);
                current_interval[1] = max(current_interval[1], ans1[i+1][1]);
                i++;
            }
            ans2.push_back(current_interval);
            i++;
        }
        return ans2;
    }
};
