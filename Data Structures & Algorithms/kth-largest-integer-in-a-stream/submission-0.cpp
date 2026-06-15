class KthLargest {
    int threshold;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        threshold = k;
        for(auto testscore : nums){
            minHeap.push(testscore);
            if(minHeap.size() > threshold){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > threshold){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
