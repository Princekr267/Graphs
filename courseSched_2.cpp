#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &graph){
    vis[src]=true;
    for(int i=0; i<graph.size(); i++){
        int u=graph[i][1];
        int v=graph[i][0];
        if(u==src){
            if(!vis[v]){
                topoSort(v, vis, s, graph);
            }
        }
    }
    s.push(src);
}
bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>> &graph){
    vis[src]=true;
    rec[src]=true;

    for(int i=0; i<graph.size(); i++){
        int u=graph[i][1];
        int v=graph[i][0];
        if(u==src){
            if(!vis[v]){
                if(isCycle(v, vis, rec, graph)){
                    return true;
                }
            } else{
                if(rec[v]){
                    return true;
                }
            }
        }
    }
    rec[src]=false;
    return false;
}
vector<int> findOrder(int V, vector<vector<int>> &graph){
    vector<bool> vis(V, false);
    vector<bool> rec(V, false);
    vector<int> ans;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(isCycle(i, vis, rec, graph)){
                return ans;
            }
        }
    }
    //Topological Sorting
    vector<bool> vis_2(V, false);
    stack<int> s;
    for(int i=0; i<V; i++){
        if(!vis_2[i]){
            topoSort(i, vis_2, s, graph);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main() {
    int V = 4;
    vector<vector<int>> graph = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> order = findOrder(V, graph);
    if (order.empty()) {
        cout << "Cycle detected! Topological sort not possible." << endl;
    } else {
        cout << "Topological order: ";
        for (int node : order)
            cout << node << " ";
        cout << endl;
    }
    return 0;
}
