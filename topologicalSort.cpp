#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int V;
    bool isUndirec;
    list<int>* l;
public:
    Graph(int V, bool isUndirec=true){
        this->V=V;
        this->isUndirec=isUndirec;
        l=new list<int> [V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndirec){
            l[v].push_back(u);
        }
    }

    void topoHeler(int src, vector<bool> &vis, stack<int> &s){ //dfs - O(V + E)
        vis[src]=true;
        list<int> neighbours = l[src];
        for(int v : neighbours){
            if(!vis[v]){
                topoHeler(v, vis, s);
            }
        }
        s.push(src);
    }   
    void topoSort(){
        vector<bool> vis(V, false);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoHeler(i, vis, s);
            }
        }
        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};
int main(){
    Graph graph(6, false);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topoSort();
    return 0;
}