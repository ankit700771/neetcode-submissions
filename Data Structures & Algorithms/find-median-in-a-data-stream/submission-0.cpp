class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>>pq; // min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        vector<int> val;
        double ans;
        while(!pq.empty()) {
            int temp = pq.top();
            pq.pop();
            val.push_back(temp);
        }

        int n = val.size();

        if(n % 2 != 0) {
            ans = val[n/2] * 1.0;
        } else {
            int temp = n / 2;

            ans = (double(val[temp-1]) + double(val[temp])) / 2.0;
        }

        for(int i = 0; i<n; i++) {
            pq.push(val[i]);
        }

        return ans;

    }
};
