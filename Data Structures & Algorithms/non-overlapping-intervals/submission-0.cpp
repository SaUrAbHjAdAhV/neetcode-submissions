class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int ans = 0;
        //vector<int> ans_vec;
        int i = 0;

        while(i<n){
            vector<int> current_interval = intervals[i];
            while(i < n-1 && intervals[i+1][0] < current_interval[1]){
                i++;
                //current_interval = intervals[i];
            }
            //ans.push_back(current_interval);
            ans++;
            i++;
        }

        return n-ans;
    }
};