#include<iostream>
#include<list>
#include<vector>
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
    bool cycleInDFS(int src, int par, vector<bool> &vis){
        vis[src] = true;

        list<int> neigh = l[src];

        for(int v : neigh){
            if(!vis[v]){
                if(cycleInDFS(v, src, vis)) return true;
            }
            else if(v != par){
                return true;
            }
        }
         return false;
    }
   

    bool isCycle(){
        vector<bool> vis(v, false);

        for(int i = 0; i<v; i++){
            if(!vis[i]){
                if(cycleInDFS(i, -1, vis)){
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
    
    
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    
    cout<<g.isCycle()<<endl;
    return 0;
}