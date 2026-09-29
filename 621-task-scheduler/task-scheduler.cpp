class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        // Count frequency
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // Max heap
        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0)
                pq.push(f);
        }

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;

            // One cycle = n + 1
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
                    // No task available
                    if (temp.empty())
                        break;

                    time++;
                }
            }

            // Put unfinished tasks back
            for (int f : temp) {
                pq.push(f);
            }
        }

        return time;
    }
};