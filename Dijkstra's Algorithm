#include <bits/stdc++.h>
using namespace std; 

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

const int N = 10000;

int n,m;
vector<pair<int,int>> adj[N];
ll dist[N];

void dijkstra(int src)
{
    for(int i=0;i<=n;i++)dist[i] = INT_MAX;

    dist[src] = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;

    pq.push({0,src});

    while(!pq.empty())
    {
        int cur = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        for(auto child : adj[cur])
        {
            if(cur_dist + child.second < dist[child.first])
            {
                dist[child.first] = cur_dist + child.second;
                pq.push({dist[child.first],child.first});
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<" \n"[i==n];
}

int main() {
    FAST
    int t=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=n;i++)
        {
            adj[i].clear();
        }

        for(int i=0;i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
            // for directed graph add the below line.
            adj[b].push_back({a,w});
        }
        // run the vertex for finding shortest distances to all other vertices
        dijkstra(1);
    }
    return 0;
}
