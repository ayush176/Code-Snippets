vector<ll> adj[200003];
ll lca[200003][20];
ll level[200003];

void dfs(int node, int lvl, int par)
{
    level[node] = lvl;
    lca[node][0] = par;
    
    for(auto ch : adj[node])
    {
        if(ch!=par)dfs(ch,lvl+1,node);
    }
    
}

void init()
{
    for(int j=0;j<19;j++)
    {
        for(int i=0;i<=n;i++)
        {
            lca[i][j] = -1;
        }
    }

    dfs(1,0,-1);
    
    for(int j=1;j<19;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(lca[i][j-1]!=-1)
            {
                int par = lca[i][j-1];
                lca[i][j] = lca[par][j-1];
            }
        }
    }
}

ll LCA(int a, int b)
{
    if(level[b]<level[a])swap(a,b);
    
    int d = level[b] - level[a];
    
    while(d>0)
    {
        int i = log2(d);
        b = lca[b][i];
        
        d -= (1<<i);
    }
    
    if(a==b)return a;
    
    for(int i=19;i>=0;i--)
    {
        if(lca[a][i]!=-1 && (lca[a][i] != lca[b][i]))
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    
    return lca[a][0];
}

ll dist(int a,int b)
{
    int cmn_anc = LCA(a,b);
    
    return level[a]+level[b] - 2*level[cmn_anc];
}
