#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int>* l;
    bool isUndirec;
public:
    Graph(int V, bool isUndirec=true){
        this->V=V;
        l=new list<int> [V];
        this->isUndirec=isUndirec;
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndirec){
            l[v].push_back(v);
        }
    }

    bool dirCycleDirHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src]=true;
        recPath[src]=true;
        list<int> neighbours=l[src];

        for(int v : neighbours){
            if(!vis[v]){
                if(dirCycleDirHelper(v, vis, recPath)){
                    return true;
                }
            } else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false; 
    }
    bool isCycleDir(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dirCycleDirHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }

  /*  bool isBipartite(){   // less optimised
        queue<int> q;
        vector<bool> vis(5, false);
        vector<int> color(5, -1);
        q.push(0);
        color[0]=0;
        vis[0]=0;
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            list<int> neighbour=l[curr];
            for(int v : neighbour){
                if(!vis[v]){
                    vis[v]=true;
                    color[v]=!color[curr];
                    q.push(v);
                } else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    } */
    bool isBipartite(){   // More optimised
        queue<int> q;
        vector<int> color(5, -1);
        q.push(0);
        color[0]=0;
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            list<int> neighbour=l[curr];
            for(int v : neighbour){
                if(color[v]==-1){
                    color[v]=!color[curr];
                    q.push(v);
                } else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void pathHelper(int src, int dest, vector<bool> &vis, string path){  // O(V+E)
        if(src==dest){
            cout<<path<<dest<<endl;
            return;
        }
        vis[src]=true;
        path+=to_string(src);
        list<int> neighbour=l[src];
        for(int v : neighbour){
            if(!vis[v]){
                pathHelper(v, dest, vis, path);
            }
        }
        path=path.substr((0, path.size()-1));
        vis[src]=false;

    }
    void printAllPaths(int src, int dest){
        vector<bool> vis(V, false);
        string path="";
        pathHelper(src, dest, vis, path);
    }
};
int main(){
    Graph graph(4, false);
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 3);
   // graph.addEdge(3, 0);
    cout<<graph.isCycleDir()<<endl;

    Graph bipart(5, false);
    bipart.addEdge(0, 1);
    bipart.addEdge(0, 2);
    bipart.addEdge(1, 3);
    bipart.addEdge(2, 3);
//    bipart.addEdge(0, 3);
    cout<<bipart.isBipartite()<<endl;

    Graph allPath(7, false);
    allPath.addEdge(0, 3);
    allPath.addEdge(2, 3);
    allPath.addEdge(3, 1);
    allPath.addEdge(4, 0);
    allPath.addEdge(4, 1);
    allPath.addEdge(5, 0);
    allPath.addEdge(5, 2);
    allPath.printAllPaths(5, 1);
    return 0;
}