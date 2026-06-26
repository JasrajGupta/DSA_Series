#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

int prims(int v, vector<vector<pair<int, int>>>g){
    vector<bool> inMst(v, false);
    int minCost = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;

    pq.push({0, 0});
    while(pq.size() > 0){
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;
        pq.pop();

        if(!inMst[u]){
            inMst[u] = true;
            minCost += wt;

        for(int i = 0; i<g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;

            pq.push({w, v});
        }
    }
}
return minCost;
}


int main(){
    int v = 4;
    vector<vector<pair<int, int>>>g(v);

    g[0].push_back({1, 10}); //v wt
    g[1].push_back({0, 10}); //u wt

    g[0].push_back({2, 5});
    g[2].push_back({0, 5});
    
    g[1].push_back({3, 30});
    g[3].push_back({1, 30});

    g[2].push_back({3, 35});
    g[3].push_back({2, 35});

    g[3].push_back({0, 15});
    g[0].push_back({3, 15});

    cout<<"min cost"<<prims(v, g);

    return 0;
}