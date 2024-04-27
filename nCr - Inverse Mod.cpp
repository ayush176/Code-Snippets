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
