// Problem Link -> https://leetcode.com/problems/find-median-from-data-stream/description/


class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()){
            maxHeap.push(num);
            return;
        }

        if(maxHeap.top() < num){
            minHeap.push(num);
        }else{
            maxHeap.push(num);
        }
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        if(abs(maxHeapSize - minHeapSize) == 2){
            if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        if((minHeapSize + maxHeapSize)%2 == 0){
            int total = minHeap.top() + maxHeap.top();
            double res = ((double)total/2.0);
            return res;
        }else{
            if(maxHeapSize > minHeapSize)return (double)maxHeap.top();
            else return (double)minHeap.top();
        }
    }
};