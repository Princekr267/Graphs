#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
            cout<<i<<" : ";
            for(int v : neighbours){
                cout<<v<<" ";
            }
            cout<<endl; 
        }
    }
   /* void bfs(){  // O(V + E)    basic (for connected graphs only)
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            list<int> neighbours=l[u];
            for(int v : neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    } */
    void bfsHelper(int st, vector<bool> &vis){  // O(V + E)    (for disconnected graphs)
        queue<int> q;
        q.push(st);
        vis[st]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            list<int> neighbours=l[u];
            for(int v : neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
    void bfs(){
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                bfsHelper(i, vis);
                cout<<endl;
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis){ // O(V + E)
        vis[u]=true;
        cout<<u<<" ";
        list<int> neighbours=l[u];
        for(int v : neighbours){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }
    /*void dfs(){
        vector<bool> vis(7, false);  //basic
        dfsHelper(0, vis);
    }*/
   void dfs(){
    vector<bool> vis(V, false);
    for(int u=0; u<V; u++){
        if(!vis[u]){
            dfsHelper(u, vis);
            cout<<endl;  // different line for disconnected
        }
    }
   }

    bool pathHelper(int src, int dest, vector<bool> vis){
        if(src==dest) return true;
        vis[src]=true;
        list<int> neighbours=l[src];
        for(int v: neighbours){
            if(!vis[v]){
                if(pathHelper(v, dest, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(int src, int dest){
        vector<bool> vis(V, false);
        return pathHelper(src, dest, vis);
    }
};
class weighGraph{
    int V;
    list<pair<int, int>> * l;
    weighGraph(int V){
        this->V=V;
        l=new list<pair<int, int>> [V];
    }
    
    void addEdge(int u, int v){
        
    }
};
int main(){
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
//    graph.addEdge(5, 6);

    // graph.print();

    graph.bfs();

    graph.dfs ();
    cout<<endl;
    cout<<graph.hasPath(5, 6)<<endl;
    return 0;
}
