class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        for (int d = 1; d <= 26; d++) {
            int cnt[26] = {}, l = 0, unique = 0, good = 0;

            for (int r = 0; r < s.size(); r++) {
                int x = s[r] - 'a';
                if (cnt[x]++ == 0) unique++;
                if (cnt[x] == k) good++;

                while (unique > d) {
                    int y = s[l++] - 'a';
                    if (cnt[y]-- == k) good--;
                    if (cnt[y] == 0) unique--;
                }

                if (unique == d && good == d)
                    ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};
