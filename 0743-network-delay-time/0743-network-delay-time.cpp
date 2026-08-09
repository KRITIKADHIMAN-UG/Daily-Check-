class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dis(n+1,1e8);
        dis[k]=0;
        while(!pq.empty()){
            int node = pq.top().second;
            int step = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                if(dis[node] + it.second<dis[it.first]){
                    dis[it.first] = dis[node] + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i] == 1e8)
            return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};