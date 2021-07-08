#include <bits/stdc++.h>
using namespace std;

struct query{
    int l,r,id;
};

//Preset block size around sqrt of max constraint
int BLK = 555;
int cnt = 0;
int ar[30001],freq[1000001],ans[200001];
query Q[200001];

bool comp(query a, query b)
{
    if(a.l / BLK != b.l/BLK) return a.l/BLK < b.l/BLK;
    
    return a.r/BLK < b.r/BLK;
}

void add(int pos)
{
    int val = ar[pos];
    if(freq[val]==0)cnt++;
    freq[val]++;
}

void remove(int pos)
{
    int val = ar[pos];
    if(freq[val]==1)cnt--;
    freq[val]--;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>ar[i];
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].l--,Q[i].r--;
        Q[i].id = i;
    }

    sort(Q,Q+q,comp);
    
    int ML=0,MR=-1;

    for(int i=0;i<q;i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        //extending the range
        while(ML > L)ML-- , add(ML);
        while(MR < R)MR++ , add(MR);

        //contracting the range
        while(ML < L)remove(ML) , ML++;
        while(MR > R)remove(MR) , MR--;

        ans[Q[i].id] = cnt;
    }
    for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
    return 0;
}
