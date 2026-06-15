class Twitter {
    int timestamp;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        struct Node{
            int timestamp;
            int tweetId;
            int userId;
            int index;
        };

        struct Compare{
            bool operator()(Node &a, Node &b){
                return a.timestamp < b.timestamp;
            }
        };

        priority_queue<Node, vector<Node>, Compare> maxHeap;

        unordered_set<int> followee = followMap[userId];
        followee.insert(userId);

        for(auto &follow : followee){
            if(tweetMap[follow].empty()){
                continue;
            }

            int idx = tweetMap[follow].size()-1;

            maxHeap.push({
                tweetMap[follow][idx].first,
                tweetMap[follow][idx].second,
                follow,
                idx
                });
        }

        vector<int> ans;

        while(!maxHeap.empty() && ans.size() < 10){
            Node cur = maxHeap.top();
            maxHeap.pop();
            
            ans.push_back(cur.tweetId);

            int next_idx = cur.index-1;
            if(next_idx >= 0){
                maxHeap.push({
                    tweetMap[cur.userId][next_idx].first,
                    tweetMap[cur.userId][next_idx].second,
                    cur.userId,
                    next_idx
                });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
