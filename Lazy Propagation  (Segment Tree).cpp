#include <bits/stdc++.h>
using namespace std; 

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

const int N = 400003;
int n,q,seg[N],lazy[N],arr[N];

void buildTree(int si, int ss, int se)
{
    if(ss == se)
    {
        seg[si] = arr[ss];
        return;
    }

    int mid = (ss+se)/2;
    buildTree(2*si, ss, mid);
    buildTree(2*si+1, mid+1, se);

    seg[si] = seg[2*si] + seg[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe)
{
    if(lazy[si]!=0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        seg[si] += dx*(se-ss+1);

        if(ss != se)
        {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }

    if(ss>qe || se<qs) return 0;

    if(ss>=qs && se<=qe)return seg[si];

    int mid = (ss+se)/2;

    int l = query(2*si, ss, mid, qs, qe);
    int r = query(2*si+1, mid+1, se, qs, qe);

    return l+r;
}

void update(int si, int ss, int se, int qs, int qe, int val)
{
    if(lazy[si]!=0)
    {
        int dx = lazy[si];
        lazy[si] = 0;
        seg[si] += dx*(se-ss+1);

        if(ss != se)
        {
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }

    if(ss>qe || se<qs) return;

    if(ss>=qs && se<=qe)
    {
        seg[si] += val*(se-ss+1);

        if(ss!=se)
        {
            lazy[2*si]+=val;
            lazy[2*si+1]+=val;
        
        }
        return ;
    }

    int mid = (ss+se)/2;

    update(2*si, ss, mid, qs, qe, val);
    update(2*si+1, mid+1, se, qs, qe, val);

    seg[si] = seg[2*si] + seg[2*si+1];
}

int main() {
    FAST
    int t=1;
    //cin>>t;
    while(t--)
    {
       cin>>n>>q;
       for(int i=1;i<=n;i++)cin>>arr[i];

       buildTree(1,1,n);
       
       while(q--)
       {
           int act;
           cin>>act;
           
           if(act==1)
           {
               int l,r;
               cin>>l>>r;
               l++,r++;
               cout<<query(1,1,n,l,r)<<"\n";
           }
           else
           {
               int l,r,val;
               cin>>l>>r>>val;
               //for 0-based indexing in ques.
               l++,r++;
               update(1,1,n,l,r,val);
           }
       }
    }
    return 0;
}
