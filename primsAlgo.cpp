#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<pair<int, int>>* l;
    bool isUndirec;
    public:
        Graph(int V, bool isUndirec=true){
            this->V=V;
            l=new list<pair<int, int>> [V];
            this->isUndirec=isUndirec;
        }

        void addEgde(int u, int v, int wt){
            l[u].push_back(make_pair(v, wt));
            if(isUndirec){
                l[v].push_back(make_pair(u, wt));
            }
        }

        void primsAlgo(int src){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<bool> mst(V, false);
            pq.push(make_pair(0, src));
            int ans=0;
            while(pq.size()>0){
                int u=pq.top().second;
                int wt=pq.top().first;
                pq.pop();

                if(!mst[u]){
                    mst[u]=true;
                    ans+=wt;
                    list<pair<int, int>> neighbours=l[u];
                    for(pair<int, int> n : neighbours){
                        int v=n.first;
                        int currwt=n.second;
                        pq.push(make_pair(currwt, v));

                    }
                }
            }
            cout<<"Final cost of mst: "<<ans<<endl;
        }

};
int main(){
    Graph graph(4);
    graph.addEgde(0, 1, 10);
    graph.addEgde(0, 2, 15);
    graph.addEgde(0, 3, 30);
    graph.addEgde(1, 3, 40);
    graph.addEgde(2, 3, 50);

    graph.primsAlgo(0);
    return 0;
}