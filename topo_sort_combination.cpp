/*
#define ll long long int
class Solution {
public:
ll N;
vector<ll>fact,inverse_fact;
ll mod=pow(10,9)+7;
ll power(ll a){
     ll b=mod-2;
     ll ans=1;
     while(b>0){
          if(b&1){
               ans*=a;
               ans%=mod;
          }
          a*=a;
          a%=mod;
          b/=2;
     }
     return ans;
}
void solve(){
     ll i;
     fact.resize(N,1LL);
     inverse_fact.resize(N,1LL);
     for(i=1;i<N;i++){
          fact[i]=(fact[i-1]*i)%mod;
     }
     inverse_fact[N-1]=power(fact[N-1]);
     for(i=N-2;i>=0;i--){
          inverse_fact[i]=((i+1)*inverse_fact[i+1])%mod;
     } 
}
vector<vector<ll>>adj;
vector<ll>szn;
vector<ll>dpx;
ll ncr(ll n,ll r){
     ll base=(inverse_fact[r]*inverse_fact[n-r])%mod;
     ll upper=(fact[n])%mod;
     return (base*upper)%mod;
}
void dfs(ll v){
    ll ans=1;
    szn[v]=1;
    for(auto &x:adj[v]){
          dfs(x);
          szn[v]+=szn[x];
    }
    for(auto &x:adj[v]){
        ans*=inverse_fact[szn[x]];
        ans%=mod;
        dpx[v]*=(dpx[x]);
        dpx[v]%=mod;
    }
    ans*=(fact[szn[v]-1]);
    ans%=mod;
    dpx[v]*=ans;
    dpx[v]%=mod;
}
    int waysToBuildRooms(vector<int>& pre) {
        ll n=pre.size();
        N=n+1;
        solve();
        adj.clear();
        adj.resize(n+1);
        ll i;
        for(i=1;i<n;i++){
           adj[pre[i]].push_back(i);
        }
        dpx.clear();
        dpx.resize(n+1,1LL);
        szn.clear();
        szn.resize(n+1);
        dfs(0);
        int jp=dpx[0];
        return jp;
    }
};


*/