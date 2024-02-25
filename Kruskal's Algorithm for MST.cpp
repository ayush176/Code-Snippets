#include <bits/stdc++.h>
using namespace std; 

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

const int N = 10000;
int n,m;
int par[N];

struct edge{
    int a,b,w;
};
vector<edge> edges;

bool comp(edge fir, edge sec)
{
    return fir.w<sec.w;
}

int find(int node)
{
    if(par[node]==-1)return node;
    return par[node] = find(par[node]);
}

void merge(int a, int b)
{
    par[a] = b;
}

void kruskal()
{
    for(int i=0;i<=n;i++)par[i]=-1;
    sort(edges.begin(),edges.end(),comp);
    
    int sum = 0;
    for(auto it : edges)
    {
        int fir = find(it.a);
        int sec = find(it.b);
        if(fir!=sec)
        {
            sum += it.w;
            merge(fir,sec);
        }
    }
    cout<<sum<<"\n";
}

int main() {
    FAST
    int t=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        edges = vector<edge> (m);

        for(int i = 0;i<m;i++)
        {
            cin>>edges[i].a>>edges[i].b>>edges[i].w;
        }
        
        kruskal();
    }
    return 0;
}


////////////////GFG find min spanning tree////////////
class DSU{
    private:
    vector<int> par,rank,size;
    
    public:
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    
    int findPar(int node){
        if(par[node]==node)return node;
        return par[node] = findPar(par[node]);
    }
    
    void unionByRank(int a, int b){
        int up_a = findPar(a);
        int up_b = findPar(b);
        
        if(up_a != up_b){
            if(rank[up_a] < rank[up_b]){
                par[up_a] = up_b;
            } else if(rank[up_b] < rank[up_a]){
                par[up_b] = up_a;
            } else {
                par[up_a] = up_b;
                rank[up_b]++;
            }
        }
    }
    
    void unionBySize(int a, int b){
        int up_a = findPar(a);
        int up_b = findPar(b);
        
        if(size[up_a] < size[up_b]){
            par[up_a] = up_b;
            size[up_b] += size[up_a];
        } else {
            par[up_b] = up_a;
            size[up_a]+= size[up_b];
        }
    }
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int node = 0;node<V;node++){
            for(auto it : adj[node]){
                int u = it[0];
                int wt = it[1];
                edges.push_back({wt,{u,node}});
            }
        }
        sort(edges.begin(),edges.end());
        
        int ans = 0;
        DSU d(V);
        
        for(auto it: edges){
            int a = it.second.first;
            int b = it.second.second;
            int wt = it.first;
            
            if(d.findPar(a) != d.findPar(b)){
                ans += wt;
                d.unionBySize(a,b);
            }
        }
        return ans;
    }
};
