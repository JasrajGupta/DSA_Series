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
     }
     bool cycleDirdfs(int src, vector<bool> &vis, vector<bool> &recpath){
        vis[src] = true;
        recpath[src] = true;

        for(int v : l[src]){
            if(!vis[v]){
                if(cycleDirdfs(v, vis, recpath)){
                    return true;
                }
            }
            else if(recpath[v]){
                return true;
            }
        }
        recpath[src] =  false;
        return false;

     }

     bool isCycle(){
        vector<bool> vis(v, false);
        vector<bool> recpath(v, false);

        for(int i = 0; i<v; i++){
            if(!vis[i]){
                if(cycleDirdfs(i, vis, recpath)){
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
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 4);

    cout<<g.isCycle()<<endl;
   
    return 0;
}