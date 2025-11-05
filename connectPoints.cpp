#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
void changeToCurlyBrackets(string &input){
    for(int i=0; i<input.size(); i++){
        if(input[i]=='[' || input[i]=='('){
            input[i]='{';
        } else if(input[i]==']' || input[i]==')'){
            input[i]='}';
        }
    }    
}
int minCostConnectPoints(vector<vector<int>> &points){  // MST(min spanning tree) Problem
    int V=points.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src=0;
    vector<bool> mst(V, false);
    pq.push(make_pair(0, src));
    int minCost=0;
    while(pq.size()>0){
        int u=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        if(!mst[u]){
            mst[u]=true;
            minCost+=cost;
            for(int v=0; v<V; v++){
                if(u!=v){
                    int wt=abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                    pq.push(make_pair(wt, v));
                }
            }
        }
    }
    return minCost;
}

class Info{
public:
    int u;
    int cost;
    int stops;
    Info(int u, int cost, int stops){
        this->u=u;
        this->cost=cost;
        this->stops=stops;
    }
};
int findCheapestFlight(int V, vector<vector<int>> &flights, int src, int dest, int k){
    queue<Info> q;
    vector<int> dist(V, INT32_MAX);
    dist[src]=0;
    q.push(Info(src, 0, -1));
    while(q.size()>0){
        Info curr=q.front();
        q.pop();

        for(int i=0; i<flights.size(); i++){
            if(flights[i][0]==curr.u){
                int v=flights[i][1];
                int wt=flights[i][2];

                if(dist[v]>curr.cost + wt && curr.stops+1 <= k){
                    dist[v]=curr.cost+wt;
                    q.push(Info(v, dist[v], curr.stops+1));
                }
            }
        }
    }
    if(dist[dest]==INT32_MAX){
        return -1;
    }
    return dist[dest];
}

int main(){
    vector<vector<int>> points={{3, 12}, {-2, 5}, {-4, 1}};
    cout<<minCostConnectPoints(points)<<endl;

    
    vector<vector<int>> flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    cout<<findCheapestFlight(4, flights, 0, 3, 1)<<endl;
    return 0;
}