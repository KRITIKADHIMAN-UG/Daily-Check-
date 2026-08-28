class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        makecombo(candidates, target, 0, comb, 0, ans);
        return ans;
    }
    void makecombo(vector<int>& candidates, int target, int i,
                   vector<int>& comb, int combtotal, vector<vector<int>>& ans) {

        // base case 1: if target is hit
        if (combtotal == target) {
            ans.push_back(comb);
            return;
        }

        // base case 2: if combtotal exceeds target
        if (combtotal > target) {
            return;
        }

        // base case 3: if index 'i' exceeds bounds
        if (i >= candidates.size()) {
            return;
        }

        // choose current element at 'i'
        comb.push_back(candidates[i]);

        // recusively call function for same 'i' because duplicate elements are
        // allowed here
        makecombo(candidates, target, i, comb, combtotal + candidates[i], ans);

        // if combtotal exceeds target in above recursive call, 'return' will be
        // executed [base case 2] and execution will reach here.
        comb.pop_back();

        // we are done with current i, move forward
        makecombo(candidates, target, i + 1, comb, combtotal, ans);
    }
};