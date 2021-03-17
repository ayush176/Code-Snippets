#include <bits/stdc++.h>
using namespace std; 

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

const int N = 400003;
int n,seg[N],arr[N];

void buildTree(int si, int ss, int se)
{
    if(ss == se)
    {
        seg[si] = arr[ss];
        return;
    } 

    int mid = (ss+se)/2;

    buildTree(2*si, ss , mid);
    buildTree(2*si+1, mid+1, se);

    seg[si] = min(seg[2*si],seg[2*si+1]);
}

int query(int si, int ss, int se , int qs, int qe)
{
    if(se<qs || ss>qe) return INT_MAX;

    if(ss>=qs && se<=qe)return seg[si];

    int mid = (ss+se)/2;
    int l = query(2*si,ss,mid,qs,qe);
    int r = query(2*si+1,mid+1,se,qs,qe);

    return min(l,r);
}

void update(int si, int ss, int se , int qi )
{
    if(ss==se)
    {
        seg[si] = arr[ss];
        return;
    }

    int mid = (ss+se)/2;

    if(qi<=mid)update(2*si,ss,mid,qi);
    else update(2*si,mid+1,se,qi);
    
    seg[si] = min(seg[2*si],seg[2*si+1]);
}

void update(int si, int ss, int se, int qi, int val)
{
    if(ss == se)
    {
        arr[ss] = val;
        seg[si] = val;
        return;
    }
    int mid = (ss+se)/2;
    
    if(qi<=mid) update(2*si,ss,mid,qi,val);
    else update(2*si+1,mid+1,se,qi,val);
}

int main() {
    FAST
    int t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n;

        //We are using 1-based indexing
        for(int i=1;i<=n;i++)cin>>arr[i];
        buildTree(1,1,n);
        int q;
        cin>>q;
        while(q--)
        {
            int act;
            cin>>act;
            if(act==0)//query
            {
                int l,r;
                cin>>l>>r;
                //if in ques 0-based indexing was there ,So increase and r.
                l++;r++;
                int ans = query(1,1,n,l,r);
                cout<<ans<<"\n";
            }
            else //update
            {
                int qi,val;
                cin>>qi>>val;
                qi++; // for 0-based indexing increase qi.
                update(1,1,n,qi,val);
            }
        }
    }
    return 0;
}
