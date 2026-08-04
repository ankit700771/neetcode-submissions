
// batter understanding - https://www.youtube.com/watch?v=rYh-Kkbzsnw

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task(26, 0);

        // store frquency of each char
        for(int i = 0; i<tasks.size(); i++) {
            task[tasks[i] - 'A']++;
        }

        // require max heap that help us to always store max element on top
        priority_queue<int> pq;
        int time = 0;

        for(int i = 0; i<26; i++) {
            if(task[i] != 0) {
                pq.push(task[i]);
            }
        }

        while(!pq.empty()) {
            vector<int> ans;

            for(int i = 0; i<=n; i++) {
                if(!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    ans.push_back(freq);
                }
            }

            for(int i = 0; i<ans.size(); i++) {
                if(ans[i] != 0) {
                    pq.push(ans[i]);
                }
            }

            if(pq.empty()) {
                time += ans.size();
            } else {
                time += n+1;
            }
            
        }

        return time;

    }
};
