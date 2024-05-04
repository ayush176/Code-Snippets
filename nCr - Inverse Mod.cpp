//nCr --  using Fermet's Little Theorem

class Solution{   
public:
    vector<long> fac;
    long mod = 1e9+7;
    long int inverseMod(long a){
        return power(a,mod-2);
    }
    long power(long a,long b){
        long res = 1;
        while(b){
            if(b&1) res = (res*a)%mod;
            b >>= 1;
            a = (a*a)%mod;
        }
        return res%mod;
    }
    long int ncr(int n, int r){
        //complete the function here
        if(r>n)return 0;
        fac.resize(1e5+1,1);
        
        for(long i=1;i<fac.size();i++){
            fac[i] = (fac[i-1]*i)%mod;
        }
        
        return ((fac[n]*inverseMod(fac[r]))%mod * inverseMod(fac[n-r]))%mod;
    }
};


/////////////////////////////////////////////////////////////////////////
// if numbers are big - use 128 bits integer for powers

QUES - Modular GCD codechef

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
using uint128 = __uint128_t;
ll power(ll a, ll b, ll n){
    ll res = 1;
    a = a%n;
    while(b){
        if(b&1) res = ((uint128)res*a)%n;
        b>>=1;
        a = ((uint128)a*a)%n;
    }
    return res%n;
}
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--){
	    ll a,b,n;
	    cin>>a>>b>>n;
	    ll mod = 1e9+7ll;
	    ll num = a-b;
	    if(a==b){
	        cout<<((power(a,n,mod)+ power(b,n,mod))%mod)<<"\n";
	        continue;
	    }
	    ll fir = power(a,n,num);
	    ll sec = power(b,n,num);
	    cout<< (__gcd((fir+sec)%num,num)%mod)<<"\n";
	}

}

