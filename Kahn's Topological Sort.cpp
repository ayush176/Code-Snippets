#include <bits/stdc++.h>
using namespace std; 

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

const int N = 10000;

int n,m;
vector<ll> adj[N];
ll vis[N],in_deg[N];

void topo_sort()
{
    queue<int> q;
    vector<int> ans;
    int cnt = 0;

    for(int i=1;i<=n;i++)
    {
        if(in_deg[i]==0)q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        cnt++;

        for(auto ch : adj[node])
        {
            in_deg[ch]--;
            if(in_deg[ch]==0)
            {
                q.push(ch);
            }
        }
    }

    if(cnt!=n)cout<<"There is a cycle in the graph\n";
    else
    {
        for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
    }
    
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
            in_deg[i]=0;
            vis[i] = 0;
            adj[i].clear();
        }

        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            in_deg[b]++;
        }
        topo_sort();
    }
    return 0;
}

