#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int> *l;

public: 
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool cycleInBfs(int src, vector<bool> &vis){
        queue<pair<int, int>>q;

        q.push({src, -1});
        vis[src] = true;

        while(q.size() > 0){
            int u = q.front().first;
            int par = q.front().second;
            q.pop();

            list<int> neigh = l[u];
            for(int v : neigh){
                if(!vis[v]){
                    q.push({v, u});
                    vis[v] = true;
                }
                else if(v != par){
                    return true;
                }
            }
        }
        return false;
    }
    bool cycle(){
        vector<bool> vis(v, false);

        for(int i = 0; i<v; i++){
            if(!vis[i]){
                if(cycleInBfs(i, vis)){ 
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph g(5);
     
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    // g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout<<g.cycle()<<endl;
}