#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>
#define ordered_mutliset_pair tree<pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
#define ll  long long int
#define dbg(x) cout << #x << " -> "; ppp(x); cout<<endl
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define endk '\n'
void ppp(int a)          { cout<<a; }
void ppp(ll a)           { cout<<a; }
void ppp(long double a)  { cout<<a; }
void ppp(double a)       { cout<<a; }
void ppp(char a)         { cout<<a; }
void ppp(string a)       { cout<<a; }
void ppp(bool a)         { cout<<a; }
//   priority_queue<ll,vector<ll>,greater<ll>>q;
template<class T , class V> void ppp(pair<T,V> p) {cout<<"{"; ppp(p.ff); cout<<','; ppp(p.ss); cout<<"}";}
template<class T> void ppp(vector<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
template<class T> void ppp(set<T> v){cout<<"[ ";for(T x:v) ppp(x) , cout<<" ";cout<<']';}
template<class T, class V> void ppp(map<T,V> m){cout<<endl;for(auto x:m){ppp(x.ff);cout<<" -> ";ppp(x.ss);cout<<endl;}cout<<endl;}
template<class T> void ppp(deque<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
/*    ordered_set ma insert karva
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */
vector<ll>dx={-1,1,-1,1};
vector<ll>dy={-1,-1,1,1};
ll N=1e3+1;
vector<ll>fact,inverse_fact;
ll mod=998244353;
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
ll ncr(ll n,ll r){
     ll base=(inverse_fact[r]*inverse_fact[n-r])%mod;
     ll upper=(fact[n])%mod;
     return (base*upper)%mod;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n;
   cin>>n;
   solve();
   vector<ll>a(n);
   ll i;
   for(i=0;i<n;i++){
        cin>>a[i];
   }
   vector<ll>dp(n+1,0);
   dp[n]++;
   ll j;
   for(i=n-1;i>=0;i--){
        if(a[i]<=0){
             continue;
        }
     //    dbg(dp);
       for(j=a[i]+i+1;j<=n;j++){
            ll land=j-i-1;
            ll op=ncr(land,a[i]);
            dp[i]+=(dp[j]*op)%mod;
            dp[i]%=mod;
       }
     //   dbg(dp);
   }
   for(i=n-2;i>=0;i--){
        dp[i]+=dp[i+1];
        dp[i]%=mod;
   }
   cout<<dp[0];
}