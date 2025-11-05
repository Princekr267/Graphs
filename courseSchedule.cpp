#include<iostream>  // leetcode problem no. =~207
#include<vector>
using namespace std;
bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>> &graph){
    vis[src]=true;
    rec[src]=true;

    for(int i=0; i<graph.size(); i++){
        int u=graph[i][1];
        int v=graph[1][0];
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
bool canFinish(int numCourses, vector<vector<int>> &graph){
    int V=numCourses;
    vector<bool> vis(V, false);
    vector<bool> rec(V, false);
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(isCycle(i, vis, rec, graph)){
                return false;
            }
        }
    }
    return true;
}
int main(){
    // Test case 1: No cycle (can finish courses)
    vector<vector<int>> graph1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Test 1 - Prerequisites: 1->0, 2->0, 3->1, 3->2\n";
    if(canFinish(4, graph1)){
        cout << "Result: Can finish all courses\n";
    } else {
        cout << "Result: Cannot finish - cycle detected\n";
    }
    
    // Test case 2: Has cycle (cannot finish courses)
    vector<vector<int>> graph2 = {{1, 0}, {0, 1}};
    cout << "\nTest 2 - Prerequisites: 1->0, 0->1 (circular)\n";
    if(canFinish(2, graph2)){
        cout << "Result: Can finish all courses\n";
    } else {
        cout << "Result: Cannot finish - cycle detected\n";
    }
    
    // Test case 3: Single course
    vector<vector<int>> graph3 = {};
    cout << "\nTest 3 - No prerequisites\n";
    if(canFinish(1, graph3)){
        cout << "Result: Can finish all courses\n";
    } else {
        cout << "Result: Cannot finish - cycle detected\n";
    }
    return 0;
}