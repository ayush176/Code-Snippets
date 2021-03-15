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
