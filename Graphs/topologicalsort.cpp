#include<iostream>
#include<stack>
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

     void dfs(int src, vector<bool> &vis, stack<int> &s){
        vis[src] = true;

        for(int v : l[src]){
            if(!vis[v]){
                dfs(v, vis, s);
            }
        }
        s.push(src);
    }
     void topo(){
        vector<bool> vis(v, false);
        stack<int> s;

        for(int i = 0; i<v; i++){
            if(!vis[i]){
                dfs(i, vis, s);
            }
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

};

int main(){
    Graph g(6);

    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.topo();

    return 0;
}