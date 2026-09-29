class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for (char c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0)
                pq.push(f);
        }

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;

            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {
                    int f = pq.top();
                    pq.pop();

                    f--;

                    if (f > 0)
                        temp.push_back(f);

                    time++;
                }
                else {
                    
                    if (temp.empty())
                        break;

                    time++;
                }
            }

            
            for (int f : temp) {
                pq.push(f);
            }
        }

        return time;
    }
};