/*
 * Author: Mukhammadkhon Asrorov
 * Date: 14/01/2024
 * Name: hw-10
 */

class Problem6 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>time(n+1,1e9);
        set<pair<int,int>>s;
        s.insert({0,k});
        time[k]=0;
        while(!s.empty()){
            auto i=*(s.begin());
            int wt=i.first;
            int node=i.second;
            s.erase(s.begin());
            for(auto it:adj[node]){
                if(it.second+wt<time[it.first]){
                    time[it.first]=it.second+wt;
                    s.insert({time[it.first],it.first});
                }
            }
        }
        for(int i=1;i<n+1;i++){
            if(time[i]==1e9){
                return -1;
            }
        }
        return *max_element(time.begin()+1,time.end());
    }
};
