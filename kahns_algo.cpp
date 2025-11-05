#include<iostream>
#include<vector>
#include<queue>
#include<list>
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
            l[v].push_back(u);
        }
    }
    void print(){
        for(int i=0; i<V; i++){
            list<int> neighbours = l[i];
            cout<<i<<": ";
            for(int v : neighbours){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    void calIndegree(vector<int> &indeg){
        for(int u=0; u<V; u++){
            list<int> neighbours=l[u];
            for(int v : neighbours){
                indeg[v]++;
            }
        }
    }
    void topoSort_2(){
        vector<int> indeg(V, 0);
        calIndegree(indeg);
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            list<int> neighbours=l[curr];
            for(int v : neighbours){
                indeg[v]--;
                if(indeg[v]==0){   // no pending dependencies
                    q.push(v);
                }
            }
        }
        cout<<endl; 
    }
};
int main(){
    Graph graph(6, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topoSort_2();
    return 0;
}