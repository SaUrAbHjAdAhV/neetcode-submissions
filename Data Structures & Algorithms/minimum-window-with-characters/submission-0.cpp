class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int m = s.size();
        int n = t.size();
        int l = 0;
        int r = 0;
        int start = 0;
        int end = m+1;
        int missing = n;

        for(int i = 0; i < n; i++){
            mp1[t[i]]++;
        }

        mp2 = mp1;

        while(r<m){
            auto it = mp2.find(s[r]);

            if(it != mp2.end()){
                it->second--;

                if(it->second >= 0){
                    missing--;
                }
            }

            if(missing == 0){
                auto it4 = mp2.find(s[l]);

                while(it4 == mp2.end() || it4->second < 0){
                    if(it4 != mp2.end()){
                        it4->second++;
                    }
                    l++;
                    it4 = mp2.find(s[l]);
                }
                if(end-start > r-l){
                    start = l;
                    end = r;
                }
                if(++mp2[s[l]] > 0){
                    missing++;
                }
                l++;
            }
            r++;
        }
        if(end-start>m){
            return "";
        }
        return s.substr(start,end-start+1);
    }
};