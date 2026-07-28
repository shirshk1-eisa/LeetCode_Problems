class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& c, int target, int idx) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < c.size(); i++) {
            if (c[i] > target) continue;

            temp.push_back(c[i]);
            solve(c, target - c[i], i);   // reuse same element
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};