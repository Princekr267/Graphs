#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<string>
using namespace std;
class Graph{
    int V;
    list<int> * l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int i=0; i<V; i++){
            list<int> neighbours=l[i];
            cout<<i<<" ";
            for(int v : neighbours){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    bool undirectHelper(int src, int par, vector<bool> &vis){
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v: neighbours){
            if(!vis[v]){
                if(undirectHelper(v, src, vis)){
                    return true;
                }
            } else{  // back edge
                if (v!=par){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycleUndir(){
        vector<bool> vis(V, false);
        return undirectHelper(0, -1, vis);
    }
};
int main(){
    int V=5;
    Graph graph(V);
    // undirected graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    cout<<graph.isCycleUndir()<<endl;
    return 0;
}