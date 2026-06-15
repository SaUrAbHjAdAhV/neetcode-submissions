class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int limit = intervals.size();
        int i = 1;

        while(i < limit){
            if(intervals[i][0] <= intervals[i-1][1]){
                intervals[i-1][0] = min(intervals[i-1][0], intervals[i][0]);
                intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);

                intervals.erase(intervals.begin()+i);
                limit--;
            }
            else{
                i++;
            }
        }
        return intervals;
    }
};