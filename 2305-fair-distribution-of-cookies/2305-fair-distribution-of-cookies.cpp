class Solution {
public:
    int solve(vector<int>& cookies, int k, vector<int>& veck, int ind){
        if(ind == cookies.size()) return *max_element(veck.begin(), veck.end());

        int mini = INT_MAX;
        for(int i=0;i<k;i++){
            veck[i] += cookies[ind];
            mini = min(mini, solve(cookies, k, veck, ind+1));
            veck[i] -= cookies[ind];
        }
        return mini;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> veck(k, 0);
        return solve(cookies, k, veck, 0);
    }
};