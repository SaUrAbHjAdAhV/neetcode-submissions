class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        int groupNum = n/groupSize;
        map <int,int> freq;

        for(int i = 0; i < n; i++){
            freq[hand[i]]++;
        }
        
        

        for(int i = 0; i < groupNum; i++){
            if(freq.size() < groupSize){
                return false;
            }
            pair <int,int> prev = {0,0};
            int count = 0;
            for(auto &it: freq){
                if(count > 0){
                    if(it.first - prev.first != 1){
                        return false;
                    }
                }
                prev = it;
                it.second = it.second -1;
                count++;
                if(count == groupSize){
                    break;
                }
            }
            vector<int> toErase;

            for(auto &it : freq){
                if(it.second == 0){
                    toErase.push_back(it.first);
                }
            }

            for(int key : toErase){
                freq.erase(key);
            }
        }

        return true;

    }
};