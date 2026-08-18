class Solution {
public:
    int fun(vector<int>&coins, int amount, int idx, vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            if(amount%coins[idx]==0) return amount/coins[idx];
            else return 1e7; 
        }  
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int nt = fun(coins,amount,idx-1,dp);
        int t = INT_MAX;
        if(coins[idx]<=amount)
        {
            t = 1+fun(coins,amount-coins[idx],idx,dp);
        }
        return dp[idx][amount] = min(nt,t);
    }
    int coinChange(vector<int>& coins, int amount) 
    { 
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = fun(coins,amount,n-1,dp);
        if(ans>=1e7) return -1;
        return ans;
    }
//please upvote...
};